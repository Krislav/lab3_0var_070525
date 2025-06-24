#pragma once
#include "Sequence\Errors.h"
#include "PersonManager.h"
#include "Deque.h"
#include "Queue.h"
#include "Stack.h"
#include <vector>
#include <memory>
enum class DataType { INT, DOUBLE, PERSON };

template <typename T> using ContainerVector = std::vector<std::unique_ptr<T>>;
extern ContainerVector<Deque<int>> intDeques;
extern ContainerVector<Deque<double>> doubleDeques;
extern ContainerVector<Deque<Person>> personDeques;
extern ContainerVector<Queue<int>> intQueues;
extern ContainerVector<Queue<double>> doubleQueues;
extern ContainerVector<Queue<Person>> personQueues;
extern ContainerVector<Stack<int>> intStacks;
extern ContainerVector<Stack<double>> doubleStacks;
extern ContainerVector<Stack<Person>> personStacks;

void MainMenu();
void TypeMenu(DataType type);

template <typename T>
void ContainerMenu(ContainerVector<T>& containers);

template <typename T>
void CreateContainer(ContainerVector<T>& containers);

template <typename T>
void PrintContainer(ContainerVector<T>& containers);

template <typename T>
void PushToContainer(ContainerVector<T>& containers);

template <typename T>
void PushToContainer(ContainerVector<Deque<T>>& containers);

template <typename T>
void ConcatContainers(ContainerVector<T>& containers);

template <typename T>
void PopFromContainer(ContainerVector<Deque<T>>& containers);

template <typename T>
void PopFromContainer(ContainerVector<Queue<T>>& containers);

template <typename T>
void PopFromContainer(ContainerVector<Stack<T>>& containers);