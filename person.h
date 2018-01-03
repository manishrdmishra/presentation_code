#pragma once

#include <string>
enum class Gender {MALE, FEMALE};

// struct Name {
//     std::string first_name_{};
//     std::string last_name_;
// };

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

std::unique_ptr<Person>
 make_person(std::string first_name, std::string last_name,
            int age, Gender gender);
