#include <iostream>


class Student
{
private:
    std::string mName;
    unsigned int mAge;
    std::string mRegNumber;

public:
    Student(std::string name, std::string regNumber)
    : mName(name), mRegNumber(regNumber)
    {}

    void mSetAge()
    {
        std::cout << "Please enter student age: ";
        std::cin >> mAge;
        std::cin.ignore();
    }

    void mDisplay()
    {
        std::cout << "Student Information\n"
                  << "Name: " + mName + '\n'
                  << "Registration Number: " + mRegNumber + '\n'
                  << "Age: " << mAge << std::endl;
    }
};


int main()
{
    Student student("Raahim", "BSE203039");
    student.mSetAge();
    student.mDisplay();

    std::cout << "Press enter to exit the program\n";
    std::cin.get();
}