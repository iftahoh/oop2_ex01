#pragma once 

#include "Functions.h"

class Comp : public Functions {
public:
	Comp(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);
	~Comp();
	void run(std::vector<SquaredMatrix>& matrices)  override;
	void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Comp>(*this); }


private:
	std::vector<std::shared_ptr<Functions>> m_compFunctions;
};