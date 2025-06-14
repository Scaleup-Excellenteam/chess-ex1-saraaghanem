# Chess Project – Final Submission

This is the complete chess engine project developed through four progressive stages.

## Features by Stage

Stage 1: Basic Engine
- Board parsing from string
- Piece hierarchy (King, Queen, Bishop, Knight, Rook, Pawn)
- Move validation for each piece
- Error codes for invalid moves

Stage 2: Recommendation Engine
- MoveScorer::recommendTopMoves(depth) for selecting best moves
- Priority Queue (Min-Heap) for scoring moves
- Evaluates future positions recursively

Stage 3: Multithreading + Benchmark
- ThreadPool implementation with task queue
- Thread-safe move evaluation using mutex
- Execution time comparison for 0, 2, 4, 8 threads
- Bonus: Early termination of threads if move exceeds score threshold

Stage 4: Full Chess Rules + AI
- Checkmate detection using isCheckmate(bool white)
- Castling (both sides, both colors) with rule validation
- Draw detection if only kings remain
- AI opponent using the recommendation engine
- Selectable search depth at game start
- User chooses mode: PvP or vs AI

## Build Instructions

1. Open terminal and run:

   mkdir build  
   cd build  
   cmake ..  
   make  
   ./chess

## Game Modes

- When prompted:
  - Enter 1 → Player vs Player
  - Enter 2 → Player vs Computer
- Then choose search depth (e.g., 2 or 3)

## AI Logic

- Uses MoveScorer::recommendTopMoves(depth)
- Searches future moves up to selected depth
- Selects the best evaluated move using priority queue

## Testing and Debugging

- Manual move testing supported
- AI moves are printed to console
- Code structure enables easy validation and logging

## Summary

- All core chess rules implemented
- Optimized with multithreading
- Fully supports AI and player interaction
