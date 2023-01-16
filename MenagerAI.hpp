<<<<<<< HEAD
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
=======
#ifndef MENAGERAI_H
#define MENAGERAI_H

/* MenagerAI is interface for describing the behaviour of any implemented AI */

class Board;
class MenagerAI
{
public:
    MenagerAI() {}
    virtual ~MenagerAI() {}

    virtual int play(Board &board) = 0;
    virtual void reset() {};
};

#endif // MENAGERAI_H
>>>>>>> fc9f2c7b6afbcdfc3183b30f95252a7aaa69cbaf
