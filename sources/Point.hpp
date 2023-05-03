#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{
    class Point {
    public:
        // Constructor
        Point(double x, double y);

        // Calculates the distance between this point and another point
        double distance(const Point& other) const;

        // Prints the coordinates of this point
        void print() const;

        // Returns the closest point to the destination point, which is at most the given distance from the source point
        Point moveTowards(const Point& source, const Point& destination, double distance) const;

    private:
        double m_x;
        double m_y;
    };
};
#endif // POINT_HPP
