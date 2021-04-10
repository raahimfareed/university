#include <iostream>

void reff(int &var);

int main()
{
    int var = 2;
    std::cout << "Variable: " << var << std::endl;
    reff(var);
    std::cout << "After the function the value is: " << var << std::endl;
}

void reff(int &var)
{
    var = 6;
}
