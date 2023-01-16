#include "HomePage.h"
#include "GameController.h"

HomePage::HomePage(QWidget *parent): QMainWindow(parent), ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setConnections();
}


void HomePage::setConnections()
{
    connect(ui->onePlayer, SIGNAL(toggled(bool)), SLOT(singlePlayer(bool)));
    connect(ui->AIstarts, SIGNAL(toggled(bool)), SLOT(isAIstartingGame(bool)));
    connect(ui->AlgDepth, SIGNAL(valueChanged(int)), SLOT(updateAlgDepth(int)));
    connect(ui->startGame, SIGNAL(clicked()), SLOT(startGame()));
}


void HomePage::isAIstartingGame(bool checked)
{
    if (checked)
        options.AIstarts = true;
    else
        options.AIstarts = false;
}


void HomePage::singlePlayer(bool checked)
{
    if (checked) {
        ui->AIstarts->setEnabled(true);
        ui->AlgDepth->setEnabled(true);
        options.AIopponent = true;
    }
}

void HomePage::updateAlgDepth(int depth)
{
    ui->AlgDepthValue->setText(QString::number(depth));
    options.AlgDepth = static_cast<unsigned short>(depth);
}

void HomePage::startGame()
{
    this->hide();
    GameController GameInstance(options);
    GameInstance.startGame();
    this->show();

}
