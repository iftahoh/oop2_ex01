#include "Transfer.h"

Transfer::Transfer()
{
	setNumOfMatrix(1);
}

Transfer::~Transfer()
{
}

void Transfer::run(std::vector<SquaredMatrix>& matrices) const
{
	int matrixSize;
	std::cin >> matrixSize;
	SquaredMatrix matrix(matrixSize);
	SquaredMatrix transMatrix = matrix;
	for (int i = 0; i < matrix.getSize(); i++)
	{
		for (int j = 0; j < matrix.getSize(); j++)
		{
			transMatrix[i][j] = matrix[j][i];
		}
	}
	std::cout << "tran (" << std::endl;
	printTransMatrix(matrix);
	std::cout << ") = " << std::endl;
	printTransMatrix(transMatrix);
	matrices.push_back(transMatrix);

}

void Transfer::print() const
{
	std::cout << "Transfer";
}






