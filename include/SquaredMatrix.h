#include <iostream>
#include <vector>

class SquaredMatrix {
public:
	SquaredMatrix(int n);
	~SquaredMatrix();
	void print() const;
	//operators
	

	//SquaredMatrix(const SquaredMatrix& other);
	//SquaredMatrix& operator=(const SquaredMatrix& other);
	//int& operator()(int i, int j);
	//int operator()(int i, int j) const;
	//int size() const;
private:
	int m_n;
	std::vector<std::vector<int>> m_matrix;

	void setMatrix();
};