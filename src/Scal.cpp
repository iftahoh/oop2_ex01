#include "Scal.h"

Scal::Scal(int scalar) : m_scalar(scalar)
{
	setNumOfMatrix(1);
}

//----------------------------------------------------------
Scal::~Scal()
{
}

//----------------------------------------------------------
void Scal::run(std::vector<SquaredMatrix>& matrices) 
{
	
	SquaredMatrix temp = matrices[0];
	for (int row = 0; row < matrices[0].getSize(); row++)
	{
		for (int col = 0; col < matrices[0].getSize(); col++)
		{
			temp[row][col] = matrices[0][row][col] * m_scalar;
		}
	}
	std::cout << "scal " << m_scalar << " (" << std::endl;
	printTransMatrix(matrices[0]);
	std::cout << ") = " << std::endl;
	matrices.push_back(temp);
	printTransMatrix(temp);
}

//----------------------------------------------------------
void Scal::run1(SquaredMatrix& mat , std::vector<SquaredMatrix>& matrices)
{
	SquaredMatrix scalMat = mat;
	for (int row = 0; row < mat.getSize(); row++)
	{
		for (int col = 0; col < mat.getSize(); col++)
		{
			scalMat[row][col] = mat[row][col] * m_scalar;
		}
	}
	std::cout << "(" << std::endl;
	printTransMatrix(scalMat);
	std::cout << ")";
	mat = scalMat;
}

//----------------------------------------------------------
void Scal::print() const
{
	std::cout << "Scal " << m_scalar;
}