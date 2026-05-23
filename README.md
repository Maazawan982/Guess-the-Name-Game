# Guess the Name Game 🎯

A fun console-based C++ game that tries to guess your name using a grid selection method and frequency analysis.

## How It Works
- A 6x5 grid of alphabets (a-z) is displayed to the user
- User selects columns where each character of their name appears
- The program builds arrays from selected columns and rows
- Most frequent character in each array is picked as the guessed letter

## Features
- Choose between **lower case (a-z)** or **upper case (A-Z)** grid
- Interactive step-by-step input system
- Uses frequency analysis to guess each character of the name
- Built without any advanced STL — compatible with older compilers

## Tech Stack
- Language: C++
- Compiler: Dev-C++ (MinGW GCC)
- Concepts used: 2D Vectors, Maps, Sets, Iterators

## How to Run
1. Open `game.cpp` in Dev-C++ or any C++ compiler
2. Press `F9` to compile and run
3. Follow the on-screen instructions to play
