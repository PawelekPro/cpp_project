<<<<<<< HEAD
#include "Board.h"
#include <QString>
#ifdef QT_DEBUG
#include <QDebug>
#endif
#include <stdexcept>

Board::Board(size_t size)
    : board(size, std::vector<boardMarks>(size, boardMarks::Empty)),
      boardSize(size) {}

Board::Board(Board &b)
    : board(b.board), boardSize(b.boardSize)
{}

Board::Board(Board &&b)
    : board(std::move(b.board)),
      boardSize(std::move(b.boardSize))
{}

Board &Board::operator=(Board b)
{
    std::swap(board, b.board);
    std::swap(boardSize, b.boardSize);
    return *this;
}

Board::~Board()
{}

size_t Board::getSize() const { return boardSize; }

boardMarks Board::at(size_t row, size_t col) const { return board.at(row).at(col); }

boardState Board::evaluateBoardState() const
{
    /* Check the rows for a win for current player */
    bool equalRow = true;
    for (size_t row = 0 ; row < boardSize; ++row)
    {
        equalRow = true;
        boardMarks ref = board[row][0];
        for (size_t col = 1; col < boardSize; ++col)
        {
            if(board[row][col] != ref)
                equalRow = false;
        }
        if(equalRow)
        {
            if (boardMarks::X == ref)
                return boardState::XWins;
            if (boardMarks::O == ref)
                return boardState::OWins;
        }
    }

    /* Check the columns for a win for current player */
    bool equalCol = true;
    for(size_t col = 0; col < boardSize; ++col)
    {
        equalCol = true;
        boardMarks ref = board[0][col];
        for (size_t row = 0; row < boardSize; ++row)
        {
            if(board[row][col] != ref)
                equalCol = false;
        }
        if(equalCol)
        {
            if(boardMarks::X == ref)
                return boardState::XWins;
            if(boardMarks::O == ref)
                return boardState::OWins;
        }
    }

    /* Check diagonal (\) for a win for current player */
    bool equalDiag = true;
    boardMarks ref = board[0][0];
    for (size_t idx = 1; idx < boardSize; ++idx) {
        if(board[idx][idx] != ref)
            equalDiag = false;
    }
    if (equalDiag) {
        if (boardMarks::X == ref)
            return boardState::XWins;
        if (boardMarks::O == ref)
            return boardState::OWins;
    }

    /* Check diagonal (/) for a win for current player */
    equalDiag = true;
    ref = board[0][boardSize - 1];
    for (size_t idx = 1; idx < boardSize; ++ idx)
    {
        size_t row = idx;
        size_t col = boardSize - idx - 1;
        if(board[row][col] != ref)
            equalDiag = false;
    }
    if(equalDiag) {
        if(boardMarks::X == ref)
            return boardState::XWins;
        if(boardMarks::O == ref)
            return boardState::OWins;
    }

    /* If there is an empty cell and no winner is determined, the the game is still ongoing */
    for (size_t row = 0; row < boardSize ; ++row)
        for (size_t col = 0; col < boardSize; ++col)
            if (boardMarks::Empty == board[row][col])
                return boardState::noWinner;

    /* No winner and there are no empty cells, than the game is a tie */
    return boardState::Tie;
}

bool Board::setPlayerInput(size_t row, size_t col, boardMarks currentPlayer)
{
    /* The game is over - any input isn't allowed until state reset */
    if(boardState::noWinner != evaluateBoardState())
        return false;

    if (row >= boardSize)
        throw std::out_of_range("Row index is out of range!");
    if (col >= boardSize)
        throw std::out_of_range("Column index is out of range!");

    /* Cell is not empty */
    if (boardMarks::Empty != board[row][col])
        return false;

    board[row][col] = currentPlayer;
    return true;
}


void Board::resetCell(size_t row, size_t col)
{
    /* Row input is not valid */
    if (row >= boardSize)
        throw std::out_of_range("Row index is out of range.");

    /* Column input is not valid */
    if (col >= boardSize)
        throw std::out_of_range("Column index is out of range.");

    // Reset Cell
    board[row][col] = boardMarks::Empty;
}

void Board::reset()
{
    /* Sets all cells to empty */
    for (size_t row = 0; row < boardSize; ++row) {
        for (size_t col = 0; col < boardSize; ++col) {
            board[row][col] = boardMarks::Empty;
        }
    }
}







=======
#include "Board.h"
#include <QString>
#ifdef QT_DEBUG
#include <QDebug>
#endif
#include <stdexcept>

Board::Board(size_t size)
    : board(size, std::vector<boardMarks>(size, boardMarks::Empty)),
      boardSize(size) {}

