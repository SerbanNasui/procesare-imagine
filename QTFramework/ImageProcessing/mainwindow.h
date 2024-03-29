#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "plotter.h"
#include "magnifier.h"
#include "smartdialog.h"

#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QMainWindow>
#include <qpixmap.h>
#include <qfiledialog.h>
#include <qinputdialog.h>
#include <qmap.h>
#include<QMouseEvent>
#include<QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionGreyscale_triggered();
    void on_actionSave_as_triggered();
    void on_actionColor_triggered();
    void on_btnSaveAsInitialImage_clicked();
    void on_actionLamba_triggered();
    void on_actionRevert_colors_triggered();
    void on_actionPlot_grey_level_triggered();
    void on_actionLaunch_magnifier_triggered();
    void on_actionGama_triggered();

    void on_actionMirroring_triggered();//1
    void on_actionThresholding_triggered();//1
    void on_actionHistogram_triggered();//1
    void on_actionBrightnessIncreasing_triggered();//2
    void on_actionBrightnessDiminishing_triggered();//2
    void on_actionColorBinarization_triggered();//3
    void on_actionMeanFilter_triggered();//4
    void on_actionPrewitt_triggered(); //5
    void on_actionClosing_triggered();//6
    void on_actionRotatiaCuInterpolare_triggered();//7






private:
    void toGreyScale(QImage* image);
    void updateImages(bool isOpen);
    void loadImages();
    bool eventFilter(QObject *obj, QEvent *event) override;
    void launchMagnifierDialog(int x, int y, QImage* image);
    bool isMousedPressedOnInitialImage(QObject *obj, QEvent *event);
    bool isMousedPressedOnModifiedImage(QObject *obj, QEvent *event);
    void plotGreyPixels(int y, QImage* image) const;
    int* histogram();


private:
    int x;
    int y;
    bool param;
    QMap<QString,double>* transientData;
    QImage* initialImage;
    QString initialImagePath;
    QImage* modifiedImage;
    Magnifier* magnifierDialog;
    Plotter* greyPlotterDialog;
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
