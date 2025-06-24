#pragma once
#include "Person.h"
#include <vector>
#include <memory>

extern std::vector<std::unique_ptr<Person>> persons;

void PrintPerson(const Person& person);