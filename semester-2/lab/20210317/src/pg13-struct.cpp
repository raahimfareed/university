#include <iostream>
#include <string>

struct Person
{
    std::string name;
    int age;
    float salary;
};

int main()
{
    Person p1;
    std::cout << "Please enter full name: ";
    std::getline(std::cin, p1.name);
    std::cout << "Enter age: ";
    std::cin >> p1.age;
    std::cout << "Enter salary: ";
    std::cin >> p1.salary;

    std::cout << "\nInformation"
              << "\nName: " << p1.name
              << "\nAge: " << p1.age
              << "\nSalary: " << p1.salary
              << std::endl;
}
