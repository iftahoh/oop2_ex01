#pragma once
#include "Functions.h"

class Transfer : public Functions {

public:
	Transfer();
	~Transfer();
	void run(std::vector<SquaredMatrix>& matrices)  override;
	void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Transfer>(*this); }
private:
	
};