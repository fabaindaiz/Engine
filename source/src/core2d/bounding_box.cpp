#include <cmath>
#include "bounding_box.h"
#include "vector2d.h"
#include "vector2d_functions.h"

BoundingBox::BoundingBox(const Vector2D& position, const Vector2D& size):
    position(position), size(size)
{
}

Vector2D BoundingBox::getPosition() const
{
    return position;
}

Vector2D BoundingBox::getSize() const
{
    return size;
}

void BoundingBox::update(const Vector2D& position, const Vector2D& size)
{
    this -> position = position;
    this -> size = size;
}

void BoundingBox::setPosition(const Vector2D& position)
{
    this -> position = position;
}

void BoundingBox::setSize(const Vector2D& size)
{
    this -> size = size;
}

bool BoundingBox::inside(const Vector2D& point)
{
    return true;
}

void BoundingBox::enclose(const Vector2D& point)
{
    if (this -> inside(point))
        return;
    const Vector2D size = point - position;
}

bool BoundingBox::collide(const BoundingBox& box) const
{
    const Vector2D distance = this -> getPosition() - box.getPosition();
    const Vector2D bounding = this -> getSize() + box.getSize();
    const bool collideX = ( std::abs(distance.getX()) <= std::abs(bounding.getX()) );
    const bool collideY = ( std::abs(distance.getY()) <= std::abs(bounding.getY()) );
    return ( collideX && collideY );
}


