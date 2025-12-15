//
//  main.cpp
//  CPlusPlusReviewSandbox
//
//  Created by Alex Neville on 12/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include "Bird.hpp"
#include "Emu.hpp"
#include "Seagull.hpp"

void passByValue(int x)
{
    x = 666;
    std::cout << "We just passed x by value and inside here, it's " << x << std::endl;
}

void passByReference(int& y)
{
    // this is an lvalue btw
    y = 67;
    std::cout << "We just passed y by reference, and inside here, it's " << y << std::endl;
}

void passByConstReference(const int& z)
{
    std::cout << "We just passed z by const reference, so we actually cannot modify it and it's just " << z << std::endl;
}

void passAnRvalue(int&& a)
{
    std::cout << "Rvalue passed: " << a << std::endl;
}

void addToVector(std::vector<std::string>& vec, std::string&& str)
{
    std::cout << "Adding to vector: " << str << std::endl;
    vec.push_back(str);
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
    
    // Now let's loop through it using a range-based for loop:
    for (const auto& element : theCoolerStorageContainer)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    // Now let's erase all occurrences of an element
    std::vector<int> theCoolestStorageContainer = {360, 720, 360, 260, 360, 360};
    theCoolestStorageContainer.erase(std::remove_if(theCoolestStorageContainer.begin(), theCoolestStorageContainer.end(),
                   [](int x) { return x == 360; }), theCoolestStorageContainer.end());
    
    // Another ranged for
    for (const auto& element : theCoolestStorageContainer)
    {
        std::cout << element << " " ;
    }
    std::cout << std::endl;

    // bird class with emu subclass
    Bird mrBird;
    mrBird.call();
    mrBird.fly();
    Emu harbingerOfDeath;
    harbingerOfDeath.call();
    harbingerOfDeath.fly();
    harbingerOfDeath.attack_viciously();
    // Now a smart pointers situation:
    std::vector<std::unique_ptr<Bird>> aviary;
    aviary.push_back(std::make_unique<Emu>());
    aviary.push_back(std::make_unique<Seagull>());
    
    std::cout << "Let us hear the birds make their great calls!" << std::endl;
    for (auto& bird : aviary)
    {
        bird->call();
    }
    std::cout << std::endl;
    
    // Move semantics:
    int a = 10;
    passAnRvalue(17);
    passAnRvalue(std::move(a));
    
    std::string name = "Alice";
    std::vector<std::string> vec;
    addToVector(vec, std::move(name));
    name = "Bob";
    addToVector(vec, std::move(name));
    
    /*
        The Rule of 5 states that if you write a destructor, you also need to write
        - a copy constructor
        - a move constructor
        - a copy assignment operator
        - a move assignment operator
     
        in order to avoid valgrind hell.
     */
    
    // TODO could write a test class here; otherwise, know the high-level concept
    
    /*
        STL
        - Vector
        - Map
        - Unordered Map (Hash Table)
        - Deque
        - Sort
     */
    
    // Vector: See above
    // O(1) access, O(1) amortized insert/delete at end, O(n) insert/delete at middle, O(n) search
    
    // Map: (red-black tree underneath) -- this is ordered and a bit slower than its unordered counterpart
    std::cout << "now let's talk about ages including how old your mom is, cuz she's really old" << std::endl;
    std::map<std::string, int> ages;
    ages["Your Mom"] = 567; // INSERT: O(log n)
    ages["Your Dad"] = 61;
    int theAgeOfYourMom = ages["Your Mom"]; // ACCESS: O(log n)
    std::cout << "Your mom is age " << theAgeOfYourMom << std::endl;
    ages["Satan"] = 666;
    ages.erase("Satan"); // DELETE: O(log n)
    ages["Aaaaaaron"] = 21;
    ages["zzzzzzzzzzyzyx"] = 37;
    
    // Expected order: Alphabetical, as it sorts by key
    for (auto& [name, age] : ages)
    {
        std::cout << name << ": Age " << age << std::endl;
    }
    
    // Unordered map uses a Hash Table
    std::unordered_map<std::string, int> momentsContemplatingTheEphemeralityOfExistence;
    momentsContemplatingTheEphemeralityOfExistence["Marge"] = 37; // Insert: O(1) average, O(n) worst
    momentsContemplatingTheEphemeralityOfExistence["Big Jimmy"] = 3;
    momentsContemplatingTheEphemeralityOfExistence["Yoseph"] = 1;
    momentsContemplatingTheEphemeralityOfExistence["Selena"] = 14;
    momentsContemplatingTheEphemeralityOfExistence["Doogles"] = 4;
    
    int momentsThatDooglesHasContemplatedTheEphemeralityOfExistence = momentsContemplatingTheEphemeralityOfExistence["Doogles"];
    // Access: That was an O(1) operation also, but could be O(n) worst
    std::cout << "doogles has contemplated the ephemerality of existence " << momentsThatDooglesHasContemplatedTheEphemeralityOfExistence << " times " << std::endl;
    
    std::cout << "doogles would like to forget" << std::endl;
    momentsContemplatingTheEphemeralityOfExistence.erase("Doogles");
    
    // now his memories are forgotten in O(1) deletion time (on average; worst case O(n)
    for (auto& [name, moments] : momentsContemplatingTheEphemeralityOfExistence)
    {
        std::cout << name << " has contemplated " << moments << " times " << std::endl;
    }
    // other examples include linear probing, quadratic probing, Robin Hood, cuckoo
    // no aliens are probing tho
    
    // okay now it's deque time:
    
    // then sort:
    
    // STL basics
    // AND: Threading stuff.
    // AND: Start Linux.
    
    return EXIT_SUCCESS;
}
