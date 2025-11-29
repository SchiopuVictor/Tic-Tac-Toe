#include "RaylibRenderer.hpp"
#include "raylib.h"

RaylibRenderer::RaylibRenderer() {}

RaylibRenderer::~RaylibRenderer()
{
    CloseWindow();
}

void RaylibRenderer::Init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic-Tac-Toe");
    SetTargetFPS(60);
}

void RaylibRenderer::ClearScreen() const
{
    ClearBackground(RAYWHITE);
}

void RaylibRenderer::PutText(int x, int y, const std::string &text) const
{
    DrawText(text.c_str(), x, y, 20, BLACK);
}

void RaylibRenderer::PutBox(int x, int y, int width, int height) const
{
    DrawRectangle(x, y, width, height, LIGHTGRAY);
}

void RaylibRenderer::DrawBoard(const Board &board) const
{
    ClearBackground(RAYWHITE);

    int width = board.GetWidth();
    int height = board.GetHeight();

    for (int i = 1; i < width; ++i)
    {
        DrawLineEx(
            Vector2{(float)(i * CELL_SIZE), 0},
            Vector2{(float)(i * CELL_SIZE), (float)(height * CELL_SIZE)},
            3, BLACK);
    }

    for (int i = 1; i < height; ++i)
    {
        DrawLineEx(
            Vector2{0, (float)(i * CELL_SIZE)},
            Vector2{(float)(width * CELL_SIZE), (float)(i * CELL_SIZE)},
            3, BLACK);
    }

    // --- Draw X and O symbols ---
    std::string boardStr = board.ToString();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {

            char symbol = boardStr[y * width + x];
            if (symbol == ' ')
                continue;

            int posX = x * CELL_SIZE;
            int posY = y * CELL_SIZE;
            int centerX = posX + CELL_SIZE / 2;
            int centerY = posY + CELL_SIZE / 2;

            int padding = 20;

            if (symbol == 'X')
            {
                DrawLineEx(
                    Vector2{(float)(posX + padding), (float)(posY + padding)},
                    Vector2{(float)(posX + CELL_SIZE - padding), (float)(posY + CELL_SIZE - padding)},
                    5, RED);
                DrawLineEx(
                    Vector2{(float)(posX + CELL_SIZE - padding), (float)(posY + padding)},
                    Vector2{(float)(posX + padding), (float)(posY + CELL_SIZE - padding)},
                    5, RED);
            }
            else if (symbol == 'O')
            {
                DrawCircleLines(centerX, centerY, CELL_SIZE / 2 - padding, BLUE);
            }
        }
    }
}

void RaylibRenderer::PrepareFrame() const
{
    BeginDrawing();
}

void RaylibRenderer::Release() const
{
    EndDrawing();
}
