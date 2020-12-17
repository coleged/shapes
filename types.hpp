//
//  types.hpp
//  shapes
//
//  Created by Ed Cole on 14/12/2020.
//  Copyright © 2020 colege. All rights reserved.
//

#ifndef types_h
#define types_h

enum shapeType {
                    CIRCLE,
                    RECTANGLE,
                    TRIANGLE };

enum colorType {
                    RED,
                    BLUE,
                    GREEN,
                    YELLOW
};

enum lineStyle {
                    SOLID,
                    DASHED
                };

enum lineWeight {
                    FINE,
                    MEDIUM,
                    THICK
                };

enum fillType   {
                    NOFILL,
                    FILL,
                    HASHED
                };

#endif /* types_h */
