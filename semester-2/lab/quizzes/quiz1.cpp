#include <iostream>

struct Student
{
    std::string mFirstName;
    std::string mLastName;
    float mMarks;
    char mGrade;
};

void initStudents(Student students[]);
float calculateAverageMarks(Student students[]);
void displayStudents(Student students[]);
void calculateGrades(Student students[]);

const int gTotalStudents = 10;

int main()
{
    Student students[gTotalStudents];
    initStudents(students);
    displayStudents(students);
    calculateGrades(students);

    std::cout << "Press enter to exit the program\n";
    std::cin.get();
}

void initStudents(Student students[])
{
    for (int i = 0; i < gTotalStudents; ++i)
    {
        std::cout << "Student " << i + 1 << std::endl;

        std::cout << "Enter student first name: ";
        std::getline(std::cin, students[i].mFirstName);
        std::cout << "Enter student last name: ";
        std::getline(std::cin, students[i].mLastName);
        std::cout << "Enter student marks(0 - 100): ";
        std::cin >> students[i].mMarks;
        std::cin.ignore();
    }
}

float calculateAverageMarks(Student students[])
{
    float sum = 0;
    for (int i = 0; i < gTotalStudents; ++i)
    {
        sum += students[i].mMarks;
    }

    return sum / gTotalStudents;
}

void displayStudents(Student students[])
{
    float averageMarks = calculateAverageMarks(students);
    std::cout << "Students who have greater than average marks\n";
    std::cout << "First name\tLast Name\n";
    for (int i = 0; i < gTotalStudents; ++i)
    {
        if (students[i].mMarks > averageMarks)
        {
            std::cout << students[i].mFirstName << "\t\t"
                      << students[i].mLastName << '\n';
        }
    }
}

void calculateGrades(Student students[])
{
    std::cout << "Name\t\tGrade\n";
    for (int i = 0; i < gTotalStudents; ++i)
    {
        if (students[i].mMarks < 50)
        {
            students[i].mGrade = 'F';
        }
        else if (students[i].mMarks >= 50 && students[i].mMarks <= 57)
        {
            students[i].mGrade = 'D';
        }
        else if (students[i].mMarks >= 58 && students[i].mMarks <= 71)
        {
            students[i].mGrade = 'C';
        }
        else if (students[i].mMarks >= 72 && students[i].mMarks <= 85)
        {
            students[i].mGrade = 'B';
        }
        else
        {
            students[i].mGrade = 'A';
        }
        std::cout << students[i].mFirstName << "\t\t"
                  << students[i].mGrade << '\n';
    }
}

