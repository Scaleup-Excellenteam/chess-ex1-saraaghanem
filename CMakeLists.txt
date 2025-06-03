target_sources(Chess
		PRIVATE
		main.cpp
		Logger.cpp
		Board.cpp
		Chess.cpp
		Bishop.cpp
		King.cpp
		Knight.cpp
		Pawn.cpp
		Queen.cpp
		Rook.cpp
)

target_include_directories(Chess PRIVATE ${PROJECT_SOURCE_DIR}/include)
