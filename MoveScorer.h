
#ifndef MOVE_SCORER_H
#define MOVE_SCORER_H

#include "PriorityQueue.h"
#include "CustomExceptions.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// טופס נתונים פשוט לתיאור מהלך וציון
struct Move {
    std::string from;
    std::string to;
    int score;

    Move(std::string f, std::string t, int s) : from(std::move(f)), to(std::move(t)), score(s) {}

    // אופרטור הדפסה
    friend std::ostream& operator<<(std::ostream& os, const Move& move) {
        os << "Move from " << move.from << " to " << move.to << " | Score: " << move.score;
        return os;
    }
};

// קומפרטור עבור מהלכים - ציון גבוה עדיף
struct MoveComparator {
    int operator()(const Move& a, const Move& b) const {
        return b.score - a.score;  // גבוהים קודם
    }
};

class MoveScorer {
public:
    // מחזיר את 3 המהלכים הטובים ביותר (דוגמה לצורך תצוגה)
    static void recommendTopMoves(int depth = 1) {
        PriorityQueue<Move, MoveComparator> pq;

        // דוגמת מהלכים (בפועל ייווצרו על בסיס לוח המשחק)
        pq.push(Move("e2", "e4", 3));
        pq.push(Move("g1", "f3", 5));
        pq.push(Move("d2", "d4", 4));
        pq.push(Move("b1", "c3", 2));
        pq.push(Move("h2", "h4", 1));

        std::cout << "Top 3 recommended moves:
";
        int count = 0;
        for (auto it = pq.begin(); it != pq.end() && count < 3; ++it, ++count) {
            std::cout << *it << std::endl;
        }
    }
};

#endif // MOVE_SCORER_H
