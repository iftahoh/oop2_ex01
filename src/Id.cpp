#pragma once
#include "Id.h"

//---------------------------------------------------------
Id::Id() {
	setNumOfMatrix(1);
}

//---------------------------------------------------------
Id::~Id() {
}

void Id::print() const
{
	std::cout << "Id";
}

void Id::run(std::vector<SquaredMatrix>& matrices) 
{
	printId(matrices[0]);
	
}

void Id::run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices)
{
	std::cout << "(" << std::endl;
	printTransMatrix(mat);
	std::cout << ")";
}

//---------------------------------------------------------

void Id::printId(const SquaredMatrix matrix) const
{
	std::cout << "Id (" << std::endl;
	matrix.print();
	std::cout << ") =" << std::endl;
	matrix.print();
}