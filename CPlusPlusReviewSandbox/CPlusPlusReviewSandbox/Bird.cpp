//
//  Bird.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#include "Bird.hpp"
#include <iostream>

void Bird::call() const
{
    std::cout << "CHIRP CAW" << std::endl;
}

void Bird::fly() const
{
    std::cout << "I am flying! WHEE" << std::endl;
}
