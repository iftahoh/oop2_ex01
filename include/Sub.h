#pragma once
#include "Functions.h"
#include <iostream>

class Sub : public Functions {
public:
	Sub(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);
	~Sub();
	void run(std::vector<SquaredMatrix>& matrices)  override;
	void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Sub>(*this); }


private:
	std::vector<std::shared_ptr<Functions>> m_subFunctions;
};