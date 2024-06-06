#include <iostream>
#include <utility> // for std::move

class MyClass {
public:
    int* data;
    int size;
    // Constructor
    MyClass(int s) : size(s), data(new int[s]) {
        std::cout << "Constructor\n";
    }
    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor\n";
    }
    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor\n";
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            // Free existing resource
            delete[] data;
            // Transfer resource
            data = other.data;
            size = other.size;
            // Nullify the source
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move Assignment Operator\n";
        }
        return *this;
    }
    // Copy Constructor (for comparison)
    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy Constructor\n";
    }
    // Copy Assignment Operator (for comparison)
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // Free existing resource
            delete[] data;
            // Allocate new resource and copy
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
            std::cout << "Copy Assignment Operator\n";
        }
        return *this;
    }
};

int main() {
    MyClass a(5);            // Constructor
    MyClass b(10);           // Constructor
    b = std::move(a);        // Move Assignment Operator
    MyClass c(15);           // Constructor
    c = b;                   // Copy Assignment Operator
    MyClass d(std::move(c));
    MyClass e = d;
    return 0;                // Destructor for c, b, a
}

 
