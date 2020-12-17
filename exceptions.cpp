//
//  exceptions.cpp
//  shapes
//
//  Created by Ed Cole on 10/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#include <iostream>
#include <exception>
#include "exceptions.hpp"

const char* InvalidShapeException::what () const throw ()
{
    return "Invalid Shape Exception";
}
