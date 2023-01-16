#ifndef ALGORITHMAI_H
#define ALGORITHMAI_H

#include "GameOptions.h"
#include "MenagerAI.hpp"


/* The AlogithmAI class is handling ale the logic of picking a cell based on the MiniMax algorithm.
   Check README.md for more infromation about the algorithm. */

class AlgorithmAI : public MenagerAI
{
public:
    /* AgorithmAI is a constructor the creates the MiniMax algorithm menager.
       depth is a parameter that defines the cutoff of the algorithm (see README.md for more info).
       AImark defines te mark (X or O) which algorithm is using.
       playerMark defines the user's mark (X or O). */
    AlgorithmAI(unsigned short depth, boardMarks AImark, boardMarks playerMark);

    /* Method that override play method from parent class (MenagerAI.hpp)
       parameter board is a reference to the model board.
       returns 1D index of the chosen cell. */
    int play(Board &board) override;

private:
    /* @param depth is a parameter that defines the cutoff of the algorithm (see README.md for more info). */
    const unsigned short depth;

    /* @param AImark defines te mark (X or O) which algorithm is using. */
    const boardMarks AImark;

    /* @param playerMark defines the user's mark (X or O). */
    const boardMarks playerMark;

    /* AI_WIN_SCORE defines the score when computer wins. */
    static constexpr short AI_WIN_SCORE = 1;

    /* PLAYER_WIN_SCORE defines the score when user wins. */
    static constexpr short PLAYER_WIN_SCORE = -1;

    /* TIE_SCORE defines the score when there is a tie. */
    static constexpr short TIE_SCORE = 0;

    /* maxMove simulates the algorithm choice based on the final game state -> choosing the maximum score of each (simulated) move.
       @param board, @param depth <as earlier explained>
       @param alpha: the minimum score
       @param beta: the maximum score */
    short maxMove(Board &board, unsigned short depth, short alpha, short beta) const;

    /* minMove simulates the player choice based on the final game state -> choosing the minimum score of each (simulated) move.
       @param board, @param depth <as earlier explained>
       @param alpha: the minimum score
       @param beta: the maximum score */
    short minMove(Board &board, unsigned short depth, short alpha, short beta) const;

    /* Method which is making input parameter [state] associative with the state of game. */
    short score(const boardState state) const;
};

#endif // ALGORITHMAI_H
