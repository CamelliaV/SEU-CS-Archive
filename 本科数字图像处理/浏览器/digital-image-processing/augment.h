#ifndef AUGMENT_H
#define AUGMENT_H

#include <QDialog>
#include "utils.h"

constexpr int gaussCovSize = 3;
constexpr double cov[gaussCovSize][gaussCovSize] = {
  {0.3679 / 4.8976, 0.6065 / 4.8976, 0.3679 / 4.8976},
  {0.6065 / 4.8976, 1.0000 / 4.8976, 0.6065 / 4.8976},
  {0.3679 / 4.8976, 0.6065 / 4.8976, 0.3679 / 4.8976},
};
constexpr int laplaceCovSize = 3;
constexpr double cov2[laplaceCovSize][laplaceCovSize] = {
  {0, -1, 0},
  {-1, 4, -1},
  {0, -1, 0},
};
constexpr int middleCovSize = 3;
constexpr int middlePlace = middleCovSize * middleCovSize / 2;

namespace Ui {
  class Augment;
}

class Augment : public QDialog
{
  Q_OBJECT

public:
  explicit Augment(QWidget *parent = nullptr);
  QMetaObject::Connection handle(QImage *&target, QImage *reference);
  ~Augment();

private:
  Ui::Augment *ui;
  Utils *utilsWindow = Utils::getInstance();
  void augment(QImage *&target, QImage *reference);

  int getPixel(int i, int j, QImage *reference);
  void gaussify(int i, int j, QImage *&target, QImage* reference);
  void laplace(int i, int j, QImage *&target, QImage* reference);
  void middle(int i, int j, QImage *&target, QImage* reference);
  void high(int i, int j, QImage *&target, QImage* candidate, QImage* reference);
  void addBack(int i, int j, QImage *&target, QImage* reference);
  void writeBack(int i, int j, QImage *&target, QImage *reference, int value);
private slots:
  void augmentHandler(QImage *&target, QImage *reference);
};

#endif // AUGMENT_H
