#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
namespace ariel{
    class Character {
        protected:
            std::string m_name;
            Point m_location;
            int m_hitPoints;
        public:
            // Constructor
            Character(const std::string& name, const Point& location, int hitPoints);

            // Checks if the character is alive (has more than zero hit points)
            bool isAlive() const;

            // Calculates the distance between this character and another character
            double distance(const Character* other) const;

            // Subtracts the specified amount of hit points from the character
            void hit(int amount);

            // Returns the name of the character
            std::string getName() const;

            // Returns the location of the character
            Point getLocation() const;

            void setHitPoints(int hitPoint);

            // Prints the character's details (name, hit points, and location)
            char print() const;
    };
};
#endif // CHARACTER_HPP
