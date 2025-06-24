#include "Interface.h"

ContainerVector<Deque<int>> intDeques;
ContainerVector<Deque<double>> doubleDeques;
ContainerVector<Deque<Person>> personDeques;
ContainerVector<Queue<int>> intQueues;
ContainerVector<Queue<double>> doubleQueues;
ContainerVector<Queue<Person>> personQueues;
ContainerVector<Stack<int>> intStacks;
ContainerVector<Stack<double>> doubleStacks;
ContainerVector<Stack<Person>> personStacks;

void PrintError(ErrorCode ex) {
    switch (ex) {
        case ErrorCode::OK:
            std::cout << "Operation completed successfully.\n";
            break;
        case ErrorCode::INVALID_INPUT:
            std::cout << "Error: Invalid input.\n";
            break;
        case ErrorCode::INDEX_OUT_OF_RANGE:
            std::cout << "Error: Index out of range.\n";
            break;
        case ErrorCode::NEGATIVE_QUANTITY:
            std::cout << "Error: Negative value not allowed.\n";
            break;
        case ErrorCode::MEMORY_ALLOCATION_FAILED:
            std::cout << "Error: Memory allocation failed. Out of memory.\n";
            break;
        case ErrorCode::EMPTY_CONTAINER:
            std::cout << "Error: Container is empty. No elements to operate.\n";
            break;
        default:
            std::cout << "Error: Unknown error occurred.\n";
    }
}

void MainMenu() {
    while (true) {
        std::cout << "\n=== Main Menu ==="
                  << "\n1. Work with int"
                  << "\n2. Work with double"
                  << "\n3. Work with Person"
                  << "\n4. Exit"
                  << "\nSelect: ";
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: TypeMenu(DataType::INT); break;
            case 2: TypeMenu(DataType::DOUBLE); break;
            case 3: TypeMenu(DataType::PERSON); break;
            case 4: return;
            default: std::cout << "Invalid choice!\n";
        }
    }
}

void TypeMenu(DataType type) {
    int containerChoice;
    std::cout << "\nSelect container type:\n"
              << "1. Deque\n"
              << "2. Queue\n"
              << "3. Stack\n"
              << "4. Back\n"
              << "Choice: ";
    std::cin >> containerChoice;

    if (containerChoice == 4) return;

    try {
        switch (containerChoice) {
            case 1:
                switch (type) {
                    case DataType::INT: ContainerMenu(intDeques); break;
                    case DataType::DOUBLE: ContainerMenu(doubleDeques); break;
                    case DataType::PERSON: ContainerMenu(personDeques); break;
                }
                break;
            case 2:
                switch (type) {
                    case DataType::INT: ContainerMenu(intQueues); break;
                    case DataType::DOUBLE: ContainerMenu(doubleQueues); break;
                    case DataType::PERSON: ContainerMenu(personQueues); break;
                }
                break;
            case 3:
                switch (type) {
                    case DataType::INT: ContainerMenu(intStacks); break;
                    case DataType::DOUBLE: ContainerMenu(doubleStacks); break;
                    case DataType::PERSON: ContainerMenu(personStacks); break;
                }
                break;
            default:
                throw ErrorCode::INVALID_INPUT;
        }
    } catch (ErrorCode ex) {
        PrintError(ex);
    }
}

template <typename T>
void ContainerMenu(ContainerVector<T>& containers) {
    while (true) {
        std::cout << "\n=== Container Operations ==="
                  << "\n1. Create container"
                  << "\n2. Print container"
                  << "\n3. Concat containers"
                  << "\n4. Push element"
                  << "\n5. Pop element"
                  << "\n6. Back"
                  << "\nChoice: ";

        int choice;
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: CreateContainer(containers); break;
                case 2: PrintContainer(containers); break;
                case 3: ConcatContainers(containers); break;
                case 4: PushToContainer(containers); break;
                case 5: PopFromContainer(containers); break;
                case 6: return;
                default: throw ErrorCode::INVALID_INPUT;
            }
        } catch (ErrorCode ex) {
            PrintError(ex);
        }
    }
}

template <typename T>
void CreateContainer(ContainerVector<T>& containers) {
    containers.push_back(std::make_unique<T>());
    std::cout << "Container created. Total: " << containers.size() << "\n";
}

