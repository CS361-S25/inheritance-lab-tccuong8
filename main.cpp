
#include "emp/base/vector.hpp"
#include "emp/base/Ptr.hpp"
#include <ostream>

// While you could get away with just including Dog.h, this is a good time to observe and fix one problem you’ll eventually run into. At the top of your file, make sure you have included both Animal.h and Dog.h:
#include "Animal.h"
#include "Dog.h"
#include "Ladybug.h"

int main()
{
    // In main.cpp, create an Empirical vector of Empirical pointers to Animal called population:
    emp::vector<emp::Ptr<Animal>> population;

    // Create a new Dog instance and add it to the vector. Note that because the vector holds pointers to the superclass of Dog, it’s fine to put Dog objects in it:
    population.push_back(emp::NewPtr<Dog>(5, 2));

    // In main.cpp, call the GetType() method of the only item in your population and print it out:
    std::cout << population[0]->GetType() << std::endl;
    // It should be printing “Animal” meaning it’s calling the Animal method instead of the Dog method! Because C++ “bundles” both types together when it makes a subclass object, it is defaulting to the superclass method since that is what the vector knows that it is holding. You can tell C++ that you want it to actually default to the subclass method with the virtual keyword. In Animal.h add the keyword virtual before the return type of the GetType() method:
    // Now when you compile and run, you should get “Dog” printing out. This means that anytime you have a superclass method that you want the base class method to be called instead, you should put virtual in front of it.

    // This process only works because these are pointers! If you ever dereference the pointer and save it to an Animal variable, C++ cuts off the Dog portion. Test this out in main.cpp:
    Animal test = *population[0];
    std::cout << test.GetType() << std::endl;

    // What if you want to print out the dog’s age? You didn’t define a GetAge() function for the Dog class, but you didn’t have to, because the super class is in charge of that! In main.cpp call and print out the age of your dog using GetAge():
    std::cout << population[0]->GetAge() << std::endl;
    // This is the great thing about inheritance: you can have functionality in Animal that is shared across all the subclasses (once you have more of them) and only need to implement it once (and you can keep them all in the same vector).

    // In main.cpp, call the Reproduce method of your existing dog and add the offspring to the population, then make sure that it is the correct type:
    population.push_back(population[0]->Reproduce());
    std::cout << population[1]->GetType() << std::endl;

    // What if you want to access dog specific methods? While it’s generally best to avoid needing to access methods special to the subclasses in this kind of setup, sometimes you need to. Fortunately, Empirical’s pointer makes that fairly easy to do.

    // First, let’s see the problem. In main.cpp try to print the number of spots of your dog:
    // std::cout << population[0]->GetSpots() << std::endl;
    // You should be seeing an error that Animal has no member GetSpots(). This is because C++ only knows that this object is of type Animal, it doesn’t know that it’s actually a Dog. Because you know for sure that the object is a dog at this point in the code, you can cast it to type Dog and then call the Dog specific method (you should only do this when you know for sure!):
    std::cout << population[0].DynamicCast<Dog>()->GetSpots() << std::endl;

    // You should avoid dynamic casting whenever you can, and instead override methods of the superclass for subclass specific behavior. So for example, we could have a GetAttributes method that all Animals have and gets whatever the subclass specific attributes are.

    // The big reason that you’re going to be wanting to use inheritance is so that you can have objects of multiple different types all in the same vector (the pop vector of your world), but you aren’t actually doing that right now. Create another subclass of Animal and play around with having both it and Dogs in the same vector and accessing their methods correctly.
    population.push_back(emp::NewPtr<Ladybug>(3, 5));
    std::cout << population[2]->GetType() << std::endl;
    std::cout << population[2]->GetAge() << std::endl;
    std::cout << population[2].DynamicCast<Ladybug>()->GetSpots() << std::endl;

    // Now, let’s add a method to Ladybug that takes in a pointer to a Dog and returns a Dog with the same age but with the number of spots of the ladybug added onto its number of spots. In Ladybug.h, define a LandOn function that takes in a pointer to a Dog and return a Dog with the same age but with the number of spots of the ladybug added onto its number of spots:
    emp::Ptr<Animal> dog = population[0].DynamicCast<Dog>();
    emp::Ptr<Animal> ladybug = population[2].DynamicCast<Ladybug>();
    emp::Ptr<Animal> new_dog = ladybug.DynamicCast<Ladybug>()->LandOn(dog);
    std::cout << new_dog->GetType() << std::endl;
    std::cout << new_dog->GetAge() << std::endl;
    std::cout << new_dog.DynamicCast<Dog>()->GetSpots() << std::endl;
    

}
