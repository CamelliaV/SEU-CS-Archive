#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QScreen>
#include <QThread>
#include "scale.h"
#include "display.h"
#include "rotate.h"
#include "graytrans.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage* imageToProcess = nullptr;
    QImage* imageProcessed = nullptr;
private:
    Ui::MainWindow *ui;
    Scale *scaleWindow = new Scale(this);
    Rotate *rotateWindow = new Rotate(this);
    GrayTrans *grayTransWindow = new GrayTrans(this);
    void openRaw(const QString&);

    // for .raw file (intermediate)
    unsigned long width;
    unsigned long height;
    QVector<unsigned short> vec;
    void loadGrayTransImage();
    void updateMainScreen();
private slots:
    /**
      * @brief Open image from resource manager
      *   and display in the MainWindow
      * @date Sept.20 2022
      * @param imageToProcess(modified)
      */
    void openImage();
    void updateImage();
    void loadScaledImage();
    void loadRotatedImage();
    void displayImage(QImage *target);
};
#endif // MAINWINDOW_H
