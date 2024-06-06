#include <iostream>
#include <utility> // for std::move

void process(int& x) {
    std::cout << "L-value reference\n";
}

void process(int&& x) {
    std::cout << "R-value reference\n";
}

template<typename T>
void forwarder(T&& arg) {
    process(std::forward<T>(arg)); // Perfect forwarding
}

int main() {
    int a = 5;
    forwarder(a);             // L-value reference
    forwarder(5);             // R-value reference
    forwarder(std::move(a));  // R-value reference
    return 0;
}

 
