#pragma once
#include "Board.hpp"
#include <iostream>
#include <memory>
#include <string>

class AI
{
public:
    std::string symbol;

    AI();
    explicit AI(const std::string &symbol);

    AI(const AI &other);
    AI &operator=(const AI &other);

    bool operator==(const AI &other) const;

    void MakeMove(const std::shared_ptr<Board> &board);
};

std::istream &operator>>(std::istream &in, AI &ai);
std::ostream &operator<<(std::ostream &out, const AI &ai);
