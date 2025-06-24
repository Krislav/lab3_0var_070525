#pragma once
#include <string>
#include <iostream>

struct PersonID{
    int series;
    int number;

    bool operator==(const PersonID& other) const {
        return series == other.series && number == other.number;
    }
    
    bool operator!=(const PersonID& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const PersonID& id) {
        return os << id.series << " " << id.number;
    }
};

class Person { 
private: 
    PersonID id; 
    std::string name; 
    std::string middle_name; 
    std::string last_name; 
public:
    Person();
    Person(PersonID id, std::string last_name, std::string name, std::string middle_name);
    Person(const Person& another);

    PersonID GetID() const; 
    std::string GetName() const;
    std::string GetMiddleName() const;
    std::string GetLastName() const; 
    std::string GetFullName() const;
    
    void ChangeID(PersonID id);
    void ChangeName(std::string name);
    void ChangeMiddleName(std::string middle_name);
    void ChangeLastName(std::string last_name);

    Person& operator=(const Person& other);
    bool operator==(const Person& other) const;
    bool operator!=(const Person& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.GetLastName() << " " 
           << person.GetName() << " " 
           << person.GetMiddleName()
           << " (ID: " << person.GetID() << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Person& person);
};