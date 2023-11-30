#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    // create layout for files
    auto layout = new QVBoxLayout;
    auto table = new DataModel;
    // create table view
    this->setLayout(layout);

    //    layout->addWidget();
}

// function to read files from absolute path
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
