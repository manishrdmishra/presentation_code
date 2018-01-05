#pragma once

#include <iostream>
#include <memory>
#include <exception>

struct Foo
{
    Foo() { std::cout << "Foo's constructor" << "\n"; }
    ~Foo() { std::cout<< "Foo's destructor"<< "\n"; }
};

class Bar
{
public:
    Bar()
    {
        number_ptr_ = new int;

        // If something fails in constructor then there is no way
        // to convey this failure to calling code, except throwing exception

        if(number_ptr_ == nullptr) throw std::runtime_error("Not enough memeory");
        *number_ptr_ = 0;
    }
    Bar(int a)
    {
        number_ptr_ = new int;
        if(number_ptr_ == nullptr) throw std::runtime_error("Not enough memeory");
        *number_ptr_ = a;

        std::cout << "Bar's constructor "<< "\n";
        std::cout<< "value : " << *number_ptr_ << "\n";
    }

    void setValue(int x) { *number_ptr_ = x;}
    ~Bar()
    {
        std::cout<<"Bar's destructor" << "\n";
        delete number_ptr_;
    }

private:
    int *number_ptr_{nullptr};

};
