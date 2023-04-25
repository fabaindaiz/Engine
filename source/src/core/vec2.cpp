#include <cmath>
#include "vec2.h"
#include "vec2_functions.h"


namespace Engine
{

void Vec2::update(float X, float Y)
{
    this -> mX = X;
    this -> mY = Y;
}

float Vec2::length() const
{
    return distance(Vec2{0, 0}, Vec2{mX, mY});
}

Vec2 Vec2::normalized() const
{
    return Vec2{ mX, mY } / this -> length();
}

bool Vec2::is_normalized() const
{
    return (*this == this -> normalized());
}

} // namespace Engine