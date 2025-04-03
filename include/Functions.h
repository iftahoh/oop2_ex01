#pragma once
#include "SquaredMatrix.h"

class Functions {
public:
	Functions();
	 ~Functions();
	
	virtual void print() const = 0;
	virtual void run(std::vector<SquaredMatrix>& matrices)  = 0;
	virtual void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) = 0;
	virtual void printTransMatrix(const SquaredMatrix& matrix) const;
	virtual std::shared_ptr<Functions> clone() const = 0; // for clone
	virtual void setNumOfMatrix(int num);
	virtual int getNumOfMatrix() const;
	bool ifPrinted();
	void setPrinted(bool printed);

private:
	int m_numOfMatrix;
	bool m_printed;
};
