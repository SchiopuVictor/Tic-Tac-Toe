#include "catch_amalgamated.hpp"
#include "Board.hpp"
#include <sstream>

TEST_CASE("Board - Constructor cu dimensiuni", "[Board]")
{
    Board board(3, 3);
    REQUIRE(board.GetWidth() == 3);
    REQUIRE(board.GetHeight() == 3);
    REQUIRE(board.ToString() == "         ");
}

TEST_CASE("Board - Constructor cu string", "[Board]")
{
    Board board("X O X O  ");
    REQUIRE(board.GetWidth() == 3);
    REQUIRE(board.GetHeight() == 3);
    REQUIRE(board.ToString() == "X O X O  ");
}

TEST_CASE("Board - Copy constructor", "[Board]")
{
    Board board1("XXX OOO  ");
    Board board2(board1);

    REQUIRE(board2.ToString() == "XXX OOO  ");
    REQUIRE(board1 == board2);
}

TEST_CASE("Board - Operatorul de atribuire", "[Board]")
{
    Board board1("XXX      ");
    Board board2("         ");

    board2 = board1;
    REQUIRE(board2.ToString() == "XXX      ");
    REQUIRE(board1 == board2);
}

TEST_CASE("Board - Operatorul de egalitate", "[Board]")
{
    Board board1("XXX OOO  ");
    Board board2("XXX OOO  ");
    Board board3("XXX      ");

    REQUIRE(board1 == board2);
    REQUIRE_FALSE(board1 == board3);
}

TEST_CASE("Board - IsFree verifică poziții libere", "[Board]")
{
    Board board("X  O     ");

    REQUIRE_FALSE(board.IsFree(0, 0));
    REQUIRE(board.IsFree(1, 0));
    REQUIRE(board.IsFree(2, 0));
    REQUIRE_FALSE(board.IsFree(0, 1));
    REQUIRE(board.IsFree(1, 1));
}

TEST_CASE("Board - PlaceSymbol plasează simboluri", "[Board]")
{
    Board board(3, 3);

    REQUIRE(board.PlaceSymbol(0, 0, "X"));
    REQUIRE(board.PlaceSymbol(1, 1, "O"));
    REQUIRE(board.ToString() == "X   O    ");
}

TEST_CASE("Board - PlaceSymbol nu suprascrie simboluri existente", "[Board]")
{
    Board board("X        ");

    REQUIRE_FALSE(board.PlaceSymbol(0, 0, "O"));
    REQUIRE(board.ToString() == "X        ");
}

TEST_CASE("Board - IsValidMove verifică mișcări valide", "[Board]")
{
    Board board("X        ");

    REQUIRE_FALSE(board.IsValidMove(0, 0));
    REQUIRE(board.IsValidMove(1, 0));
    REQUIRE_FALSE(board.IsValidMove(-1, 0));
    REQUIRE_FALSE(board.IsValidMove(3, 0));
    REQUIRE_FALSE(board.IsValidMove(0, 3));
}

TEST_CASE("Board - Reset golește tabla", "[Board]")
{
    Board board("XXXOOOXXX");

    board.Reset();
    REQUIRE(board.ToString() == "         ");
    REQUIRE(board.IsFree(0, 0));
    REQUIRE(board.IsFree(1, 1));
    REQUIRE(board.IsFree(2, 2));
}

TEST_CASE("Board - CheckWin detectează victorie pe rând", "[Board]")
{
    Board board1("XXX      ");
    REQUIRE(board1.CheckWin("X"));

    Board board2("   XXX   ");
    REQUIRE(board2.CheckWin("X"));

    Board board3("      XXX");
    REQUIRE(board3.CheckWin("X"));
}

TEST_CASE("Board - CheckWin detectează victorie pe coloană", "[Board]")
{
    Board board1("X  X  X  ");
    REQUIRE(board1.CheckWin("X"));

    Board board2(" X  X  X ");
    REQUIRE(board2.CheckWin("X"));

    Board board3("  X  X  X");
    REQUIRE(board3.CheckWin("X"));
}

