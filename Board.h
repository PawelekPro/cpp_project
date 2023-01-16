<<<<<<< HEAD
#ifndef BOARD_H
#define BOARD_H

#include "GameOptions.h"
#include <QtGlobal>
#include <vector>

/* The Borad class represents the underlaying layer of the game.
   It's a 2D matrix representation of the GUI. */

class Board
{
protected:
    /* board is 2D vector that represents GUI. */
    std::vector<std::vector<boardMarks>> board;

    /* size of board -> size 3 means 3x3 (default dimension) */
    size_t boardSize;
public:
    /* Constructor */
    Board(size_t size);

    /* Copy constructor */
    Board(Board& b);

    /* Move contructor */
    Board(Board&& b);

    /* Assignment operator */
    Board& operator=(Board b);

    /* Destructor */
    virtual ~Board();

    /* evaluates the state of the current board.
       The method can evaluate to X wins or O wins or a Tie. */
    virtual boardState evaluateBoardState() const;

    /* Getter function that returns a cell given a row and column. */
    virtual boardMarks at(size_t row, size_t col) const;

    /* Setting the board with the mark given by the current player in specific location. */
    virtual bool setPlayerInput(size_t row, size_t col, boardMarks currentPlayer);

    /* Resetting cell to empty type. */
    virtual void resetCell(size_t row, size_t col);

    /* Getter function of the board size. */
    size_t getSize() const;

    /* Making all cells as an empty type. */
    virtual void reset();

};

#endif // BOARD_H
=======
#ifndef BOARD_H
#define BOARD_H

#include "GameOptions.h"
#include <QtGlobal>
#include <vector>

class Board
{
protected:
    std::vector<std::vector<boardMarks>> board;
    size_t boardSize;
public:
    Board(size_t size);
    Board(Board& b);
    Board(Board&& b);
    Board& operator=(Board b);
    virtual ~Board();


    virtual boardState evaluateBoardState() const;
    virtual boardMarks at(size_t row, size_t col) const;
    virtual bool setPlayerInput(size_t row, size_t col, boardMarks currentPlayer);
    virtual void resetCell(size_t row, size_t col);
    size_t getSize() const;
    virtual void reset();

#ifdef QT_DEBUG
    virtual void printBoard() const;
#endif
};

#endif // BOARD_H
>>>>>>> fc9f2c7b6afbcdfc3183b30f95252a7aaa69cbaf
