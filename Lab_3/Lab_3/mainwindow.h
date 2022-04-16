#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "opencv2/opencv.hpp"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMessageBox>
#include <QCheckBox>
#include <QListView>
#include <QGridLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QStatusBar>
#include <QApplication>
#include <QShortcut>
#include <QVideoWidget>
#include <QMediaCaptureSession>
#include <QStandardItemModel>
#include <QCameraDevice>
#include <QCamera>
#include <QMediaDevices>


#include "capturethread.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    void initUI();

    void createActions();

private slots:
    void showCameraInfo();

    void openCamera();

    void updateFrame(cv::Mat* mat);

    void calculateFPS();

    void updateFPS(float fps);

    void recordingStartStop();

    void appendSavedVideo(QString name);

    void populateSavedList();

    void updateMonitorStatus(int status);

    void changeStatus(int fps, cv::Scalar mean,cv::Scalar dev);
private:
    QAction *cameraInfoAction;
    QAction *openCameraAction;
    QAction *calcFPSAction;
    QMenu *fileMenu;

    QStandardItemModel *list_model;
    QGridLayout *main_layout;
    QGraphicsScene *imageScene;
    QGraphicsView *imageView;
    QCheckBox *monitorCheckBox;
    QPushButton *recordButton;
    QListView *saved_list;
    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;
    cv::Mat currentFrame;
    QMutex *data_lock;
    CaptureThread *capturer = nullptr;

#ifdef GAZER_USE_QT_CAMERA
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QVideoWidget *preview;
#endif
};
#endif // MAINWINDOW_H
