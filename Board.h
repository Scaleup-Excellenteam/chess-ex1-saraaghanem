//
// Created by MyPC on 24/04/2025.
//

#ifndef CHESS_EX1_SARAAGHANEM_MAIN_BOARD_H
#define CHESS_EX1_SARAAGHANEM_MAIN_BOARD_H
#pragma once
#include <vector>
#include <string>
#include "../include/Piece.h"

class Board {
    std::vector<std::vector<Piece*>> grid;
    bool whiteTurn = true;
public:
    Board(const std::string& boardString);
    ~Board();
    int validateAndMove(const std::string& move);
    std::vector<std::vector<Piece*>> getGrid() const;
    bool isInCheck(bool white) const;
    bool causesCheck(int srcRow, int srcCol, int destRow, int destCol);
    bool isCheckmate(bool white);
};

#endif //CHESS_EX1_SARAAGHANEM_MAIN_BOARD_H
