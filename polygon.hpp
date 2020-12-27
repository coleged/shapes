//
//  polygon.hpp
//  shapes
//
//  Created by Ed Cole on 10/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <vector>

#ifndef polygon_hpp
#define polygon_hpp
#include "line.hpp"
#include "shape.hpp"

class Polygon:  public Shape{
    
friend class Triangle;

   
public:
    Polygon();
    
    Polygon(std::vector<Vertex*>);
    
    float area();
    float perimeter() final;
    
    Shape* mkLines();
    
    
};// Polygon



#endif /* polygon_hpp */
