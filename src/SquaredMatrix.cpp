#include "SquaredMatrix.h"

// Constructor: Initializes the matrix with size `n` and sets all elements to 0.
SquaredMatrix::SquaredMatrix(int n) : m_n(n) {
    m_matrix.resize(n, std::vector<int>(n, 0));
}

// Destructor: Cleans up the matrix data.
SquaredMatrix::~SquaredMatrix() {
    for (int i = 0; i < m_n; i++) {
        m_matrix[i].clear(); // Clear each row of the matrix
    }
    m_matrix.clear(); // Clear the entire matrix
}

// Prints the matrix to the standard output.
void SquaredMatrix::print() const {
    for (int i = 0; i < m_n; i++) {
        for (int j = 0; j < m_n; j++) {
            std::cout << m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Returns the size (dimension) of the matrix.
const int SquaredMatrix::getSize() const {
    return m_n;
}

// Reads matrix data from the user.
void SquaredMatrix::setMatrix() {
    std::cout << "Enter matrix elements: " << std::endl;
    for (int i = 0; i < m_n; i++) {
        for (int j = 0; j < m_n; j++) {
            std::cin >> m_matrix[i][j];
        }
    }
}

// Allows access to matrix elements via the subscript operator (`[]`).
const std::vector<int>& SquaredMatrix::operator[](size_t index) const {
    return m_matrix[index];
}

std::vector<int>& SquaredMatrix::operator[](size_t index) {
    return m_matrix[index];
}

// Matrix addition operator: Adds two matrices and returns the result.
SquaredMatrix operator+(const SquaredMatrix& lhs, const SquaredMatrix& rhs) {
    int size = lhs.getSize();
    SquaredMatrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    return result;
}

// Matrix subtraction operator: Subtracts two matrices and returns the result.
SquaredMatrix operator-(const SquaredMatrix& lhs, const SquaredMatrix& rhs) {
    int size = lhs.getSize();
    SquaredMatrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = lhs[i][j] - rhs[i][j];
        }
    }
    return result;
}
