#include "Functions.h"

// Constructor: Initializes the member variables, setting `m_printed` to false and `m_numOfMatrix` to 0.
Functions::Functions() : m_printed(false) {
    m_numOfMatrix = 0;
}

// Destructor: No special cleanup is needed.
Functions::~Functions() {
}

// Prints the matrix to the standard output.
void Functions::printTransMatrix(const SquaredMatrix& matrix) const {
    for (int i = 0; i < matrix.getSize(); i++) {
        for (int j = 0; j < matrix.getSize(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Sets the number of matrices that the function requires.
void Functions::setNumOfMatrix(int num) {
    m_numOfMatrix = num;
}

// Returns the number of matrices that the function requires.
int Functions::getNumOfMatrix() const {
    return m_numOfMatrix;
}

// Returns whether the function has already been printed.
bool Functions::ifPrinted() {
    return m_printed;
}

// Sets whether the function has been printed.
void Functions::setPrinted(bool printed) {
    m_printed = printed;
}
