#include "Add.h"

// Constructor: clones the two functions and stores them in the addition list.
// It also calculates the number of required matrices.
Add::Add(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
    m_addFunctions.push_back(func1->clone());  // Clone func1
    m_addFunctions.push_back(func2->clone());  // Clone func2
    int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix();
    setNumOfMatrix(numOfMatrix);  // Set the number of matrices required for this operation
}

// Destructor: no special cleanup required since smart pointers manage the memory.
Add::~Add()
{
}

// Executes the addition operation: applies both functions to their respective matrices
// and then adds the results of the two matrices together.
void Add::run(std::vector<SquaredMatrix>& matrices)
{
    print(); // Print the operation
    m_addFunctions[0]->run1(matrices[0], matrices); // Apply the first function on matrix 0
    m_addFunctions[1]->run1(matrices[1], matrices); // Apply the second function on matrix 1

    // Perform matrix addition
    SquaredMatrix resultMatrix(matrices[0].getSize());
    resultMatrix = matrices[0] + matrices[1]; // Add matrices

    std::cout << " = " << std::endl;
    printTransMatrix(resultMatrix); // Print the result matrix
    setPrinted(false); // Reset printed flag for potential future operations
}

// Helper version of run(): applies the addition on matrices in-place and prints the result.
void Add::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    if (ifPrinted() == false)
    {
        print(); // Print the operation if not already printed
        setPrinted(true);
    }

    // Apply both functions to the matrices
    m_addFunctions[0]->run1(matrices[0], matrices);
    m_addFunctions[1]->run1(matrices[1], matrices);

    if (ifPrinted() == false)
    {
        // Perform matrix addition and print the result
        SquaredMatrix resultMatrix(matrices[0].getSize());
        resultMatrix = matrices[0] + matrices[1];
        std::cout << std::endl;
        std::cout << " = " << std::endl;
        printTransMatrix(resultMatrix); // Print the result matrix
        setPrinted(true);
    }
}

// Prints the addition operation in the form: (func1 + func2).
void Add::print() const
{
    std::cout << "(";
    for (int index = 0; index < m_addFunctions.size(); index++)
    {
        m_addFunctions[index]->print();  // Print each function in the addition list
        if (index != m_addFunctions.size() - 1)
        {
            std::cout << " + ";  // Print "+" between functions
        }
    }
    std::cout << ")";
}
