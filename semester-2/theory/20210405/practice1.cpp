#include <iostream>


class Box
{
private:
    int mLength;
    int mWidth;
    int mHeight;

public:
    Box(int length, int width, int height)
    : mLength(length), mHeight(height), mWidth(width)
    {}

    void mDisplay()
    {
        std::cout << "Length: " << mLength << std::endl
                  << "Width: " << mWidth << std::endl
                  << "Height: " << mHeight << std::endl;
    }
};


int main()
{
    Box deez(5, 10, 15);
    deez.mDisplay();

    Box object = deez;
    object.mDisplay();
}
