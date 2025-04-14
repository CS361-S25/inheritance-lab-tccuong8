#include "Animal.h"

// Create a new file for a Dog subclass. In that subclass, define a Dog class that inherits from Animal (you’ll need to #include Animal.h as well):
class Dog : public Animal
{
    // Let’s have our dog have an additional instance variable num_spots. To allow our dog’s constructor to set both num_spots and age, we need to take them both as parameters and then set them in two slightly different ways:
    int num_spots;

public:
    Dog(int _age, int _num_spots) : Animal(_age), // Calls Animal constructor and gives it age
                                    num_spots(_num_spots)
    { // Sets num_spots
      // Doesn't do anything else
    }
    // Also create a GetType() method that returns “Dog” so that we can tell the difference easily.
    std::string GetType() { return "Dog"; }

    // What if you wanted to make a custom GetAge method for dog, for example to express the dog’s age in dog years (multiplied by 7) instead? You can’t access the age variable directly since it is private to the Animal class. Instead, you need to use the same accessor method, but specify that you want to call the super class version in Dog’s GetAge() method:
    int GetAge()
    {
        return Animal::GetAge() * 7;
    }

    int GetSpots()
    {
        return num_spots;
    }

    // Go into your Dog class and make a Reproduce method. It needs to return the same type as Animal, but it should make a dog, because we can again make an actual instance of type Dog, but pass it around as an Animal without a problem. Note also that you can use the Dog specific method GetSpots() without a problem because it is a Dog instance and C++ knows that at this point:
    emp::Ptr<Animal> Reproduce()
    {
        return new Dog(0, GetSpots()); // assuming it should have the same number of spots as parent
    }
};
