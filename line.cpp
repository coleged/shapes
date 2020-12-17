//
//  Line.cpp
//  shapes
//
//  Created by Ed Cole on 09/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <vector>
#include "line.hpp"
#include <cmath>


    int Line::count = 1000;   // initialise Line counter outside class
    std::vector<Line> Line::myLines;    // initalise

    Line::Line(Vertex& a, Vertex& b, std::string n){
        A = &a;
        B = &b;
        name = n;
        ref = ++count;
        
        // debug
        myLines.push_back(*this);
        
    }
    Line::Line(float x1, float y1, float x2, float y2, std::string n){
        A = new Vertex(x1,y1);
        B = new Vertex(x2,y2);
        name = n;
        ref = ++count;
        
        // debug
        myLines.push_back(*this);
    }

    Point* Line::getA(){
        return A;
    }

    Point* Line::getB(){
        return B;
    }

    double Line::len(){
        double adj = A->getX() - B->getX();
        double opp = A->getY() - B->getY();
        double len = sqrt(adj*adj + opp*opp);
        
        return len;
    }

    double Line::product(Line l2){
    // vector product
    double ret =  (A->getX() - B->getX())*(l2.A->getX() - l2.B->getX()) +
                  (A->getY() - B->getY())*(l2.A->getY() - l2.B->getY())     ;
    
    return ret;
    }//product()

    double Line::cosAngle(Line l2) {
        // vector math shows that the cosine of angle between two vectors
        // is equal to the product of the two vectors divided by the product of
        // there determinants (lengths)
        
        double cosA = product(l2) / (len() * l2.len());
        
        return cosA;
    }//cosAngle()

    std::string Line::toString(){
        std::string ret = "R:" + std::to_string(ref)
                        + "\tA:" + A->toString()
                        + "\n"
                        + "\tB:" + B->toString()
                        + "\n"
                        + "\tL:" + std::to_string(len())
                        + " N:" + name;
        return ret;
    };

    

