#include <iostream>
#include <string>

class Vehicle
{
private:
    std::string mLicensePlate;
    int mModelNumber;
    std::string mType;

public:
    Vehicle(std::string licensePlate, int modelNumber, std::string type)
    : mLicensePlate(licensePlate), mModelNumber(modelNumber), mType(type)
    {}

    Vehicle() = default;

    void mSetLicensePlate()
    {
        std::cout << "Enter license plate number: ";
        std::getline(std::cin, mLicensePlate);
    }

    void mSetModelNumber()
    {
        std::cout << "Enter model number: ";
        std::cin >> mModelNumber;
    }

    void mSetType()
    {
        std::cout << "Enter license plate number: ";
        std::getline(std::cin, mType);
    }

    std::string mGetLicensePlate() const
    {
        return mLicensePlate;
    }

    int mGetModelNumber() const
    {
        return mModelNumber;
    }

    std::string mGetType() const
    {
        return mType;
    }

    void mRegisterVehicle()
    {
        mSetLicensePlate();
        mSetModelNumber();
        mSetType();
    }

    void mUpdateVehicle()
    {
        mSetLicensePlate();
        mSetModelNumber();
        mSetType();
    }

    void mDisplay() const
    {
        std::cout << "Type: " << mGetType() << std::endl
                  << "Model: " << mGetModelNumber() << std::endl
                  << "License Plate: " << mGetLicensePlate() << std::endl;
    }
};

int main()
{
    Vehicle deez("AB - 205", 2012, "NUTZ");
    deez.mDisplay();
}