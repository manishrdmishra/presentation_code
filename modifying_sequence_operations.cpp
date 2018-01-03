#include "employee.h"

#include <iostream>
#include <vector>



int main()
{
    std::vector<Employee> employees;
    employees.reserve(5);

    employees.emplace_back(make_person("foo_0", "bar_0", 25, Gender::FEMALE),
                    Department::DEVELOPMENT, Designation::SOFTWARE_DEVELOPER, 40000);
    employees.emplace_back(make_person("foo_1", "bar_1", 20, Gender::FEMALE),
                    Department::DEVELOPMENT, Designation::SOFTWARE_DEVELOPER, 40000);
    employees.emplace_back(make_person("foo_2", "bar_2", 35, Gender::MALE),
                    Department::FINANCE, Designation::ACCOUNTANT, 30000);
    employees.emplace_back(make_person("foo_3", "bar_3", 55, Gender::MALE),
                    Department::DEVELOPMENT, Designation::SOFTWARE_DEVELOPER, 60000);
    employees.emplace_back(make_person("foo_4", "bar_4", 45, Gender::FEMALE),
                    Department::HR, Designation::MANAGER, 50000);


    std::vector<Employee> manager = managers(employees);

    std::cout<< "Number of managers: "<< manager.size() << "\n";

    change_salary_by(employees, 5000, std::plus<int>());

    std::cout << "salary : " << employees[0].salary() << "\n";

    return 0;
}
