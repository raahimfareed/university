#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    string regno;
    float CGPA;

public:
    Student()
    {
        cout << " the details of the student are" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << " enter name" << endl;
            cin >> name;
            cout << " enter age" << endl;
            cin >> age;
            cout << " enter regno" << endl;
            cin >> regno;
            cout << " enter cgpa" << endl;
            cin >> CGPA;
            cout << "******************" << endl;
        }
    }
    void show()
    {
        float max = 4.0;
        for (int i = 0; i < 3; i++)
        {
            if (CGPA = max)
            {
                cout << "NAme of student " << name << endl;
                cout << "Age of student " << age << endl;
                cout << "Registration number " << regno << endl;
            }
        }
    }

    float getCGPA()
    {
        return CGPA;
    }
};

void initStudents(Student s[])
{
    // For loop to enter students information in array
}

void searchStudents(Student s[])
{
    int highGpaIndex = 0;
    // For loop to search for student in the array.
    // Inside for loop, if (s[i].getCGPA() > s[highGpaIndex].getCGPA()) then { highGpaIndex = i }
    // outside for loop, cout information of s[highGpaIndex];
}

int main()
{
    Student s[5];
    initStudents(s);
    searchStudents(s);
}