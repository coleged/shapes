//
//  shape.cpp
//  shapes
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <iostream>
#include "point.hpp"
#include "shape.hpp"

int Shape::count = 2000;   // initialise Shape counter outside class
std::vector<Shape*> Shape::allMyShapes;    // initalise


Shape::~Shape(){};

Shape* Shape::setName(std::string n){
    name = n;
    return this;
};

// getters
std::string Shape::getName() const{
    return name;
};

std::string Shape::toString(){
    return name;
};

void Shape::printData(){
    std::cout << "Shape data" << std::endl;
    for( auto i : verts){
        std::cout << i->toString() << std::endl;
    }
}

float Shape::perimeter(){
    return 0.0;
}

float Shape::area(){
    return 0.0;
}


bool Shape::isValid(){
    return uniqueVertices();
}

bool Shape::uniqueVertices() {
    std::vector<Vertex*> v = verts; // method local copy of verts vector
    
    // sort vector of pointers with a compare predicate using functor
    // alphabetic sort or cartisian co-ordinates
    //      i.e. compare returns true is l < r where comaprison is first made
    //          with x and then if equal with y
    // Point::sort_point s;   // instantiate the sorting functor
    // std::sort(v.begin(), v.end(), s );
    //                      or
    // sort vector of pointers with a compare predicate using lambda function
    std::sort(v.begin(), v.end(), [] (Point* l, Point* r) -> bool {
                if( l->getX() < r->getX() ){
                            return true;
                }
                if( l->getX() == r->getX()){
                    if( l->getY() < r->getY()){
                            return true;
                    }
                }
                return false;
            }// lambda
                        );
    
    

    // delete duplicates with an identity predicate using functor
    // Point::same_point f;   // instantiate the identity functor
    // v.erase(std::unique(v.begin(), v.end(), f ),v.end());
    //                          or
    // delete duplicates with an identity predicate using lambda function
    v.erase(std::unique(v.begin(), v.end(), [] (Point* l, Point* r) -> bool {
            if( (l->getX()==r->getX()) && (l->getY()==r->getY()) )
                        return true;
                return false;
            }
                        ), v.end());
    if( v.size() != verts.size()){ // there are duplicates in verts
        return false;
    }
    return true;
}


int Shape::compare(Shape* to){
    if( area() < to->area()) return SMALLER;
    if( area() == to->area()) return SAME;
    return LARGER;
};

