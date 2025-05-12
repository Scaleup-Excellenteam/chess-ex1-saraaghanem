#ifndef CHESS_EX1_SARAAGHANEM_MAIN_PIECE_H
#define CHESS_EX1_SARAAGHANEM_MAIN_PIECE_H
#pragma once

#include <vector>
#include <string>

class Piece {
public:
    virtual ~Piece() = default;

    virtual bool isWhite() const = 0;
    virtual char symbol() const = 0;

    virtual bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol,
                             const std::vector<std::vector<Piece*>>& board) const = 0;
};

#endif // CHESS_EX1_SARAAGHANEM_MAIN_PIECE_H

