#include "SquaredMatrix.h"

//---------------------------------------------------------
SquaredMatrix::SquaredMatrix(int n) : m_n(n) {
	m_matrix.resize(n, std::vector<int>(n, 0));
}

//---------------------------------------------------------
SquaredMatrix::~SquaredMatrix() {
	//deleting matrix
	for (int i = 0; i < m_n; i++) {
		m_matrix[i].clear();
	}
	m_matrix.clear();
}

//---------------------------------------------------------
void SquaredMatrix::print() const {
	for (int i = 0; i < m_n; i++) {
		for (int j = 0; j < m_n; j++) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//---------------------------------------------------------
const int SquaredMatrix::getSize() const
{
	return m_n;
}

//---------------------------------------------------------
void SquaredMatrix::setMatrix() {
	//reading data from user
	std::cout << "Enter matrix elements: " << std::endl;
	for (int i = 0; i < m_n; i++) {
		for (int j = 0; j < m_n; j++) {
			std::cin >> m_matrix[i][j];
		}
	}
}

//---------------------------------------------------------
const std::vector<int>& SquaredMatrix::operator[](size_t index) const {
	return m_matrix[index];
}

//---------------------------------------------------------
std::vector<int>& SquaredMatrix::operator[](size_t index) {
	return m_matrix[index];
}

//---------------------------------------------------------
SquaredMatrix operator+(const SquaredMatrix& lhs, const SquaredMatrix& rhs)
{
	int size = lhs.getSize();
	SquaredMatrix result(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result[i][j] = lhs[i][j] + rhs[i][j];
		}
	}
	return result;
}
//---------------------------------------------------------
SquaredMatrix operator-(const SquaredMatrix& lhs, const SquaredMatrix& rhs)
{
	int size = lhs.getSize();
	SquaredMatrix result(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result[i][j] = lhs[i][j] - rhs[i][j];
		}
	}
	return result;
}
	
