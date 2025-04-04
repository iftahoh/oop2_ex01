#pragma once 
#include "Functions.h"

// The Add class represents an addition operation on two matrix functions.
// It inherits from the abstract base class Functions and adds functionality
// to perform matrix addition based on two function results.
class Add : public Functions {
public:
    // Constructor: clones the two functions and stores them in the addition list.
    // It also calculates the number of required matrices.
    Add(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);

    // Destructor: no special cleanup needed, smart pointers handle memory management.
    ~Add();

    // Executes the addition operation on the given matrices.
    // The two functions are applied to their respective matrices, and then the results are added.
    void run(std::vector<SquaredMatrix>& matrices) override;

    // A helper version of run(), which works on a single matrix and applies the addition operation in-place.
    void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;

    // Prints the operation as "(func1 + func2)".
    void print() const override;

    // Creates a clone of this Add operation (used for copying or creating new instances).
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Add>(*this); }

private:
    // Stores the two function components that make up the addition operation.
    std::vector<std::shared_ptr<Functions>> m_addFunctions;
};
