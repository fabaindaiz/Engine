#include <cmath>
#include "geometric_functions.h"
#include "vector2d.h"
#include "vector2d_functions.h"

float distance(const Vector2D& lhs, const Vector2D& rhs)
{
    const Vector2D delta = lhs - rhs;
    const float squaredDistance = delta.getX() * delta.getX() + delta.getY() * delta.getY();
    return std::sqrt(squaredDistance);
}

