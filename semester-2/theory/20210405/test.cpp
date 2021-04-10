#include <iostream>
using namespace std;

class Test
{
public:
    ~Test()
    {
        cout << "This is a destructor\n";
    }

    ~Test(int a)
    {
        cout << a << std::endl;
    }
};


int main()
{
    Test obj;
}