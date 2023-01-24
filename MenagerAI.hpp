#ifndef MENAGERAI_H
#define MENAGERAI_H

/* The MenagerAI interface describes the behaviour of implemented menagers. */

class Board;
class MenagerAI
{
public:
    MenagerAI() {}
    virtual ~MenagerAI() {}

    /* Starts the algorithm to choose cell to play on a given board.
     board is a reference to the board model.
     return 1D index of the chosen cell (obtained by static_cast) */

    virtual int play(Board &board) = 0;

    /* Reset function that is responsible for resetting the state of algorithm. */
    virtual void reset() {};
};

#endif // MENAGERAI_H
