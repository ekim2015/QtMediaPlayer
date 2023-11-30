#include "mainwindow.h"

void MainWindow::createMenus()
{
    // with menu bar, create menus
    QMenu *fileMenu = mainMenu->addMenu(tr("&File"));
    QMenu *viewMenu = mainMenu->addMenu(tr("&View"));
    QMenu *aboutMenu = mainMenu->addMenu(tr("&About"));

    QAction *openFile = new QAction(tr("&Open"), this);
    fileMenu->addAction(openFile);
    connect(openFile, &QAction::triggered, this, &MainWindow::openFile);

    mainMenu->addSeparator();

    QAction *exitWindow = new QAction(tr("&Exit"), this);
    fileMenu->addAction(exitWindow);

    // first parameter is sender, second parameter is when exitWindow is triggered
    connect(exitWindow, &QAction::triggered, this, &MainWindow::quitApp);

    QAction *information = new QAction(tr("&Info"), this);
    aboutMenu->addAction(information);
    // connect About to show version + author
    connect(information, &QAction::triggered, this, &MainWindow::showAboutMsg);

    // set checkable parameters under view
    // view will specify grid or table view
    QAction *gridView = new QAction(tr("&Grid"), this);
    viewMenu->addAction(gridView);

    QAction *tableView = new QAction(tr("&Table"), this);
    viewMenu->addAction(tableView);
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), player(new Player)
{
    setWindowTitle(tr("Media Player"));
    setCentralWidget(player);
    createMenus();
}

void MainWindow::quitApp()
{
    QCoreApplication::quit();
}

void MainWindow::openFile()
{
    QFileDialog dialog(this);
    // singular file
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter("Audio files (*.wav *.mp3 *.aac *.flac");
    if (dialog.exec())
    {
        const QStringList pathList = dialog.selectedFiles();
        player->readFiles(pathList);
        //        table->insertFileData(pathList);
    }
}

int MainWindow::showAboutMsg()
{
    QMessageBox msg;
    QString str = "Version: 0.0.1\nAuthor: Elliot Kim";

    msg.setText(str);
    return msg.exec();
}
