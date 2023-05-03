#include "Ninja.hpp"
#include <cmath>

using namespace ariel;

Ninja::Ninja(const std::string& name, const Point& location, int speed) : Character(name, location, 11), m_speed(speed)
{
    // Ninja starts with 11 hit points
}

void Ninja::move(Character* enemy)
{
    if (isAlive() && enemy != nullptr) {
        Point destination = enemy->getLocation();
        Point newLocation = m_location.moveTowards(m_location, destination, m_speed);
        m_location = newLocation;
    }
}

void Ninja::slash(Character* enemy)
{
    if (isAlive() && enemy != nullptr && distance(enemy) < 1.0) {
        enemy->hit(31);
    }
}