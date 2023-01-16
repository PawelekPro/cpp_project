#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>
#include "MenagerAI.hpp"
#include "GameOptions.h"
#include "TTTGame.h"
#include "Board.h"
#include <vector>

class GameController : public QObject
{
    Q_OBJECT
protected:
    TTTGame view;
    Board board;
    const Options& options;
    boardMarks currentPlayer;
    std::vector<Cell> cells;
    std::unique_ptr<MenagerAI> AIMenager;

private:
    void setConnections();
    void reset();

protected:
    virtual void updateGameState(Cell &cell);
    virtual void AIMenagerPlay();
    virtual void switchPlayer();

public:
    explicit GameController(const Options &options, QObject *parent = nullptr);
    virtual void startGame();

signals:
    void turnFinished();

public slots:
    virtual void updateGame(Cell &cell);

};


#endif // GAMECONTROLLER_H
