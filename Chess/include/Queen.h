//
// Created by MyPC on 24/04/2025.
//

#ifndef CHESS_EX1_SARAAGHANEM_MAIN_QUEEN_H
#define CHESS_EX1_SARAAGHANEM_MAIN_QUEEN_H

#pragma once
#include "Piece.h"

class Queen : public Piece {
    bool white;
public:
    Queen(bool isWhite);
    bool isWhite() const override;
    char symbol() const override;
    bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol,
                     const std::vector<std::vector<Piece*>>& board) const override;
};


#endif //CHESS_EX1_SARAAGHANEM_MAIN_QUEEN_H
