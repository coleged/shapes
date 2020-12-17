//
//  Line.hpp
//  shapes
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

// Line objects contain reference data, they don't contain Vertices/points, but
// rather pointers to Vertex/Point objects. i.e. they describe how the dots are
// joined up, not the dots themselves

#ifndef Line_hpp
#define Line_hpp

#include "types.hpp"
#include <stdio.h>
#include "point.hpp"

class Line{
private:
    Vertex *A;  // pointer to end Vertex of line
    Vertex *B;
    lineStyle style;
    colorType color;
    lineWeight weight;
    int ref;
    std::string name;
    
    static int count;
    
    
    
public:
    Line(Vertex& a, Vertex& b, std::string = "no name");
    Line(float x1, float y1, float x2, float y2, std::string = "no name");
    
    Point* getA();
    Point* getB();
    int   getRef();
    std::string to_string();
    
    double len();
    double product(Line);
    double cosAngle(Line);
    
    std::string toString();
    
    // DEBUG LINES
    static std::vector<Line> myLines;
    
};


#endif /* Line_hpp */
