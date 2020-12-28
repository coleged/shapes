//
//  polygon.cpp
//  shapes
//
//  Created by Ed Cole on 10/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include "polygon.hpp"
#include "triangle.hpp"

Polygon::Polygon(){};

Polygon::Polygon(std::vector<Vertex*> v){
    verts = v;
    mkLines();
}

float Polygon::perimeter(){
    float per = 0;
    
    for(auto l : lines) {
        per += l.len();
    }
    return per;
    
}// perimeter()

float Polygon::area(){
    
    float a = 10.0;
    
    return a;
    
}// area()

Shape* Polygon::mkLines(){  // joins the dots by creating line objects to dowm closed
                            // polygon. scans through the verts vector begin
    Vertex* A = nullptr;
    Vertex* B = nullptr;
    Vertex* F = nullptr;
    for(const auto& p : verts){
        B = p;
        if (A == nullptr){ // first point
            A = B;
            F = B;
            continue;
        }
        //Line L = new Line(A,B);
        lines.emplace_back(Line(A,B));
        A = B;
    }
    //L = new Line(B,F); // last line closing the polygon
    //std::cout << " ** " << L->toString() << std::endl;
    //lines.push_back(L);
    lines.emplace_back(Line(B,F));
    
    return (Shape*)this; // or should I use a static_cast ????
}


