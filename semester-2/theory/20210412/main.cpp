#include <iostream>
#include <string>


class Student
{
private:
    std::string mName;
    unsigned int mAge;

public:
    void mSetName()
    {
        std::getline(std::cin, mName);
    }

    void mSetAge()
    {
        std::cin >> mAge;
        std::cin.ignore();
    }

    void mDisplay()
    {
        std::cout << "Name: " << mName << std::endl
                  << "Age: " << mAge << std::endl;
    }
};


int main()
{
    Student students[3];

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Student " << i + 1 << std::endl;
        std::cout << "Enter name: ";
        students[i].mSetName();
        std::cout << "Enter Age: ";
        students[i].mSetAge();
        std::cout << std::endl;
    }

    std::cout << "Display\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Student " << i + 1 << std::endl;
        students[i].mDisplay();
        std::cout << std::endl;
    }

    std::cin.get();
}