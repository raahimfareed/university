#include <iostream>

class Student
{
private:
    std::string mName;
    std::string mRegistrationNumber;
    unsigned int mAge;
    double mCgpa;

public:
    void mSetName()
    {
        std::cout << "Please enter name: ";
        std::getline(std::cin, mName);
    }

    void mSetRegistrationNumber()
    {
        std::cout << "Please enter registration number: ";
        std::getline(std::cin, mRegistrationNumber);
    }

    void mSetAge()
    {
        std::cout << "Please enter age: ";
        std::cin >> mAge;
        std::cin.ignore();
    }

    void mSetCgpa()
    {
        std::cout << "Please enter CGPA: ";
        std::cin >> mCgpa;
        std::cin.ignore();
    }

    double mGetCgpa() const
    {
        return mCgpa;
    }

    void mDisplay() const
    {
        std::cout << "Name: " << mName << std::endl
                  << "Reg Number: " << mRegistrationNumber << std::endl
                  << "Age: " << mAge << std::endl
                  << "CGPA: " << mCgpa << std::endl;
    }
};

void initStudents(Student students[]);

void highestScoringStudent(Student students[]);

int main()
{
    Student students[5];

    initStudents(students);
    highestScoringStudent(students);

    std::cout << "Press [Enter] key to exit the program.\n";
    std::cin.get();
}

void initStudents(Student students[])
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Student " << i + 1 << std::endl;
        students[i].mSetName();
        students[i].mSetRegistrationNumber();
        students[i].mSetAge();
        students[i].mSetCgpa();
    }
}

void highestScoringStudent(Student students[])
{
    int highestScorer = 0;
    for (int i = 1; i < 5; ++i)
    {
        if (students[i].mGetCgpa() > students[highestScorer].mGetCgpa())
        {
            highestScorer = i;
        }
    }

    std::cout << "Highest scoring student\n";
    students[highestScorer].mDisplay();
}
