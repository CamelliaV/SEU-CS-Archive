#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("09020328王亮-第二次数字图像处理实验");
    this->setWindowIcon(QIcon(":/src/94722079_p0.jpg"));
    // tie 'openImage' to 'openImageButton'
    // both methods for instance not for class
    connect(ui->openImageButton, SIGNAL(clicked(bool)), this, SLOT(openImage()));

    connect(ui->functionality->actions()[0], SIGNAL(triggered(bool)), this, SLOT(loadScaledImage()));
    connect(scaleWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[1], SIGNAL(triggered(bool)), this, SLOT(loadRotatedImage()));
    connect(rotateWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->checkOriginal, &QPushButton::clicked, this, [&]() {
      displayImage(this->imageToProcess);
      });
    connect(ui->checkNew, &QPushButton::clicked, this, [&]() {
      displayImage(this->imageProcessed);
      });
    // Debug:
    // ui->imageLabel->setStyleSheet("background-color: red");


}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::openImage()
{

  // qDebug() << "Method called" << Qt::endl;
  QString openFile;
  QImage openImage;

  // open image file
  openFile = QFileDialog::getOpenFileName(this,
                                          "Select one image file",
                                          "",
                                          "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");

  // if not chosen, skip
  // otherwise, display image
  if (openFile != "")
  {
      if (openImage.load(openFile))
      {
          this->imageToProcess = new QImage(openImage);
          this->imageProcessed = new QImage(openImage);
          QPixmap imageUnDisposed = QPixmap::fromImage(openImage);
          int height = 0.5 * this->screen()->virtualSize().height();
          int width = 0.5 * this->screen()->virtualSize().width();
          QPixmap imageDisposed = imageUnDisposed.scaled(QSize(width, height), Qt::KeepAspectRatio, Qt::SmoothTransformation);
          height = openImage.height();
          width = openImage.width();
          ui->openImageButton->setText("Width: " + QString::number(width) + ", " + "Height: " + QString::number(height));
          ui->imageLabel->setPixmap(imageDisposed);
          ui->imageLabelDisposed->setPixmap(imageDisposed);

          // set the size of layout to fit the image
          ui->centralwidget->layout()->setSizeConstraint(QLayout::SetFixedSize);
          // Note: I expect the mainWindow to adjust to fit the layout
          //       which is the visual part of the program
          //       however, the layout is binded to the centralWidget
          //       so both must adjust in the following sequence
          this->centralWidget()->adjustSize();
          this->adjustSize();
      }
  }
  // demonstrate image file info
  QFileInfo openFileInfo;
  openFileInfo = QFileInfo(openFile);
  ui->urlEdit->setText(openFileInfo.filePath());
}

void MainWindow::updateImage()
{
  if (!imageProcessed) return;
  QPixmap imageUnDisposed = QPixmap::fromImage(*imageProcessed);
  int height = 0.5 * this->screen()->virtualSize().height();
  int width = 0.5 * this->screen()->virtualSize().width();
  QPixmap imageDisposed = imageUnDisposed.scaled(QSize(width, height), Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->imageLabelDisposed->setPixmap(imageDisposed);
  height = imageProcessed->height();
  width = imageProcessed->width();
  ui->openFunctionButton->setText("Width: " + QString::number(width) + ", " + "Height: " + QString::number(height));
  ui->centralwidget->layout()->setSizeConstraint(QLayout::SetFixedSize);
  this->centralWidget()->adjustSize();
  this->adjustSize();
}

void MainWindow::loadScaledImage()
{
  auto event = scaleWindow->handle(this->imageProcessed, this->imageToProcess);
  scaleWindow->exec();
  disconnect(event);
}

void MainWindow::loadRotatedImage()
{
  auto event = rotateWindow->handle(this->imageProcessed, this->imageToProcess);
  rotateWindow->exec();
  disconnect(event);
}

void MainWindow::displayImage(QImage *target)
{
  Display* screen = new Display(this, target);
  screen->exec();
  delete screen;
}

