#include "graytrans.h"
#include "ui_graytrans.h"

GrayTrans::GrayTrans(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GrayTrans)
{
  ui->setupUi(this);
}

QMetaObject::Connection GrayTrans::handle(QImage *&target, QImage *reference)
{
  QMetaObject::Connection event = connect(ui->work, &QPushButton::clicked, this, [&](){
      grayTransHandler(target, reference);
    });
  return event;
}

GrayTrans::~GrayTrans()
{
  delete ui;
}

void GrayTrans::grayTransHandler(QImage *&target, QImage *reference)
{
  utilsWindow->setMiddle(ui->middle->value());
  utilsWindow->setInterval(ui->interval->value());
}


