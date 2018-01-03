#include "person.h"

#include <algorithm>
#include <vector>
#include <iostream>

// non modiying sequence operations
int main()
{
    std::vector<Person> persons {
        {"foo_0", "bar_0", 40, Gender::MALE},
        {"foo_1", "bar_1", 30, Gender::MALE},
        {"foo_2", "bar_2", 25, Gender::FEMALE},
        {"foo_3", "bar_3", 50, Gender::FEMALE}
    };

    auto is_any_person_above_age_50 = std::any_of(persons.begin(),
                                    persons.end(),[](const Person& person)
                                    { return person.age() > 50; }
                                    );
    std::cout<< "Is any person above age 50: "<< is_any_person_above_age_50 << "\n";

    auto are_all_of_above_age_20 = std::all_of(persons.begin(),
                                    persons.end(),[](const Person& person)
                                    { return person.age() > 20; }
                                    );

    std::cout<< "Are all persons above age 20: "<< are_all_of_above_age_20 << "\n";

    auto person_with_age_30 = std::find_if(persons.begin(), persons.end(), [](const Person& person)
                               {return person.age() == 30;});
    if(person_with_age_30 != persons.end())
    {
        std::cout<< "Name of person with age 30: " << person_with_age_30->first_name()
        << " " << person_with_age_30->last_name() << "\n";
    }

    auto female_count = std::count_if(persons.begin(), persons.end(), [](const Person& person)
                        {return person.gender() == Gender::FEMALE;
                        });

    std::cout << "female count: " << female_count << "\n";

    return 0;
}
