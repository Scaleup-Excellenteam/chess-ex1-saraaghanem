//
// Created by MyPC on 03/05/2025.
//
#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream logFile;
    int knightMoves = 0;
    int checkCount = 0;
    std::string winner;

public:
    Logger() {
        logFile.open("chess_log.log", std::ios::app);
        logFile << "=== New Game ===\n";
    }

    void logKnightMove() {
        ++knightMoves;
    }

    void logCheck() {
        ++checkCount;
    }

    void setWinner(const std::string& player) {
        winner = player;
    }

    void writeSummary() {
        logFile << "Winner: " << winner << "\n";
        logFile << "Knight moves: " << knightMoves << "\n";
        logFile << "Number of checks: " << checkCount << "\n";
        logFile << "=================\n\n";
        logFile.close();
    }
};
