#include "Renderer.hpp"
#include <iostream>
#include <cstdlib>

Renderer::Renderer() {}

void Renderer::Init()
{
    std::cout << "Renderer initialized.\n";
}

void Renderer::SetBackgroundColor(int r, int g, int b)
{
    std::cout << "Background color set to RGB("
              << r << "," << g << "," << b << ")\n";
}

void Renderer::SetForegroundColor(int r, int g, int b)
{
    std::cout << "Foreground color set to RGB("
              << r << "," << g << "," << b << ")\n";
}

void Renderer::ClearScreen() const
{
    system("cls||clear");
}

void Renderer::PutText(int x, int y, const std::string &text) const
{
    std::cout << "\n" << text << "\n";
}

void Renderer::PutBox(int x, int y, int width, int height) const
{
    std::cout << "Box at (" << x << "," << y << ") size "
              << width << "x" << height << "\n";
}

void Renderer::DrawBoard(const Board &board) const
{
    std::string boardStr = board.ToString();
    int width = board.GetWidth();
    int height = board.GetHeight();
    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            std::cout << boardStr[y * width + x];
        }
        std::cout << "\n";
    }
}
