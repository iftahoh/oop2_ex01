#include "Scal.h"

// Constructor: initializes the scalar value and sets the number of matrices to 1.
Scal::Scal(int scalar) : m_scalar(scalar)
{
    setNumOfMatrix(1); // Set the number of matrices required for this operation to 1
}

// Destructor: no special cleanup needed as smart pointers handle memory management.
Scal::~Scal()
{
}

// Executes the scalar multiplication operation on the matrix.
// Each element of the matrix is multiplied by the scalar.
void Scal::run(std::vector<SquaredMatrix>& matrices)
{
    SquaredMatrix temp = matrices[0]; // Create a temporary matrix to store the result

    // Multiply each element by the scalar value
    for (int row = 0; row < matrices[0].getSize(); row++)
    {
        for (int col = 0; col < matrices[0].getSize(); col++)
        {
            temp[row][col] = matrices[0][row][col] * m_scalar; // Multiply element by scalar
        }
    }

    // Print the operation result
    std::cout << "scal " << m_scalar << " (" << std::endl;
    printTransMatrix(matrices[0]);  // Print original matrix
    std::cout << ") = " << std::endl;
    matrices.push_back(temp); // Add the resulting matrix to the list
    printTransMatrix(temp); // Print the resulting matrix
}

// Helper version of run(): applies scalar multiplication in-place on a single matrix.
void Scal::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    SquaredMatrix scalMat = mat; // Create a copy of the matrix to store the result

    // Multiply each element by the scalar value
    for (int row = 0; row < mat.getSize(); row++)
    {
        for (int col = 0; col < mat.getSize(); col++)
        {
            scalMat[row][col] = mat[row][col] * m_scalar; // Multiply element by scalar
        }
    }

    // Print the result
    std::cout << "(" << std::endl;
    printTransMatrix(scalMat);  // Print the resulting matrix
    std::cout << ")";
    mat = scalMat; // Update the original matrix with the result
}

// Prints the scalar operation as "Scal {scalar}".
void Scal::print() const
{
    std::cout << "Scal " << m_scalar;
}
