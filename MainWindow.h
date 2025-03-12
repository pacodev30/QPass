#pragma once

#include <QtWidgets/QMainWindow>
#include <QMdiArea>
#include <qapplication.h>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initialize();
    void manageAction();
    void manageMenu();
    void manageLayout();
    void manageConnect();

private slots:
    void onNewAction_triggered();
    void onOpenAction_triggered();

private:
    QMdiArea        *_centralArea = nullptr;
    QMdiSubWindow   *_sub1 = nullptr;
    QMenu           *_fileMenu = nullptr;
    QAction         *_newAction = nullptr;
    QAction         *_openAction = nullptr;
    QAction         *_quitAction = nullptr;
    QWidget         *_widget1 = nullptr;
};
