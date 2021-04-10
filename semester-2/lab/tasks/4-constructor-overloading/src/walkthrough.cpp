#include <iostream>
#include <string>


class Student
{
private:
    std::string mName;
    int mAge;

public:
    Student()
    {
        mSetName();
        mSetAge();
    }

    Student(std::string name, int age)
    : mName(name), mAge(age)
    {}

    void mSetName()
    {
        std::cout << "Please enter name: ";
        std::getline(std::cin, mName);
    }

    void mSetAge()
    {
        std::cout << "Enter age: ";
        std::cin >> mAge;
    }

    void mDisplay() const
    {
        std::cout << "\nName: " << mGetName()
                  << "\nAge: " << mGetAge() << '\n';
    }

    std::string mGetName() const
    {
        return mName;
    }

    int mGetAge() const
    {
        return mAge;
    }
};


int main()
{
    Student s1;
    Student s2("A", 17);
    s1.mDisplay();
    s2.mDisplay();

    Student s3 = s1;
    s3.mDisplay();
}
