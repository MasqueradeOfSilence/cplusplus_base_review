//
//  main.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

void passByValue(int x)
{
    x = 666;
    std::cout << "We just passed x by value and inside here, it's " << x << std::endl;
}

void passByReference(int& y)
{
    y = 67;
    std::cout << "We just passed y by reference, and inside here, it's " << y << std::endl;
}

void passByConstReference(const int& z)
{
    
}

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World! C++ review time\n";
    
    // EXAMPLE 1: PASSING BY VALUE
    int x = 333;
    std::cout << "x is initialized to 333" << std::endl;
    passByValue(x);
    std::cout << "But out here, it's still " << x << std::endl;
    
    // EXAMPLE 2: PASSING BY REFERENCE
    int y = 69;
    std::cout << "y is initialized to 69" << std::endl;
    passByReference(y);
    std::cout << "Since we passed y by reference, it's now " << y << std::endl;
    
    int z = 42;
    std::cout << "z is initialized to the meaning of the life, universe, and everything (42)" << std::endl;
    passByConstReference(z);
    // enforces not modifying, but in a more efficient manner
    std::cout << "z is still " << z << " because const ref doesn't modify anything" << std::endl;
    
    // Old-fashioned arrays
    int theStorageContainer[7] = {666, 69, 621, 67, 420, 444, 92};
    std::cout << "Piss off redditors by mentioning the number " << theStorageContainer[3] << std::endl;
    // Vectors are better
    std::vector<int> theCoolerStorageContainer = {666, 69, 621, 67, 420, 444, 92};
    theCoolerStorageContainer.push_back(333);
    std::cout << "Be half-evil by mentioning the number " << theCoolerStorageContainer.at(7) << std::endl;
    theCoolerStorageContainer.pop_back();
    
    // Oh hey an O(n) operation:
    auto iterateMeHarderUwu = theCoolerStorageContainer.end();
    std::advance(iterateMeHarderUwu, -2);
    theCoolerStorageContainer.erase(iterateMeHarderUwu);
    // There we go
    
    // Now let's remove all even numbers. The [] thing is a lamdba and you could also just define a function and pass it in.
    theCoolerStorageContainer.erase(
        std::remove_if(theCoolerStorageContainer.begin(), theCoolerStorageContainer.end(),
            [](int x) { return x % 2 == 0; }),
                                    theCoolerStorageContainer.end()
    );
    
    // Now let's loop through it:
    for (const auto& element : theCoolerStorageContainer)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Please review inheritance after you get through the other stuff
    
    return EXIT_SUCCESS;
}
