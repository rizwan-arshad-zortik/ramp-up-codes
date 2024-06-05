#ifndef STACK_H

#define STACK_H

 

#include <iostream>

#include <stdexcept>

 

template <typename T>

class Stack

{

public:

    Stack(int size = 100);       // Constructor with default size

    ~Stack();                    // Destructor

 

    void push(T value);          // Push value onto stack

    T pop();                     // Pop value from stack

    T top() const;               // Get top value of stack

    bool isEmpty() const;        // Check if stack is empty

    bool isFull() const;         // Check if stack is full

 

private:

    T* stackArray;               // Pointer to stack array

    int maxSize;                 // Maximum size of stack

    int topIndex;                // Index of top element

};

 

template <typename T>

Stack<T>::Stack(int size) : maxSize(size), topIndex(-1)

{

    stackArray = new T[maxSize];

}

 

template <typename T>

Stack<T>::~Stack() {

    delete[] stackArray;

}

 

template <typename T>

void Stack<T>::push(T value)

{

    if (isFull())

    {

        std::cout<<"Stack overflow: cannot push onto full stack."<<std::endl;

    }

    else

    {

        stackArray[++topIndex] = value;

    }

}

 

template <typename T>

T Stack<T>::pop()

{

    if (isEmpty())

    {

        std::cout<<"Stack underflow: cannot pop from empty stack."<<std::endl;

        return -1;

    }

    else

    {

        return stackArray[topIndex--];

    }

}

 

template <typename T>

T Stack<T>::top() const

{

    if (isEmpty())

    {

        std::cout<<"Stack is empty: no top element."<<std::endl;

        return -1;

    }

    else

    {

        return stackArray[topIndex];

    }

}

 

template <typename T>

bool Stack<T>::isEmpty() const

{

    return topIndex == -1;

}

 

template <typename T>

bool Stack<T>::isFull() const

{

    return topIndex == maxSize - 1;

}

 

#endif // STACK_H
