#pragma once
#include <string>
#include <iostream>

#include "Board.hpp"

struct IRenderer
{
    virtual ~IRenderer() {}

    virtual void Init() = 0;

    virtual void ClearScreen() const = 0;

    virtual void PutText(int x, int y, const std::string &text) const = 0;
    virtual void PutBox(int x, int y, int width, int height) const = 0;

    virtual void DrawBoard(const Board &board) const = 0;

    virtual void PrepareFrame() const = 0;
    virtual void Release() const = 0;
};
