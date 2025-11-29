#include "Game.hpp"

#include "AI.hpp"
#include "Player.hpp"
#include "RaylibRenderer.hpp"
#include "RaylibListener.hpp"
#include "raylib.h"

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
    std::cout << "[debug] Starting a new game between " << player1->GetName() << " and " << player2->GetName() << "!\n";
    board.Reset();
    currentPlayer = player1.get();

    std::cout << "[debug] Init renderer!\n";

    std::shared_ptr<IRenderer> renderer = std::make_shared<RaylibRenderer>();
    renderer->Init();
    std::shared_ptr<IListener> listener = std::make_shared<RaylibListener>();

    std::cout << "[debug] Start main loop!\n";

    while (!IsGameOver() && !listener->OnExitRequested())
    {
        renderer->PrepareFrame();
        renderer->ClearScreen();

        renderer->DrawBoard(board);
        renderer->PutText(1, 3 * CELL_SIZE + 10, currentPlayer->GetName() + "'s turn (" + currentPlayer->GetSymbol() + "): ");

        Coord coord = currentPlayer->MakeMove(board);

        if (coord.x != -1 && coord.y != -1)
        {
            if (board.IsValidMove(coord.x, coord.y))
            {
                board.PlaceSymbol(coord.x, coord.y, currentPlayer->GetSymbol());

                if (!IsGameOver())
                {
                    SwitchTurn();
                }
            }
        }

        renderer->Release();
    }

    std::string finalMessage;
    Color messageColor = BLACK;
    int finalFontSize = 50;

    if (board.CheckWin(player1->GetSymbol()))
    {
        finalMessage = player1->GetName() + " A CASTIGAT!";
        messageColor = LIME;
    }
    else if (board.CheckWin(player2->GetSymbol()))
    {
        finalMessage = player2->GetName() + " A CASTIGAT!";
        messageColor = LIME;
    }
    else if (board.CheckDraw())
    {
        finalMessage = "EGALITATE! (DRAW)";
        messageColor = ORANGE;
    }
    else
    {
        return;
    }

    while (!listener->OnExitRequested())
    {
        renderer->PrepareFrame();
        renderer->DrawBoard(board);
        const int boxHeight = 150;
        const int boxY = 450;
        const int boxWidth = 800;

        DrawRectangle(0, boxY, boxWidth, boxHeight, Fade(DARKGRAY, 0.9f));
        int finalTextWidth = MeasureText(finalMessage.c_str(), finalFontSize);
        int xFinalPos = (boxWidth / 2) - (finalTextWidth / 2);

        const int messageY = boxY + 20;
        const int exitY = boxY + 90;
        DrawText(finalMessage.c_str(), xFinalPos, messageY, finalFontSize, messageColor);
        int exitTextWidth = MeasureText("Apasa ESC pentru a iesi.", 20);
        int xExitPos = (boxWidth / 2) - (exitTextWidth / 2);

        DrawText("Apasa ESC pentru a iesi.", xExitPos, exitY, 20, WHITE);

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
    std::cout << "Checking winner...\n";
}