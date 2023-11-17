#ifndef PLAYER_H
#define PLAYER_H

#include "qtDependencies.h"

// serves as the central widget
class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    void readFiles(const QStringList &files);

private slots:

private:
    // to-do: create instance of QMediaPlayer
};

#endif // PLAYER_H
