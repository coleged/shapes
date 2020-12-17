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
#include "types.hpp"
#include "point.hpp"
#include "line.hpp"

class Shape {
    
friend class Polygon;
friend class Triangle;
 
public:
   
    
    
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
                                    
    std::vector<Line*>   lines;
    
    
public:
    
    
    // setters
    Shape* setName(std::string);    // returns this
    
    // getters
    std::string getName();          // returns the name of the shape
    
    std::string toString();        // returns shape data as string
    
    //int compare(Shape to);          // compares areas of shape with other shape
    
    // virtual methods to be implimented by subclasses
    //virtual double area();          // returns area of shape
    float perimeter();     // returns perimeter of shape
    bool isValid();                 // verifies validity of shape vertices and
                                    // other parameters
    
    void printData();
    
    
    Shape* mkLines();       // fills out the lines vector
    
};// Shape

#endif /* shape_hpp */
