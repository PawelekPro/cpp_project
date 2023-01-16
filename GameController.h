<<<<<<< HEAD
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>
#include "MenagerAI.hpp"
#include "GameOptions.h"
#include "TTTGame.h"
#include "Board.h"
#include <vector>

/* GameController class controlls the game.
   Inputs: GameOptions
   Task: controll the view and board model, calling algorithm to play its turn. */

class GameController : public QObject
{
    Q_OBJECT
protected:
    /* view is an instance of TTTGame class. */
    TTTGame view;

    /* Board is an instance of Board class -> underlaying layer of the game. */
    Board board;

    /* options is the struct of values that controlls the game. */
    const Options& options;

    /* currentPlayer: instance of class boardMarks that is specifing the player to make move in current turn. */
    boardMarks currentPlayer;

    /* cells is the collection of cell buttons represented by 1D vector. */
    std::vector<Cell> cells;

    /* AIMenager is pointer to algorithm chosen to play against User. */
    std::unique_ptr<MenagerAI> AIMenager;

    /* updateGameState updates the view and the model and switches the players.
       @param cell represents the cell clicked by current player. */
    void updateGameState(Cell &cell);

   /* Method that calls AIMenager to play. */
    void AIMenagerPlay();

    /* Method that switches the current player mark. */
    void switchPlayer();

private:
    /* setConnections is a method to handle all events defined by slots in GUI. */
    void setConnections();

    /* resets all internal attributes, then the game is started by algorithm if <UI: Algorithm starts> is checked. */
    void reset();

public:
    /* GameController is a cosntructor of class.
       @param options: struct of values to controll the game
       @param parent is a QObject type parent that owns this instance of controller. */
    GameController(const Options &options, QObject *parent = nullptr);
    virtual void startGame();

signals:
    /* Signal emitted when User finished his turn. */
    void turnFinished();

public slots:
    /* updateGame sets the cell clicked in the UI. */
    virtual void updateGame(Cell &cell);

};


#endif // GAMECONTROLLER_H
=======
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
>>>>>>> fc9f2c7b6afbcdfc3183b30f95252a7aaa69cbaf
