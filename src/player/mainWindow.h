#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtDependencies.h"
#include "player.h"

// inheritence
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // main widget

private:
    Player *player;
    QMenuBar *mainMenu = menuBar();
    QAction *openAbout;
    // for menus: file, view menus
    void createMenus();
    void quitApp();
    void openFile();
    int showAboutMsg();
};
#endif // MAINWINDOW_H
