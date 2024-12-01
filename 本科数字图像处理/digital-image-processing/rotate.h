#ifndef ROTATE_H
#define ROTATE_H

#include <QDialog>

namespace Ui {
  class Rotate;
}

class Rotate : public QDialog
{
  Q_OBJECT

public:
  explicit Rotate(QWidget *parent = nullptr);
  QMetaObject::Connection handle(QImage *&target, QImage *reference);
  ~Rotate();

private:
  Ui::Rotate *ui;
  void rotateIndex8(QImage *&target, QImage *reference);
  void rotateGray8(QImage *&target, QImage *reference);
private slots:
  void rotateHandler(QImage *&target, QImage *reference);
};

#endif // ROTATE_H
