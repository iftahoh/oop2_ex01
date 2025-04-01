#pragma once
#include <iostream>
#include <vector>

class SquaredMatrix {
public:
	SquaredMatrix(int n);
	~SquaredMatrix();
	void print() const;
	const int getSize() const;

	//operators
	const std::vector<int>& operator[](size_t index) const;
	std::vector<int>& operator[](size_t index);
	//*scal
	//+
	//-

private:
	int m_n;
	std::vector<std::vector<int>> m_matrix;
	void setMatrix();
};