#include "catch_amalgamated.hpp"
#include "AI.hpp"
#include "Board.hpp"
#include "Coord.hpp"

TEST_CASE("AI - Constructor implicit", "[AI]")
{
    AI ai;
    REQUIRE(ai.GetSymbol() == "O");
    REQUIRE(ai.GetName() == "AI Player");
}

TEST_CASE("AI - Constructor cu parametru", "[AI]")
{
    AI ai("X");
    REQUIRE(ai.GetSymbol() == "X");
    REQUIRE(ai.GetName() == "AI Player");
}

TEST_CASE("AI - Copy constructor", "[AI]")
{
    AI ai1("X");
    AI ai2(ai1);
    REQUIRE(ai2.GetSymbol() == "X");
    REQUIRE(ai1 == ai2);
}

TEST_CASE("AI - Operatorul de atribuire", "[AI]")
{
    AI ai1("X");
    AI ai2("O");

    ai2 = ai1;
    REQUIRE(ai2.GetSymbol() == "X");
    REQUIRE(ai1 == ai2);
}

TEST_CASE("AI - Operatorul de egalitate", "[AI]")
{
    AI ai1("X");
    AI ai2("X");
    AI ai3("O");

    REQUIRE(ai1 == ai2);
    REQUIRE_FALSE(ai1 == ai3);
}

TEST_CASE("AI - MakeMove pe o tablă goală", "[AI]")
{
    Board board(3, 3);
    AI ai("X");

    Coord move = ai.MakeMove(board);

    REQUIRE(move.x >= 0);
    REQUIRE(move.x < board.GetWidth());
    REQUIRE(move.y >= 0);
    REQUIRE(move.y < board.GetHeight());
}

TEST_CASE("AI - MakeMove alege doar poziții libere", "[AI]")
{
    Board board(3, 3);
    AI ai("X");

    for (int i = 0; i < 5; i++)
    {
        Coord move = ai.MakeMove(board);
        REQUIRE(board.IsFree(move.x, move.y));
    }
}

TEST_CASE("AI - Operatorul de output stream", "[AI]")
{
    AI ai("X");
    std::ostringstream oss;
    oss << ai;
    REQUIRE(oss.str() == "X");
}

TEST_CASE("AI - Operatorul de input stream", "[AI]")
{
    AI ai;
    std::istringstream iss("Y");
    iss >> ai;
    REQUIRE(ai.GetSymbol() == "Y");
}