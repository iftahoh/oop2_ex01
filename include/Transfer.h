#pragma once
#include <iostream>
#include "Functions.h"

class Transfer : public Functions {

public:
	Transfer();
	~Transfer();
	void run(std::vector<SquaredMatrix>& matrices) const override;
	void print() const override;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Transfer>(*this); }
private:
	
};