#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class Passport
{
private:
    string top;
    string bottom;
public:
    void setTop()
    {
        while (true)
        {
            cout << "Enter top line of your passport: ";
            getline(cin, top);

            if (top.length() == 5)
            {
                break;
            }
            else
            {
                cout << "Top line needs to be 44 characters long.\n";
            }
        }
    }

    void checkTop()
    {
        for (int i = 0; i < 5; i++)
        {
            if (!isalnum(top[i]) || top[i] != '<')
            {
                cout << top[i] << " is not an alphanumerical.\n";
            }
        }
    }

    void setBottom()
    {
        while (true)
        {
            cout << "Enter bottom line of your passport: ";
            getline(cin, bottom);

            if (bottom.length() == 44)
            {
                break;
            }
            else
            {
                cout << "Bottom line needs to be 44 characters long.\n";
            }
        }
    }
};


int main()
{
    Passport p;
    p.setTop();
    p.checkTop();
}
