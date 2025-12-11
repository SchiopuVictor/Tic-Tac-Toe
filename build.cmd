@echo off
set CC=g++
set CFLAGS=-std=c++11 -Wall -Wextra -I.\raylib\include
set LDFLAGS=-L.\raylib\lib -lraylibdll -lopengl32 -lgdi32 -lwinmm
set OUTDIR=build
set OBJDIR=obj
set APPNAME=game.exe

if not exist %OUTDIR% mkdir %OUTDIR%
if not exist %OBJDIR% mkdir %OBJDIR%

echo Compiling source files...
%CC% %CFLAGS% -c Game.cpp -o %OBJDIR%\Game.o
%CC% %CFLAGS% -c Coord.cpp -o %OBJDIR%\Coord.o
%CC% %CFLAGS% -c Board.cpp -o %OBJDIR%\Board.o
%CC% %CFLAGS% -c RaylibListener.cpp -o %OBJDIR%\RaylibListener.o
%CC% %CFLAGS% -c Player.cpp -o %OBJDIR%\Player.o
%CC% %CFLAGS% -c AI.cpp -o %OBJDIR%\AI.o
%CC% %CFLAGS% -c main.cpp -o %OBJDIR%\main.o
%CC% %CFLAGS% -c RaylibRenderer.cpp -o %OBJDIR%\RaylibRenderer.o

echo Linking executable...
%CC% %OBJDIR%\Game.o %OBJDIR%\Coord.o %OBJDIR%\Board.o %OBJDIR%\Player.o %OBJDIR%\RaylibListener.o %OBJDIR%\AI.o %OBJDIR%\main.o %OBJDIR%\RaylibRenderer.o -o %OUTDIR%\%APPNAME% %LDFLAGS%

echo Copy of Raylib DLL...
copy .\raylib\lib\raylib.dll %OUTDIR%\raylib.dll

echo Build finalizat! Executabilul este %OUTDIR%\%APPNAME%
pause
