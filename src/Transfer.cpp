#include "Transfer.h"

Transfer::Transfer()
{
	setNumOfMatrix(1);
}

Transfer::~Transfer()
{
}

void Transfer::run(std::vector<SquaredMatrix>& matrices) 
{
	
	SquaredMatrix transMatrix = matrices[0];
	for (int i = 0; i < matrices[0].getSize(); i++)
	{
		for (int j = 0; j < matrices[0].getSize(); j++)
		{
			transMatrix[i][j] = matrices[0][j][i];
		}
	}
	std::cout << "tran (" << std::endl;
	printTransMatrix(matrices[0]);
	std::cout << ") = " << std::endl;
	printTransMatrix(transMatrix);
	matrices.push_back(transMatrix);

}

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
	printTransMatrix(transMatrix);
	std::cout << ")";
	mat = transMatrix;
}

void Transfer::print() const
{
	std::cout << "Transfer";
}