Board::Board(Board &b)
    : board(b.board), boardSize(b.boardSize)
{

}

Board::Board(Board &&b)
    : board(std::move(b.board)),
      boardSize(std::move(b.boardSize))
{

}

Board &Board::operator=(Board b)
{
    std::swap(board, b.board);
    std::swap(boardSize, b.boardSize);
    return *this;
}

Board::~Board()
{

}

size_t Board::getSize() const
{
    return boardSize;
}

boardMarks Board::at(size_t row, size_t col) const
{
    return board.at(row).at(col);
}

boardState Board::evaluateBoardState() const
{
    /* Check the rows for a win for current player */
    bool equalRow = true;
    for (size_t row = 0 ; row < boardSize; ++row)
    {
        equalRow = true;
        boardMarks ref = board[row][0];
        for (size_t col = 1; col < boardSize; ++col)
        {
            if(board[row][col] != ref)
                equalRow = false;
        }
        if(equalRow)
        {
            if (boardMarks::X == ref)
                return boardState::XWins;
            if (boardMarks::O == ref)
                return boardState::OWins;
        }
    }

    /* Check the columns for a win for current player */
    bool equalCol = true;
    for(size_t col = 0; col < boardSize; ++col)
    {
        equalCol = true;
        boardMarks ref = board[0][col];
        for (size_t row = 0; row < boardSize; ++row)
        {
            if(board[row][col] != ref)
                equalCol = false;
        }
        if(equalCol)
        {
            if(boardMarks::X == ref)
                return boardState::XWins;
            if(boardMarks::O == ref)
                return boardState::OWins;
        }
    }

    /* Check diagonal (\) for a win for current player */
    bool equalDiag = true;
    boardMarks ref = board[0][0];
    for (size_t idx = 1; idx < boardSize; ++idx) {
        if(board[idx][idx] != ref)
            equalDiag = false;
    }
    if (equalDiag) {
        if (boardMarks::X == ref)
            return boardState::XWins;
        if (boardMarks::O == ref)
            return boardState::OWins;
    }

    /* Check diagonal (/) for a win for current player */
    equalDiag = true;
    ref = board[0][boardSize - 1];
    for (size_t idx = 1; idx < boardSize; ++ idx)
    {
        size_t row = idx;
        size_t col = boardSize - idx - 1;
        if(board[row][col] != ref)
            equalDiag = false;
    }
    if(equalDiag) {
        if(boardMarks::X == ref)
            return boardState::XWins;
        if(boardMarks::O == ref)
            return boardState::OWins;
    }

    /* If there is an empty cell and no winner is determined, the the game is still ongoing */
    for (size_t row = 0; row < boardSize ; ++row)
        for (size_t col = 0; col < boardSize; ++col)
            if (boardMarks::Empty == board[row][col])
                return boardState::noWinner;

    /* No winner and there are no empty cells, than the game is a tie */
    return boardState::Tie;
}

bool Board::setPlayerInput(size_t row, size_t col, boardMarks currentPlayer)
{
    /* The game is over - any input isn't allowed until state reset */
    if(boardState::noWinner != evaluateBoardState())
        return false;

    if (row >= boardSize)
        throw std::out_of_range("Row index is out of range!");
    if (col >= boardSize)
        throw std::out_of_range("Column index is out of range!");

    /* Cell is not empty */
    if (boardMarks::Empty != board[row][col])
        return false;

    board[row][col] = currentPlayer;
    return true;
}


void Board::resetCell(size_t row, size_t col)
{
    /* Row input is not valid */
    if (row >= boardSize)
        throw std::out_of_range("Row index is out of range.");

    /* Column input is not valid */
    if (col >= boardSize)
        throw std::out_of_range("Column index is out of range.");

    // Reset Cell
    board[row][col] = boardMarks::Empty;
}

void Board::reset()
{
    /* Sets all cells to empty */
    for (size_t row = 0; row < boardSize; ++row) {
        for (size_t col = 0; col < boardSize; ++col) {
            board[row][col] = boardMarks::Empty;
        }
    }
}

#ifdef QT_DEBUG
void Board::printBoard() const
{
    QString board_;
    for (size_t row = 0; row < boardSize; ++row) {
        for (size_t col = 0; col < boardSize; ++col) {
            board_ += QString::number(static_cast<int>(board[row][col]));
        }
        board_ += '\n';
    }
    qDebug().noquote() << board_;
}
#endif





>>>>>>> fc9f2c7b6afbcdfc3183b30f95252a7aaa69cbaf
