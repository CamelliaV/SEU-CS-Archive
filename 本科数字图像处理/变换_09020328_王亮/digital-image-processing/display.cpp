#include "display.h"
#include "qgraphicsscene.h"
#include "ui_display.h"

Display::Display(QWidget *parent, QImage *target) :
  QDialog(parent),
  ui(new Ui::Display)
{
  ui->setupUi(this);
  if (!target) return;
  QGraphicsScene *scene = new QGraphicsScene();
  scene->addPixmap(QPixmap::fromImage(*target));
  ui->view->setScene(scene);
  // this->adjustSize();
}

Display::~Display()
{
  delete ui;
}
