#include "employee.h"

#include <iostream>
#include <vector>

int main()
{
    std::vector<Employee> employees{create_employees()};

    auto manager = managers(employees);

    std::cout<< "Number of managers: "<< manager.size() << "\n";

    auto updated_employees = change_salary_by(employees, std::plus<int>(), 5000);

    std::cout << "salary : " << updated_employees[0].salary() << "\n";

    auto employee_older_than_60 = [](const Employee& employee) { return employee.age() > 60; };
    remove_employee_if(employees, employee_older_than_60);

    std::cout << "New size of employees: " << employees.size() << "\n";
    print_employees(employees);

    return 0;
}
