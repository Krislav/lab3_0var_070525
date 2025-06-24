#include "Person.h"

Person::Person() {
    id.number = 0;
    id.series = 0;
    name = "Unknown";
    middle_name = "Unknown";
    last_name = "Unknown";
}

Person::Person(PersonID id, std::string last_name, std::string name, std::string middle_name) {
    this->id = id;
    this->name = name;
    this->middle_name = middle_name;
    this->last_name = last_name;
}

Person::Person(const Person& another){
    this->id = another.id;
    this->name = another.name;
    this->middle_name = another.middle_name;
    this->last_name = another.last_name;
}

PersonID Person::GetID() const {
    return  id;
}

std::string Person::GetName() const {
    return name;
}

std::string Person::GetMiddleName() const {
    return middle_name;
}

std::string Person::GetLastName() const {
    return last_name;
}

std::string Person::GetFullName() const {
    return last_name + name + last_name;
}

void Person::ChangeID(PersonID id) {
    this->id = id;
}

void Person::ChangeName(std::string name) {
    this->name = name;
}

void Person::ChangeMiddleName(std::string middle_name) {
    this->middle_name = middle_name;
}

void Person::ChangeLastName(std::string last_name){
    this->last_name = last_name;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        this->id = other.id;
        this->name = other.name;
        this->middle_name = other.middle_name;
        this->last_name = other.last_name;
    }
    return *this;
}

bool Person::operator==(const Person& other) const {
    return id == other.id && 
           name == other.name &&
           middle_name == other.middle_name &&
           last_name == other.last_name;
}

bool Person::operator!=(const Person& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& is, Person& person) {
    std::cout << "Enter passport series: ";
    while (!(is >> person.id.series)) {
        std::cout << "Invalid input. Please enter a number: ";
    }

    std::cout << "Enter passport number: ";
    while (!(is >> person.id.number)) {
        std::cout << "Invalid input. Please enter a number: ";
    }
    is.ignore();

    std::cout << "Enter last name: ";
    std::getline(is, person.last_name);

    std::cout << "Enter first name: ";
    std::getline(is, person.name);

    std::cout << "Enter middle name: ";
    std::getline(is, person.middle_name);

    return is;
}