#pragma once 

#include "Functions.h"

// The Comp class represents the composition of two matrix operations.
// Given two functions f and g, it applies them as f(g(matrix)).
class Comp : public Functions {
public:
    // Constructor: receives two function pointers and stores cloned copies.
    Comp(std::shared_ptr<Functions>& func1, std::shared_ptr<Functions>& fun2);

    // Destructor: no manual cleanup needed due to smart pointers.
    ~Comp();

    // Executes the composed function on the given matrix list.
    void run(std::vector<SquaredMatrix>& matrices) override;

    // Helper function that operates on a single matrix reference.
    void run1(SquaredMatrix& mat, std::vector<SquaredMatrix>& matrices) override;

    // Prints the composed function as (func2 -> func1).
    void print() const override;

    // Clones this composed function (used when copying operations).
    std::shared_ptr<Functions> clone() const override { return std::make_shared<Comp>(*this); }

private:
    // Stores the two function components that make up the composition.
    std::vector<std::shared_ptr<Functions>> m_compFunctions;
};
