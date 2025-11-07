#pragma once
#include <string>
#include <iostream>

#include "Board.hpp"

class Renderer
{
public:
    Renderer();

    void Init();

    void SetBackgroundColor(int r, int g, int b);
    void SetForegroundColor(int r, int g, int b);

    void ClearScreen() const;

    void PutText(int x, int y, const std::string &text) const;

    void PutBox(int x, int y, int width, int height) const;

    void DrawBoard(const Board &board) const;
};
