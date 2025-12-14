//
//  Seagull.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#include "Seagull.hpp"
#include <iostream>

void Seagull::call() const
{
    std::cout << "MINE MINE MINE give me your fries" << std::endl;
}

void Seagull::steal_your_cheetos() const
{
    std::cout << "I swoop down and steal your cheetos" << std::endl;
}

void Seagull::beach_bomb() const
{
    std::cout << "POOP" << std::endl;
}
