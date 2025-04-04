#include "Transfer.h"

// Constructor: sets the number of required matrices to 1,
// since transpose works on a single matrix.
Transfer::Transfer()
{
    setNumOfMatrix(1);
}

// Destructor: no manual memory handling needed.
Transfer::~Transfer()
{
}

// Executes the transpose operation:
// Transposes the first matrix in the list, prints the original and result,
// and then adds the transposed matrix to the list.
void Transfer::run(std::vector<SquaredMatrix>& matrices)
{
    SquaredMatrix transMatrix = matrices[0];

    for (int i = 0; i < matrices[0].getSize(); i++)
    {
        for (int j = 0; j < matrices[0].getSize(); j++)
        {
            transMatrix[i][j] = matrices[0][j][i]; // swap rows and columns
        }
    }

    std::cout << "tran (" << std::endl;
    printTransMatrix(matrices[0]); // print original matrix
    std::cout << ") = " << std::endl;
    printTransMatrix(transMatrix); // print transposed matrix

    matrices.push_back(transMatrix); // store result for future use
}

// A helper version of run() that works on a single matrix reference.
// Updates the matrix in-place to be its transpose.
void Transfer::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
    SquaredMatrix transMatrix = mat;

    for (int i = 0; i < mat.getSize(); i++)
    {
        for (int j = 0; j < mat.getSize(); j++)
        {
            transMatrix[i][j] = mat[j][i];
        }
    }

    std::cout << "(" << std::endl;
    printTransMatrix(transMatrix); // print the result
    std::cout << ")";

    mat = transMatrix; // replace the original with the transpose
}

// Prints the name of the operation.
void Transfer::print() const
{
    std::cout << "Transfer";
}
