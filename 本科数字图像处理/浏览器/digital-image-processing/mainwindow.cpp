#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("09020328王亮-第五次数字图像处理实验");
    this->setWindowIcon(QIcon(":/src/94722079_p0.jpg"));
    // tie 'openImage' to 'openImageButton'
    // both methods for instance not for class
    QMessageBox::information(this, "Brief Intro!", "A rudiment software to resolve fundamental image processing tasks. Use functionality menu to augment|set gray window|rotate|scale, use utils to accomplish symmetry transpose | gray inversion; Redo is possible, but keep in mind the stored data is temporarily on ram and the size is adjustable; Save can function as well, with demerits of inability to change dirs of history save notwithstanding.");
    connect(ui->openImageButton, SIGNAL(clicked(bool)), this, SLOT(openImage()));
    connect(ui->replaceInputButton, &QPushButton::clicked, this, [&]() {
      if (this->imageProcessed) {
        if (this->isAutoSave) {
          QMessageBox::information(this, "Invalid operation!", "Function only with autosave turned off!");
          return;
        }
        delete this->imageToProcess;
        this->imageToProcess = new QImage(*(this->imageProcessed));
        updateMainScreen();
      }
    });
    connect(ui->undo, &QPushButton::clicked, this, [&]() {
      if (this->imageProcessed) {
        isUndo = true;
        this->utilsWindow->restoreData(this->imageToProcess, this->imageProcessed, this->imageToProcessMask, this->imageProcessedMask);
        updateImage();
      }
    });
    connect(ui->autoSave, &QPushButton::clicked, this, [&]() {
      QMessageBox::information(this, "Auto Save State Change!", "Auto save state change, see menu above to check!");
      this->isAutoSave = !this->isAutoSave;
      ui->AutoSave->setEnabled(this->isAutoSave);
    });
    connect(ui->saveAll, &QPushButton::clicked, this, [&]() {
      if (!this->imageProcessed) {
         return;
      }
      this->utilsWindow->saveAllHistory();
      QMessageBox::information(this, "All History Saved!", "All History Saved! Current image can be saved with the bottom right button");
    });
    connect(ui->saveRight, &QPushButton::clicked, this, [&]() {
        if (!this->imageProcessed) {return;}
        saveImage(this->imageProcessed);
        QMessageBox::information(this, "Current Image Saved!", "Current Image Saved!");
      });


    connect(ui->functionality->actions()[0], SIGNAL(triggered(bool)), this, SLOT(loadScaledImage()));
    connect(scaleWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[1], SIGNAL(triggered(bool)), this, SLOT(loadRotatedImage()));
    connect(rotateWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[2], SIGNAL(triggered(bool)), this, SLOT(loadGrayTransImage()));
    connect(grayTransWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[3], SIGNAL(triggered(bool)), this, SLOT(loadAugmentImage()));
    connect(augmentWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[4], SIGNAL(triggered(bool)), this, SLOT(loadUtilsImage()));
    connect(utilsWindow, SIGNAL(rejected()), this, SLOT(updateImage()));

    connect(ui->functionality->actions()[5], SIGNAL(triggered(bool)), this, SLOT(clearData()));

    connect(ui->checkOriginal, &QPushButton::clicked, this, [&]() {
      displayImage(this->imageToProcessMask);
      });
    connect(ui->checkNew, &QPushButton::clicked, this, [&]() {
      displayImage(this->imageProcessedMask);
      });
    // Debug:
    // ui->imageLabel->setStyleSheet("background-color: red");


}

MainWindow::~MainWindow()
{
  delete ui;
}

std::pair<QImage **, QImage **> MainWindow::getterImages()
{
  isUndo = false;
  if (this->isAutoSave && this->imageProcessed) {
      this->utilsWindow->storeData(this->imageProcessed, imageProcessedMask);

  }
  return std::pair(&this->imageToProcess, &this->imageProcessed);
}

