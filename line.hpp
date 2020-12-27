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
    
    static int count;   // line counter for ref generation
    
public:
    Line(Vertex*, Vertex*, std::string = "no name");
    Line(float&, float&, float&, float&, std::string = "no name");
    
    Point* getA() const;
    Point* getB() const;
    int   getRef() const;
    
    float len() const;             // length of line
    float product(Line*) const;    // vector product of this and Line*
    float cosAngle(Line*) const;   // cosine of angle between this and Line*
    bool   rightAngle(Line*) const; // true if this line is perpendicular with Line*
    
    std::string toString() const;
    
    // DEBUG CODE. non member static collection of all the lines created
    static std::vector<Line*> allMyLines;
    
};


#endif /* Line_hpp */
