#include "rotate.h"
#include "ui_rotate.h"

Rotate::Rotate(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Rotate)
{
  ui->setupUi(this);
}

QMetaObject::Connection Rotate::handle(QImage *&target, QImage *reference)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
      rotateHandler(target, reference);
    });
  return event;
}

Rotate::~Rotate()
{
  delete ui;
}

void Rotate::rotate(QImage *&target, QImage *reference)
{
  if (!target || !reference) return;
  double angle = ui->value->value();
  double radian = angle * M_PI / 180;
  int rows = reference->height();
  int cols = reference->width();


  int x_default = reference->width() / 2;
  int y_default = reference->height() / 2;

  int x_0 = ui->value_x->value();
  int y_0 = ui->value_y->value();

  x_0 = x_0 == -1 ? x_default : x_0;
  y_0 = y_0 == -1 ? y_default : y_0;

  if (x_0 >= cols || y_0 >= rows) return;

  double sin_ = sin(radian);
  double cos_ = cos(radian);
  QImage *image = new QImage(QSize(cols, rows), reference->format());

   for (int y = 0; y < rows; y++) {

     for (int x = 0; x < cols; x++) {

       double pos_x = x_0 + cos_ * (x - x_0) + sin_ * (y - y_0);
       double pos_y = y_0 + cos_ * (y - y_0) - sin_ * (x - x_0);

       int xx = pos_x;
       int yy = pos_y;

       if (yy < 0 || xx < 0 || yy >= rows || xx >= cols) {
         // image->setPixel(x, y, 0);
         this->utilsWindow->writeBack(y, x, image, reference, 0);
       //  newMat[y][x] = 0;
         continue;
       }

       if (pos_y == yy && pos_x == xx) {
           // image->setPixel(x, y, reference->pixelIndex(xx, yy));
           this->utilsWindow->writeBack(y, x, image, reference, this->utilsWindow->getPixel(yy, xx, reference));

         // newMat[y][x] = mat[yy][xx];
         continue;
       }

       double u = int(pos_x) == (cols - 1) ? 1 : pos_x - xx;
       double v = int(pos_y) == (rows - 1) ? 1 : pos_y - yy;

       yy = int(pos_y) == (rows - 1) ? int(pos_y) - 1 : pos_y;
       xx = int(pos_x) == (cols - 1) ? int(pos_x) - 1 : pos_x;


       double Q_00 = (1 - u) * (1 - v) * this->utilsWindow->getPixel(yy, xx, reference);
       double Q_10 = (1 - u) * (v) * this->utilsWindow->getPixel(yy + 1, xx, reference);
       double Q_01 = (u) * (1 - v) * this->utilsWindow->getPixel(yy, xx + 1, reference);
       double Q_11 = (u) * (v) * this->utilsWindow->getPixel(yy + 1, xx + 1, reference);

       this->utilsWindow->writeBack(y, x, image, reference, Q_00 + Q_01 + Q_10 + Q_11);

     }

   }
   delete target;
   target = image;
}

void Rotate::rotateHandler(QImage *&target, QImage *reference)
{

  // if (reference->format() == QImage::Format_Indexed8) return rotateIndex8(target, reference);
  rotate(target, reference);



}
