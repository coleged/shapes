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
    std::vector<Line*> Line::allMyLines;    // initalise

    Line::Line(Vertex* a, Vertex* b, std::string n){
        A = a;
        B = b;
        name = n;
        ref = ++count;
        
        // debug
        allMyLines.push_back(this);
        
    }
    Line::Line(float& x1, float& y1, float& x2, float& y2, std::string n){
        A = new Vertex(x1,y1);
        B = new Vertex(x2,y2);
        name = n;
        ref = ++count;
        
        // debug
        allMyLines.push_back(this);
    }

    Point* Line::getA() const{
        return A;
    }

    Point* Line::getB() const{
        return B;
    }

    int Line::getRef() const{
        return ref;
    }

    float Line::len() const{
        const float& adj = A->getX() - B->getX();
        const float& opp = A->getY() - B->getY();
        const float& len = sqrt(adj*adj + opp*opp);
        
        return len;
    }

    float Line::product(Line* l2) const{
    // vector product
    const float& ret =  (A->getX() - B->getX())*(l2->A->getX() - l2->B->getX()) +
                  (A->getY() - B->getY())*(l2->A->getY() - l2->B->getY())     ;
    
    return ret;
    }//product()

    float Line::cosAngle(Line* l2) const{
        // vector math shows that the cosine of angle between two vectors
        // is equal to the product of the two vectors divided by the product of
        // there determinants (lengths)
        
        const float& cosA = product(l2) / (len() * l2->len());
        
        return cosA;
    }//cosAngle()

    bool Line::rightAngle(Line* l2) const{
        //std::cout << this->getRef() << "with" << l2->getRef() << std::endl;
        if (cosAngle(l2) == 0) return true;
        return false;
    }

    std::string Line::toString() const{
        std::string ret = "R:" + std::to_string(ref)
                        + "\tA:" + A->toString()
                        + "\n"
                        + "\tB:" + B->toString()
                        + "\n"
                        + "\tL:" + std::to_string(len())
                        + " N:" + name;
        return ret;
    };

    

