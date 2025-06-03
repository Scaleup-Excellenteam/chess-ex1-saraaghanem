#include "Knight.h"
#include <cmath>
#include <iostream>

Knight::Knight(bool isWhite) : white(isWhite) {}

bool Knight::isWhite() const { return white; }

char Knight::symbol() const { return white ? 'N' : 'n'; }

bool Knight::isLegalMove(int srcRow, int srcCol, int destRow, int destCol,
                         const std::vector<std::vector<Piece*>>& board) const {
    std::cout << "Knight moving from (" << srcRow << "," << srcCol << ") to (" << destRow << "," << destCol << ")" << std::endl;
    int dRow = std::abs(destRow - srcRow);
    int dCol = std::abs(destCol - srcCol);
    if ((dRow == 2 && dCol == 1) || (dRow == 1 && dCol == 2)) {
        return board[destRow][destCol] == nullptr || board[destRow][destCol]->isWhite() != white;
    }
    return false;
}
