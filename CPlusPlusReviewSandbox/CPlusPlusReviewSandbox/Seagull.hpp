//
//  Seagull.hpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#ifndef Seagull_hpp
#define Seagull_hpp

#include <stdio.h>
#include "Bird.hpp"

class Seagull : public Bird
{
public:
    void call() const override;
    void steal_your_cheetos() const;
    void beach_bomb() const;
};

#endif /* Seagull_hpp */
