#include "Game.hpp"
#include <iostream>

Game::Game(std::string& name1, std::string& name2)
    : player1('X', name1), player2('O', name2) {}

void Game::Start() {
    std::cout << "Game started!\n";
    board.Display();
    board.Reset();
}

void Game::SwitchTurn() {
    std::cout << "Switching turn...\n";
}

bool Game::IsGameOver() {
    return false;
}

void Game::GetWinner() {
    std::cout << "No winner yet!\n";
}
