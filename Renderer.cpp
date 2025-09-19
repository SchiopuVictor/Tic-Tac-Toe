#include "Renderer.hpp"
#include <iostream>

void Renderer::Init() {
    std::cout << "Renderer initialized.\n";
}

void Renderer::SetBackgroundColor(int r, int g, int b) {
    std::cout << "Background color set to RGB("
              << r << "," << g << "," << b << ")\n";
}

void Renderer::SetForegroundColor(int r, int g, int b) {
    std::cout << "Foreground color set to RGB("
              << r << "," << g << "," << b << ")\n";
}

void Renderer::ClearScreen() {
    std::cout << "Screen cleared.\n";
}

void Renderer::PutText(int x, int y, char* text) {
    std::cout << "Text at (" << x << "," << y << "): " << text << "\n";
}

void Renderer::PutBox(int x, int y, int width, int height) {
    std::cout << "Box at (" << x << "," << y << ") size " 
              << width << "x" << height << "\n";
}

void Renderer::Draw() {
    std::cout << "Draw frame.\n";
}
