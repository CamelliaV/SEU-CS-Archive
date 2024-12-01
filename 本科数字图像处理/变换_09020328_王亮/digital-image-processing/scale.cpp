#include "scale.h"
#include "ui_scale.h"

Scale::Scale(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Scale)
{
  ui->setupUi(this);
}

QMetaObject::Connection Scale::handle(QImage *&target, QImage *reference)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
      scaleHandler(target, reference);
    });
  return event;
}

Scale::~Scale()
{
  delete ui;
}

void Scale::scaleHandler(QImage *&target, QImage *reference)
{
  if (!target) return;
  // qDebug() << target->width() << " " << target->height();
  int rows = reference->height();
  int cols = reference->width();
  double scale = ui->value->value();
  if (scale <= 0) return;
  int newRows = int(rows * scale);
  int newCols = int(cols * scale);
  QImage *image = new QImage(QSize(newCols, newRows), QImage::Format_Indexed8);
  image->setColorCount(256);
  for (int i = 0; i < 256; i++) {
    image->setColor(i, reference->color(i));
  }
  for (int i = 0; i < newRows; i++) {
      for (int j = 0; j < newCols; j++) {

        double pos_i = i / scale;
        double pos_j = j / scale;

        int pos_i_integer = pos_i;
        int pos_j_integer = pos_j;

        if (pos_i == pos_i_integer && pos_j == pos_j_integer) {
          image->setPixel(j, i, reference->pixelIndex(pos_j_integer, pos_i_integer));
          // newMat[i][j] = mat[pos_i_integer][pos_j_integer];
          continue;
        }

        double u = int(pos_j) == (cols - 1) ? 1 : pos_j - pos_j_integer;
        double v = int(pos_i) == (rows - 1) ? 1 : pos_i - pos_i_integer;

        pos_i_integer = int(pos_i) == (rows - 1) ? int(pos_i) - 1 : pos_i;
        pos_j_integer = int(pos_j) == (cols - 1) ? int(pos_j) - 1 : pos_j;

//        double Q_00 = (1 - u) * (1 - v) * mat[pos_i_integer][pos_j_integer];
//        double Q_10 = (1 - u) * (v) * mat[pos_i_integer + 1][pos_j_integer];
//        double Q_01 = (u) * (1 - v) * mat[pos_i_integer][pos_j_integer + 1];
//        double Q_11 = (u) * (v) * mat[pos_i_integer + 1][pos_j_integer + 1];

        double Q_00 = (1 - u) * (1 - v) * reference->pixelIndex(pos_j_integer, pos_i_integer);
        double Q_10 = (1 - u) * (v) * reference->pixelIndex(pos_j_integer, pos_i_integer + 1);
        double Q_01 = (u) * (1 - v) * reference->pixelIndex(pos_j_integer + 1, pos_i_integer);
        double Q_11 = (u) * (v) * reference->pixelIndex(pos_j_integer + 1, pos_i_integer + 1);

        // newMat[i][j] = Q_00 + Q_01 + Q_10 + Q_11;
        image->setPixel(j, i, Q_00 + Q_01 + Q_10 + Q_11);
      }
    }
    delete target;
    target = image;
}
