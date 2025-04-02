#include "Add.h"
#include "Add.h"

//---------------------------------------------------------
Add::Add(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& func2)
{
	m_addFunctions.push_back(func1->clone());
	m_addFunctions.push_back(func2->clone());
}

//---------------------------------------------------------
Add::~Add()
{
}

//---------------------------------------------------------
void Add::run(std::vector<SquaredMatrix>& matrices) const
{
	m_addFunctions[0]->run(matrices);
	m_addFunctions[1]->run(matrices);

}

void Add::print() const
{
	for (int index = 0; index < m_addFunctions.size(); index++)
	{
		m_addFunctions[index]->print();
		if (index != m_addFunctions.size() - 1)
		{
			std::cout << " + ";
		}
	}
}
