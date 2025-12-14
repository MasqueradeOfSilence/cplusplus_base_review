//
//  Bird.hpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/14/25.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>

class Bird
{
public:
    virtual void call() const;
    virtual void fly() const;
    virtual ~Bird() = default;
private:
};

#endif /* Bird_hpp */
