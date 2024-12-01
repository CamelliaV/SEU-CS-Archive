#ifndef GRAYTRANS_H
#define GRAYTRANS_H

#include <QDialog>
#include "utils.h"

namespace Ui {
  class GrayTrans;
}

class GrayTrans : public QDialog
{
  Q_OBJECT

public:
  explicit GrayTrans(QWidget *parent = nullptr);
  QMetaObject::Connection handle(QImage *&target, QImage *reference);
  ~GrayTrans();


private:
  Ui::GrayTrans *ui;
  Utils *utilsWindow = Utils::getInstance();
private slots:
  void grayTransHandler(QImage *&target, QImage *reference);
};

#endif // GRAYTRANS_H
