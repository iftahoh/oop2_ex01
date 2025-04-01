#include "Functions.h"

//---------------------------------------------------------
Functions::Functions()
{
}

//---------------------------------------------------------
Functions::~Functions()
{
}

void Functions::printTransMatrix(const SquaredMatrix& matrix) const
{
	for (int i = 0; i < matrix.getSize(); i++)
	{
		for (int j = 0; j < matrix.getSize(); j++)
		{
			std::cout << matrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

