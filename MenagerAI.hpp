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
