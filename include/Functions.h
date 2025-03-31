#pragma once
#include <iostream>
#include "SquaredMatrix.h"

class Functions {
public:
	Functions();
	~Functions();
	
	virtual void print() const = 0;
	virtual void run() const = 0;
private:

};
