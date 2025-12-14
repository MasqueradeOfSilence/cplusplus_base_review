//
//  Emu.hpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#ifndef Emu_hpp
#define Emu_hpp

#include <stdio.h>
#include "Bird.hpp"

class Emu: public Bird
{
public:
    void attack_viciously();
    void call() const override;
    void fly() const override;
private:
};

#endif /* Emu_hpp */
