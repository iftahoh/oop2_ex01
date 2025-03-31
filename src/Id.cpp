#pragma once
#include "Id.h"

//---------------------------------------------------------
Id::Id() {
}

//---------------------------------------------------------
Id::~Id() {
}

void Id::print() const
{
	std::cout << "Id" << std::endl;
}

void Id::run() const
{
	int matrixSize;
	std::cin >> matrixSize;
	SquaredMatrix matrix(matrixSize);
	printId(matrix);
}

//---------------------------------------------------------

void Id::printId(const SquaredMatrix matrix) const
{
	std::cout << "Id (" << std::endl;
	matrix.print();
	std::cout << ") =" << std::endl;
	matrix.print();
}