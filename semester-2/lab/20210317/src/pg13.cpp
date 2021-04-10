#include <iostream>

int main()
{
    int x = 100;
    int *ptr;
    ptr = &x;
    *ptr = 150;

    std::cout << "Value of x is " << x
              << "\nAddress of x is " << &x
              << "\nData where ptr is pointing is " << *ptr
              << "\nAddress of ptr is " << &ptr
              << "\nAddress stored in the pointer is " << ptr
              << std::endl;

    return 0;
}