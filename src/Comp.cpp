#include "Comp.h"

// Constructor: clones the two functions and stores them in the composition list.
// Calculates the number of required matrices (shared one matrix).
Comp::Comp(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
    m_compFunctions.push_back(func1->clone());
    m_compFunctions.push_back(func2->clone());
    int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix();
    setNumOfMatrix(numOfMatrix - 1); // one shared matrix is reused
}

// Destructor: nothing to do since smart pointers manage memory automatically.
Comp::~Comp()
{
}

// Executes the composed operation on the matrix list.
// Applies func2 first, then func1 on the result.
void Comp::run(std::vector<SquaredMatrix>& matrices)
{
    print(); // Print the composed operation name
    m_compFunctions[0]->run1(matrices[0], matrices); // Apply inner function (g)
    m_compFunctions[1]->run1(matrices[0], matrices); // Apply outer function (f)
    std::cout << " = " << std::endl;
    printTransMatrix(matrices[0]); // Print the final transformed matrix
    setPrinted(false); // Reset printed flag for next use
}

// A helper version of run() used when operating on a single matrix reference.
// This is used for recursive or nested function calls.
void Comp::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    if (ifPrinted() == false)
    {
        print();         // Print the operation name if not already printed
        setPrinted(true);
    }

    m_compFunctions[0]->run1(mat, matrices); // Apply inner function
    m_compFunctions[1]->run1(mat, matrices); // Apply outer function

    if (ifPrinted() == false)
    {
        std::cout << std::endl;
        std::cout << " = " << std::endl;
        printTransMatrix(mat);   // Show the result of the composed function
        setPrinted(true);
    }
}

// Prints the composed function in the format: (func2 -> func1)
void Comp::print() const
{
    std::cout << "(";
    for (int index = 0; index < m_compFunctions.size(); index++)
    {
        m_compFunctions[index]->print();
        if (index != m_compFunctions.size() - 1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << ")";
}
