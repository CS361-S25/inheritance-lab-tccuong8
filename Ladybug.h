#include "Animal.h"

class Ladybug : public Animal
{
    int num_bug_spots;

public:
    Ladybug(int _age, int _num_bug_spots) : Animal(_age), // Calls Animal constructor and gives it age
                                            num_bug_spots(_num_bug_spots)
    { // Sets num_bug_spots
      // Doesn't do anything else
    }
    std::string GetType() { return "Ladybug"; }

    int GetAge()
    {
        return Animal::GetAge();
    }

    int GetSpots()
    {
        return num_bug_spots;
    }

    emp::Ptr<Animal> Reproduce()
    {
        return new Ladybug(0, GetSpots()); // assuming it should have the same number of spots as parent
    }

    // Define a LandOn function that takes in a pointer to a Dog and return a Dog with the same age but with the number of spots of the ladybug added onto its number of spots.
    emp::Ptr<Animal> LandOn(emp::Ptr<Animal> dog)
    {
        return new Dog(dog->GetAge() / 7, dog.DynamicCast<Dog>()->GetSpots() + GetSpots());
    }
};