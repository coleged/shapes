//
//  point.hpp
//  shapes
//
//  class   Point, Vertex class declarations
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

#include <iostream>
#include <sstream>

// Point Point Point Point Point Point Point Point Point Point Point Point
class Point{
    
friend class Line;
    
private:
    
    static int count;       // Object counter
    
    float X;
    float Y;
    std::string name;
    int ref;
    
friend class Vertex;
    
    public:
    
    // constructors
    Point();
    Point(float x, float y, std::string n = "no name");
    // copy constructor - not sure about this, trying to avoid the extra object
    // created incrementing count in +operator method assigning to existing oject
    // i.e. C = A + B (which increments Point::count twice)
    Point(const Point& p);
    ~Point();
    
    // getters
    float getX() const;
    float getY() const;
    int getRef() const;
    std::string getName() const;
    
    // setters
    Point* setX(float x);
    Point* setY(float y);
    Point* setPoint(float x, float y);
    Point* setName(std::string s);
    
    bool same(Point) const;
    
    // operators
    // take care using this as it creates a temp object and increments ref count
    // use it in initialisation with assigment i.e. Point NEW = P1 + P2
    Point& operator+(const Point& p);
    bool const operator==(const Point& p);
    bool const operator!=(const Point& p);
    
    // An alternative to std::to_string() that takes a second param (int)
    // to define precision for floats - bit of an overkill to template it!!
    template <typename T> std::string to_string(const T a_value, const int n);
    
    std::string toString();
    
    // Functor binary predicates for soring and duplicate removal of collections
    // of Point objects. Can use lambdas to do this also.
    class sort_point{
        public: bool operator() (Point*, Point*);
    };
    
    class same_point{
        public: bool operator() (Point*, Point*);
    };
    
    
    
};

// Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex

class Vertex: public Point{
    // inherit all constructors
    using Point::Point;
    
    Vertex* setVertex(float x, float y);
    
};


#endif /* point_hpp */
