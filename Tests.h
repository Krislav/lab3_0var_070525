#pragma once
#include "Sequence\Errors.h"
#include "PersonManager.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

#include <iostream>
#include <string>

void TestResultPrint(int result_of_test, int test_group_number, int test_number);
void TestDeque();               //Test group 1
void TestStack();             //Test group 2
void TestQueue();             //Test group 3
void TestAll();
