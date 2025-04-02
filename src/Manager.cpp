#include "Manager.h"
#include "Id.h"
#include "Transfer.h"
#include "Scal.h"
#include "Add.h"

//---------------------------------------------------------
Manager::Manager() {
	//default functions
	m_functions.push_back(std::make_shared<Id>());
	m_functions.push_back(std::make_shared<Transfer>());
}

//---------------------------------------------------------
Manager::~Manager() {
}

//---------------------------------------------------------
void Manager::run() 
{

	while (1)
	{
		//list of available matrix operations
		std::cout << "List of available matrix operations:" << std::endl;
		printCurrFunc();
		//list of functions
		std::cout << "Enter command ('help' for the list of available commands):" << std::endl;
		//get input from user until pressed enter
		std::string input;
		std::cin >> input;
		if (input == "eval")
		{
			int func;
			int matrixSize;
			std::cin >> func >> matrixSize;
			int numOfMatrix;
			numOfMatrix = m_functions[func]->getNumOfMatrix();
			m_functions[func]->run(m_matrices);
		}
		else if (input == "scal")
		{
			int scalar;
			std::cin >> scalar;
			m_functions.push_back(std::make_shared<Scal>(scalar));
		}
		else if (input == "add")
		{
			int func1, func2;
			std::cin >> func1 >> func2;
			m_functions.push_back(std::make_shared<Add>(m_functions[func1], m_functions[func2]));
		}
		else if (input == "sub")
		{
		}
		else if (input == "comp")
		{
				
		}
		else if (input == "del")
		{
			int func;
			std::cin >> func;
			if (func >= 0 && func < m_functions.size()) {
				m_functions.erase(m_functions.begin() + func);
			}
		}
		else if (input == "help")
		{
			std::cout << "The available commands are :" << std::endl;
			std::cout << "* eval(uate) num n - compute the result of operation #num on all needed n×n matrices(that will be prompted)" << std::endl;
			std::cout << "* scal(ar) val - creates an operation that multiplies the given matrix by scalar val" << std::endl;
			std::cout << "* add num1 num2 - creates an operation that is the addition of the result of operation #num1 and the result of operation #num2" << std::endl;
			std::cout << "* sub num1 num2 - creates an operation that is the subtraction of the result of operation #num1 and the result of operation #num2" << std::endl;
			std::cout << "* comp(osite) num1 num2 - creates an operation that is the composition of operation #num1 and operation #num2" << std::endl;
			std::cout << "* del(ete) num - delete operation #num from the operation list" << std::endl;
			std::cout << "* help - print this command list" << std::endl;
			std::cout << "* exit - exit the program" << std::endl;

		}
		else if (input == "exit")
		{
			std::cout << "Goodbye" << std::endl;
			break;
		}
	}
}

//---------------------------------------------------------
void Manager::printCurrFunc() const
{
	std::cout << "Current functions:" << std::endl;
	for (int i = 0; i < m_functions.size(); i++)
	{
		std::cout << i << ". ";
		m_functions[i]->print();
		std::cout << std::endl;
	}
}
