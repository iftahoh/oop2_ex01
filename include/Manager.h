#pragma once
#include <iostream>
#include "Functions.h"
#include "SquaredMatrix.h"

class Manager {
public:
	Manager(); // add ID and TRANSFER as Default functions
	~Manager();

	void run() ;

private:
	std::string m_command;
	int m_func;
	int m_matrixSize;

	std::vector<SquaredMatrix> m_matrices;
	std::vector<std::shared_ptr<Functions>> m_functions;
	void printCurrFunc() const;
	void printNumOfMatrix(int num) const;
	void inputMatrix(int numOfMatrix, int matricsSize);
	void printHelp();
};

