@echo off
REM ============================================
REM Build script pentru testele logice Tic-Tac-Toe
REM ============================================

set CC=g++
set CFLAGS=-std=c++17 -Wall -Wextra -I. -I.\tests -DTEST_BUILD
set TESTDIR=tests
set OBJDIR=obj_tests
set TEST_RUNNER=test_runner.exe

if not exist %OBJDIR% mkdir %OBJDIR%

echo ============================================
echo Compilare Catch2 amalgamated...
%CC% %CFLAGS% -c %TESTDIR%\catch_amalgamated.cpp -o %OBJDIR%\catch_amalgamated.o

echo ============================================
echo Compilare fisiere sursa logica...
%CC% %CFLAGS% -c Coord.cpp -o %OBJDIR%\Coord.o
%CC% %CFLAGS% -c Board.cpp -o %OBJDIR%\Board.o
%CC% %CFLAGS% -c AI.cpp -o %OBJDIR%\AI.o

echo ============================================
echo Compilare fisiere de teste...
%CC% %CFLAGS% -c %TESTDIR%\test_AI.cpp -o %OBJDIR%\test_AI.o  
%CC% %CFLAGS% -c %TESTDIR%\test_Board.cpp -o %OBJDIR%\test_Board.o 

echo ============================================
echo Linking test runner...
%CC% %OBJDIR%\catch_amalgamated.o %OBJDIR%\test_AI.o %OBJDIR%\test_Board.o %OBJDIR%\Coord.o %OBJDIR%\Board.o  %OBJDIR%\AI.o -o %TESTDIR%\%TEST_RUNNER%

echo ============================================
echo Rulare teste...
cd %TESTDIR%
%TEST_RUNNER% -s --reporter console
cd ..

echo ============================================
echo Teste finalizate!
pause
