#include "Game.hpp"

#include "AI.hpp"
#include "Player.hpp"
#include "Renderer.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

Game::Game(const std::string &name1, const std::string &name2) : currentPlayer(nullptr)
{
    if (name1 == "AI")
    {
        player1 = std::make_shared<AI>("X");
    }
    else
    {
        player1 = std::make_shared<Player>("X", name1);
    }
    if (name2 == "AI")
    {
        player2 = std::make_shared<AI>("O");
    }
    else
    {
        player2 = std::make_shared<Player>("O", name2);
    }
}

void Game::Start()
{
    board.Reset();
    currentPlayer = player1.get();

    Renderer renderer;
    Coord coord{-1, -1};

    while (!IsGameOver())
    {
        renderer.ClearScreen();
        renderer.DrawBoard(board);
        if (coord.x != -1 && coord.y != -1)
        {
            renderer.PutText(0, 1, "Last move: (" + std::to_string(coord.x) + ", " + std::to_string(coord.y) + ")");
        }
        renderer.PutText(0, 0, currentPlayer->GetName() + "'s turn (" + currentPlayer->GetSymbol() + "): ");

        coord = currentPlayer->MakeMove(board);
        board.PlaceSymbol(coord.x, coord.y, currentPlayer->GetSymbol());

        if (board.CheckWin(currentPlayer->GetSymbol()))
        {
            renderer.ClearScreen();
            renderer.DrawBoard(board);
            std::cout << currentPlayer->GetName() << " wins!\n";
            return;
        }

        if (board.CheckDraw())
        {
            renderer.ClearScreen();
            renderer.DrawBoard(board);
            std::cout << "Draw!\n";
            return;
        }

        SwitchTurn();
    }
}

void Game::SwitchTurn()
{
    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}

bool Game::IsGameOver()
{
    if (board.CheckWin(player1->GetSymbol()) || board.CheckWin(player2->GetSymbol()))
        return true;

    if (board.CheckDraw())
        return true;
    return false;
}

void Game::GetWinner()
{
    std::cout << "No winner yet!\n";
}
