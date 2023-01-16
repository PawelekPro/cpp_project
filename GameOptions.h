#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H
#include <cstddef>

class QPushButton;
namespace defaultOptions
{
    constexpr short INVALID_CELL = -1;
    constexpr size_t DEFAULT_BOARD_SIZE = 3;
    constexpr unsigned short DEFAULT_ALG_DEPTH = 3;
    constexpr unsigned short GUI_CELL_ROW_SPAN = 1;
    constexpr unsigned short GUI_CELL_COLUMN_SPAN = 1;
    constexpr char X_COLOR[] = "#455A64";
    constexpr char O_COLOR[] = "#FF5752";
    constexpr char DEFAULT_COLOR[] = "FFF";
}

/* The Cell structure represent o board cell and all the necessary info about the cell. */
struct Cell
{
    QPushButton *cellButton = nullptr;
    int row = defaultOptions::INVALID_CELL;
    int col = defaultOptions::INVALID_CELL;
    Cell(QPushButton *cellButton, int row, int col) : cellButton(cellButton), row(row), col(col) {}
};

/* Definition of game options which are represented by the struct */
struct Options
{
    size_t boardSize = defaultOptions::DEFAULT_BOARD_SIZE;
    unsigned short AlgDepth = defaultOptions::DEFAULT_ALG_DEPTH;
    bool AIopponent = true;
    bool AIstarts = false;
};

/* boardMarks class defines the type of mark on the board */
enum class boardMarks {Empty, X, O};

/* boardMarks class defines possible states of the board */
enum class boardState {noWinner, XWins, OWins, Tie};

#endif // GAMEOPTIONS_H
