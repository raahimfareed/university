#include <iostream>

class Android_Device
{
private:
    int IMEIno;
    int Modelno;
    float Memory;
    std::string Type;
    std::string Make;
    std::string Operating_System;
public:
    void setImeiNo(int imei)
    {
        IMEIno = imei;
    }

    void setModelNo(int model)
    {
        Modelno = model;
    }

    void setMemory(float mem)
    {
        Memory = mem;
    }

    void setType(std::string t)
    {
        Type = t;
    }

    void setMake(std::string m)
    {
        Make = m;
    }

    void setOperatingSystem(std::string os)
    {
        Operating_System = os;
    }

    void display() const
    {
        std::cout << "IMEI Number = " << IMEIno
                  << "\nType = " << Type
                  << "\nMake = " << Make
                  << "\nModel Number = " << Modelno
                  << "\nMemory = " << Memory
                  << "\nOperating System = " << Operating_System
                  << std::endl;
    }
};

int main()
{
    Android_Device mobile;
    mobile.setImeiNo(123456789);
    mobile.setType("Tablet");
    mobile.setMake("Chuwi");
    mobile.setModelNo(9);
    mobile.setMemory(860.5f);
    mobile.setOperatingSystem("Android Ice Cream Sandwich 4.0.4");

    mobile.display();
}