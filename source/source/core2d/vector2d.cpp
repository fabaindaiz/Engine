#include <cmath>
#include "vector2d.h"
#include "vector2d_functions.h"
#include "geometric_functions.h"

Vector2D::Vector2D(float x, float y):
    x(x), y(y)
{
}

float Vector2D::getX() const
{
    return x;
}

float Vector2D::getY() const
{
    return y;
}

void Vector2D::update(float A, float B)
{
    this -> x = x;
    this -> y = y;
}

float Vector2D::length() const
{
    return distance(Vector2D{0, 0}, Vector2D{x, y});
}

Vector2D Vector2D::normalized() const
{
    return Vector2D{ x, y } / this -> length();
}

bool Vector2D::is_normalized() const
{
    return (Vector2D{ x, y } == this->normalized());
}
