#include "Sub.h"

// Constructor: takes two functions and stores their clones to represent the subtraction of their results.
Sub::Sub(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
    m_subFunctions.push_back(func1->clone());  // Clone the first function
    m_subFunctions.push_back(func2->clone());  // Clone the second function
    int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix(); // Calculate total matrices required
    setNumOfMatrix(numOfMatrix);  // Set the total number of matrices
}

// Destructor: no special cleanup needed as smart pointers handle memory management.
Sub::~Sub()
{
}

// Executes the subtraction operation on two matrices.
void Sub::run(std::vector<SquaredMatrix>& matrices)
{
    print();  // Print the operation
    m_subFunctions[0]->run1(matrices[0], matrices);  // Run the first function
    m_subFunctions[1]->run1(matrices[1], matrices);  // Run the second function
    SquaredMatrix resultMatrix(matrices[0].getSize());  // Create a result matrix of the same size as the input
    resultMatrix = matrices[0] - matrices[1];  // Subtract the matrices
    std::cout << " = " << std::endl;
    printTransMatrix(resultMatrix);  // Print the result matrix
    setPrinted(false);  // Reset printed state
}

// Helper function for running the subtraction with a single matrix.
void Sub::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    if (ifPrinted() == false)
    {
        print();  // Print the operation once if it hasn't been printed yet
        setPrinted(true);
    }
    m_subFunctions[0]->run1(matrices[0], matrices);  // Run the first function
    m_subFunctions[1]->run1(matrices[1], matrices);  // Run the second function
    if (ifPrinted() == false)
    {
        SquaredMatrix resultMatrix(matrices[0].getSize());
        resultMatrix = matrices[0] - matrices[1];  // Perform subtraction
        std::cout << std::endl << " = " << std::endl;
        printTransMatrix(resultMatrix);  // Print the result matrix
    }
}

// Prints the operation as "(func1 - func2)".
void Sub::print() const
{
    std::cout << "(";
    for (int index = 0; index < m_subFunctions.size(); index++)
    {
        m_subFunctions[index]->print();  // Print each function in the subtraction
        if (index != m_subFunctions.size() - 1)
        {
            std::cout << " - ";  // Print the minus sign between the functions
        }
    }
    std::cout << ") ";
}
