
#ifndef MOVE_EVALUATOR_H
#define MOVE_EVALUATOR_H

#include "MoveScorer.h"
#include <map>

// סימולציה נאיבית של ערך כלים
static std::map<char, int> pieceValue = {
    {'P', 1},  // חייל (Pawn)
    {'N', 3},  // פרש (Knight)
    {'B', 3},  // רץ (Bishop)
    {'R', 5},  // צריח (Rook)
    {'Q', 9},  // מלכה (Queen)
    {'K', 100} // מלך (King)
};

// משבצות שנחשבות "מרכז הלוח"
static std::set<std::string> centerSquares = {"d4", "d5", "e4", "e5"};

// הערכת מהלך – דוגמה ראשונית בלבד (לשדרוג בהתאם ללוח אמיתי)
class MoveEvaluator {
public:
    static int evaluate(const Move& move, char targetPiece = 0, bool exposesToThreat = false) {
        int score = 0;

        // אם יש אכילה
        if (targetPiece != 0 && pieceValue.count(targetPiece)) {
            score += pieceValue[targetPiece];
        }

        // אם נע למרכז
        if (centerSquares.count(move.to)) {
            score += 2;
        }

        // אם המהלך חושף לאיום מכלי חלש
        if (exposesToThreat) {
            score -= 2;
        }

        return score;
    }
};

#endif // MOVE_EVALUATOR_H
