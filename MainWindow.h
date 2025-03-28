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

private:
    /**
     * @brief initialize
     */
    void initialize();

    /**
     * @brief manageAction
     */
    void manageAction();

    /**
     * @brief manageMenu
     */
    void manageMenu();

    /**
     * @brief manageLayout
     */
    void manageLayout();

    /**
     * @brief manageConnect
     */
    void manageConnect();

private slots:
    void onNewAction_triggered();
    void onOpenAction_triggered();

private:
    QMdiArea        *_centralArea = nullptr;
    QMdiSubWindow   *_passList = nullptr;
    QMenu           *_fileMenu = nullptr;
    QAction         *_newAction = nullptr;
    QAction         *_openAction = nullptr;
    QAction         *_exitAction = nullptr;
    QWidget         *_entries = nullptr;
};
