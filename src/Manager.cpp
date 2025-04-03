#include "Manager.h"
#include "Id.h"
#include "Transfer.h"
#include "Scal.h"
#include "Add.h"
#include "Sub.h"
#include "Comp.h"

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
		std::cout << std::endl << "List of available matrix operations:" << std::endl;
		printCurrFunc();
		//list of functions
		std::cout << "Enter command ('help' for the list of available commands): ";
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
			printNumOfMatrix(numOfMatrix);
			inputMatrix(numOfMatrix, matrixSize);
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
			int func1, func2;
			std::cin >> func1 >> func2;
			m_functions.push_back(std::make_shared<Sub>(m_functions[func1], m_functions[func2]));
		}
		else if (input == "comp")
		{
			int func1, func2;
			std::cin >> func1 >> func2;
			m_functions.push_back(std::make_shared<Comp>(m_functions[func1], m_functions[func2]));
				
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
			printHelp();
		}
		else if (input == "exit")
		{
			std::cout << "Goodbye" << std::endl;
			break;
		}
		m_matrices.clear(); // clear the matrices for the next operation
	}
}

//---------------------------------------------------------
void Manager::printCurrFunc() const
{
	for (int i = 0; i < m_functions.size(); i++)
	{
		std::cout << i << ". ";
		m_functions[i]->print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//---------------------------------------------------------
void Manager::printNumOfMatrix(int num) const
{	
	if (num > 1) {
		std::cout << "Please enter " << num << " matrices:" << std::endl;
	}
	return;
}

//---------------------------------------------------------
void Manager::inputMatrix(int numOfMatrix , int matricsSize)
{
	for (int i = 0; i < numOfMatrix; i++)
	{
		std::cout << "Enter " << matricsSize << "X" << matricsSize << " matrics element:" << std::endl;
		SquaredMatrix matrix(matricsSize);
		for (int i = 0; i < matrix.getSize(); i++) {
			for (int j = 0; j < matrix.getSize(); j++) {
				std::cin >> matrix[i][j];
			}
		}
		m_matrices.push_back(matrix);
	}
	return;
}

//---------------------------------------------------------
void Manager::printHelp()
{
	std::cout << "The available commands are :" << std::endl;
	std::cout << "* eval(uate) num n - compute the result of operation #num" << std::endl;
	std::cout << "  on all needed n×n matrices(that will be prompted)" << std::endl;
	std::cout << "* scal(ar) val - creates an operation that multiplies" << std::endl;
	std::cout << "  the given matrix by scalar val" << std::endl;
	std::cout << "* add num1 num2 - creates an operation that is the addition" << std::endl;
	std::cout << "  of the result of operation #num1 and the result of operation #num2" << std::endl;
	std::cout << "* sub num1 num2 - creates an operation that is the subtraction" << std::endl;
	std::cout << "  of the result of operation #num1 and the result of operation #num2" << std::endl;
	std::cout << "* comp(osite) num1 num2 - creates an operation that is the composition" << std::endl;
	std::cout << "  of operation #num1 and operation #num2" << std::endl;
	std::cout << "* del(ete) num - delete operation #num from the operation list" << std::endl;
	std::cout << "* help - print this command list" << std::endl;
	std::cout << "* exit - exit the program" << std::endl;
}
