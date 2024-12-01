#include "utils.h"
#include "ui_utils.h"

int SINGAL_CAPACITY = 10;
int MIDDLE = 0;
int INTERVAL = 0;

Utils::Utils(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Utils)
{
  ui->setupUi(this);
}

Utils* Utils::utilsInstance = nullptr;

Utils* Utils::getInstance()
{
  if (utilsInstance == nullptr) {
    utilsInstance = new Utils();
  }
  return utilsInstance;
}

QMetaObject::Connection Utils::handle(QImage *&target, QImage *reference)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
     utilsHandler(target, reference);
  });
  return event;
}

void Utils::storeData(QImage *imageProcessed, QImage *imageProcessedMask)
{
  if (this->imageProcessedList.size() > SINGAL_CAPACITY) {
    if (ui->isClear->isChecked()) {
      this->imageProcessedList.clear();
      this->maskProcessedList.clear();
    } else {
      this->imageProcessedList.erase(this->imageProcessedList.begin());
      this->maskProcessedList.erase(this->maskProcessedList.begin());
    }
  }

  this->imageProcessedList.push_back(new QImage(*imageProcessed));
  this->maskProcessedList.push_back(new QImage(*imageProcessedMask));
}

void Utils::restoreData(QImage *&imageToProcess, QImage *&imageProcessed, QImage *&imageToProcessMask, QImage *&imageProcessedMask)
{
  if (this->imageProcessedList.empty()) {
    return;
  }

  imageToProcess = new QImage(*(this->imageProcessedList.back()));
  imageProcessed = new QImage(*(this->imageProcessedList.back()));
  imageToProcessMask = new QImage(*(this->maskProcessedList.back()));
  imageProcessedMask = new QImage(*(this->maskProcessedList.back()));

  delete this->imageProcessedList.back();
  this->imageProcessedList.pop_back();

  delete this->maskProcessedList.back();
  this->maskProcessedList.pop_back();
}

void Utils::clearData()
{
  for (auto i : this->imageProcessedList) {
    delete i;
  }
  for (auto i : this->maskProcessedList) {
    delete i;
  }
  this->imageProcessedList.clear();
  this->maskProcessedList.clear();

}

void Utils::saveAllHistory()
{
  for (QImage* item : maskProcessedList) {
      QDateTime time = QDateTime::currentDateTime();
      QString current_date = time.toString("yyyy_MM_dd_hh_mm_ss_zzz");
      current_date = current_date + ".bmp";
      QImage *temp = new QImage(*item);
      temp->save(current_date);
      delete temp;
  }
}


Utils::~Utils()
{
  delete ui;
}

void Utils::grayInverseHandler(QImage *&target, QImage *reference)
{
  if (!target) return;
  int rows = reference->height();
  int cols = reference->width();
  // qDebug() << "Gray Inverse Original: " << getPixel(0, 0, reference) << Qt::endl;

  QImage *image = new QImage(reference->width(), reference->height(), reference->format());

  int grayLevel = reference->format() == QImage::Format_Grayscale8 ? 256 : 4095;

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          int newPixel = grayLevel - 1 - getPixel(i, j, reference);
          writeBack(i, j, image, reference, newPixel);
      }
    }
  // qDebug() << "Gray Inverse After: " << getPixel(0, 0, reference) << Qt::endl;
  delete target;
  target = image;
}

void Utils::symmetryHandler(QImage *&target, QImage *reference)
{
  if (!target) return;
  int rows = reference->height();
  int cols = reference->width();

  QImage *image = new QImage(reference->width(), reference->height(), reference->format());

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          writeBack(i, j, image, reference, getPixel(i, cols - j - 1, reference));
      }
  }

  delete target;
  target = image;
}

void Utils::utilsHandler(QImage *&target, QImage *reference)
{
  if (!target) {
    return;
  }
  SINGAL_CAPACITY = ui->capacity->value();
  if (ui->symmetry->isChecked()) {
    symmetryHandler(target, reference);
  }
  if (ui->grayInverse->isChecked()) {
    grayInverseHandler(target, reference);
  }
}

int Utils::getPixel(int i, int j, QImage *reference)
{
  if (i < 0 || j < 0 || i >= reference->height() || j >= reference->width()) {
    return 0;
  }
//  if (reference->format() == QImage::Format_Indexed8) {
//    return reference->pixelIndex(j, i);
//  }
  if (reference->format() == QImage::Format_Grayscale8) {
    return reference->scanLine(i)[j];
  }
  if (reference->format() == QImage::Format_Grayscale16) {
    return ((ushort*)reference->scanLine(i))[j];
  }
  return 0;
}


void Utils::writeBack(int i, int j, QImage *&target, QImage *reference, int value)
{
  if (reference->format() == QImage::Format_Grayscale8) {
    target->scanLine(i)[j] = fmin(value, 255);
  }
  if (reference->format() == QImage::Format_Grayscale16) {
    ((ushort*)target->scanLine(i))[j] = fmin(value, 4095);
    }
}

void Utils::grayTransPublicGray8(QImage *&target, QImage *reference)
{
  if (target) {
    delete target;
  }
  target = new QImage(*reference);
}

void Utils::grayTransPublicGray16(QImage *&target, QImage *reference)
{
  if (target) {
    delete target;
  }
  unsigned long rows = reference->height();
  unsigned long cols = reference->width();

  QImage *image = new QImage(QSize(cols, rows), QImage::Format_Grayscale8);

  // [a, b] -> [c, d]

  int middle = MIDDLE;
  int interval = INTERVAL;
  int b = middle + interval / 2;
  int a = middle - interval / 2;
  int c = 0;
  int d = 255;

  double factor = double(d - c) / double(b - a);

  for (int i = 0; i < rows; i++) {
    ushort* ori = (ushort*)reference->scanLine(i);
    uchar* scanner = image->scanLine(i);
    for (int j = 0; j < cols; j++) {
      ushort f = ori[j];
      if (f > b) {
        scanner[j] = 255;
      } else if (f < a) {
        scanner[j] = 0;
      } else {
        scanner[j] = (uchar)(factor * f + c);
      }
    }
  }
  target = image;
}

void Utils::setMiddle(int middle)
{
  MIDDLE = middle;
}

void Utils::setInterval(int interval)
{
  INTERVAL = interval;
}
