#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtDependencies.h"

// inheritence
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QMenuBar *mainMenu = menuBar();
    QAction *openAbout;
    // for menus: file, view menus
    void createMenus();
    void quitApp();
    int showAboutMsg();
};
#endif // MAINWINDOW_H
