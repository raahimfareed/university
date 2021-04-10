#include <iostream>

// Highest common factor recursive funciton
int hcf(int x, int y);

int main()
{
    // Variables
    int numOne, numTwo;

    // Take input from user
    std::cout << "Enter a number: ";
    std::cin >> numOne;
    std::cout << "Enter another number: ";
    std::cin >> numTwo;

    // Calculate hcf and output it to user
    std::cout << "HCF of " << numOne << " and " << numTwo << " is " << hcf(numOne, numTwo) << std::endl;
}

// HCF function Euclids algorithm
int hcf(int x, int y) {
    return (y == 0) ? x : hcf(y, x % y);
}