template <typename T>
void PrintContainer(ContainerVector<T>& containers) {
    using ElementType = typename T::value_type;
    
    if (containers.empty()) {
        std::cout << "No containers available.\n";
        return;
    }

    std::cout << "Available containers (0-" << containers.size()-1 << "): ";
    size_t index;
    std::cin >> index;

    if (index >= containers.size()) {
        throw ErrorCode::INDEX_OUT_OF_RANGE;
    }

    std::cout << "Container #" << index << " [";
    for (size_t i = 0; i < containers[index]->Size(); ++i) {
        if constexpr (std::is_same_v<ElementType, Person>) {
            PrintPerson((*containers[index])[i]);
        } else {
            std::cout << (*containers[index])[i];
        }
        if (i != containers[index]->Size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

template <typename T>
void ConcatContainers(ContainerVector<T>& containers) {
    if (containers.size() < 2) {
        std::cout << "Need at least 2 containers for concatenation.\n";
        return;
    }

    std::cout << "Available containers (0-" << containers.size()-1 << ")\n";
    std::cout << "Select first container: ";
    size_t index1;
    std::cin >> index1;

    std::cout << "Select second container: ";
    size_t index2;
    std::cin >> index2;

    if (index1 >= containers.size() || index2 >= containers.size()) {
        throw ErrorCode::INDEX_OUT_OF_RANGE;
    }

    auto newContainer = containers[index1]->Concat(containers[index2].get());
    containers.push_back(std::unique_ptr<T>(newContainer));
    std::cout << "Concatenated container created. ID: " << containers.size()-1 << "\n";
}

template <>
void PushToContainer(ContainerVector<Deque<Person>>& containers) {
    std::cout << "Available containers: 0-" << containers.size()-1 << "\n";
    size_t containerId;
    std::cin >> containerId;


    Person person;
    std::cin >> person;

    containers[containerId]->PushBack(person);
}

template <typename T>
void PushToContainer(ContainerVector<Deque<T>>& containers) {
    std::cout << "Enter value to push: ";
    T value;
    std::cin >> value;

    std::cout << "Container ID (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;
    containers[id]->PushBack(value);
}

template <typename T>
void PushToContainer(ContainerVector<T>& containers) {
    using ElementType = typename T::value_type;

    std::cout << "Enter value to push: ";
    ElementType value;
    std::cin >> value;

    std::cout << "Container ID (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;
    containers[id]->Push(value);
}

template <typename T>
void PopFromContainer(ContainerVector<Deque<T>>& containers) {
    if (containers.empty()) {
        std::cout << "No containers available.\n";
        return;
    }

    std::cout << "Pop from front(1) or back(0).\n";
    int front;
    std::cin >> front;

    std::cout << "Available containers (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    if (front) {
        T value = containers[id]->PopFront();
        std::cout << "Extracted from front: " << value << "\n";
    } else {
        T value = containers[id]->PopBack();
        std::cout << "Extracted from back: " << value << "\n";
    }
}

template <typename T>
void PopFromContainer(ContainerVector<Queue<T>>& containers) {
    if (containers.empty()) {
        std::cout << "No queues available.\n";
        return;
    }

    std::cout << "Available queues (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    T value = containers[id]->Pop();
    std::cout << "Dequeued: " << value << "\n";
}

template <typename T>
void PopFromContainer(ContainerVector<Stack<T>>& containers) {
    if (containers.empty()) {
        std::cout << "No stacks available.\n";
        return;
    }

    std::cout << "Available stacks (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    T value = containers[id]->Pop();
    std::cout << "Popped: " << value << "\n";
}

template <>
void PopFromContainer(ContainerVector<Queue<Person>>& containers) {
    if (containers.empty()) {
        std::cout << "No queues available.\n";
        return;
    }

    std::cout << "Available queues (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    Person person = containers[id]->Pop();
    std::cout << "Dequeued person: ";
    PrintPerson(person);
}

template <>
void PopFromContainer(ContainerVector<Deque<Person>>& containers) {
    if (containers.empty()) {
        std::cout << "No containers available.\n";
        return;
    }

    std::cout << "Pop from front(1) or back(0).\n";
    int front;
    std::cin >> front;

    std::cout << "Available containers (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    if (front) {
        Person person = containers[id]->PopFront();
    std::cout << "Pop Front person: ";
    PrintPerson(person);
    } else {
        Person person = containers[id]->PopBack();
    std::cout << "Pop Back person: ";
    PrintPerson(person);
    }
}

template <>
void PopFromContainer(ContainerVector<Stack<Person>>& containers) {
    if (containers.empty()) {
        std::cout << "No queues available.\n";
        return;
    }

    std::cout << "Available queues (0-" << containers.size()-1 << "): ";
    size_t id;
    std::cin >> id;

    if (id >= containers.size()) throw ErrorCode::INDEX_OUT_OF_RANGE;

    if (containers[id]->Size() == 0) throw ErrorCode::EMPTY_CONTAINER;

    Person person = containers[id]->Pop();
    std::cout << "Pop person: ";
    PrintPerson(person);
}