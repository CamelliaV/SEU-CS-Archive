#include "augment.h"
#include "ui_augment.h"

Augment::Augment(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Augment)
{
  ui->setupUi(this);
}

QMetaObject::Connection Augment::handle(QImage *&target, QImage *reference)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
      augmentHandler(target, reference);
    });
  return event;
}

Augment::~Augment()
{
  delete ui;
}

void Augment::augment(QImage *&target, QImage *reference)
{
  if (!target) return;
  if (target) {
    delete target;
  }
  int width = reference->width();
  int height = reference->height();
  QImage *gaussImage = new QImage(width, height, reference->format());
  QImage *medianImage = new QImage(width, height, reference->format());
  QImage *laplaceImage = new QImage(width, height, reference->format());

//  if (reference->format() == QImage::Format_Indexed8) {
//      image->setColorCount(256);
//      for (int i = 0; i < 256; i++) {
//        image->setColor(i, reference->color(i));
//      }
//  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
       middle(i, j, medianImage, reference);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
       gaussify(i, j, gaussImage, medianImage);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
       laplace(i, j, laplaceImage, gaussImage);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
       high(i, j, medianImage, gaussImage, reference);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
       addBack(i, j, medianImage, laplaceImage);
    }
  }

  delete laplaceImage;
  delete gaussImage;
  target = medianImage;
  qDebug() << "Gauss Succeed!" << Qt::endl;
}

int Augment::getPixel(int i, int j, QImage *reference)
{
//  if (i < 0 || j < 0 || i >= reference->height() || j >= reference->width()) {
//    return 0;
//  }
////  if (reference->format() == QImage::Format_Indexed8) {
////    return reference->pixelIndex(j, i);
////  }
//  if (reference->format() == QImage::Format_Grayscale8) {
//    return reference->scanLine(i)[j];
//  }
//  if (reference->format() == QImage::Format_Grayscale16) {
//    return ((ushort*)reference->scanLine(i))[j];
//  }
//  return 0;
  return utilsWindow->getPixel(i, j, reference);
}

void Augment::gaussify(int i, int j, QImage *&target, QImage *reference)
{
  int start_i = i - 1;
  int start_j = j - 1;
  double temp = 0;
  for (int offset_i = 0; offset_i < gaussCovSize; offset_i++) {
    for (int offset_j = 0; offset_j < gaussCovSize; offset_j++) {
        temp += getPixel(start_i + offset_i, start_j + offset_j, reference) * cov[offset_i][offset_j];
    }
  }
//  if (reference->format() == QImage::Format_Indexed8) {
//    target->setPixel(j, i, temp);
//  }
  writeBack(i, j, target, reference, temp);
}

void Augment::laplace(int i, int j, QImage *&target, QImage *reference)
{
  int start_i = i - 1;
  int start_j = j - 1;
  double temp = 0;
  for (int offset_i = 0; offset_i < laplaceCovSize; offset_i++) {
    for (int offset_j = 0; offset_j < laplaceCovSize; offset_j++) {
        temp += getPixel(start_i + offset_i, start_j + offset_j, reference) * cov2[offset_i][offset_j];
    }
  }
//  if (reference->format() == QImage::Format_Indexed8) {
//    target->setPixel(j, i, temp);
//  }
  temp = temp < 0 ? 0 : temp;
  writeBack(i, j, target, reference, temp);
}

void Augment::middle(int i, int j, QImage *&target, QImage *reference)
{
  std::vector<int> temp;
  int start_i = i - 1;
  int start_j = j - 1;
  for (int offset_i = 0; offset_i < middleCovSize; offset_i++) {
    for (int offset_j = 0; offset_j < middleCovSize; offset_j++) {
        int te = getPixel(start_i + offset_i, start_j + offset_j, reference);
        // if (!te) continue;
        temp.push_back(te);
    }
  }
  std::nth_element(temp.begin(), temp.begin() + temp.size() / 2, temp.end());
  writeBack(i, j, target, reference, *(temp.begin() + temp.size() / 2));
}

void Augment::high(int i, int j, QImage *&target, QImage *candidate, QImage *reference)
{
  int temp = getPixel(i, j, reference);
  temp -= getPixel(i, j, candidate);
  temp = getPixel(i, j, target) + temp * ui->high->value();
  writeBack(i, j, target, reference, temp);
}

void Augment::addBack(int i, int j, QImage *&target, QImage *reference)
{
  writeBack(i, j, target, reference, ui->addBack->value() * getPixel(i, j, reference) + getPixel(i, j, target));
}

void Augment::writeBack(int i, int j, QImage *&target, QImage *reference, int value)
{
//  if (reference->format() == QImage::Format_Grayscale8) {
//    target->scanLine(i)[j] = fmin(value, 255);
//  }
//  if (reference->format() == QImage::Format_Grayscale16) {
//    ((ushort*)target->scanLine(i))[j] = fmin(value, 4095);
//  }
  return utilsWindow->writeBack(i, j, target, reference, value);
}

void Augment::augmentHandler(QImage *&target, QImage *reference)
{
  augment(target, reference);
}
