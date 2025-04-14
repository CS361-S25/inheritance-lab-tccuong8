#ifndef ANIMAL
#define ANIMAL
#include <string>
#include "Animal.h"

// Make a new file Animal.h and define an Animal class with a private instance variable age:
class Animal
{
    int age;

    // Create a constructor for your class and set the age from a parameter. Remember that you can do this in the fancy C++ way like so:
public:
    Animal(int _age) : age(_age)
    {
        // doesn't do anything else
    }
    virtual std::string GetType() { return "Animal"; }

    // If we want to be able to get access to the age variable, we’ll need an accessor method, since it’s private (and should stay that way). Make a GetAge() method in Animal:
    virtual int GetAge() {return age;}

    // Make a virtual Reproduce method in the Animal class that return a new Animal (you could argue that this shouldn’t do anything, or throw an exception, but we’re assuming that maybe you do want to make just animals sometimes):
    virtual emp::Ptr<Animal> Reproduce() {
        return new Animal(0);
    }
};

#endif