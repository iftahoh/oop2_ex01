#include "SquaredMatrix.h"

//---------------------------------------------------------
SquaredMatrix::SquaredMatrix(int n) : m_n(n) {
	//creating matrix
	m_matrix.resize(m_n);
	for (int i = 0; i < m_n; i++) {
		m_matrix[i].resize(m_n);
	}
	//default values
	for (int i = 0; i < m_n; i++) {
		for (int j = 0; j < m_n; j++) {
			m_matrix[i][j] = 0;
		}
	}
	//reading data from user
	setMatrix();
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