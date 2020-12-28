//
//  shape.hpp
//  shapes
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "types.hpp"
#include "exceptions.hpp"
#include "point.hpp"
#include "line.hpp"

class Shape {
    
friend class Polygon;
friend class Triangle;
friend class Rectangle;
 
public:
    
    virtual ~Shape();
    
private:
    // constants for size comparison
    static const int SMALLER     = -1;
    static const int SAME        =  0;
    static const int LARGER      =  1;
    
    std::string         name;
    int                 ref;        // reference number of shape
    static int          count;
    
    shapeType           type;
    int                 nverts;
    int                 nsides;
    Vertex              origin; // origin and/or anchor
    double              radius; // for Circle
    
    std::vector<Vertex*> verts;  // first element is the origin/anchor
    std::vector<Line>   lines;   // vector of line objects, as the shape owns the
                                 // lines
    
public:
    
    // setters
    Shape* setName(std::string);    // returns this
    
    // getters
    std::string getName() const;          // returns the name of the shape
    
    std::string toString();         // returns shape data as string
    
    //int compare(Shape to);        // compares areas of shape with other shape
    
    //  virtual methods to be implimented by subclasses
    virtual float area();      // returns area of shape
    virtual float perimeter();  // returns perimeter of shape
    
    bool uniqueVertices();           // returns true if all Points are unique
    bool isValid();                 // verifies validity of shape vertices and
                                    // other parameters
    int compare(Shape *);           // TODO: better to overload operator<
    void printData();
    
    Shape* mkLines();       // fills out the lines vector
    
    // DEBUG CODE. non member static collection of all the Shapes created
    static std::vector<Shape*> allMyShapes;
    
};// Shape

#endif /* shape_hpp */
