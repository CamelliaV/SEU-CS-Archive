#ifndef GRAYTRANS_H
#define GRAYTRANS_H

#include <QDialog>

namespace Ui {
  class GrayTrans;
}

class GrayTrans : public QDialog
{
  Q_OBJECT

public:
  explicit GrayTrans(QWidget *parent = nullptr);
  QMetaObject::Connection handle(QImage *&reference, unsigned long width, unsigned long height, QVector<unsigned short> &vec);
  ~GrayTrans();

private:
  Ui::GrayTrans *ui;
private slots:
  void grayTransHandler(QImage *&reference, unsigned long width, unsigned long height, QVector<unsigned short> &vec);
};

#endif // GRAYTRANS_H
