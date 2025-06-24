#include "Tests.h"

void TestResultPrint(int result_of_test, int test_group_number, int test_number){
    switch (result_of_test)
    {
    case 0:
        std::cout << "Test " << test_group_number << "." << test_number << " passed [O]\n";
        break;
    case 1:
        std::cout << "Test " << test_group_number << "." << test_number << " failed [X]\n";
        break;
    case 2:
        std::cout << "Test " << test_group_number << "." << test_number << " ended with unexpected error [?]\n";
        break;
    default:
        std::cout << "Test " << test_group_number << "." << test_number << " uncorrect\n";
        break;
    }
}

void TestDeque() { //GROUP 1
    int test_group_number = 1;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 1.1 Проверка создания пустого дека
    Deque<int> deque11;
    try {
        if (!deque11.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.2 Проверка PushFront и Front
    try {
        deque11.PushFront(10);
        if (deque11.Front() != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.3 Проверка PushBack и Back
    try {
        deque11.PushBack(20);
        if (deque11.Back() != 20) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.4 Проверка PopFront
    try {
        deque11.PopFront();
        if (deque11.Front() != 20) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 1.5 Проверка PopBack
    try {
        deque11.PopBack();
        if (!deque11.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.6 Проверка ошибки Front для пустого дека
    try {
        deque11.Front();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 1.7 Проверка ошибки Back для пустого дека
    try {
        deque11.Back();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestStack() { //GROUP 2
    int test_group_number = 2;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 2.1 Проверка создания пустого стека
    Stack<int> stack21;
    try {
        if (!stack21.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.2 Проверка Push и Peek
    try {
        stack21.Push(10);
        if (stack21.Peek() != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 2.3 Проверка Pop
    try {
        stack21.Pop();
        if (!stack21.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.4 Проверка ошибки Peek для пустого стека
    try {
        stack21.Peek();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 2.5 Проверка ошибки Pop для пустого стека
    try {
        stack21.Pop();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestQueue() { //GROUP 3
    int test_group_number = 3;
    int test_number = 1;
    int result_of_test = 0;

    result_of_test = 0; //TEST 3.1 Проверка создания пустой очереди
    Queue<int> queue31;
    try {
        if (!queue31.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.2 Проверка Push и Peek
    try {
        queue31.Push(10);
        if (queue31.Peek() != 10) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 0; //TEST 3.3 Проверка Pop
    try {
        queue31.Pop();
        if (!queue31.Empty()) result_of_test = 1;
    }
    catch(ErrorCode ex) {
        result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.4 Проверка ошибки Peek для пустой очереди
    try {
        queue31.Peek();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;

    result_of_test = 1; //TEST 3.5 Проверка ошибки Pop для пустой очереди
    try {
        queue31.Pop();
    }
    catch(ErrorCode ex) {
        if (ex == ErrorCode::EMPTY_CONTAINER) result_of_test = 0;
        else result_of_test = 2;
    }
    TestResultPrint(result_of_test, test_group_number, test_number);
    test_number++;
}

void TestAll() {
    TestDeque();
    TestStack();
    TestQueue();
}