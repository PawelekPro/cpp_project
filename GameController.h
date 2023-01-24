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
//    void updateGameState(Cell &cell);
    template <typename T>
    void updateGameState(T &cell)
    {
        /* GUI: updates the cell's view. */
        this->view.updateCell(cell, currentPlayer);

        /* Updating board state. */
        boardState currentState = board.evaluateBoardState();
        if (boardState::noWinner != currentState)
            view.declareGameState(currentState);

        switchPlayer();
    }

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
