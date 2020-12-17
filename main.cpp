//
//  main.cpp
//  shapes
//
//  This is a grap bag of code used as ongoing development of the set of shape
//      classes over a period of study in C++
//  It and the classes present examples of
//      Inheritance
//      Polymorphism
//      Exception handling
//      Templates
//      Functors
//      Lambda functions
//      builder object instantiation
//
//  Created by colege@gmail.com on 08/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <iostream>
#include <vector>

#include "point.hpp"
#include "line.hpp"
#include "shape.hpp"
#include "polygon.hpp"
#include "triangle.hpp"
#include "exceptions.hpp"

#include "builder.cpp" // shouldn't do this. Just a temp measure while testing Builder Template


int main(int argc, const char * argv[]) {
    
    
    
    Vertex A(1,1); A.setName("A");
    std::cout << "A " << A.toString() << std::endl;
    Vertex B(2,2);B.setName("B");
    std::cout << "B " << B.toString() << std::endl;
    
    Vertex v1(0,0,"v1");
    Vertex v2(7,0,"v2");
    Vertex v3(7,7,"v3");
    Vertex v4(0,7,"v4");
    Vertex v5(7,0,"v5"); // same as v2 to test InvalidShapeException
    Vertex v6(-5,7,"v6");
    
    //Point C;      // doing it this was causes an extra Point object and increments
    //C = A + B;    // Point::count by 2. i.e. +1 when C is declared then another
                    // (A + B) which is destoyed when it is assigned to C
    Point C = A + B;// This way, C is declared and initialised to A + B, so only one object
                    // is created and ref is only incremented once
    C.setName("C");
    
    std::cout << "A + B = " << C.getX() << ","
                            << C.getY() << std::endl;
    std::cout << "C " << C.toString() << std::endl;
    std::cout << "A " << A.toString() << std::endl;
    std::cout << "B " << B.toString() << std::endl;
    
    std::cout << "C " << C.toString() << std::endl;
    Point D = C + A;
    D.setName("D");
    std::cout << "D " << D.toString() << std::endl;
    
    Point E(D);
    std::cout << "E " << E.toString() << std::endl;
    Point F = D;
    std::cout << "F " << F.toString() << std::endl;
    F.setName("F");
    // create line between A and B
    std::cout << "Create Line" << std::endl;
    Line l1(A,B);
    std::cout << l1.toString() << std::endl;
    std::cout << "check out line A Point" << std::endl;
    std::cout << l1.getA()->toString() << std::endl;
    std::cout << "Change A Point of line" << std::endl;
    A.setY(21);
    std::cout << "now details of line should have changed" << std::endl;
    std::cout << l1.toString() << std::endl;
    if (F == D) std::cout << "F & D are the same" << std::endl;
    if (F != A) std::cout << "F & A are NOT the same" << std::endl;
    
    std::cout << "Testing custom exception handling" << std::endl;
    try{
        throw InvalidShapeException();
    }catch(InvalidShapeException& ex){
        std::cout << "TESTING: ";
        std::cout << ex.what() << std::endl;
    }
    // Playing with Polygon Builder
    //
    std::cout << "Playing with Polygon Builder" << std::endl;
    Builder* b = new Builder;
    //b->add(v1);
    b->add(v2);
    b->add(v3);
    b->add(v4);
    Polygon P = b->build<Polygon>();
    delete b;
    P.printData();
    Builder* q = new Builder;
    Polygon P1 = q->add(v1)->add(v2)->add(v3)->add(v4)->build<Polygon>();
    P1.printData();
    
    std::cout << "Shapes" << std::endl;
    
    std::cout << "Triangles" << std::endl;
    std::vector<Shape> myShapes;
    Triangle* t1;
    try {
        t1 = new Triangle(v1,v2,v3);
        t1->setName("Triangle 1");
        myShapes.push_back(*t1);
    }
    catch(InvalidShapeException exc) {
        std::cout << "Triangle - oops: " << std::endl;
        exit(0);
    }
    t1->printData();
    
    q->init(); // reset builder
    Polygon p2 =  q->add(v1)->add(v3)->add(v6)->build<Polygon>();
    Triangle t2(p2);
    
    // Is there a Triangle Builder
    
        std::cout << "ALL MY LINES" << std::endl;
        for( auto line : Line::myLines){
            std::cout << line.toString() << std::endl;
        }
    std::cout << "T1 Area " << t1->area() << std::endl;
    std::cout << "T2 Area " << t2.area() << std::endl;
    
    Builder* tb = new Builder;
    //b->add(v1);
    tb->add(v2);
    tb->add(v3);
    tb->add(v4);
    Polygon t3 = tb->build<Polygon>();
    std::cout << "Stand alone builder"  << std::endl;
    Builder* sab = new Builder;
    sab->init();
    Polygon P3 = sab->add(v1)->add(v2)->add(v3)->add(v4)->build<Polygon>();
    P3.printData();
    sab->init();
    
    Triangle T3;
    try{
        T3 = sab->add(v1)->add(v2)->add(v3)->build<Triangle>();
    }
    catch(InvalidShapeException exc) {
        std::cout << "Triangle - oops: " << std::endl;
    }
    T3.printData();
   
    return 0;
}
