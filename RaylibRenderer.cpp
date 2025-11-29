#include "RaylibRenderer.hpp"
#include "raylib.h"

RaylibRenderer::RaylibRenderer() {}
RaylibRenderer::~RaylibRenderer() {
    CloseWindow();
}

void RaylibRenderer::Init() {
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
    InitWindow(width, height, "Tic-Tac-Toe");
    SetTargetFPS(60);
}

void RaylibRenderer::ClearScreen() const {
    ClearBackground(RAYWHITE);
}

void RaylibRenderer::PutText(int x, int y, const std::string& text) const {
    DrawText(text.c_str(), x, y, 20, BLACK);
}
void RaylibRenderer::PutBox(int x, int y, int width, int height) const {
    DrawRectangle(x, y, width, height, LIGHTGRAY);
}
void RaylibRenderer::DrawBoard(const Board& board) const {
    ClearBackground(RAYWHITE);
    int width = board.GetWidth();
    int height = board.GetHeight();
    std::string boardStr = board.ToString();

    // draw grid
    for (int i = 1; i < width; ++i) {
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, height * CELL_SIZE, BLACK);
    }
    for (int i = 1; i < height; ++i) {
        DrawLine(0, i * CELL_SIZE, width * CELL_SIZE, i * CELL_SIZE, BLACK);
    }
    // place symbols
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int posX = x * CELL_SIZE;
            int posY = y * CELL_SIZE;
            char symbol = boardStr[y * width + x];
            if (symbol != ' ') {
                DrawText(std::string(1, symbol).c_str(), posX + CELL_SIZE / 2 - 10, posY + CELL_SIZE / 2 - 10, 40, BLACK);
            }
        }
    }
}

void RaylibRenderer::PrepareFrame() const {
    BeginDrawing();
}

void RaylibRenderer::Release() const {
    EndDrawing();
}