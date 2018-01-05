#include <memory>
#include <cstring>
#include <iostream>
#include <mutex>

std::mutex m;

char* copy(char * source)
{
    auto len = strlen(source);
    auto destination_str_ptr = new char[len + 1];
    strcpy(destination_str_ptr, source);
    destination_str_ptr[len + 1] = '\0';
    return destination_str_ptr;
}

int critical_addition_exception_unsafe(int a, int b)
{
    m.lock();
    int c = a + b;
    //...
    // an exception here means the lock will never be released
    m.unlock();
    return c;
}

void divide_exception_unsafe(int a, int b)
{
    int *result_ptr = new int;
    *result_ptr = a/b;
    //...
    // an exception here means memory pointed by result_ptr will never be released
    delete result_ptr;
}

// tedious and verbose
void divide_exception_safe(int a, int b)
{
    int *result_ptr = new int;
    *result_ptr = a/b;
    try {
    //...
    }
    catch(std::exception& e) { delete result_ptr; throw; }
    delete result_ptr;
}

void use_file_exception_unsafe(const char* fn)
{
    FILE* f = fopen(fn,"w"); // open file fn
    // use f
    // an exception here means file will never closed
    fclose(f); // close file fn
}


int main()
{
    char source[] = "Hello World!";

    char *cloned = copy(source);
    std::cout << cloned << "\n";

    int a, b, c;

    std::cin >> a >> b;
    if(b == 0) throw std::runtime_error("division by zero is not defined");

    //*************************************************************************
    // exception here means cloned will never be deleted, which results in
    // memory leak
    //*************************************************************************

    c = a/b;

    std::cout << "you entered : " << a << ", " << b << "\n";
    std::cout << "result of division : " << c << "\n";

    auto addition_result = critical_addition_exception_unsafe(4, 5);

    divide_exception_unsafe(8, 2);

    delete cloned;
    return 0;
}
