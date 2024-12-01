#ifndef SCALE_H
#define SCALE_H

#include <QDialog>

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
private slots:
  void scaleHandler(QImage *&target, QImage *reference);
};

#endif // SCALE_H
