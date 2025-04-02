#include "Scal.h"



Scal::Scal(int scalar) : m_scalar(scalar)
{
	setNumOfMatrix(1);
}

Scal::~Scal()
{
}

void Scal::run(std::vector<SquaredMatrix>& matrices) const
{
	int matrixSize = 0;
	std::cin >> matrixSize;
	SquaredMatrix matrix(matrixSize);
	SquaredMatrix temp = matrix;
	for (int row = 0; row < matrix.getSize(); row++)
	{
		for (int col = 0; col < matrix.getSize(); col++)
		{
			temp[row][col] = matrix[row][col] * m_scalar;
		}
	}
	std::cout << "scal " << m_scalar << " (" << std::endl;
	printTransMatrix(matrix);
	std::cout << ") = " << std::endl;
	printTransMatrix(temp);

}

void Scal::print() const
{
	std::cout << "Scal " << m_scalar;
}



