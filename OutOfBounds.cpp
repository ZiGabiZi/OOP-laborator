#include "OutOfBounds.h"
#include <iostream>
using namespace std;

const char* OutOfBounds::what() const noexcept {
    return "Indexul este in afara intervalului!";
}