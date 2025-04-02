#pragma once
#include "Functions.h"

class Scal : public Functions {
public:
	
	Scal(int scalar);
	~Scal();
	void run() const override;
	void print() const override;

private:
	int m_scalar;
};