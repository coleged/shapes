//
//  exceptions.hpp
//  shapes
//
//  Created by Ed Cole on 10/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef exceptions_hpp
#define exceptions_hpp

struct InvalidShapeException : public std::exception{
    const char* what () const throw ();
};


#endif /* exceptions_hpp */
