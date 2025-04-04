#pragma once
#include "Functions.h"

// The Scal class represents a scalar multiplication operation.
// It multiplies a matrix by a scalar value and stores the result.
class Scal : public Functions {
public:
    // Constructor: initializes the scalar value used for multiplication.
    Scal(int scalar);

    // Destructor: no special cleanup needed as smart pointers handle memory management.
    ~Scal();

    // Executes the scalar multiplication operation on the given matrices.
    void run(std::vector<SquaredMatrix>& matrices) override;

    // Helper version of run(): applies scalar multiplication in-place on a single matrix.
    void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices);

    // Prints the scalar multiplication operation as "Scal {scalar}".
    void print() const override;

    // Creates a clone of this Scal operation (used for copying or creating new instances).
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Scal>(*this); }

private:
    // The scalar value used to multiply the matrix.
    int m_scalar;
};
