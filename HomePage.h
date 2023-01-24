#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "GameOptions.h"
#include "ui_HomePage.h"
using namespace std;

class HomePage final: public QMainWindow
{
    Q_OBJECT
public:
    /*HomePage constructs the view of the title screen
      Parent is a QWidget type parent that owns this instance of the controller.*/
    explicit HomePage(QWidget *parent = nullptr);

private:
    /* ui is a reference to the ui object of the game*/
    unique_ptr<Ui::HomePage> ui;

    void setConnections();

    /* Options are the values and flags that control the game
       Source: GameOptions.h */
    Options options;

    void closeEvent(QCloseEvent *event) override;

public slots:
    void singlePlayer(bool checked);

    void isAIstartingGame(bool checked);

    void updateAlgDepth(int depth);

    void startGame();

signals:
    /* exited is emitted to manually handle the close functionality. */
    void exited();
};

#endif 
