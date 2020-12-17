//
//  point.hpp
//  shapes
//
//  class   Point, Vertex
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

#include <iostream>


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
    int getRef();
    std::string getName();
    
    // setters
    void setX(float x);
    void setY(float y);
    void setPoint(float x, float y);
    void setName(std::string s);
    
    bool same(Point);
    
    // operators
    // take care using this as it creates a temp object and increments ref count
    // use it in initialisation with assigment i.e. Point NEW = P1 + P2
    Point& operator+(const Point& p);
    bool const operator==(const Point& p);
    bool const operator!=(const Point& p);
    
    template <typename T>
    std::string to_string(const T a_value, const int n);
    std::string toString();
    
    class same_point{
    public: bool operator() (Point*, Point*);
    };
    class sort_point{
    public: bool operator() (Point*, Point*);
    };
    
};

// Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex

class Vertex: public Point{
    // inherit all constructors
    using Point::Point;
    
    void setVertex(float x, float y);
    
};


#endif /* point_hpp */
