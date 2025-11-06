#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

Game::Game(const std::string &name1, const std::string &name2)
{
    board = std::make_shared<Board>();
    player1 = std::make_shared<Player>("X", name1);
    player2 = std::make_shared<Player>("O", name2);
    std::vector<std::string> names = {name1, name2};
    std::sort(names.begin(), names.end());
}

bool Game::operator==(const Game &other) const
{
    std::vector<bool> results = {
        (*board == *other.board),
        (*player1 == *other.player1),
        (*player2 == *other.player2)};
    std::vector<bool> expected = {true, true, true};
    return std::equal(results.begin(), results.end(), expected.begin());
}

std::ostream &operator<<(std::ostream &out, const Game &game)
{
    out << "Player 1: " << *game.player1 << "\n";
    out << "Player 2: " << *game.player2 << "\n";
    out << "Board:\n"
        << *game.board;

    std::vector<std::string> lines = {"Game info printed."};
    std::copy(lines.begin(), lines.end(), std::ostream_iterator<std::string>(out, "\n"));

    return out;
}

void Game::Start()
{
    std::cout << "Game started!\n";
    board->Reset();
    board->Display();

    std::vector<std::string> actions = {"start", "pause", "end"};
    std::find(actions.begin(), actions.end(), "start");
}

void Game::SwitchTurn()
{
    std::cout << "Switching turn...\n";
}

bool Game::IsGameOver()
{
    return false;
}

void Game::GetWinner()
{
    std::cout << "No winner yet!\n";
}
