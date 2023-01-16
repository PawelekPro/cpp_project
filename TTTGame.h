<<<<<<< HEAD
#ifndef TTTGAME_H
#define TTTGAME_H

#include "GameOptions.h"
#include "ui_TTTGame.h"
#include <QDialog>
#include <vector>


class TTTGame : public QDialog
{
    Q_OBJECT
public:
    TTTGame(QWidget *parent = nullptr);

    std::vector<Cell> buildCellButtons(size_t boardSize);
    void updateCell(Cell &cell, boardMarks currentPlayer);
    void declareGameState(boardState currentState);
    void reset(std::vector<Cell> &cells);

private:
    std::unique_ptr<Ui::TTTGame> ui;
    void setConnections();
    QString getPlayerText(boardMarks currentPlayer);
    QString getPlayerStyleSheet(boardMarks currentPlayer);
    QString getBoardFinalStateText(boardState finalState);

signals:
void newGame();

};

#endif // TTTGAME_H
=======
#ifndef TTTGAME_H
#define TTTGAME_H

#include "GameOptions.h"
#include "ui_TTTGame.h"
#include <QDialog>
#include <vector>


class TTTGame final : public QDialog
{
    Q_OBJECT
public:
    explicit TTTGame(QWidget *parent = nullptr);

    std::vector<Cell> buildCellButtons(size_t boardSize);
    void updateCell(Cell &cell, boardMarks currentPlayer);
    void declareGameState(boardState currentState);
    void reset(std::vector<Cell> &cells);

private:
    std::unique_ptr<Ui::TTTGame> ui;
    void setConnections();
    QString getPlayerText(boardMarks currentPlayer);
    QString getPlayerStyleSheet(boardMarks currentPlayer);
    QString getBoardFinalStateText(boardState finalState);

signals:
void newGame();

};

#endif // TTTGAME_H
>>>>>>> fc9f2c7b6afbcdfc3183b30f95252a7aaa69cbaf
