#include "AlgorithmAI.h"
#include "Board.h"
#include <QPair>
#include <limits.h>

AlgorithmAI::AlgorithmAI(unsigned short depth, boardMarks AImark, boardMarks playerMark)
    : depth(depth),
      AImark(AImark),
      playerMark(playerMark) {}

short AlgorithmAI::maxMove(Board &board, unsigned short depth, short alpha, short beta) const
{
    boardState state = board.evaluateBoardState();
    if ( (depth == 0) || (state != boardState::noWinner))
            return score(state);
    short bestScore = SHRT_MIN;
    for (size_t row = 0; row < board.getSize(); ++row) {
        for (size_t col = 0; col < board.getSize(); ++col) {
            if (boardMarks::Empty == board.at(row, col)) {
                /* Try the move */
                board.setPlayerInput(row, col, AImark);

                /* Compare result of this move with respect to AI */
                short score = minMove(board, depth - 1, alpha, beta);

                /* Reset the move */
                board.resetCell(row, col);

                /* Update the best score */
                bestScore = std::max(bestScore, score);

                /* Update alpha */
                alpha = std::max(alpha, score);

                /* Cut the rest of cells after this one */
                if (beta <= alpha)
                    break;
            }
        }
    }
    return bestScore;
}


short AlgorithmAI::minMove(Board &board, unsigned short depth, short alpha, short beta) const
{
    boardState state = board.evaluateBoardState();
    if ( (depth == 0) || (state != boardState::noWinner))
            return score(state);

    short bestScore = SHRT_MAX;
    for (size_t row = 0; row < board.getSize(); ++row) {
        for (size_t col = 0; col < board.getSize(); ++col) {
            if (boardMarks::Empty == board.at(row, col)) {
                /* Try the move */
                board.setPlayerInput(row, col, playerMark);

                /* Compare result of this move with respect to player */
                short score = maxMove(board, depth - 1, alpha, beta);

                /* Reset the move */
                board.resetCell(row, col);

                /* Update the best score */
                bestScore = std::min(bestScore, score);

                /* Update beta */
                beta = std::min(beta, score);

                /* Cut the rest of cells after this one */
                if (beta <= alpha)
                    break;
            }
        }
    }
    return bestScore;
}


short AlgorithmAI::score(const boardState state) const
{
    /* AI win score */
    if ( (boardMarks::O == AImark) && (boardState::OWins == state) )
        return AI_WIN_SCORE;
    if ( (boardMarks::X == AImark) && (boardState::XWins == state) )
        return AI_WIN_SCORE;
    /* Player win score */
    if ( (boardMarks::O == AImark) && (boardState::XWins == state) )
        return PLAYER_WIN_SCORE;
    if ( (boardMarks::X == AImark) && (boardState::OWins == state) )
        return PLAYER_WIN_SCORE;

    /* Tie or non final state score */
    return TIE_SCORE;
}


int AlgorithmAI::play(Board &board)
{
    /* Chech if the board is not at a final state */
    if (boardState::noWinner != board.evaluateBoardState())
        return defaultOptions::INVALID_CELL;

    /* Start the algorithm and choose the best score of all available cells */
    int bestScore = INT_MIN;
    QPair<size_t, size_t> bestEntry;
    for (size_t row = 0; row < board.getSize(); ++row) {
        for (size_t col = 0; col < board.getSize(); ++col) {
            if (boardMarks::Empty == board.at(row, col)) {
                /* Try the move */
                board.setPlayerInput(row, col, AImark);

                /* Update the best score and the best cell location */
                int moveScore = minMove(board, depth - 1, SHRT_MIN, SHRT_MAX);
                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestEntry.first = row;
                    bestEntry.second = col;
                }
                board.resetCell(row, col);
            }
        }
    }
    /* Set the AI choice on the board */
    board.setPlayerInput(bestEntry.first, bestEntry.second, AImark);

    /* return the 1D index to the cell */
    return static_cast<int>(bestEntry.first * board.getSize() + bestEntry.second);
}













