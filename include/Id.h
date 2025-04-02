#include <iostream>
#include "Functions.h"

class Id : public Functions {
public:
	Id();
	~Id();
	virtual void print() const override;
	virtual void run(std::vector<SquaredMatrix>& matrices) const override;
	void printId(const SquaredMatrix matrix) const;
	std::shared_ptr<Functions> clone() const override { return std::make_shared<Id>(*this); }
private:

};
