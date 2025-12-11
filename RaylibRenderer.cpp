#include "RaylibRenderer.hpp"
#include "raylib.h"

/**
 * @file RaylibRenderer.cpp
 * @brief Implementarea clasei RaylibRenderer pentru desenarea jocului Tic-Tac-Toe
 * Clasa RaylibRenderer implementează interfața IRenderer și gestionează
 * afișarea tablei de joc, a simbolurilor și a elementelor grafice
 * utilizând biblioteca Raylib.
 */

/**
 * @brief Constructorul clasei RaylibRenderer.
 */
RaylibRenderer::RaylibRenderer() {}

/**
 * @brief Destructorul clasei RaylibRenderer.
 *
 * Închide fereastra Raylib la distrugerea obiectului.
 */
RaylibRenderer::~RaylibRenderer()
{
    CloseWindow();
}

/**
 * @brief Inițializează fereastra și setările Raylib.
 */
void RaylibRenderer::Init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic-Tac-Toe");
    SetTargetFPS(60);
}

/**
 * @brief Șterge ecranul și îl umple cu culoarea de fundal.
 */
void RaylibRenderer::ClearScreen() const
{
    ClearBackground(RAYWHITE);
}

/**
 * @brief Desenează un text pe ecran.
 * @param x Coordonata x a textului
 * @param y Coordonata y a textului
 * @param text Textul de afișat
 */
void RaylibRenderer::PutText(int x, int y, const std::string &text) const
{
    DrawText(text.c_str(), x, y, 20, BLACK);
}

/**
 * @brief Desenează un dreptunghi (box) pe ecran.
 * @param x Coordonata x a colțului stânga-sus
 * @param y Coordonata y a colțului stânga-sus
 * @param width Lățimea dreptunghiului
 * @param height Înălțimea dreptunghiului
 */
void RaylibRenderer::PutBox(int x, int y, int width, int height) const
{
    DrawRectangle(x, y, width, height, LIGHTGRAY);
}

/**
 * @brief Desenează tabla de joc și simbolurile X și O.
 * @param board Tabla de joc curentă
 */
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

/**
 * @brief Pregătește frame-ul pentru desenare.
 */
void RaylibRenderer::PrepareFrame() const
{
    BeginDrawing();
}

/**
 * @brief Eliberează frame-ul curent după desenare.
 */
void RaylibRenderer::Release() const
{
    EndDrawing();
}
