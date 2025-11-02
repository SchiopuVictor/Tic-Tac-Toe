#include "Game.hpp"
#include <iostream>

Game::Game(const std::string &name1, const std::string &name2)
{
    board = std::make_shared<Board>();
    player1 = std::make_shared<Player>("X", name1);
    player2 = std::make_shared<Player>("O", name2);
}

bool Game::operator==(const Game &other) const
{
    return (*board == *other.board) &&
           (*player1 == *other.player1) &&
           (*player2 == *other.player2);
}

std::ostream &operator<<(std::ostream &out, const Game &game)
{
    out << "Player 1: " << *game.player1 << "\n";
    out << "Player 2: " << *game.player2 << "\n";
    out << "Board:\n"
        << *game.board;
    return out;
}

void Game::Start()
{
    std::cout << "Game started!\n";
    board->Display();
    board->Reset();
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
