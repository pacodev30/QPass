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
    setWindowTitle(tr("-- QPass -- Password manager"));
    setWindowIcon(QIcon(":/img/icon/logo.png"));
    _filepath = "data.json";

    _entries = new QWidget(this);
    _entries->setFixedSize(QSize(400, 300));
        _entries->setWindowTitle(tr("Group list"));
}

void MainWindow::manageAction()
{
    _newEntryAction = new QAction(tr("&New entry"), this);
        _newEntryAction->setShortcut(QKeySequence("Ctrl+N"));
    _openAction = new QAction(tr("&Open"), this);
        _openAction->setShortcut(QKeySequence("Ctrl+O"));
    _removeAction = new QAction(tr("&Remove"), this);
        _removeAction->setShortcut(QKeySequence("Ctrl+D"));
    _exitAction = new QAction(tr("&Quit"), this);
        _exitAction->setShortcut(QKeySequence("Ctrl+Q"));
}

void MainWindow::manageMenu()
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_newEntryAction);
    _fileMenu->addAction(_openAction);
    _fileMenu->addAction(_removeAction);
    _fileMenu->addAction(_exitAction);
}

void MainWindow::manageLayout()
{
    _centralArea = new QMdiArea;
        _passList = _centralArea->addSubWindow(_entries);


    setCentralWidget(_centralArea);
}

void MainWindow::manageConnect()
{
    connect(_newEntryAction, SIGNAL(triggered(bool)), this, SLOT(onNewEntryAction_triggered()));
    connect(_openAction, SIGNAL(triggered(bool)), this, SLOT(onOpenAction_triggered()));
    connect(_removeAction, SIGNAL(triggered(bool)), this, SLOT(onRemoveAction_triggered()));
    connect(_exitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

void MainWindow::onNewEntryAction_triggered()
{
    Account google = { "Gmail", "monemail@gmail.com", "motdepasse123" };
    if(PasswordManager::addAccount(_filepath, google))
        qDebug() << google._service << " added succesfully";
}

void MainWindow::onRemoveAction_triggered()
{
    if(PasswordManager::removeAccount(_filepath, "Gmail"))
        qDebug("Account deleted succesfully");

}

void MainWindow::onOpenAction_triggered()
{
    qDebug("Open");
}

