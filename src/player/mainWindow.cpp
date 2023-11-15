#include "mainwindow.h"

void MainWindow::createMenus()
{
    // with menu bar, create menus
    QMenu *fileMenu = mainMenu->addMenu(tr("&File"));
    QMenu *viewMenu = mainMenu->addMenu(tr("&View"));
    QMenu *aboutMenu = mainMenu->addMenu(tr("&About"));

    QAction *openFile = new QAction(tr("&New"), this);
    fileMenu->addAction(openFile);
    //    connect(openFile, &QAction::triggered, this, )

    mainMenu->addSeparator();

    QAction *exitWindow = new QAction(tr("&Exit"), this);
    fileMenu->addAction(exitWindow);

    // first parameter is sender, second parameter is when exitWindow is triggered
    connect(exitWindow, &QAction::triggered, this, &MainWindow::quitApp);

    QAction *information = new QAction(tr("&Info"), this);
    aboutMenu->addAction(information);
    // connect About to show version + author
    connect(information, &QAction::triggered, this, &MainWindow::showAboutMsg);
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Media Player"));
    createMenus();
}

void MainWindow::quitApp()
{
    QCoreApplication::quit();
}

int MainWindow::showAboutMsg()
{
    QMessageBox msg;
    QString str = "Version: 0.0.1\nAuthor: Elliot Kim";

    msg.setText(str);
    return msg.exec();
}
