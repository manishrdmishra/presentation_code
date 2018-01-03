#include "employee.h"

#include <functional>

Employee::Employee()
{}

Employee::Employee(std::unique_ptr<Person> person, Department department,
                    Designation designation, int salary)
: person_{std::move(person)}
, department_{department}
, designation_{designation}
, salary_{salary}
{}

std::string Employee::name() const
{
    return { person_->first_name() + " " + person_->last_name() };
}

void Employee::set_department(Department department)
{
    department_ = department;
}

void Employee::set_designation(Designation designation)
{
    designation_ = designation;
}

void Employee::set_salary(int salary)
{
    salary_ = salary;
}

bool is_manager(const Employee& employee)
{
    return employee.designation() == Designation::MANAGER;
}

bool is_developer(const Employee& employee)
{
    return employee.designation() == Designation::SOFTWARE_DEVELOPER;
}

std::vector<Employee> managers(const std::vector<Employee>& employees)
{
    std::vector<Employee> managers;

    std::copy_if(employees.begin(), employees.end(), std::back_inserter(managers),
        is_manager);
    return managers;
}
