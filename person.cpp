#include "person.h"

Person::Person(std::string first_name , std::string last_name ,
    int age, Gender gender)
    : first_name_{first_name}
    , last_name_{last_name}
    , age_{age}
    , gender_{gender}
    {}

std::string Person::first_name() const
{
    return first_name_;
}

std::string Person::last_name() const
{
    return last_name_;
}

int Person::age() const
{
    return age_;
}

Gender Person::gender() const
{
    return gender_;
}

//*******************************************************************************
// Helper functions
//*******************************************************************************

std::unique_ptr<Person> make_person(std::string first_name, std::string last_name,
    int age, Gender gender)
{
        return std::make_unique<Person>(first_name, last_name, age, gender);
}

//*******************************************************************************

std::vector<Person> create_persons()
{
    std::vector<Person> persons {
        {"foo_0", "bar_0", 40, Gender::Male},
        {"foo_1", "bar_1", 30, Gender::Male},
        {"foo_2", "bar_2", 25, Gender::Female},
        {"foo_3", "bar_3", 50, Gender::Female}
    };

    return persons;
}

//*******************************************************************************
