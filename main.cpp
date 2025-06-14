#include "Chess.h"
#include "Board.h"
#include "Logger.cpp"
#include "MoveScorer.h"
#include <iostream>
using namespace std;

int main()
{

    cout << "Enter mode (1 = Player vs Player, 2 = Player vs Computer): ";
    int mode;
    cin >> mode;

    cout << "Enter search depth (1-3 recommended): ";
    int depth;
    cin >> depth;

    string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    Chess a(board);
    Board logicBoard(board);
    Logger logger;

    int codeResponse = 0;
    string res = a.getInput();
    MoveScorer::recommendTopMoves(2);

    
    while (res != "exit") {
        if ((mode == 1) || (mode == 2 && logicBoard.isWhiteTurn())) {
            int srcCol = res[0] - 'a';
            int srcRow = res[1] - '1';
            Piece* srcPiece = logicBoard.getGrid()[srcRow][srcCol];

            if (srcPiece && (srcPiece->symbol() == 'N' || srcPiece->symbol() == 'n'))
                logger.logKnightMove();

            codeResponse = logicBoard.validateAndMove(res);

            if (codeResponse == 41)
                logger.logCheck();

            if (codeResponse == 51)
                cout << "Draw detected.\n";

            a.setCodeResponse(codeResponse);
            res = a.getInput();
        } else if (mode == 2) {
            string aiMove = MoveScorer::recommendTopMoves(depth)[0].move;
            cout << "AI plays: " << aiMove << endl;
            codeResponse = logicBoard.validateAndMove(aiMove);
            if (codeResponse == 41)
                cout << "Check!\n";
            if (codeResponse == 51)
                cout << "Draw detected.\n";
            res = a.getInput();
        }
    }
logger.setWinner(logicBoard.isInCheck(true) ? "Black" : "White");
    logger.writeSummary();

    cout << endl << "Exiting " << endl;
    return 0;
}
