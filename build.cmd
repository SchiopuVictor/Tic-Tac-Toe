@echo off
set CC=g++
set CFLAGS=-std=c++11 -Wall -Wextra -I.\raylib\include
set LDFLAGS=-L.\raylib\lib -lraylibdll -lopengl32 -lgdi32 -lwinmm
set OUTDIR=build
set OBJDIR=obj
set APPNAME=game.exe
echo Building %APPNAME%...

if not exist %OUTDIR% (
    mkdir %OUTDIR%
)
if not exist %OBJDIR% (
    mkdir %OBJDIR%
)

echo Compiling source files...
%CC% %CFLAGS% -c Game.cpp -o %OBJDIR%\Game.o
%CC% %CFLAGS% -c Coord.cpp -o %OBJDIR%\Coord.o
%CC% %CFLAGS% -c Board.cpp -o %OBJDIR%\Board.o
%CC% %CFLAGS% -c RaylibListener.cpp -o %OBJDIR%\RaylibListener.o
%CC% %CFLAGS% -c Player.cpp -o %OBJDIR%\Player.o
%CC% %CFLAGS% -c AI.cpp -o %OBJDIR%\AI.o
%CC% %CFLAGS% -c main.cpp -o %OBJDIR%\main.o

rem compile RaylibRenderer.cpp in separate dll
echo Compiling RaylibRenderer.cpp into DLL...
%CC% %CFLAGS% -c RaylibRenderer.cpp  -o %OBJDIR%\RaylibRenderer.o
%CC% -shared -o %OUTDIR%\RaylibRenderer.dll ^
    %OBJDIR%\RaylibRenderer.o ^
    %OBJDIR%\Board.o ^
    %LDFLAGS%

echo Linking object files...
%CC% %OBJDIR%\Game.o ^
        %OBJDIR%\Coord.o ^
        %OBJDIR%\Board.o ^
        %OBJDIR%\Player.o ^
        %OBJDIR%\RaylibListener.o ^
        %OBJDIR%\AI.o ^
        %OBJDIR%\main.o ^
    -o %OUTDIR%\%APPNAME% ^
    %LDFLAGS% ^
    -L.\build -lRaylibRenderer

echo Copy of Raylib DLL...
copy .\raylib\lib\raylib.dll %OUTDIR%\raylib.dll

echo Build finalizat! Executabilul este %OUTDIR%\%APPNAME%
pause
