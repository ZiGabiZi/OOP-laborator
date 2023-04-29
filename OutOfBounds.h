#include "exception"
#include <iostream>
#ifndef OOP_OUTOFBOUNDS_H
#define OOP_OUTOFBOUNDS_H

class OutOfBounds: public std::exception{
public:
    const char* what() const noexcept override;


};

#endif //OOP_OUTOFBOUNDS_H
