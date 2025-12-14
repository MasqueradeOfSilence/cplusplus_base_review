//
//  Emu.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#include "Emu.hpp"
#include <iostream>

void Emu::attack_viciously()
{
    std::cout << "I rush towards you screaming, and desecrate your pitiful human flesh" << std::endl;
}

void Emu::call() const
{
    std::cout << "DEATH IS IMMINENT" << std::endl;
}

void Emu::fly() const
{
    // emus can't fly you dingus
    std::cout << "HAHAHAHAHAHAHHAHAHAAHAHAHAAAAAA" << std::endl;
}
