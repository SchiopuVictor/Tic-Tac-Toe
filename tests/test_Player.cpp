#include "catch_amalgamated.hpp"
#ifdef TEST_BUILD
#include "ListenerStub.hpp"
#else
#include "RaylibListener.hpp"
#endif
#include <sstream>
#include <memory>
#include "Player.hpp"
#include "Board.hpp"
#include "Coord.hpp"

TEST_CASE("Player - Constructor cu parametri", "[Player][Constructor]")
{
    Player player("X", "Alice");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - Constructor cu simbol O", "[Player][Constructor]")
{
    Player player("O", "Bob");

    REQUIRE(player.GetSymbol() == "O");
    REQUIRE(player.GetName() == "Bob");
}

TEST_CASE("Player - Constructor cu nume gol", "[Player][Constructor]")
{
    Player player("X", "");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "");
}

TEST_CASE("Player - Constructor cu simbol gol", "[Player][Constructor]")
{
    Player player("", "Alice");

    REQUIRE(player.GetSymbol() == "");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - GetSymbol returnează simbolul corect", "[Player][GetSymbol]")
{
    Player player("X", "Alice");

    std::string symbol = player.GetSymbol();

    REQUIRE(symbol == "X");
}

TEST_CASE("Player - GetName returnează numele corect", "[Player][GetName]")
{
    Player player("X", "Alice");

    std::string name = player.GetName();

    REQUIRE(name == "Alice");
}

TEST_CASE("Player - Copy constructor", "[Player][Copy]")
{
    Player player1("X", "Alice");

    Player player2(player1);

    REQUIRE(player2.GetSymbol() == "X");
    REQUIRE(player2.GetName() == "Alice");
    REQUIRE(player1 == player2);
}

TEST_CASE("Player - Operatorul de atribuire", "[Player][Assignment]")
{
    Player player1("X", "Alice");
    Player player2("O", "Bob");

    player2 = player1;

    REQUIRE(player2.GetSymbol() == "X");
    REQUIRE(player2.GetName() == "Alice");
    REQUIRE(player1 == player2);
}

TEST_CASE("Player - Operatorul de egalitate - jucători identici", "[Player][Equality]")
{
    Player player1("X", "Alice");
    Player player2("X", "Alice");

    REQUIRE(player1 == player2);
}

TEST_CASE("Player - Operatorul de egalitate - simboluri diferite", "[Player][Equality]")
{
    Player player1("X", "Alice");
    Player player2("O", "Alice");

    REQUIRE_FALSE(player1 == player2);
}

TEST_CASE("Player - Operatorul de egalitate - nume diferite", "[Player][Equality]")
{
    Player player1("X", "Alice");
    Player player2("X", "Bob");

    REQUIRE_FALSE(player1 == player2);
}

TEST_CASE("Player - Operatorul de egalitate - ambele diferite", "[Player][Equality]")
{
    Player player1("X", "Alice");
    Player player2("O", "Bob");

    REQUIRE_FALSE(player1 == player2);
}

TEST_CASE("Player - Operatorul de egalitate cu sine însuși", "[Player][Equality]")
{
    Player player("X", "Alice");

    REQUIRE(player == player);
}

TEST_CASE("Player - Operatorul de output stream", "[Player][Output]")
{
    Player player("X", "Alice");
    std::ostringstream oss;

    oss << player;

    std::string expected = "Player: Alice (Symbol: X)";
    REQUIRE(oss.str() == expected);
}

TEST_CASE("Player - Operatorul de output stream cu nume gol", "[Player][Output]")
{
    Player player("X", "");
    std::ostringstream oss;

    oss << player;

    std::string expected = "Player:  (Symbol: X)";
    REQUIRE(oss.str() == expected);
}

TEST_CASE("Player - Operatorul de output stream cu simbol gol", "[Player][Output]")
{
    Player player("", "Alice");
    std::ostringstream oss;

    oss << player;

    std::string expected = "Player: Alice (Symbol: )";
    REQUIRE(oss.str() == expected);
}

TEST_CASE("Player - Constructor cu nume lung", "[Player][Constructor]")
{
    std::string longName(1000, 'A');

    Player player("X", longName);

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == longName);
    REQUIRE(player.GetName().length() == 1000);
}

TEST_CASE("Player - Constructor cu simbol multi-caracter", "[Player][Constructor]")
{
    Player player("XXX", "Alice");

    REQUIRE(player.GetSymbol() == "XXX");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - Constructor cu caractere speciale în nume", "[Player][Constructor]")
{
    Player player("X", "Alice@123!#");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "Alice@123!#");
}

TEST_CASE("Player - Constructor cu caractere speciale în simbol", "[Player][Constructor]")
{
    Player player("@#$", "Alice");

    REQUIRE(player.GetSymbol() == "@#$");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - Multiple atribuiri în lanț", "[Player][Assignment]")
{
    Player player1("X", "Alice");
    Player player2("O", "Bob");
    Player player3("Z", "Charlie");

    player3 = player2 = player1;

    REQUIRE(player1 == player2);
    REQUIRE(player2 == player3);
    REQUIRE(player1 == player3);
}

TEST_CASE("Player - Operatorul de output cu stream multiplu", "[Player][Output]")
{
    Player player1("X", "Alice");
    Player player2("O", "Bob");
    std::ostringstream oss;

    oss << player1 << " vs " << player2;

    std::string expected = "Player: Alice (Symbol: X) vs Player: Bob (Symbol: O)";
    REQUIRE(oss.str() == expected);
}

TEST_CASE("Player - GetSymbol nu modifică obiectul (const correctness)", "[Player][GetSymbol]")
{
    const Player player("X", "Alice");

    std::string symbol = player.GetSymbol();

    REQUIRE(symbol == "X");
    REQUIRE(player.GetSymbol() == "X");
}

TEST_CASE("Player - GetName nu modifică obiectul (const correctness)", "[Player][GetName]")
{
    const Player player("X", "Alice");

    std::string name = player.GetName();

    REQUIRE(name == "Alice");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - Comparație între copie și original", "[Player][Equality]")
{
    Player original("X", "Alice");
    Player copy = original;

    REQUIRE(original == copy);
    REQUIRE(copy == original);
}

TEST_CASE("Player - Constructor cu spații în nume", "[Player][Constructor]")
{
    Player player("X", "Alice Smith");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "Alice Smith");
}

TEST_CASE("Player - Constructor cu nume care conține doar spații", "[Player][Constructor]")
{
    Player player("X", "   ");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "   ");
}

TEST_CASE("Player - Operatorul de egalitate este tranzitiv", "[Player][Equality]")
{
    Player player1("X", "Alice");
    Player player2("X", "Alice");
    Player player3("X", "Alice");

    REQUIRE(player1 == player2);
    REQUIRE(player2 == player3);
    REQUIRE(player1 == player3);
}

TEST_CASE("Player - Operatorul de output nu modifică player-ul", "[Player][Output]")
{
    Player player("X", "Alice");
    std::ostringstream oss1, oss2;

    oss1 << player;
    oss2 << player;

    REQUIRE(oss1.str() == oss2.str());
    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "Alice");
}

TEST_CASE("Player - Constructor cu Unicode în nume", "[Player][Constructor]")
{
    Player player("X", "Alicé");

    REQUIRE(player.GetSymbol() == "X");
    REQUIRE(player.GetName() == "Alicé");
}
