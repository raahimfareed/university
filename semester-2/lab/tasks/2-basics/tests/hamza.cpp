#include<iostream>
#include<math.h>

class Quadrilateral
{
    int L1;
    int L2;
    int L3;
    int L4;
    int Ang1;
    int Ang2;
    int Area;
    int Perimeter;
    int s;

    public:

    void set_length1()
    {    
        std::cout<<"L1 : ";
        std::cin>>L1;
    }
    void set_length2()
    {
        std::cout<<"L2 : ";
        std::cin>>L2;

    }
    void set_length3()
    {
        std::cout<<"L3 : ";
        std::cin>>L3;

    }
    void set_length4()
    {
        std::cout<<"L4 : ";
        std::cin>>L4;

    }
    void set_angle1()
    {
        std::cout<<"insert angle 1 : "<<std::endl;
        std::cin>>Ang1;

    }
    void set_angle2()
    {

        std::cout<<"insert angle 2 : "<<std::endl;
        std::cin>>Ang2;

    }
    void get_length1()
    {    
        std::cout<<"Length 1 = "<<L1<<std::endl;
        
    }
    void get_length2()
    {    
        std::cout<<"Length 2 = "<<L2<<std::endl;
        
    }
    void get_length3()
    {    
        std::cout<<"Length 3 = "<<L3<<std::endl;
        
    }
    void get_length4()
    {    
        std::cout<<"Length 4 = "<<L4<<std::endl;
        
    }
    void get_angle1()
    {    
        std::cout<<"Angle 1 = "<<Ang1<<std::endl;
        
    }
    void get_angle2()
    {    
        std::cout<<"Angle 2 = "<<Ang2<<std::endl;
        
    }
    void perimeter()
    {
        Perimeter= (L1+L2+L3+L4);
    }
    void area()
    {
        
        long double theta = Ang1+Ang2;
        s = Perimeter/2;
        //Area = sqrt( (s-L1)(s-L2)(s-L3)(s-L4)- ((L1)(L2)(L3)(L4)*( std::cos*2 *((theta)/2))) );

    }
    void display()
    {
        
        std::cout<<"\t\t*++*Solution++ "<<L1<<std::endl;
        get_length1();
        get_length2();
        get_length3();
        get_length4();
        get_angle1();
        get_angle2();
        std::cout<<"Perimeter = "<<Perimeter<<std::endl;
        std::cout<<"Area = "<<Area<<std::endl;
    }
};

int main()
{
    Quadrilateral func;
    std::cout<<"Please Enter values of the following"<<std::endl;

    func.area();
    func.perimeter();
    func.display();

    return 0;
}