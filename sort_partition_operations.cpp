#include "employee.h"

#include <algorithm>

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

    return 0;
}
