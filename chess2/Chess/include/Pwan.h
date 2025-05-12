//
// Created by MyPC on 24/04/2025.
//

#ifndef CHESS_EX1_SARAAGHANEM_MAIN_PWAN_H
#define CHESS_EX1_SARAAGHANEM_MAIN_PWAN_H

#pragma once
#include "Piece.h"

class Pawn : public Piece {
    bool white;
public:
    Pawn(bool isWhite);
    bool isWhite() const override;
    char symbol() const override;
    bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol,
                     const std::vector<std::vector<Piece*>>& board) const override;
};


#endif //CHESS_EX1_SARAAGHANEM_MAIN_PWAN_H
