#pragma once
#include "SquaredMatrix.h"

// Abstract base class for different matrix operations (Add, Sub, Transfer, etc.)
class Functions {
public:
    // Constructor: Initializes member variables.
    Functions();
    // Destructor: Virtual to allow proper cleanup of derived class objects.
    virtual ~Functions();

    // Abstract methods to be implemented by derived classes:
    virtual void print() const = 0; // Prints the description of the operation
    virtual void run(std::vector<SquaredMatrix>& matrices) = 0; // Executes the operation on the matrices
    virtual void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) = 0; // Executes the operation on a single matrix

    // A method to print the matrix in a readable format
    virtual void printTransMatrix(const SquaredMatrix& matrix) const;

    // Clone method to create a copy of the current object
    virtual std::shared_ptr<Functions> clone() const = 0;

    // Sets the number of matrices required for the operation
    virtual void setNumOfMatrix(int num);

    // Gets the number of matrices required for the operation
    virtual int getNumOfMatrix() const;

    // Methods to track if the result has been printed
    bool ifPrinted();
    void setPrinted(bool printed);

private:
    int m_numOfMatrix; // Stores the number of matrices
    bool m_printed; // Tracks whether the result has been printed
};
