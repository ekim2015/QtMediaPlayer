#include "player.h"

// constructor
MediaPlayer::MediaPlayer()
{
}

// protected destructor
MediaPlayer::~MediaPlayer()
{
}

// must factor in arguments
int MediaPlayer::main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // no parent widget necessary (this is top-level window)
    QWidget window;
    window.show();

    return app.exec()
}