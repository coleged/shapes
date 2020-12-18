//
//  point.cpp
//  shapes
//
//  Point and Vertex implimentation
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include "point.hpp"

// Point Point Point Point Point Point Point Point Point Point Point Point

    int Point::count = 0;   // initialise point counter outside class

    // constructors
    Point::Point(): ref(++count){
        //ref = ++count;
    };
    Point::Point(float x, float y, std::string n): ref(++count){
        //ref = ++count;
        X = x;
        Y = y;
        name = n;
    }
    // copy constructor - not sure about this, trying to avoid the extra object
    // created incrementing count in +operator method assigning to existing oject
    // i.e. C = A + B (which increments Point::count twice)
    Point::Point(const Point& p): ref(++count){
        X = p.X;
        Y = p.Y;
        //ref = p.ref;
        name = p.name;
    }
    // destructor
    Point::~Point(){
        //std::cout << "Point destruction warning" << std::endl; // DEBUG
    }
    
    // getters
    float Point::getX() const { return X;}
    float Point::getY() const { return Y;}
    int Point::getRef() const { return ref;}
    std::string Point::getName() const { return name;}
    
    // setters
    Point* Point::setX(float x) {X = x; return this;}
    Point* Point::setY(float y) {Y = y; return this;}
    Point* Point::setPoint(float x, float y) {X = x; Y = y; return this;}
    Point* Point::setName(std::string s) {name = s; return this;}

    bool Point::same(Point other) const {
        if((this->X == other.getX()) && (this->Y == other.getY())) return true;
    return false;
    }
    
    // operator overloads

    // +
    // take care using operator+ as it creates a temp object and increments ref count.
    // use it in initialisation with assigment i.e. Point P3 = P1 + P2
    Point& Point::operator+(const Point& p){
        Point* ret = new Point();
        ret->X = X + p.X;
        ret->Y = Y + p.Y;
        return *ret;
    }// +

    
    // ==
    bool const Point::operator==(const Point& p){
        if (X != p.getX()) return false;
        if (Y != p.getY()) return false;
        return true;
    }// ==

    // !=
    bool const Point::operator!=(const Point& p){
        return !( *this == p );
    }// !=

    // An alternative to std::to_string() that takes a second param (int)
    // to define precision for floats - bit of an overkill to template it!!
    template <typename T>
    std::string Point::to_string(const T a_value, const int n)
    {
        std::ostringstream out;
        out.precision(n);
        out << std::fixed << a_value;
        return out.str();
    }
    
    //
    std::string Point::toString(){
        std::string ret = "R:" + to_string(ref,0)
                        + " X:" + to_string(X,2)
                        + " Y:" + to_string(Y,2)
                        + " N:" + name;
        return ret;
    }

    // Functor
    // Inner functor Class used by Shape::isValid()
    // binary predicate for identity of two Point objects.
    // i.e. if both x and y values are identical they are identical
    bool Point::same_point::operator()(Point* l, Point* r) {
            if( (l->getX()==r->getX()) && (l->getY()==r->getY()) )
                    return true;
            return false;
        }
            /* lamnda equivelent

            [] (Point* l Point* r) -> bool {
                 if( (l->getX()==r->getX()) && (l->getY()==r->getY()) )
                         return true;
                 return false;
             }

            */

    // Functor
    // Inner functor Class used by Shape::isValid()
    // binary predicate for sorting Point objects.
    // i.e. if both l.x < r.x return true, if l.x == r.x test y
    bool Point::sort_point::operator()(Point* l, Point* r) {
            if( l->getX() < r->getX() ){
                    return true;
            }
            if( l->getX() == r->getX()){
                if( l->getY() < r->getY()){
                    return true;
                }
            }
            return false;
        }

            /* Point::sort_point::operator() lamnda equivelent

            [] (Point* l Point* r) -> bool {
                 if( l->getX() < r->getX() ){
                         return true;
                 }
                 if( l->getX() == r->getX()){
                     if( l->getY() < r->getY()){
                         return true;
                     }
                 }
                 return false;
             }

            */


// Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex Vertex

Vertex* Vertex::setVertex(float x, float y) {X = x; Y = y; return this;}
    

