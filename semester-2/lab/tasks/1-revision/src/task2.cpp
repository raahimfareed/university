#include <iostream>

// Function with pass by reference for final exponent
void powerProduct(int expOne, int expTwo, int &finalExp)
{
    // Add both powers and assign to final exponent
    finalExp = expOne + expTwo;
}

int main()
{
    // Variables
    int baseOne,baseTwo, expOne, expTwo, finalExp;

    // Take input from user
    std::cout << "Enter base one: ";
    std::cin >> baseOne;
    std::cout << "Enter exponent one: ";
    std::cin >> expOne;
    std::cout << "Enter base two: ";
    std::cin >> baseTwo;
    std::cout << "Enter exponent two: ";
    std::cin >> expTwo;

    // Check if base is same, if so, show error and end program
    if (baseOne != baseTwo)
    {
        std::cout << "Bases do not match! Your bases need to match in order to find 2 power numbers\n";
        return 0;
    }

    // Add both powers with power product rule
    powerProduct(expOne, expTwo, finalExp);

    // Output final result
    std::cout << "Final exponent: " << finalExp << std::endl
              << "Mathematical Form: " << baseOne << "^" << finalExp << std::endl;

    // Stop program from closing, waits for enter key
    std::cin.get();
}