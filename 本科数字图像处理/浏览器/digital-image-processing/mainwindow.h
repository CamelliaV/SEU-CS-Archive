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
#include "augment.h"
#include "utils.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage *imageToProcess = nullptr;
    QImage *imageProcessed = nullptr;
    QImage *imageToProcessMask = nullptr;
    QImage *imageProcessedMask = nullptr;
private:
    std::pair<QImage**, QImage**> getterImages();
    Ui::MainWindow *ui;
    Scale *scaleWindow = new Scale(this);
    Rotate *rotateWindow = new Rotate(this);
    GrayTrans *grayTransWindow = new GrayTrans(this);
    Augment *augmentWindow = new Augment(this);
    Utils *utilsWindow = Utils::getInstance();
    bool isAutoSave = true;
    bool isUndo = false;
    void openRaw(const QString&);

    // for .raw file (intermediate)
    QVector<unsigned short> vec;
    void updateMainScreen();
    void updateMask();
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
    void loadGrayTransImage();
    void loadAugmentImage();
    void loadUtilsImage();
    void saveImage(QImage *target);
    void displayImage(QImage *target);
    void clearData();
};
#endif // MAINWINDOW_H
