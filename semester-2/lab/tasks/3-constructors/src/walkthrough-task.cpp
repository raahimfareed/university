#include <iostream>
#include <string>

class Pizza
{
private:
    int mSize;
    int mPrice;
    int mThickness;
    std::string mTopping;

public:
    Pizza()
    {
        mSetSize();
        mSetPrice();
        mSetThickness();
        std::cin.ignore();
        mSetTopping();
    }


    void mSetSize()
    {
        std::cout << "Enter size of pizza: ";
        std::cin >> mSize;
    }

    void mSetPrice()
    {
        std::cout << "Enter price of pizza: ";
        std::cin >> mPrice;
    }

    void mSetThickness()
    {
        std::cout << "Enter thickness of pizza: ";
        std::cin >> mThickness;
    }

    void mSetTopping()
    {
        std::cout << "Enter toppings of pizza: ";
        std::getline(std::cin, mTopping);
    }


    int mGetSize() const
    {
        return mSize;
    }

    int mGetPrice() const
    {
        return mPrice;
    }

    int mGetThickness() const
    {
        return mThickness;
    }

    std::string mGetTopping() const
    {
        return mTopping;
    }


    void mDisplay() const
    {
        std::cout << "The ordered pizza details are\n"
             << "Size: " << mGetSize() << std::endl
             << "Price: " << mGetPrice() << std::endl
             << "Topping: " << mGetTopping() << std::endl
             << "Thickness: " << mGetThickness() << std::endl;
    }
};

int main()
{
    Pizza deez;
    deez.mDisplay();
}