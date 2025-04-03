#pragma once 

#include "Functions.h"

class Add : public Functions {
public:
	Add(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);
	~Add();
	void run(std::vector<SquaredMatrix>& matrices)  override;
	void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Add>(*this); }


private:
	std::vector<std::shared_ptr<Functions>> m_addFunctions;
};