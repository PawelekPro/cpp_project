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
