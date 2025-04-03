#include "Sub.h"


//---------------------------------------------------------
Sub::Sub(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
	m_subFunctions.push_back(func1->clone());
	m_subFunctions.push_back(func2->clone());
	int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix();
	setNumOfMatrix(numOfMatrix);
}

//---------------------------------------------------------
Sub::~Sub()
{
}

//---------------------------------------------------------
void Sub::run(std::vector<SquaredMatrix>& matrices)
{
	print();
	m_subFunctions[0]->run1(matrices[0], matrices);
	m_subFunctions[1]->run1(matrices[1], matrices);
	SquaredMatrix resultMatrix(matrices[0].getSize());
	resultMatrix = matrices[0] - matrices[1];
	std::cout << " = " << std::endl;
	printTransMatrix(resultMatrix);
}

void Sub::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
	print();
	m_subFunctions[0]->run1(mat, matrices);
	m_subFunctions[1]->run1(mat, matrices);
	SquaredMatrix resultMatrix(matrices[0].getSize());
	resultMatrix = matrices[0] - matrices[1];
	std::cout << std::endl << " = " << std::endl;
	printTransMatrix(resultMatrix);
}

void Sub::print() const
{
	std::cout << "(";
	for (int index = 0; index < m_subFunctions.size(); index++)
	{
		m_subFunctions[index]->print();
		if (index != m_subFunctions.size() - 1)
		{
			std::cout << " - ";
		}
	}
	std::cout << ") ";
}


