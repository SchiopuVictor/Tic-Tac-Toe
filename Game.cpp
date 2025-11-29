#include "Game.hpp"

#include "AI.hpp"
#include "Player.hpp"
#include "RaylibRenderer.hpp"
#include "RaylibListener.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

Game::Game(const std::string& name1, const std::string& name2) : currentPlayer(nullptr)
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
    std::cout << "[debug] Starting a new game between " << player1->GetName() << " and " << player2->GetName() << "!\n";
    board.Reset();
    currentPlayer = player1.get();

    std::cout << "[debug] Init renderer!\n";
    
    std::shared_ptr<IRenderer> renderer = std::make_shared<RaylibRenderer>();
    renderer->Init();
    std::shared_ptr<IListener> listener = std::make_shared<RaylibListener>();
    Coord coord{ -1, -1 };
    std::cout << "[debug] Start main loop!\n";
    
    while (!IsGameOver() && !listener->OnExitRequested())
    {
        renderer->PrepareFrame();
        renderer->ClearScreen();
        std::cout << "[debug] New turn for " << currentPlayer->GetName() << "!\n";
        renderer->DrawBoard(board);
        // if (coord.x != -1 && coord.y != -1)
        // {
        //     renderer->PutText(0, 1, "Last move: (" + std::to_string(coord.x) + ", " + std::to_string(coord.y) + ")");
        // }
        renderer->PutText(1, 3 * CELL_SIZE + 10, currentPlayer->GetName() + "'s turn (" + currentPlayer->GetSymbol() + "): ");

        coord = currentPlayer->MakeMove(board);
        std::cout << "[debug] " << currentPlayer->GetName() << " chose move (" << coord.x << ", " << coord.y << ")\n";
        if(board.IsValidMove(coord.x, coord.y)){
            board.PlaceSymbol(coord.x, coord.y, currentPlayer->GetSymbol());
            
            // if (board.CheckWin(currentPlayer->GetSymbol()))
            // {
            //     renderer->ClearScreen();
            //     renderer->DrawBoard(board);
            //     std::cout << currentPlayer->GetName() << " wins!\n";
            //     return;
            // }
    
            // if (board.CheckDraw())
            // {
            //     renderer->ClearScreen();
            //     renderer->DrawBoard(board);
            //     std::cout << "Draw!\n";
            //     return;
            // }
    
            SwitchTurn();
        }
        renderer->Release();
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
