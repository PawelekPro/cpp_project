#include "GameController.h"
#include <QPushButton>
#include "AlgorithmAI.h"
#include "TTTGame.h"

GameController::GameController(const Options &options, QObject *parent)
    : QObject(parent),
      view(),
      board(options.boardSize),
      options(options),
      currentPlayer(boardMarks::X)
{
    /* Build GUI */
    cells = view.buildCellButtons(options.boardSize);

    setConnections();
    if (options.AIstarts && options.AIopponent)
        AIMenager = std::make_unique<AlgorithmAI>(options.AlgDepth, boardMarks::X, boardMarks::O);
    else if (options.AIopponent)
        AIMenager = std::make_unique<AlgorithmAI>(options.AlgDepth, boardMarks::O, boardMarks::X);

    reset();
}

void GameController::startGame()
{
    /* Shows the gameplay GUI */
    view.exec();
}

void GameController::setConnections()
{
    /* GUI: Cell connections */
    for (Cell &cell: cells)
        connect(cell.cellButton, &QPushButton::clicked, [&] { updateGame(cell); });

    /* GUI: New Game connection */
    connect(&view, &TTTGame::newGame, this, [&] { reset(); });

    /* GUI: connect AI to play after user move */
    connect(this, &GameController::turnFinished, [=] { AIMenagerPlay(); });
}


void GameController::updateGameState(Cell &cell)
{
    this->view.updateCell(cell, currentPlayer);

    #ifdef QT_DEBUG
//    board.printBoard();
    #endif

    boardState currentState = board.evaluateBoardState();
    if (boardState::noWinner != currentState)
        view.declareGameState(currentState);

    switchPlayer();
}


void GameController::reset()
{
    currentPlayer = boardMarks::X;
    view.reset(cells);
    board.reset();
    AIMenager->reset();
    if (options.AIstarts)
        AIMenagerPlay();
}

void GameController::AIMenagerPlay()
{
    int cellIdx = AIMenager->play(board);
    if (defaultOptions::INVALID_CELL != cellIdx)
        updateGameState(cells.at(static_cast<size_t>(cellIdx)));
}

void GameController::switchPlayer()
{
    if (boardMarks::X == currentPlayer)
        currentPlayer = boardMarks::O;
    else if (boardMarks::O == currentPlayer)
        currentPlayer =boardMarks::X;
}

void GameController::updateGame(Cell &cell)
{
    bool success = board.setPlayerInput(static_cast<size_t>(cell.row),
                                        static_cast<size_t>(cell.col),
                                        currentPlayer);
    if (success) {
        updateGameState(cell);
        emit turnFinished();
    }
}
