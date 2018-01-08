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

//*******************************************************************************
// Helper functions
//*******************************************************************************

bool is_manager(const Employee& employee)
{
    return employee.designation() == Designation::Manager;
}

//*******************************************************************************

bool is_developer(const Employee& employee)
{
    return employee.designation() == Designation::Developer;
}

//*******************************************************************************

std::vector<Employee> managers(const std::vector<Employee>& employees)
{
    std::vector<Employee> managers;

    std::copy_if(employees.begin(), employees.end(), std::back_inserter(managers),
        is_manager);
    return managers;
}

//*******************************************************************************

std::string to_string(Designation designation)
{
    switch (designation) {
        case Designation::Developer:
            return "Software Developer";
        case Designation::Lead:
            return "Software Lead";
        case Designation::Manager:
            return "Manager";
        case Designation::Accountant:
            return "Accountant";
    }
}

//*******************************************************************************

std::string to_string(Department department)
{
    switch (department) {
        case Department::Development:
            return "Development";
        case Department::Finance:
            return "Finance";
        case Department::HR:
            return "HR";
    }
}

//*******************************************************************************

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
    out << "Name : " << employee.name() << ", ";
    out << "Department : " << to_string(employee.department()) << ", ";
    out << "Designation : " << to_string(employee.designation()) << " ";
    return out;
}

//*******************************************************************************

std::vector<Employee> create_employees()
{
    std::vector<Employee> employees;
    employees.reserve(8);

    employees.emplace_back(make_person("foo_7", "bar_7", 35, Gender::Female),
                    Department::Development, Designation::Lead, 70000);
    employees.emplace_back(make_person("foo_6", "bar_6", 30, Gender::Male),
                    Department::Development, Designation::Developer, 60000);
    employees.emplace_back(make_person("foo_0", "bar_0", 25, Gender::Female),
                    Department::Development, Designation::Developer, 40000);
    employees.emplace_back(make_person("foo_1", "bar_1", 20, Gender::Female),
                    Department::Development, Designation::Developer, 40000);
    employees.emplace_back(make_person("foo_2", "bar_2", 35, Gender::Male),
                    Department::Finance, Designation::Accountant, 30000);
    employees.emplace_back(make_person("foo_3", "bar_3", 55, Gender::Male),
                    Department::Development, Designation::Developer, 60000);
    employees.emplace_back(make_person("foo_4", "bar_4", 45, Gender::Female),
                    Department::HR, Designation::Manager, 50000);
    employees.emplace_back(make_person("foo_5", "bar_5", 65, Gender::Male),
                    Department::HR, Designation::Manager, 80000);

    return employees;
}

//*******************************************************************************

void print_employees(const std::vector<Employee>& employees)
{
    std::copy(employees.begin(), employees.end(), std::ostream_iterator<Employee>(std::cout, "\n"));
}

//*******************************************************************************
