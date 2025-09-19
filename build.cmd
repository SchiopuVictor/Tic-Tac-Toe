@echo off

g++ -c Game.cpp -o Game.o
g++ -c Board.cpp -o Board.o
g++ -c Player.cpp -o Player.o
g++ -c Renderer.cpp -o Renderer.o
g++ -c AI.cpp -o AI.o
g++ -c main.cpp -o main.o

g++ Game.o Board.o Player.o Renderer.o AI.o main.o -o game.exe

echo Build finalizat! Executabilul este game.exe
pause
