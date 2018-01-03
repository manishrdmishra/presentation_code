#include "employee.h"
#include <iostream>

int main()
{
    Employee employee(make_person("foo_0", "bar_0", 25, Gender::FEMALE),
                    Department::DEVELOPMENT, Designation::SOFTWARE_DEVELOPER);

    std::cout << "employee name : " << employee.name() << "\n";
    return 0;
}
