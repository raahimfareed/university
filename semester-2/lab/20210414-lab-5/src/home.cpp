#include <iostream>
#include <string>
using namespace std;
class Example
{
private:
    int a;
    int b;

public:
    Example()
    {
        a = 19;  //for example
        b = 10; //for example
    }
    Example(Example &parameter)
    {
        a = parameter.a;
        b = parameter.b;
    }
    void showAll()
    {
        cout << a << endl;
        cout << b << endl << endl;
    }
};
int main()
{
    Example obj;
    Example obj2(obj);
    obj.showAll();
    obj2.showAll();
}