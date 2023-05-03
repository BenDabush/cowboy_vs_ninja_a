#include "Character.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;
// Constructor
Character::Character(const std::string& name, const Point& location, int hitPoints)
    : m_name(name), m_location(location), m_hitPoints(hitPoints)
{}

// Checks if the character is alive (has more than zero hit points)
bool Character::isAlive() const
{
    return m_hitPoints > 0;
}

// Calculates the distance between this character and another character
double Character::distance(const Character* other) const
{
    return m_location.distance(other->m_location);
}

// Subtracts the specified amount of hit points from the character
void Character::hit(int amount) {
    m_hitPoints -= amount;
}

// Returns the name of the character
std::string Character::getName() const
{
    return m_name;
}

// Returns the location of the character
Point Character::getLocation() const
{
    return m_location;
}

void Character::setHitPoints(int hitPoint){
    this->m_hitPoints = hitPoint;
}

// Prints the character's details (name, hit points, and location)
void Character::print() const
{
    std::cout << (isAlive() ? "" : "(") << (m_name[0] == 'N' ? "Ninja " : "Morning ") << m_name << ": " << m_hitPoints << " HP, ";
    m_location.print();
    std::cout << (isAlive() ? "" : ")");
}


