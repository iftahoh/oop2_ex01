#pragma once
#include "Functions.h"
#include "SquaredMatrix.h"

class Manager {
public:
    Manager();
    // Constructor: adds ID and TRANSFER as default functions

    ~Manager();
    // Destructor: currently does nothing (smart pointers manage memory)

    void run();
    // Main program loop: processes user commands and performs matrix operations

private:
    std::string m_command;
    // Stores the current command input from the user

    int m_func;
    // Used to store the index of the selected function

    int m_matrixSize;
    // Size (dimension) of the square matrices entered by the user

    std::vector<SquaredMatrix> m_matrices;
    // Temporary storage for matrices entered by the user

    std::vector<std::shared_ptr<Functions>> m_functions;
    // List of function objects that perform matrix operations

    void printCurrFunc() const;
    // Prints the list of current available functions

    void printNumOfMatrix(int num) const;
    // Prints a message asking the user how many matrices are required

    void inputMatrix(int numOfMatrix, int matricsSize);
    // Collects matrices from the user input

    void printHelp();
    // Prints a help message with the list of supported commands

    void printExit();
    // Prints an exit message before closing the program
};
