#ifndef ALGORITHMAI_H
#define ALGORITHMAI_H

#include "GameOptions.h"
#include "MenagerAI.hpp"

class AlgorithmAI : public MenagerAI
{
public:
    AlgorithmAI(unsigned short depth, boardMarks AImark, boardMarks playerMark);
    int play(Board &board) override;

private:
    const unsigned short depth;
    const boardMarks AImark;
    const boardMarks playerMark;

    static constexpr short AI_WIN_SCORE = 1;
    static constexpr short PLAYER_WIN_SCORE = -1;
    static constexpr short TIE_SCORE = 0;

    short maxMove(Board &board, unsigned short depth, short alpha, short beta) const;

    short minMove(Board &board, unsigned short depth, short alpha, short beta) const;

    short score(const boardState state) const;
};

#endif // ALGORITHMAI_H
