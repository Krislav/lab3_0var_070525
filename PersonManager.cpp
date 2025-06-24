#pragma once
#include "PersonManager.h"
#include "Sequence\Errors.h"
#include <iostream>

std::vector<std::unique_ptr<Person>> persons;

void PrintPerson(const Person& person) {
    PersonID id = person.GetID();
    std::cout << "ID: " << id.series << " " << id.number
              << " | Name: " << person.GetLastName() << " " 
              << person.GetName() << " " << person.GetMiddleName();
}