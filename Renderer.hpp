#pragma once
#include <string>
#include <iostream>

#include "Board.hpp"
#include "IRenderer.hpp"

class Renderer: public IRenderer
{
public:
    Renderer();

    void Init() override;

    void ClearScreen() const override;

    void PutText(int x, int y, const std::string &text) const override;

    void PutBox(int x, int y, int width, int height) const override;
    void DrawBoard(const Board &board) const override;

    void PrepareFrame() const override;
    void Release() const override;
};
