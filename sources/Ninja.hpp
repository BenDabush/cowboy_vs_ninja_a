#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <string>

namespace ariel{

    class Ninja : public Character {
    public:
        // Constructor for Ninja
        Ninja(const std::string& name, const Point& location, int speed);

        // Moves towards the enemy by a distance equal to its speed
        void move(Character* enemy);

        // Deals damage to the enemy if the ninja is alive and the enemy is less than 1 meter away
        void slash(Character* enemy);

    protected:
        int m_speed;
    };

    class YoungNinja : public Ninja {
    public:
        // Constructor for YoungNinja
        YoungNinja(const std::string& name, const Point& location);
    };

    class TrainedNinja : public Ninja {
    public:
        // Constructor for TrainedNinja
        TrainedNinja(const std::string& name, const Point& location);
    };

    class OldNinja : public Ninja {
    public:
        // Constructor for OldNinja
        OldNinja(const std::string& name, const Point& location);
    };
};
#endif // NINJA_HPP