#include <iostream>

class TestClass
{
private:
    int x;
    int y;
};

struct TestStruct
{
private:
    int x;
    int y;

public:
    TestStruct()
    {
        std::cout << "I'm a struct constructor\n";
    }
};


int main()
{
    TestStruct test;
}