#include "employee.h"

int main()
{
    auto employees = create_employees();

    auto salary_greater_than_50000 = [](const Employee& employee)
    {
        return std::greater<int>()(employee.salary(), 50000);
    };

    auto partitions = paritition_by(employees, salary_greater_than_50000);

    std::cout << "Number of employee's with salary_greater_than_50000 : " << partitions.first.size() << "\n";
    std::cout << "Number of employee's not with salary_greater_than_50000 : " << partitions.second.size() << "\n";

    auto less_name = [](const Employee& emp1, const Employee& emp2)
    {
        return emp1.name() < emp2.name();
    };

    std::sort(employees.begin(), employees.end(), less_name);

    print_employees(employees);

    return 0;
}
