#include <iostream>
#include <cmath>

class Quadrilateral
{
private:
    double sides[4];
    double angles[2];

public:
    void setSides()
    {
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Enter length of side " << i + 1 << ": ";
            std::cin >> sides[i];
        }
    }

    void setAngles()
    {
        for (int i = 0; i < 2; ++i)
        {
            std::cout << "Enter angle " << i + 1 << ": ";
            std::cin >> angles[i];
        }
    }

    void getSides() const
    {
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Side " << i + 1 << ": " << sides[i] << std::endl;
        }
    }

    void getAngles() const
    {
        for (int i = 0; i < 2; ++i)
        {
            std::cout << "Angle " << i + 1 << ": " << angles[i] << std::endl;
        }
    }

    double degToRad(double x) const
    {
        double pi = 2 * std::acos(0.0);
        return (pi / 180.0) * x;
    }

    double calculateArea() const
    {
        double angleSum = angles[0] + angles[1];
        angleSum = degToRad(angleSum);
        double s = calculateParameter() / 2.0;
        return std::sqrt(((s - sides[0]) * (s - sides[1]) * (s - sides[2]) * (s - sides[3])) - ((sides[0] * sides[1] * sides[2] * sides[3]) * std::pow(std::cos(angleSum / 2.0), 2)));
    }

    double calculateParameter() const
    {
        return sides[0] + sides[1] + sides[2] + sides[3];
    }

    void display() const
    {
        std::cout << "All values\n";
        getSides();
        getAngles();
        std::cout << "Parameter: " << calculateParameter() << std::endl;
        std::cout << "Area: " << calculateArea() << std::endl;
    }
};

int main()
{
    Quadrilateral Box;
    Box.setSides();
    Box.setAngles();
    Box.display();
}