void MainWindow::openRaw(const QString& fileName)
{
  QFile file;
  file.setFileName(fileName);

  if (file.open(QIODevice::ReadOnly)) {
      this->vec.clear();
      char* buffer = new char[4];
      qDebug() << file.read(buffer, 4) << Qt::endl;
      ulong width = ((unsigned long)(uchar)buffer[3] << 3 * 8) +
                    ((unsigned long)(uchar)buffer[2] << 2 * 8) +
                    ((unsigned long)(uchar)buffer[1] << 8) +
                    (unsigned long)(uchar)buffer[0];
      file.read(buffer, 4);
      ulong height = ((unsigned long)(uchar)buffer[3] << 3 * 8) +
                     ((unsigned long)(uchar)buffer[2] << 2 * 8) +
                     ((unsigned long)(uchar)buffer[1] << 8) +
                     (unsigned long)(uchar)buffer[0];
      // for performance
      this->vec.reserve(width * height);
      // QVector<unsigned short> vec;

      while (file.read(buffer, 2)) {
        unsigned short tem = (((unsigned short)(uchar)buffer[1] << 8)) +
                             (unsigned short)(uchar)buffer[0];
        this->vec.push_back(tem & (ushort)4095);
      }

      unsigned long rows = height;
      unsigned long cols = width;
      QImage *image = new QImage(QSize(cols, rows), QImage::Format_Grayscale16);
        for (int i = 0; i < rows; i++) {
            ushort* scanner = (ushort*)image->scanLine(i);
            for (int j = 0; j < cols; j++) {
              scanner[j] = vec[i * width + j];
            }
        }
        if (this->imageToProcess) {
          delete this->imageToProcess;
        }
        if (this->imageProcessed) {
          delete this->imageProcessed;
        }
        this->imageToProcess = image;
        vec.clear();
        this->imageProcessed = new QImage(*image);
      file.close();
  }

}

void MainWindow::openImage()
{
  isUndo = false;

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
      if (openFile.endsWith(".raw")) {
          openRaw(openFile);
          updateMainScreen();
          return;
      }
      if (openImage.load(openFile))
      {
          if (this->imageToProcess) {
            delete this->imageToProcess;
          }
          if (this->imageProcessed) {
              delete this->imageProcessed;
          }
          this->imageToProcess = new QImage(openImage.convertToFormat(QImage::Format_Grayscale8));
          this->imageProcessed = new QImage(openImage.convertToFormat(QImage::Format_Grayscale8));
          updateMainScreen();
      }
  }
  // demonstrate image file info
  QFileInfo openFileInfo;
  openFileInfo = QFileInfo(openFile);
  ui->urlEdit->setText(openFileInfo.filePath());
}

void MainWindow::updateImage()
{
  // QMessageBox::information(this, "Action Done!", "Action Done, Updating MainScreen!");
  if (this->isAutoSave) {
      if (this->imageProcessed) {
        delete this->imageToProcess;
        this->imageToProcess = new QImage(*(this->imageProcessed));
        updateMainScreen();
      }
  }
  if (!isUndo) updateMask();
  QPixmap imageUnDisposed = QPixmap::fromImage(*imageProcessedMask);
  int height = 0.5 * this->screen()->virtualSize().height();
  int width = 0.5 * this->screen()->virtualSize().width();
  QPixmap imageDisposed = imageUnDisposed.scaled(QSize(width, height), Qt::KeepAspectRatio, Qt::SmoothTransformation);
  ui->imageLabelDisposed->setPixmap(imageDisposed);
  height = imageProcessedMask->height();
  width = imageProcessedMask->width();
  ui->replaceInputButton->setText("Width: " + QString::number(width) + ", " + "Height: " + QString::number(height));
  //ui->centralwidget->layout()->setSizeConstraint(QLayout::SetFixedSize);
  this->centralWidget()->adjustSize();
  this->adjustSize();

  QImage openImage = *(this->imageToProcessMask);
  imageUnDisposed = QPixmap::fromImage(openImage);
  height = 0.5 * this->screen()->virtualSize().height();
  width = 0.5 * this->screen()->virtualSize().width();
  imageDisposed = imageUnDisposed.scaled(QSize(width, height), Qt::KeepAspectRatio, Qt::SmoothTransformation);
  height = openImage.height();
  width = openImage.width();
  ui->openImageButton->setText("Width: " + QString::number(width) + ", " + "Height: " + QString::number(height));
  ui->imageLabel->setPixmap(imageDisposed);
}

