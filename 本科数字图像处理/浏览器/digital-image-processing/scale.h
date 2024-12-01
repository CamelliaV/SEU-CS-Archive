#ifndef SCALE_H
#define SCALE_H

#include <QDialog>
#include "utils.h"

namespace Ui {
  class Scale;
}

class Scale : public QDialog
{
  Q_OBJECT

public:
  explicit Scale(QWidget *parent = nullptr);
  QMetaObject::Connection handle(QImage *&target, QImage *reference);
  ~Scale();

private:
  Ui::Scale *ui;
  Utils *utilsWindow = Utils::getInstance();

  void scale(QImage *&target, QImage *reference);
  int getPixel(int i, int j, QImage *reference);
  void writeBack(int i, int j, QImage *&target, QImage *reference, int value);
private slots:
  void scaleHandler(QImage *&target, QImage *reference);
};

#endif // SCALE_H
