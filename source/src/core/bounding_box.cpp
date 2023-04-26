#include <cmath>
#include "bounding_box.h"
#include "vec2.h"
#include "vec2_functions.h"


namespace Engine
{

void BoundingBox::update(const Vec2& position, const Vec2& size)
{
    this -> mPosition = position;
    this -> mSize = size;
}

void BoundingBox::setPosition(const Vec2& position)
{
    this -> mPosition = position;
}

void BoundingBox::setSize(const Vec2& size)
{
    this -> mSize = size;
}

bool BoundingBox::inside(const Vec2& point)
{
    return true;
}

void BoundingBox::enclose(const Vec2& point)
{
    if (this -> inside(point))
        return;
    const Vec2 size = point - mPosition;
}

bool BoundingBox::collide(const BoundingBox& box) const
{
    const Vec2 distance = this -> position() - box.position();
    const Vec2 bounding = this -> size() + box.size();
    const bool collideX = ( std::abs(distance.x()) <= std::abs(bounding.x()) );
    const bool collideY = ( std::abs(distance.y()) <= std::abs(bounding.y()) );
    return ( collideX && collideY );
}

std::ostream& operator<< (std::ostream& os, const BoundingBox& box)
{
    return os << "BoundingBox " << "( " << box.position() << ", " << box.size() << ")";
}

} // namespace Engine