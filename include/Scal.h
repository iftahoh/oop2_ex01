#pragma once
#include "Functions.h"

class Scal : public Functions {
public:
	
	Scal(int scalar);
	~Scal();
	void run(std::vector<SquaredMatrix>& matrices)  override;
	void run1(SquaredMatrix& mat , std::vector<SquaredMatrix>& matrices);
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Scal>(*this); }


private:
	int m_scalar;
};