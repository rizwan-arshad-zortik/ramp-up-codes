#include <iostream>
#include <memory>

int main()
{
    {
        std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
        std::cout << "UniquePtr Value: " << *uniquePtr << std::endl;
    }
    {
        std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
        std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Shared ownership
        std::shared_ptr<int> sharedPtr3 = sharedPtr1; // Shared ownership
        std::cout << "SharedPtr1 Value: " << *sharedPtr1 << std::endl;
        std::cout << "SharedPtr2 Value: " << *sharedPtr2 << std::endl;
        *sharedPtr1 = 55;
        std::cout << "SharedPtr3 Value: " << *sharedPtr3 << std::endl;
    }

    {
        std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
        std::weak_ptr<int> weakPtr = sharedPtr;
        if (auto lockedPtr = weakPtr.lock())
        {
            std::cout << "WeakPtr locked value: " << *lockedPtr << std::endl;
        }
        else
        {
            std::cout << "WeakPtr expired" << std::endl;
        }
    }

    return 0;
}
