#include "exception_example.h"

#include <iostream>
#include <memory>
#include <exception>


// in C++ automatic variables are scoped
void createFoo()
{
    Foo foo;
}


Bar divide(int a, int b)
{
    //*************************************************************************
    // If an exception occurs then, C++ calls destructors for all automatic objects
    // constructed since the beginning of the try block that is directly associated
    // with  that catch block.
    //*************************************************************************

    try
    {
        Foo f;

        if(b == 0) throw std::runtime_error("divide by zero");
        int result = a/b;  // if exception occurs here then Foo's destructor is called
        Bar b(result);
        //...              // if exception occurs here then both Foo's and Bar's destructors are called
        return b;
    }
    catch(std::exception& e)
    { std::cout << "exception occured due to : " << e.what() << "\n";}

    return {};
}

int main()
{
    createFoo();
    auto good_bar = divide(6,3);
    auto bad_bar = divide(3,0);
    return 0;
}