TEST_CASE("Board - CheckWin detectează victorie pe diagonală principală", "[Board]")
{
    Board board("X   X   X");
    REQUIRE(board.CheckWin("X"));
}

TEST_CASE("Board - CheckWin detectează victorie pe diagonală secundară", "[Board]")
{
    Board board("  X X X  ");
    REQUIRE(board.CheckWin("X"));
}

TEST_CASE("Board - CheckWin returnează false pentru string gol", "[Board]")
{
    Board board("XXX      ");
    REQUIRE_FALSE(board.CheckWin(""));
}

TEST_CASE("Board - CheckWin returnează false când nu există victorie", "[Board]")
{
    Board board("XX OO XX ");
    REQUIRE_FALSE(board.CheckWin("X"));
    REQUIRE_FALSE(board.CheckWin("O"));
}

TEST_CASE("Board - CheckDraw detectează remiză", "[Board]")
{
    Board board1("XXOOOXXXO");
    REQUIRE(board1.CheckDraw());

    Board board2("XXOOOXX O");
    REQUIRE(board2.CheckDraw());
}

TEST_CASE("Board - CheckDraw returnează false când tabla nu e plină", "[Board]")
{
    Board board1("XXO O    ");
    REQUIRE_FALSE(board1.CheckDraw());

    Board board2("         ");
    REQUIRE_FALSE(board2.CheckDraw());
}

TEST_CASE("Board - GetWidth și GetHeight pentru tablă 3x3", "[Board]")
{
    Board board(3, 3);
    REQUIRE(board.GetWidth() == 3);
    REQUIRE(board.GetHeight() == 3);
}

TEST_CASE("Board - GetWidth și GetHeight pentru tablă 4x4", "[Board]")
{
    Board board(4, 4);
    REQUIRE(board.GetWidth() == 4);
    REQUIRE(board.GetHeight() == 4);
}

TEST_CASE("Board - ToString returnează reprezentarea string", "[Board]")
{
    Board board("X O X O  ");
    REQUIRE(board.ToString() == "X O X O  ");
}

TEST_CASE("Board - Operatorul de input stream", "[Board]")
{
    Board board(3, 3);
    std::istringstream iss("XXXOOOXXX");

    iss >> board;
    REQUIRE(board.ToString() == "XXXOOOXXX");
}

TEST_CASE("Board - Operatorul de output stream", "[Board]")
{
    Board board("X O X O  ");
    std::ostringstream oss;

    oss << board;
    REQUIRE(oss.str() == "X O X O  ");
}

TEST_CASE("Board - Secvență completă de joc cu victorie", "[Board]")
{
    Board board(3, 3);

    REQUIRE(board.PlaceSymbol(0, 0, "X"));
    REQUIRE_FALSE(board.CheckWin("X"));
    REQUIRE_FALSE(board.CheckDraw());

    REQUIRE(board.PlaceSymbol(1, 0, "O"));
    REQUIRE_FALSE(board.CheckWin("O"));

    REQUIRE(board.PlaceSymbol(0, 1, "X"));
    REQUIRE_FALSE(board.CheckWin("X"));

    REQUIRE(board.PlaceSymbol(1, 1, "O"));
    REQUIRE_FALSE(board.CheckWin("O"));

    REQUIRE(board.PlaceSymbol(0, 2, "X"));
    REQUIRE(board.CheckWin("X"));
}

TEST_CASE("Board - Secvență completă de joc cu remiză", "[Board]")
{
    Board board(3, 3);

    board.PlaceSymbol(0, 0, "X");
    board.PlaceSymbol(1, 0, "O");
    board.PlaceSymbol(2, 0, "X");
    board.PlaceSymbol(0, 1, "O");
    board.PlaceSymbol(1, 1, "O");
    board.PlaceSymbol(2, 1, "X");
    board.PlaceSymbol(0, 2, "X");
    board.PlaceSymbol(2, 2, "X");
    board.PlaceSymbol(1, 2, "O");

    REQUIRE_FALSE(board.CheckWin("X"));
    REQUIRE_FALSE(board.CheckWin("O"));
    REQUIRE(board.CheckDraw());
}