void MainWindow::loadScaledImage()
{
  auto images = getterImages();
  auto event = scaleWindow->handle(*images.second, *images.first);
  scaleWindow->exec();
  disconnect(event);
}

void MainWindow::loadRotatedImage()
{
  auto images = getterImages();
  auto event = rotateWindow->handle(*images.second, *images.first);
  rotateWindow->exec();
  disconnect(event);
}

void MainWindow::loadGrayTransImage()
{
  auto images = getterImages();
  auto event = grayTransWindow->handle(*images.second, *images.first);
   grayTransWindow->exec();
   disconnect(event);
}

void MainWindow::loadAugmentImage()
{
  auto images = getterImages();
  auto event = augmentWindow->handle(*images.second, *images.first);
   augmentWindow->exec();
   disconnect(event);
}

void MainWindow::loadUtilsImage()
{
  auto images = getterImages();
  auto event = utilsWindow->handle(*images.second, *images.first);
   utilsWindow->exec();
   disconnect(event);
}

void MainWindow::saveImage(QImage *target)
{
  QString filename = QFileDialog::getSaveFileName(this,
         tr("Save Image"),
         "",
         tr("*.bmp;;*.png;;*.jpg;;*.tif;;*.GIF"));
  if(filename.isEmpty())
  {
      QDateTime time = QDateTime::currentDateTime();
      QString current_date = time.toString("yyyy_MM_dd_hh_mm_ss_zzz");
      current_date = current_date + ".bmp";
      filename = current_date;
  }
  QImage *temp = new QImage(*target);
  if (target->format() == QImage::Format_Grayscale16) {
    this->utilsWindow->grayTransPublicGray16(temp, target);
  }

  if(!temp->save(filename) )
  {
        QMessageBox::information(this,
                tr("Failed to save the image"),
                tr("Failed to save the image!"));
        return;
  }
  delete temp;
}

void MainWindow::updateMainScreen()
{
  ui->functionality->setEnabled(this->imageProcessed);
  if (!isUndo) updateMask();
  QImage openImage = *(this->imageToProcessMask);
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
  // ui->centralwidget->layout()->setSizeConstraint(QLayout::SetFixedSize);
  // Note: I expect the mainWindow to adjust to fit the layout
  //       which is the visual part of the program
  //       however, the layout is binded to the centralWidget
  //       so both must adjust in the following sequence
  this->centralWidget()->adjustSize();
  this->adjustSize();
}

void MainWindow::updateMask()
{
  if (!imageProcessed) return;
  if (this->imageToProcessMask) {
      delete this->imageToProcessMask;
      this->imageToProcessMask = nullptr;
  }
  if (this->imageProcessedMask) {
      delete this->imageProcessedMask;
      this->imageProcessedMask = nullptr;
  }
//  if (this->imageToProcess->format() == QImage::Format_Indexed8) {
//      this->imageProcessedMask = this->imageProcessed;
//      this->imageToProcessMask = this->imageToProcess;
//  }
  if (this->imageProcessed->format() == QImage::Format_Grayscale16) {
      this->utilsWindow->grayTransPublicGray16(this->imageProcessedMask, this->imageProcessed);
      this->utilsWindow->grayTransPublicGray16(this->imageToProcessMask, this->imageToProcess);
  } else {
      this->utilsWindow->grayTransPublicGray8(this->imageProcessedMask, this->imageProcessed);
      this->utilsWindow->grayTransPublicGray8(this->imageToProcessMask, this->imageToProcess);

  }
}

void MainWindow::displayImage(QImage *target)
{
  Display* screen = new Display(this, target);
  screen->exec();
  delete screen;
}

void MainWindow::clearData()
{
  this->utilsWindow->clearData();
  QMessageBox::information(this, "Clear Done!", "Redo Buffer Cleared!");
}

