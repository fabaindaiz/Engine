#include "vec2.h"
#include "vec2_functions.h"


namespace Engine
{

float distance(const Vec2& lhs, const Vec2& rhs)
{
    const Vec2 delta = lhs - rhs;
    const float squaredDistance = delta.x() * delta.x() + delta.y() * delta.y();
    return std::sqrt(squaredDistance);
}

bool operator== (const Vec2& lhs, const Vec2& rhs)
{
    return ( (lhs.x() == rhs.x()) && (lhs.y() == rhs.y()) );
}

Vec2 operator+ (const Vec2& lhs, const Vec2& rhs)
{
    return { lhs.x() + rhs.x(), lhs.y() + rhs.y() };
}

Vec2 operator- (const Vec2& lhs, const Vec2& rhs)
{
    return { lhs.x() - rhs.x(), lhs.y() - rhs.y() };
}

Vec2 operator* (const Vec2& lhs, float rhs)
{
    return { lhs.x() * rhs, lhs.y() * rhs };
}

Vec2 operator* (float lhs, const Vec2& rhs)
{
    return { lhs * rhs.x(), lhs * rhs.y() };
}

Vec2 operator/ (const Vec2& lhs, float rhs)
{
    return { lhs.x() / rhs, lhs.y() / rhs };
}

Vec2 operator/ (float lhs, const Vec2& rhs)
{
    return { lhs / rhs.x(), lhs / rhs.y() };
}

} // namespace Engine