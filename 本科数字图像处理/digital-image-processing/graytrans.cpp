#include "graytrans.h"
#include "ui_graytrans.h"

GrayTrans::GrayTrans(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GrayTrans)
{
  ui->setupUi(this);
}

QMetaObject::Connection GrayTrans::handle(QImage *&reference, unsigned long width, unsigned long height, QVector<unsigned short> &vec)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
      grayTransHandler(reference, width, height, vec);
    });
  return event;
}

GrayTrans::~GrayTrans()
{
  delete ui;
}

void GrayTrans::grayTransHandler(QImage *&reference, unsigned long width, unsigned long height, QVector<unsigned short> &vec)
{
  if (reference) {
    delete reference;
  }
  unsigned long rows = height;
  unsigned long cols = width;

  QImage *image = new QImage(QSize(cols, rows), QImage::Format_Grayscale8);

  // [a, b] -> [c, d]

  int middle = ui->middle->value();
  int interval = ui->interval->value();
  int b = middle + interval / 2;
  int a = middle - interval / 2;
  int c = 0;
  int d = 255;

  qDebug() << Qt::endl << "rows: " << rows;
  qDebug() << Qt::endl << "cols: " << cols;

  double factor = double(d - c) / double(b - a);
//  QList<QRgb> colorList;
//  for (int i = 0; i < 256; i++) {
//    colorList.append(qRgb(i, i, i));
//  }

  // image->setColorTable(colorList);

  for (int i = 0; i < rows; i++) {
    uchar* scanner = image->scanLine(i);
    for (int j = 0; j < cols; j++) {
      ushort f = vec[i * width + j];
      if (f > b) {
        scanner[j] = 255;
      } else if (f < a) {
        scanner[j] = 0;
      } else {
        scanner[j] = (uchar)(factor * f + c);
      }
    }
  }
  reference = image;
}


