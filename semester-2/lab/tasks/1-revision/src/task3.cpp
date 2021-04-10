#include <iostream>
#include <string>

// structure for Course
struct Course
{
    // Unsigned integers because value will never be less than 0
    static unsigned int msCount;
    unsigned int mId;
    std::string mTitle;
    unsigned int mCreditHours;
};

// int count = 0;

// Used to keep track of total courses registered
unsigned int Course::msCount = 0;

// Function declarations
void menu();
void addCourse(Course courses[]);
void updateCourse(Course courses[]);
void deleteCourse(Course courses[]);
void searchCourse(Course courses[]);
void displayCourses(Course courses[]);

int main()
{
    // Variables
    int userChoice;
    Course courses[5];

    // Program main loop
    do
    {
        // Show menu to user and ask for input
        menu();
        std::cin >> userChoice;

        // Check user input and call function accordingly
        switch (userChoice)
        {
            case 1:
                addCourse(courses);
                break;
            case 2:
                updateCourse(courses);
                break;
            case 3:
                deleteCourse(courses);
                break;
            case 4:
                searchCourse(courses);
                break;
            case 5:
                displayCourses(courses);
                break;
            // Empty case so that default case is not triggered when the user selects 6 for exiting the program
            case 6: break;
            default:
                std::cout << "Invalid option! Choose again.\n\n";
        }
    // Keep loop running until user presses 6
    } while (userChoice != 6);
}

void menu()
{
    // All menu choices
    std::cout << "Menu\n"
              << "1) Add a course\n"
              << "2) Update a course\n"
              << "3) Delete a course\n"
              << "4) Search and display a course\n"
              << "5) Display all courses\n"
              << "6) Exit\n"
              << "[Your Choice]: ";
}

void addCourse(Course courses[])
{
    // Check if there is space for courses
    if (courses->msCount < 5)
    {
        std::cout << "Enter course ID in digits: ";
        std::cin >> courses[courses->msCount].mId;
        std::cin.ignore();

        std::cout << "Enter course title: ";
        std::getline(std::cin, courses[courses->msCount].mTitle);

        std::cout << "Enter course credit hours in digits: ";
        std::cin >> courses[courses->msCount].mCreditHours;

        // Increment total courses registered
        ++courses->msCount;

        std::cout << "Course added\n\n";
    }
    else
    {
        std::cout << "Course limit reached\n";
    }
}

void updateCourse(Course courses[])
{
    // Check if any courses are registered
    if (courses->msCount == 0)
    {
        std::cout << "No courses found\n\n";
        return;
    }

    int id;

    std::cout << "Enter ID of the course you want to update: ";
    std::cin >> id;

    bool foundCourse = false;

    // Search for course
    for (int i = 0; i < courses->msCount; ++i)
    {
        // Course found
        if (id == courses[i].mId)
        {
            foundCourse = true;

            std::cout << "Current id: " << courses[i].mId
                      << "\nEnter new id: ";
            std::cin >> courses[i].mId;
            std::cout << "Current title: " << courses[i].mTitle
                      << "\nEnter new title: ";
            std::cin >> courses[i].mTitle;
            std::cout << "Current credit hours: " << courses[i].mCreditHours
                      << "\nEnter new credit hours: ";
            std::cin >> courses[i].mCreditHours;
            break;
        }
    }

    // If course is not found
    if (!foundCourse)
    {
        std::cout << "Course with Id " << id << " was not found\n";
    }

}

void deleteCourse(Course courses[])
{
    // Check if any courses are registered
    if (courses->msCount == 0)
    {
        std::cout << "No courses found\n\n";
        return;
    }

    int tempId;

    std::cout << "Enter ID of the course you want to delete: ";
    std::cin >> tempId;

    bool foundCourse = false;

    // Search for course
    for (int i = 0; i < 5; ++i)
    {
        // Course found
        if (tempId == courses[i].mId)
        {
            foundCourse = true;
            // Decrease the total courses count
            --courses->msCount;

            // Assign last course to deleted course's position
            courses[i].mId = courses[courses->msCount].mId;
            courses[i].mTitle = courses[courses->msCount].mTitle;
            courses[i].mCreditHours = courses[courses->msCount].mCreditHours;

            std::cout << "Course deleted!\n";
            break;
        }
    }

    // If course not found
    if (!foundCourse)
    {
        std::cout << "Course with Id " << tempId << " was not found\n";
    }
}

void searchCourse(Course courses[])
{
    // If no courses registered
    if (courses->msCount == 0)
    {
        std::cout << "No courses found\n\n";
        return;
    }

    int id;

    std::cout << "Enter ID of the course you want to search: ";
    std::cin >> id;

    bool foundCourse = false;

    // Search for course
    for (int i = 0; i < courses->msCount; ++i)
    {
        // Course found
        if (id == courses[i].mId)
        {
            foundCourse = true;

            std::cout << "Course ID: " << courses[i].mId
                      << "\nCourse Title: " << courses[i].mTitle
                      << "\nCourse Credit Hours: " << courses[i].mCreditHours
                      << std::endl;

            break;
        }
    }

    // If course was not found
    if (!foundCourse)
    {
        std::cout << "Course with Id " << id << " was not found\n";
    }
}

void displayCourses(Course courses[])
{
    // If no courses are registered
    if (courses->msCount == 0)
    {
        std::cout << "No courses found\n\n";
        return;
    }

    // Display all courses
    std::cout << "Displaying all courses\n"
              << "Sr\tID\tTitle\t\tCredit Hours\n";

    for (int i = 0; i < courses->msCount; ++i)
    {
        std::cout << i + 1 << '\t' << courses[i].mId << '\t' << courses[i].mTitle << "\t\t" << courses[i].mCreditHours << std::endl;
    }

    std::cout << std::endl;
}
