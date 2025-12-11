#include "Renderer.hpp"
#include <iostream>
#include <cstdlib>

/**
 * @file Renderer.cpp
 * @brief Implementarea clasei Renderer pentru afișarea jocului Tic-Tac-Toe în consolă
 * Clasa Renderer permite afișarea tablei de joc, a simbolurilor și
 * a elementelor grafice simplificate în consola text.
 */

/**
 * @brief Constructorul clasei Renderer.
 */
Renderer::Renderer() {}

/**
 * @brief Inițializează renderer-ul.
 *
 * În această implementare doar afișează un mesaj de debug.
 */
void Renderer::Init()
{
    std::cout << "Renderer initialized.\n";
}

/**
 * @brief Șterge ecranul consolei.
 */
void Renderer::ClearScreen() const
{
    system("cls||clear");
}

/**
 * @brief Afișează un text pe ecran.
 * @param x Coordonata x (neutilizată în consolă)
 * @param y Coordonata y (neutilizată în consolă)
 * @param text Textul de afișat
 */
void Renderer::PutText(int x, int y, const std::string &text) const
{
    std::cout << "\n"
              << text << "\n";
}

/**
 * @brief Afișează un dreptunghi (box) în consolă.
 * @param x Coordonata x
 * @param y Coordonata y
 * @param width Lățimea dreptunghiului
 * @param height Înălțimea dreptunghiului
 */
void Renderer::PutBox(int x, int y, int width, int height) const
{
    std::cout << "Box at (" << x << "," << y << ") size "
              << width << "x" << height << "\n";
}

/**
 * @brief Afișează tabla de joc în consolă.
 * @param board Tabla curentă de joc
 */
void Renderer::DrawBoard(const Board &board) const
{
    std::string boardStr = board.ToString();
    int width = board.GetWidth();
    int height = board.GetHeight();
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            std::cout << boardStr[y * width + x];
        }
        std::cout << "\n";
    }
}

/**
 * @brief Pregătește frame-ul pentru desenare (gol în această implementare).
 */
void Renderer::PrepareFrame() const
{
}

/**
 * @brief Eliberează frame-ul curent după desenare (gol în această implementare).
 */
void Renderer::Release() const
{
}
