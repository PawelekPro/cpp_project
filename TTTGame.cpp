#include "TTTGame.h"
#include <QMessageBox>
#include <QPushButton>

TTTGame::TTTGame(QWidget *parent)
    : QDialog(parent), ui(new Ui::TTTGame)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    setConnections();
}

void TTTGame::setConnections()
{
    connect(ui->reset, &QPushButton::clicked, [=] { emit newGame();});
    connect(ui->back, &QPushButton::clicked, [=] { close(); });
}

std::vector<Cell> TTTGame::buildCellButtons(size_t boardSize)
{
    std::vector<Cell> cells;
    cells.reserve(boardSize * boardSize);
    for (size_t row = 0; row < boardSize; ++row) {
        for (size_t col = 0; col < boardSize; ++col) {
            /* Add buttons to gridLayout */
            QPushButton *button = new QPushButton();
            button->setProperty("cell", true);
            ui->gridBoard->addWidget(button,
                                     static_cast<int>(row),
                                     static_cast<int>(col),
                                     defaultOptions::GUI_CELL_ROW_SPAN,
                                     defaultOptions::GUI_CELL_COLUMN_SPAN);
            cells.emplace_back(button, row, col);
        }
    }
    adjustSize();
    return cells;
}


QString TTTGame::getPlayerText(boardMarks currentPlayer)
{
    switch (currentPlayer) {
    case boardMarks::O:
        return "O";
    case boardMarks::X:
        return "X";
    default:
        return "";
    }
}


QString TTTGame::getPlayerStyleSheet(boardMarks currentPlayer)
{
    QString color;

    switch (currentPlayer) {
    case boardMarks::O:
        color = defaultOptions::O_COLOR;
        break;
    case boardMarks::X:
        color = defaultOptions::X_COLOR;
        break;
    default:
        color = defaultOptions::DEFAULT_COLOR;
        break;
    }

    return QString("font: 50px \"Verdana\";"
                   "min-height: 100px;"
                   "max-height: 100px;"
                   "min-width: 100px;"
                   "max-width: 100px;"
                   "color: %1")
        .arg(color);
}

void TTTGame::updateCell(Cell &cell, boardMarks currentPlayer)
{
    /* Update cell button in GUI */
    cell.cellButton->setStyleSheet(getPlayerStyleSheet(currentPlayer));
    cell.cellButton->setText(getPlayerText(currentPlayer));
}


QString TTTGame::getBoardFinalStateText(boardState finalState)
{
    switch(finalState) {
    case boardState::XWins:
        return "Player X wins!";
    case boardState::OWins:
        return "Player O wins!";
    case boardState::Tie:
        return "It's a TIE!";
    default:
        return "";
    }
}

void TTTGame::declareGameState(boardState currentState)
{
    QMessageBox resultBox;
    resultBox.setWindowTitle("Game Result");
    resultBox.setText("Game over," + getBoardFinalStateText(currentState));
    resultBox.exec();
}

void TTTGame::reset(std::vector<Cell> &cells)
{
    /* Resets the GUI cells to an empty button with no marks */
    for (auto &cell : cells)
        cell.cellButton->setText("");
}
