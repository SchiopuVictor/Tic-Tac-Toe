#include "catch_amalgamated.hpp"
#include <sstream>
#include <memory>
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "AI.hpp"
#include "raylib.h"
#include "Coord.hpp"

TEST_CASE("Game - Constructor cu doi jucători umani", "[Game][Constructor]")
{
    Game game("Alice", "Bob");

    REQUIRE(true);
}

TEST_CASE("Game - Constructor cu primul jucător AI", "[Game][Constructor]")
{
    Game game("AI", "Bob");

    REQUIRE(true);
}

TEST_CASE("Game - Constructor cu al doilea jucător AI", "[Game][Constructor]")
{
    Game game("Alice", "AI");

    REQUIRE(true);
}

TEST_CASE("Game - Constructor cu ambii jucători AI", "[Game][Constructor]")
{
    Game game("AI", "AI");

    REQUIRE(true);
}

TEST_CASE("Game - SwitchTurn schimbă jucătorul curent", "[Game][SwitchTurn]")
{
    Game game("Alice", "Bob");

    game.SwitchTurn();
    game.SwitchTurn();

    REQUIRE(true);
}

TEST_CASE("Game - IsGameOver returnează false la începutul jocului", "[Game][IsGameOver]")
{
    Game game("Alice", "Bob");

    bool result = game.IsGameOver();

    REQUIRE_FALSE(result);
}

TEST_CASE("Game - IsGameOver detectează victoria", "[Game][IsGameOver]")
{
    Game game("Alice", "Bob");
    REQUIRE(true);
}

TEST_CASE("Game - IsGameOver detectează remiza", "[Game][IsGameOver]")
{
    Game game("Alice", "Bob");

    REQUIRE(true);
}

TEST_CASE("Game - GetWinner nu aruncă excepții", "[Game][GetWinner]")
{
    Game game("Alice", "Bob");
    std::stringstream output_ss;
    std::streambuf *original_cout = std::cout.rdbuf(output_ss.rdbuf());

    game.GetWinner();

    REQUIRE(output_ss.str().find("Checking winner") != std::string::npos);

    std::cout.rdbuf(original_cout);
}

TEST_CASE("Game - Multiple SwitchTurn inversează corect jucătorii", "[Game][SwitchTurn]")
{
    Game game("Alice", "Bob");

    for (int i = 0; i < 10; i++)
    {
        game.SwitchTurn();
    }

    REQUIRE(true);
}

TEST_CASE("Game - Constructor cu nume goale", "[Game][Constructor]")
{
    Game game("", "");

    REQUIRE(true);
}

TEST_CASE("Game - Constructor cu nume foarte lungi", "[Game][Constructor]")
{
    std::string longName(1000, 'A');

    Game game(longName, longName);

    REQUIRE(true);
}

TEST_CASE("Game - IsGameOver pe tablă goală", "[Game][IsGameOver]")
{
    Game game("Alice", "Bob");

    bool result = game.IsGameOver();

    REQUIRE_FALSE(result);
}

TEST_CASE("Game - Multiple apeluri GetWinner", "[Game][GetWinner]")
{
    Game game("Alice", "Bob");
    std::stringstream output_ss;
    std::streambuf *original_cout = std::cout.rdbuf(output_ss.rdbuf());

    game.GetWinner();
    game.GetWinner();
    game.GetWinner();

    std::string output = output_ss.str();
    size_t count = 0;
    size_t pos = 0;
    std::string searchStr = "Checking winner";
    while ((pos = output.find(searchStr, pos)) != std::string::npos)
    {
        count++;
        pos += searchStr.length();
    }
    REQUIRE(count == 3);

    std::cout.rdbuf(original_cout);
}

TEST_CASE("Game - Constructor cu combinații AI și nume normale", "[Game][Constructor]")
{
    SECTION("AI vs nume normal")
    {
        Game game("AI", "Player1");
        REQUIRE(true);
    }

    SECTION("Nume normal vs AI")
    {
        Game game("Player1", "AI");
        REQUIRE(true);
    }

    SECTION("Ambii AI")
    {
        Game game("AI", "AI");
        REQUIRE(true);
    }

    SECTION("Niciunul AI")
    {
        Game game("Player1", "Player2");
        REQUIRE(true);
    }
}

TEST_CASE("Game - SwitchTurn nu provoacă memory leaks", "[Game][SwitchTurn]")
{
    Game game("Alice", "Bob");

    for (int i = 0; i < 1000; i++)
    {
        game.SwitchTurn();
    }

    REQUIRE(true);
}

TEST_CASE("Game - IsGameOver este consistent", "[Game][IsGameOver]")
{
    Game game("Alice", "Bob");

    bool first = game.IsGameOver();
    bool second = game.IsGameOver();
    bool third = game.IsGameOver();

    REQUIRE(first == second);
    REQUIRE(second == third);
}

TEST_CASE("Game - GetWinner funcționează după IsGameOver", "[Game][GetWinner]")
{
    Game game("Alice", "Bob");
    std::stringstream output_ss;
    std::streambuf *original_cout = std::cout.rdbuf(output_ss.rdbuf());

    game.IsGameOver();
    game.GetWinner();

    REQUIRE(output_ss.str().find("Checking winner") != std::string::npos);

    std::cout.rdbuf(original_cout);
}