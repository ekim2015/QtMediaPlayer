#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
}

// function to read file from absolute path
void Player::readFiles(const QStringList &files)
{
    if (!files.isEmpty())
    {
        for (const auto &f : files)
        {
            // instantiate QFile
            QFile currFile(f);

            if (!currFile.open(QIODevice::ReadOnly))
            {
                continue;
            }

            // otherwise, call function
        }
    }

    // for each absolute path in list
}
