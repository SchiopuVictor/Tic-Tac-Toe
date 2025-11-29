#pragma once

#include "IRenderer.hpp"
#include "defines.hpp"

class RaylibRenderer : public IRenderer
{
public:
    RaylibRenderer();
    ~RaylibRenderer() override;

    void Init() override;

    void ClearScreen() const override;

    void PutText(int x, int y, const std::string &text) const override;

    void PutBox(int x, int y, int width, int height) const override;

    void DrawBoard(const Board &board) const override;

    void PrepareFrame() const override;
    void Release() const override;
};