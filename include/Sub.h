#pragma once
#include "Functions.h"

class Sub : public Functions {
public:
    // Constructor: accepts two function objects and stores their clones.
    // The Sub class represents a subtraction operation on the results of these two functions.
    Sub(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);

    // Destructor: no special clean-up needed as smart pointers manage memory.
    ~Sub();

    // Run the subtraction operation on matrices.
    void run(std::vector<SquaredMatrix>& matrices)  override;

    // Run the subtraction operation on a single matrix.
    void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;

    // Print the operation in the form of "(func1 - func2)".
    void print() const override;

    // Create a clone of the current Sub object.
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Sub>(*this); }

private:
    // Vector to hold the two functions that will be used in the subtraction operation.
    std::vector<std::shared_ptr<Functions>> m_subFunctions;
};
