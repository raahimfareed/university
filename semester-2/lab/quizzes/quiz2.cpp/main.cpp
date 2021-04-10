#include <iostream>
#include <ctime>
#include <string>


class Examination
{
private:
    int mDuration;
    int mCreditHours;
    std::string mCourseTitle;
    int mMonth;
    int mDay;
    int mYear;
    std::string mTime;

public:
    void mSetCourseTitle()
    {
        std::cout << "Please enter course title: ";
        std::getline(std::cin, mCourseTitle);
    }

    void mSetCreditHours()
    {
        std::cout << "Please enter credit hours: ";
        std::cin >> mCreditHours;
    }

    void mSetDuration()
    {
        std::cout << "Please enter duration: ";
        std::cin >> mDuration;
    }

    void mSetMonth(int month)
    {
        mMonth = month;
    }

    void mSetDay(int day)
    {
        mDay = day;
    }

    void mSetYear(int year)
    {
        mYear = year;
    }

    void mSetTime(std::string time)
    {
        mTime = time;
    }

    void mDisplay()
    {
        std::cout << "Examination details\n"
                  << "Title: " << mCourseTitle << std::endl
                  << "Credit Hours: " << mCreditHours << std::endl
                  << "Exam Duration: " << mDuration << std::endl
                  << "UTC Time: " << mYear << "-" << mMonth << "-" << mDay << " " << mTime << std::endl;
    }

    Examination()
    {
        mSetCourseTitle();
        mSetCreditHours();
        mSetDuration();

        time_t now = time(0);
        tm *localTime = localtime(&now);

        mSetYear(1900 + localTime -> tm_year);
        mSetMonth(1 + localTime -> tm_mon);
        mSetDay(localTime -> tm_mday);

        std::string time = std::to_string(5 + localTime -> tm_hour) + ":" + std::to_string(30 + localTime -> tm_min) + ":" + std::to_string(localTime -> tm_sec);
        mSetTime(time);
    }
};


int main()
{
    Examination subject;
    subject.mDisplay();
}