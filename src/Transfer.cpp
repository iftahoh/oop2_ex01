#include "Transfer.h"

Transfer::Transfer()
{
}

Transfer::~Transfer()
{
}

void Transfer::run() const
{
	int matrixSize;
	std::cin >> matrixSize;
	SquaredMatrix matrix(matrixSize);
	SquaredMatrix temp = matrix;
	for (int i = 0; i < matrix.getSize(); i++)
	{
		for (int j = 0; j < matrix.getSize(); j++)
		{
			matrix[i][j] = temp[j][i];
		}
	}
	std::cout << "tran (" << std::endl;
	printTransMatrix(temp);
	std::cout << ") = " << std::endl;
	printTransMatrix(matrix);
}

void Transfer::print() const
{
	std::cout << "Transfer" << std::endl;
}






