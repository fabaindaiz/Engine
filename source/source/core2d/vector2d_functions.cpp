#include "vector2d.h"
#include "vector2d_functions.h"

std::ostream& operator<< (std::ostream& os, const Vector2D& vector)
{
    return os << "Vector2D "
        << "( " << vector.getX()
        << ", " << vector.getY()
        << ")";
}

bool operator== (const Vector2D& lhs, const Vector2D& rhs)
{
    return ( (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()) );
}

Vector2D operator+ (const Vector2D& lhs, const Vector2D& rhs)
{
    return { lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY() };
}

Vector2D operator- (const Vector2D& lhs, const Vector2D& rhs)
{
    return { lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY() };
}

Vector2D operator* (const Vector2D& lhs, float rhs)
{
    return { lhs.getX() * rhs, lhs.getY() * rhs };
}

Vector2D operator* (float lhs, const Vector2D& rhs)
{
    return { lhs * rhs.getX(), lhs * rhs.getY() };
}

Vector2D operator/ (const Vector2D& lhs, float rhs)
{
    return { lhs.getX() / rhs, lhs.getY() / rhs };
}

Vector2D operator/ (float lhs, const Vector2D& rhs)
{
    return { lhs / rhs.getX(), lhs / rhs.getY() };
}