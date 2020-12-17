//
//  triangle.hpp
//  shapes
//
//  Created by Ed Cole on 11/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "polygon.hpp"



class Triangle: public Polygon {

public:
    
    Triangle();

    Triangle(Vertex&, Vertex&, Vertex&);
    Triangle(std::vector<Vertex*>);
    Triangle(Polygon&);

    double area();
};

#endif /* triangle_hpp */
