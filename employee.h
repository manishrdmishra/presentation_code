#pragma once

#include "person.h"
#include <memory>

enum class Department {DEVELOPMENT, FINANCE, HR};

enum class Designation {SOFTWARE_DEVELOPER, SOFTWARE_LEAD, ACCOUNTANT, MANAGER};

class Employee {
public:
    Employee();
    Employee(std::unique_ptr<Person> person, Department department,
        Designation designation);

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
        std::unique_ptr<Person> person_{nullptr};
        Department department_{Department::DEVELOPMENT};
        Designation designation_{Designation::SOFTWARE_DEVELOPER};
        int salary_;
};
