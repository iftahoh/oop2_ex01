#include "Manager.h"
#include "Id.h"
//#include "Transfer.h"

//---------------------------------------------------------
Manager::Manager() {
	//default functions
	m_functions.push_back(std::make_shared<Id>());
	//m_functions = std::make_shared<Transfer>();
}

//---------------------------------------------------------
Manager::~Manager() {
}

//---------------------------------------------------------
void Manager::run() const
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
			int func, matrixSize;
			std::cin >> func;
			m_functions[func]->run();
		}
		else if (input == "scal")
		{
		}
		else if (input == "add")
		{
		}
		else if (input == "sub")
		{
		}
		else if (input == "comp")
		{
		}
		else if (input == "del")
		{
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
	}
}
