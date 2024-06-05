#include <iostream>

#include "stack.h"

 

int main()

{

    try {

        Stack<int> intStack(10);

        intStack.push(1);

        intStack.push(2);

        intStack.push(3);

        std::cout << "Top of intStack: " << intStack.top() << std::endl;

        std::cout << "Popped from intStack: " << intStack.pop() << std::endl;

        std::cout << "Popped from intStack: " << intStack.pop() << std::endl;

 

        Stack<double> doubleStack(10);

        doubleStack.push(1.1);

        doubleStack.push(2.2);

        doubleStack.push(3.3);

        std::cout << "Top of doubleStack: " << doubleStack.top() << std::endl;

        std::cout << "Popped from doubleStack: " << doubleStack.pop() << std::endl;

        std::cout << "Popped from doubleStack: " << doubleStack.pop() << std::endl;

 

        Stack<char> charStack(10);

        charStack.push('a');

        charStack.push('b');

        charStack.push('c');

        std::cout << "Top of charStack: " << charStack.top() << std::endl;

        std::cout << "Popped from charStack: " << charStack.pop() << std::endl;

        std::cout << "Popped from charStack: " << charStack.pop() << std::endl;

    }

 

    catch (const std::exception& e)

    {

        std::cout<<"Error : "<<e.what()<<std::endl;

    }

 

    return 0;

}
