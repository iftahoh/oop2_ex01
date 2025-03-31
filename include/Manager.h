#include <iostream>
#include "Functions.h"
#include "SquaredMatrix.h"

class Manager {
public:
	Manager(); // add ID and TRANSFER as Default functions
	~Manager();

	void run() const;

private:
	std::string m_command;
	int m_func;
	int m_matrixSize;

	std::shared_ptr<Functions> m_functions;
};
