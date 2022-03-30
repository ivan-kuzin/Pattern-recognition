#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QGraphicsView>
#include <QRegularExpression>
#include <QApplication>
#include <QFileDialog>
#include <QStatusBar>
#include <QLabel>
#include <QGraphicsPixmapItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUI();
    void setupShortcuts();
    void showImage(QString path);
    bool isLastImgInPath();
    bool isFirstImgInPath();

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void saveAs();
    void previousImg();
    void nextImg();
    void rotateImg();

private:
    QMenu *fileMenu;
    QMenu *viewMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;

    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

    QAction *openAction;
    QAction *SaveAsAction;
    QAction *exitAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *previousImgAction;
    QAction *nextImgAction;
    QAction *rotateAction;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;
    QGraphicsPixmapItem *currentImage;

    QString currentImagePath;

};
#endif // MAINWINDOW_H
