//
//  triangle.cpp
//  shapes
//
//  Created by Ed Cole on 11/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <cmath>
#include "triangle.hpp"


Triangle::Triangle(){};

Triangle::Triangle(Vertex* v1, Vertex* v2, Vertex* v3 ){
    nverts = 3;
    nsides = 3;
    type = TRIANGLE;
    verts.push_back( v1 );
    verts.push_back( v2 );
    verts.push_back( v3 );
    if(! isValid() ) throw  InvalidShapeException();
    mkLines();
    
}

Triangle::Triangle(std::vector<Vertex*> v){
    if(v.size() != 3) throw  InvalidShapeException();
    nverts = 3;
    nsides = 3;
    type = TRIANGLE;
    verts = v;
    if(! isValid() ) throw  InvalidShapeException();
    mkLines();
}

Triangle::Triangle(Polygon* p){
    nverts = 3;
    nsides = 3;
    type = TRIANGLE;
    verts = p->verts;
    if(! isValid() ) throw  InvalidShapeException();
    mkLines();
}

float Triangle::area() {
    // Using Herons rule for area of triangle
    // area = sqrt( (per/2-line1)(per/2-line2)(per/2-line3) )
    double area = 1;    // set to 1 because we are using iterative product in for loop
    double per = perimeter()/2;
    for(auto line: lines) {
        area *= (per - line->len());
    }
    area = sqrt(per*area);
    
    return area;
};
