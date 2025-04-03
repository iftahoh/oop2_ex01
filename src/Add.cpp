#include "Add.h"


//---------------------------------------------------------
Add::Add(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
	m_addFunctions.push_back(func1->clone());
	m_addFunctions.push_back(func2->clone());
	int numOfMatrix = func1->getNumOfMatrix() + func2->getNumOfMatrix();
	setNumOfMatrix(numOfMatrix);
}

//---------------------------------------------------------
Add::~Add()
{
}

//---------------------------------------------------------
void Add::run(std::vector<SquaredMatrix>& matrices) 
{
	print();
	m_addFunctions[0]->run1(matrices[0], matrices);
	m_addFunctions[1]->run1(matrices[1], matrices);
	SquaredMatrix resultMatrix(matrices[0].getSize());
	resultMatrix = matrices[0] + matrices[1];
	std::cout << " = " << std::endl;
	printTransMatrix(resultMatrix);
	setPrinted(false);
}

//---------------------------------------------------------
void Add::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
	if (ifPrinted() == false)
	{
		print();
		setPrinted(true);
	}
	m_addFunctions[0]->run1(matrices[0], matrices);
	m_addFunctions[1]->run1(matrices[1], matrices);
	if (ifPrinted() == false)
	{
		SquaredMatrix resultMatrix(matrices[0].getSize());
		resultMatrix = matrices[0] + matrices[1];
		std::cout << std::endl;
		std::cout << " = " << std::endl;
		printTransMatrix(resultMatrix);
		setPrinted(true);
	}
}

//---------------------------------------------------------
void Add::print() const
{	
	std::cout << "(";
	for (int index = 0; index < m_addFunctions.size(); index++)
	{
		m_addFunctions[index]->print();
		if (index != m_addFunctions.size() - 1)
		{
			std::cout << " + ";
		}
	}
	std::cout << ")";
}