#pragma once

#include <string>
#include <algorithm>
#include <vector>

enum class Gender {MALE, FEMALE};

//*******************************************************************************
// Person Interface 
//*******************************************************************************

class Person
{
public:
    Person(std::string first_name = {},
        std::string last_name = {},
        int age = {},
        Gender gender = Gender::MALE);
        std::string first_name() const;
        std::string last_name() const;
        int age() const;
        Gender gender() const;
    private:
        std::string first_name_;
        std::string last_name_;
        int age_;
        Gender gender_;
};

//*******************************************************************************
// Helper functions
//*******************************************************************************

std::unique_ptr<Person>
 make_person(std::string first_name, std::string last_name,
            int age, Gender gender);

std::vector<Person> create_persons();

template<typename ContainerType, typename Pred>
bool exist_any_for(const ContainerType& c, const Pred pred)
{
    return std::any_of(std::begin(c), std::end(c), pred);
}

template<typename ContainerType, typename Pred>
bool all_are_true_for(const ContainerType& c, const Pred pred)
{
    return std::all_of(std::begin(c), std::end(c), pred);
}
