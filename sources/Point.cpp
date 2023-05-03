#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;

// Constructor
Point::Point(double x, double y) : m_x(x), m_y(y) {}

// Calculates the distance between this point and another point
double Point::distance(const Point& other) const {
    double dx = m_x - other.m_x;
    double dy = m_y - other.m_y;
    return std::sqrt(dx * dx + dy * dy);
}

// Prints the coordinates of this point
void Point::print() const {
    std::cout << "(" << m_x << ", " << m_y << ")";
}

// Returns the closest point to the destination point, which is at most the given distance from the source point
Point Point::moveTowards(const Point& source, const Point& destination, double distance) const {
    // Calculate the distance between the source and destination points
    double dist = source.distance(destination);
    
    // If the distance is less than or equal to the given distance, return the destination point
    if (dist <= distance) {
        return destination;
    }
    
    // Calculate the direction and magnitude of the movement vector
    double dx = destination.m_x - source.m_x;
    double dy = destination.m_y - source.m_y;
    double magnitude = distance / dist;
    dx *= magnitude;
    dy *= magnitude;
    
    // Return the point that is the result of adding the movement vector to the source point
    return Point(source.m_x + dx, source.m_y + dy);
}
