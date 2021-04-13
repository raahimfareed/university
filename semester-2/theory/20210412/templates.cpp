#include <iostream>


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(char& a, char& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 3;

    std::cout << "a = " << a << "\nb = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << "\nb = " << b << std::endl;

    char c = 'y';
    char d = 'r';

    std::cout << "c = " << c << "\nd = " << d << std::endl;
    swap(c, d);
    std::cout << "c = " << c << "\nd = " << d << std::endl;
}