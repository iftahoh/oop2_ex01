#pragma once
#include "Functions.h"

// The Transfer class represents a matrix transpose operation.
// It inherits from the abstract base class Functions.
class Transfer : public Functions {
public:
    // Constructor: sets the number of matrices required to 1.
    Transfer();

    // Destructor: no special cleanup needed.
    ~Transfer();

    // Performs the transpose operation on the given matrix list.
    // The result is printed and added to the list.
    void run(std::vector<SquaredMatrix>& matrices) override;

    // A helper version of run(): applies the transpose in-place on a single matrix.
    void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;

    // Prints the name of the function (used in function listing).
    void print() const override;

    // Creates and returns a copy of this function object.
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Transfer>(*this); }

private:
    // No private members needed for this class.
};
