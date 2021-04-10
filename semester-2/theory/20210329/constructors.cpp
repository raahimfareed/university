#include <iostream>

class Box
{
public:
    Box()
    {
        std::cout << "I am a box\n";
    }


    Box()
    {
        std::cout << "I am not a box\n";
    }
};

int main()
{
    Box square;
}