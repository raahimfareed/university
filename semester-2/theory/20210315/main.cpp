#include <iostream>

class Box
{
private:
    int length;
    int width;
    int height;

public:
    void setLength(int l)
    {
        length = l;
    }

    int getLength()
    {
        return length;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Box chakor;
    chakor.length = 20;
    chakor.width = 5;
    chakor.height = 12;

    std::cout << chakor.length << std::endl
              << chakor.width << std::endl
              << chakor.height << std::endl;
}
