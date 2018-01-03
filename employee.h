#pragma once

#include "person.h"
#include <memory>
#include <vector>

enum class Department {DEVELOPMENT, FINANCE, HR};

enum class Designation {SOFTWARE_DEVELOPER, SOFTWARE_LEAD, ACCOUNTANT, MANAGER};

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

bool is_manager(const Employee& employee);
bool is_developer(const Employee& employee);

std::vector<Employee> managers(const std::vector<Employee>& employees);
std::vector<Employee> developers(const std::vector<Employee>& employees);

template<typename ContainerType, typename Op>
void change_salary_by(ContainerType& employees, int amount, Op op)
{
    std::transform(employees.begin(), employees.end(), std::back_inserter(employees),
    [amount, op](Employee& employee) -> Employee
    {
        auto result = op(employee.salary(), amount);
        employee.set_salary(result);
        return employee;
    });
}
