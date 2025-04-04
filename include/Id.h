#pragma once
#include "Functions.h"

// The Id class represents an identity operation on a matrix.
// It doesn't modify the matrix, simply prints it as the identity operation.
class Id : public Functions {
public:
    // Constructor: initializes the identity operation, which uses one matrix.
    Id();

    // Destructor: no special cleanup needed as smart pointers handle memory management.
    ~Id();

    // Prints the operation as "Id".
    virtual void print() const override;

    // Executes the identity operation on the given matrices.
    virtual void run(std::vector<SquaredMatrix>& matrices) override;

    // Helper function to print the matrix with the "Id" label and its content.
    virtual void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;

    // Prints the matrix with the label "Id" and shows the matrix content.
    void printId(const SquaredMatrix matrix) const;

    // Creates a clone of this Id operation (used for copying or creating new instances).
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Id>(*this); }

private:
    // No additional private members for this class
};
