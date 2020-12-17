//
//  builder.cpp
//  shapes
//
//  Created by Ed Cole on 15/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <vector>
#include "point.hpp"
#include "polygon.hpp"
#include "exceptions.hpp"


class Builder{

    std::vector<Vertex*> verts;
    
public:
    
    Builder(){};
    
    Builder* init(){
        verts.clear();
        return this;
    };
    
    Builder* add(Vertex& v){
        verts.push_back(&v);
        return this;
    };
    
    template <typename SHAPE>   // Shape == Polygon, Triangle, Rectangle, Square
    SHAPE build(){
        // if vertices = 3 its a triangle
        // if vertices = 3 it's a quad
        // if all angles = 90, it's a rectangle
        // if sides equal its a square
        // rhomboid and parallelagram to consider
        SHAPE p;
        try{
            p =  SHAPE(verts);
        }
        catch(InvalidShapeException exc) {
                std::cout << "Bad Shape geometry " << std::endl;
                throw InvalidShapeException();
            }
            
        return p;
    };
    
};// Builder
