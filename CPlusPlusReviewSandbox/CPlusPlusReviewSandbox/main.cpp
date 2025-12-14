//
//  main.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/13/25.
//

#include <iostream>

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

    // Please review inheritance after you get through the other stuff
    
    return EXIT_SUCCESS;
}
