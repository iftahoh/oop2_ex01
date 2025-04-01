#pragma once
#include <iostream>
#include "Functions.h"

class Transfer : public Functions {

public:
	Transfer();
	~Transfer();
	void run() const override;
	void print() const override;
private:
	
};