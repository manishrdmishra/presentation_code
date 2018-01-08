#include "person.h"

#include <algorithm>
#include <vector>
#include <iostream>

// non modiying sequence operations
int main()
{
    auto persons = create_persons();

    // using raw loops

    bool persone_above_50_found = false;

    for (auto it = persons.begin(); it != persons.end(); ++it)
    {
        if(it->age() > 50)
        {
            persone_above_50_found = true;
            break;
        }
    }

    std::cout<< "Is any person above age 50: "<< persone_above_50_found << "\n";

    auto person_above_age_50 = [](const Person& person) { return std::greater<int>()(person.age(), 50);};

    auto is_any_person_above_age_50 = exist_any_for(persons, person_above_age_50);
    std::cout<< "Is any person above age 50: "<< is_any_person_above_age_50 << "\n";

    auto person_above_age_20 = [](const Person& person) { return person.age() > 20; };
    auto are_all_of_above_age_20 = all_are_true_for(persons, person_above_age_20);
    std::cout<< "Are all persons above age 20: "<< are_all_of_above_age_20 << "\n";

    auto person_with_age_30 = std::find_if(persons.begin(), persons.end(), [](const Person& person)
                               {return person.age() == 30;});
    if(person_with_age_30 != persons.end())
    {
        std::cout<< "Name of person with age 30: " << person_with_age_30->first_name()
        << " " << person_with_age_30->last_name() << "\n";
    }

    auto female_count = std::count_if(persons.begin(), persons.end(), [](const Person& person)
                        {return person.gender() == Gender::Female;
                        });

    std::cout << "female count: " << female_count << "\n";

    return 0;
}
