#ifndef UTILS_H
#define UTILS_H

#include <QDialog>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
  class Utils;
}

class Utils : public QDialog
{
  Q_OBJECT

public:
  static Utils* getInstance();
  QMetaObject::Connection handle(QImage *&target, QImage *reference);
  void storeData(QImage *imageProcessed, QImage *imageProcessedMask);
  void restoreData(QImage *&imageToProcess, QImage *&imageProcessed, QImage *&imageToProcessMask, QImage *&imageProcessedMask);
  void clearData();
  int getPixel(int i, int j, QImage *reference);
  void writeBack(int i, int j, QImage *&target, QImage *reference, int value);
  void grayTransPublicGray8(QImage *&target, QImage *reference);
  void grayTransPublicGray16(QImage *&target, QImage *reference);
  void setMiddle(int middle);
  void setInterval(int interval);
  ~Utils();

public slots:
  void saveAllHistory();


private:
  std::vector<QImage*> imageProcessedList;
  std::vector<QImage*> maskProcessedList;
  // QImage *imageToProcess = nullptr;
  // QImage *imageProcessed = nullptr;
  static Utils* utilsInstance;
  explicit Utils(QWidget *parent = nullptr);
  Ui::Utils *ui;


  void grayInverseHandler(QImage *&target, QImage *reference);
  void symmetryHandler(QImage *&target, QImage *reference);
private slots:
  void utilsHandler(QImage *&target, QImage *reference);
};


#endif // UTILS_H
