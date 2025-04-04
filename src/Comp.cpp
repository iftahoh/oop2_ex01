#include "Comp.h"


//---------------------------------------------------------
Comp::Comp(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
	m_compFunctions.push_back(func1->clone());
	m_compFunctions.push_back(func2->clone());
	int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix();
	setNumOfMatrix(numOfMatrix);
}

//---------------------------------------------------------
Comp::~Comp()
{
}

//---------------------------------------------------------
void Comp::run(std::vector<SquaredMatrix>& matrices)
{
	print();
	m_compFunctions[0]->run1(matrices[0], matrices);
	m_compFunctions[1]->run1(matrices[0], matrices);
	std::cout << " = " << std::endl;
	printTransMatrix(matrices[0]);
}

void Comp::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
	print();
	m_compFunctions[0]->run1(mat, matrices);
	m_compFunctions[1]->run1(mat, matrices);
	std::cout << std::endl;
	std::cout << " = " << std::endl;
	printTransMatrix(mat);
}

void Comp::print() const
{
	std::cout << "(";
	for (int index = 0; index < m_compFunctions.size(); index++)
	{
		m_compFunctions[index]->print();
		if (index != m_compFunctions.size() - 1)
		{
			std::cout << " -> ";
		}
	}
	std::cout << ") ";
}


