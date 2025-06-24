# Компилятор и флаги
CC = g++
CFLAGS = -Wall -Wextra -g

# Исходные файлы
SRCS = main.cpp \
       Tests.cpp \
       Interface.cpp \
       Person.cpp \
       PersonManager.cpp

# Заголовочные файлы
HEADERS = ArraySequence.h \
          ListSequence.h \
          LinkedList.h \
          DynamicArray.h \
          Errors.h \
          ImmutableArraySequence.h \
          ImmutableListSequence.h \
          Sequence.h \
          Tests.h \
          Interface.h \
          Person.h \
          PersonManager.h \
          Deque.h \
          Queue.h \
          Stack.h

OBJS = $(SRCS:.cpp=.o)

TARGET = lab3

.PHONY: all clean cleanall rebuild run rerun

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(TARGET)

rebuild: cleanall all

run:
	./$(TARGET)

rerun: rebuild run