#include "Functions.h"

//---------------------------------------------------------
Functions::Functions() : m_printed(false)
{
	m_numOfMatrix = 0;
}

//---------------------------------------------------------
Functions::~Functions()
{
}

//---------------------------------------------------------
void Functions::printTransMatrix(const SquaredMatrix& matrix) const
{	
	for (int i = 0; i < matrix.getSize(); i++)
	{
		for (int j = 0; j < matrix.getSize(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//---------------------------------------------------------
void Functions::setNumOfMatrix(int num)
{
	m_numOfMatrix = num;
}

//---------------------------------------------------------
int Functions::getNumOfMatrix() const
{
	return m_numOfMatrix;
}

//---------------------------------------------------------
bool Functions::ifPrinted()
{
	return m_printed;
}

//---------------------------------------------------------
void Functions::setPrinted(bool printed)
{
	m_printed = printed;
}