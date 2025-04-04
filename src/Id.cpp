#include "Id.h"

// Constructor: sets the number of matrices required for this operation to 1.
Id::Id() {
    setNumOfMatrix(1); // This operation uses one matrix
}

// Destructor: no special cleanup needed as smart pointers handle memory management.
Id::~Id() {
}

// Prints the operation as "Id".
void Id::print() const
{
    std::cout << "Id";
}

// Executes the identity operation, which just prints the matrix as it is.
void Id::run(std::vector<SquaredMatrix>& matrices)
{
    printId(matrices[0]); // Prints the matrix as an identity operation (no change)
}

// Helper function for run(), prints the matrix in the format "Id (matrix) = matrix".
void Id::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    std::cout << "(" << std::endl;
    printTransMatrix(mat);  // Print the input matrix
    std::cout << ")";
}

// Prints the matrix with the "Id" label.
void Id::printId(const SquaredMatrix matrix) const
{
    std::cout << "Id (" << std::endl;
    matrix.print();  // Print the matrix
    std::cout << ") =" << std::endl;
    matrix.print();  // Print the matrix again as result (no modification)
}
