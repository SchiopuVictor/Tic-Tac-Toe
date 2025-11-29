#pragma once
#include "Board.hpp"
#include "IPLayer.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Game
{
    Board board;
    std::shared_ptr<IPLayer> player1;
    std::shared_ptr<IPLayer> player2;
    IPLayer *currentPlayer;

public:
    Game(const std::string &name1, const std::string &name2);

    void Start();

    // DECLARATII ADAUGATE / CORECTATE:
    void SwitchTurn();
    bool IsGameOver();
    void GetWinner();
};
