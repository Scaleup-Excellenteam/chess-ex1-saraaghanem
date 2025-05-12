#include "Chess.h"
#include "Board.h"
#include "Logger.cpp"
#include "MoveScorer.h"
#include <iostream>
using namespace std;

int main()
{
    string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    Chess a(board);
    Board logicBoard(board);
    Logger logger;

    int codeResponse = 0;
    string res = a.getInput();
    MoveScorer::recommendTopMoves(2);

    while (res != "exit")
    {

        int srcCol = res[0] - 'a';
        int srcRow = res[1] - '1';
        Piece* srcPiece = logicBoard.getGrid()[srcRow][srcCol];

        if (srcPiece && (srcPiece->symbol() == 'N' || srcPiece->symbol() == 'n'))
            logger.logKnightMove();

        codeResponse = logicBoard.validateAndMove(res);

        if (codeResponse == 41)
            logger.logCheck();

        a.setCodeResponse(codeResponse);
        res = a.getInput();
    }


    logger.setWinner(logicBoard.isInCheck(true) ? "Black" : "White");
    logger.writeSummary();

    cout << endl << "Exiting " << endl;
    return 0;
}
