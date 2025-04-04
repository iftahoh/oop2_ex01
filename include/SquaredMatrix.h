#pragma once
#include <iostream>
#include <vector>

class SquaredMatrix {
public:
    // Constructor: Initializes a square matrix of size n x n.
    SquaredMatrix(int n);

    // Destructor: Cleans up the matrix data.
    ~SquaredMatrix();

    // Prints the matrix elements.
    void print() const;

    // Returns the size (dimension) of the matrix.
    const int getSize() const;

    // Operators
    // Subscript operator to access matrix elements by row and column.
    const std::vector<int>& operator[](size_t index) const;
    std::vector<int>& operator[](size_t index);

private:
    int m_n;  // Matrix size (n x n)
    std::vector<std::vector<int>> m_matrix;  // 2D vector to store matrix data.

    // Private method to set matrix elements (not used directly in header).
    void setMatrix();
};

// Operator to add two matrices.
SquaredMatrix operator+(const SquaredMatrix& lhs, const SquaredMatrix& rhs);

// Operator to subtract two matrices.
SquaredMatrix operator-(const SquaredMatrix& lhs, const SquaredMatrix& rhs);
