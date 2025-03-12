#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initialize();
    manageAction();
    manageMenu();
    manageLayout();
    manageConnect();
}

MainWindow::~MainWindow()
{}

void MainWindow::initialize()
{
    setWindowTitle(tr("Password manager"));
    setWindowIcon(QIcon(":/img/icon/logo.png"));
    _widget1 = new QWidget(this);
}

void MainWindow::manageAction()
{
    _newAction = new QAction(tr("&New"), this);
        _newAction->setShortcut(QKeySequence("Ctrl+N"));
    _openAction = new QAction(tr("&Open"), this);
        _openAction->setShortcut(QKeySequence("Ctrl+O"));
    _quitAction = new QAction(tr("&Quit"), this);
        _quitAction->setShortcut(QKeySequence("Ctrl+Q"));
}

void MainWindow::manageMenu()
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_newAction);
    _fileMenu->addAction(_openAction);
    _fileMenu->addAction(_quitAction);
}


void MainWindow::manageLayout()
{
    _centralArea = new QMdiArea;
    _sub1 = _centralArea->addSubWindow(_widget1);

    setCentralWidget(_centralArea);
}

void MainWindow::manageConnect()
{
    connect(_newAction, SIGNAL(triggered(bool)), this, SLOT(onNewAction_triggered()));
    connect(_openAction, SIGNAL(triggered(bool)), this, SLOT(onOpenAction_triggered()));
    connect(_quitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

void MainWindow::onNewAction_triggered()
{
    qDebug("New action");
}

void MainWindow::onOpenAction_triggered()
{
    qDebug("Open");
}

