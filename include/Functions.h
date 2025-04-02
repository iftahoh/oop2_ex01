#pragma once
#include <iostream>
#include "SquaredMatrix.h"

class Functions {
public:
	Functions();
	 ~Functions();
	
	virtual void print() const = 0;
	virtual void run(std::vector<SquaredMatrix>& matrices) const = 0; 
	virtual void printTransMatrix(const SquaredMatrix& matrix) const;
	virtual std::shared_ptr<Functions> clone() const = 0; // for clone
private:

};
