#include "actor.h"
#include "vector2d.h"
#include "vector2d_functions.h"
#include "bounding_box.h"

Actor::Actor(const Vector2D& position, const Vector2D& size, const Vector2D& velocity):
    position(position), size(size), velocity(velocity), bounding(BoundingBox{ position, size })
{
}

Vector2D Actor::getPosition() const
{
    return position;
}

Vector2D Actor::getSize() const
{
    return size;
}

Vector2D Actor::getVelocity() const
{
    return velocity;
}

BoundingBox Actor::getBounding() const
{
    return bounding;
}

void Actor::update(const Vector2D& position, const Vector2D& size, const Vector2D& velocity)
{
    this -> position = position;
    this -> size = size;
    this -> velocity = velocity;
    this -> bounding.update(position, size);
}

void Actor::setPosition(const Vector2D& position)
{
    this -> position = position;
    this -> bounding.setPosition(position);
}

void Actor::setSize(const Vector2D& size)
{
    this -> size = size;
    this -> bounding.setSize(size);
}

void Actor::setVelocity(const Vector2D& velocity)
{
    this -> velocity = velocity;
}

bool Actor::collide(const Actor& box) const
{
    return this -> getBounding().collide(box.getBounding());
}

void Actor::update(float delta_time)
{
    this -> position = position + ( delta_time * this -> getVelocity() );
    this -> bounding.setPosition(this -> position);
}
