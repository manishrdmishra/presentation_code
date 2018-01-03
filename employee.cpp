#include "employee.h"

Employee::Employee()
{}

Employee::Employee(std::unique_ptr<Person> person, Department department,
                    Designation designation)
: person_{std::move(person)}
, department_{department}
, designation_{designation}
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
