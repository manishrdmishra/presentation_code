#pragma once

#include "person.h"
#include <memory>
#include <vector>
#include <iostream>
#include <iterator>

enum class Department {DEVELOPMENT, FINANCE, HR};

enum class Designation {SOFTWARE_DEVELOPER, SOFTWARE_LEAD, ACCOUNTANT, MANAGER};

//*******************************************************************************
// Employee Interface
//*******************************************************************************

class Employee {
public:
    Employee();
    Employee(std::unique_ptr<Person> person, Department department,
        Designation designation, int salary);

        std::string name() const;
        std::string first_name() const { return person_->first_name(); }
        std::string last_name() const { return person_->last_name(); }
        int age() const { return person_->age(); };
        Gender gender() const { return person_->gender(); };

        Department department() const { return department_; };
        Designation designation() const { return designation_; };
        int salary() const { return salary_; };

        void set_department(Department department);
        void set_designation(Designation designation);
        void set_salary(int salary);

    private:
        std::shared_ptr<Person> person_{nullptr};
        Department department_{Department::DEVELOPMENT};
        Designation designation_{Designation::SOFTWARE_DEVELOPER};
        int salary_;
};

//*******************************************************************************
// Helper functions
//*******************************************************************************

std::vector<Employee> create_employees();

std::string to_string(Designation designation);
std::string to_string(Department department);

std::ostream& operator<<(std::ostream& out, const Employee& employee);

bool is_manager(const Employee& employee);
bool is_developer(const Employee& employee);

std::vector<Employee> managers(const std::vector<Employee>& employees);
std::vector<Employee> developers(const std::vector<Employee>& employees);

void print_employees(const std::vector<Employee>& employees);

//*******************************************************************************

template<typename ContainerType, typename Op>
std::vector<Employee> change_salary_by(const ContainerType& employees, Op op, int amount)
{
    std::vector<Employee> updated_employees;
    updated_employees.reserve(employees.size());

    std::transform(employees.begin(), employees.end(), std::back_inserter(updated_employees),
    [amount, op = op](const Employee& employee) -> Employee
    {
        auto result = op(employee.salary(), amount);
        Employee emp(employee);
        emp.set_salary(result);
        return emp;
    });

    return updated_employees;
}

//*******************************************************************************

template<typename ContainerType, typename Pred>
void remove_employee_if(ContainerType& employees, Pred pred)
{
    employees.erase(std::remove_if(employees.begin(), employees.end(), pred),
                    employees.end());
}

//*******************************************************************************

template<typename ContainerType, typename Pred>
std::pair<ContainerType, ContainerType> paritition_by(const ContainerType& employees, Pred pred)
{
    ContainerType first;
    ContainerType second;
    std::partition_copy(employees.begin(), employees.end(),
                        std::back_inserter(first), std::back_inserter(second), pred);
    return {first, second};
}

//*******************************************************************************
