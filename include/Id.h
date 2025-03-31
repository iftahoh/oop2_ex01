#include <iostream>
#include "Functions.h"

class Id : public Functions {
public:
	Id();
	~Id();
	virtual void print() const override;
	virtual void run() const override;
	void printId(const SquaredMatrix matrix) const;
private:

};
