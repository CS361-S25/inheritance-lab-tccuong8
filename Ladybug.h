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

    int GetBugSpots()
    {
        return num_bug_spots;
    }

    emp::Ptr<Animal> Reproduce()
    {
        return new Ladybug(0, GetBugSpots()); // assuming it should have the same number of spots as parent
    }
};