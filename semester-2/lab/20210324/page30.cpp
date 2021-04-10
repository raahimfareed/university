#include <iostream>

class Arc
{
private:
    float mRadius;
    float mArcLength;
    float mAngle;

public:
    void mSetRadius(float);
    void mSetAngle(float);
    void mSetArcLength();

    void mDisplay() const
    {
        std::cout << "Arc Details\n"
                  << "Radius of Arc is " << mRadius << std::endl
                  << "Length of Arc is " << mArcLength << std::endl
                  << "Angle of the Arc is " <<  mAngle << std::endl;
    }
};

void Arc::mSetRadius(float r)
{
    mRadius = r;
}

void Arc::mSetAngle(float a)
{
    mAngle = a;
}

void Arc::mSetArcLength()
{
    std::cout << "Enter length of Arc: ";
    std::cin >> mArcLength;
}

int main()
{
    Arc object;
    // object.mRadius;
    object.mSetRadius(5.4);
    object.mSetAngle(12.2);
    object.mSetArcLength();
    object.mDisplay();
}