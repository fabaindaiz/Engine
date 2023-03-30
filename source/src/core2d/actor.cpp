#include "actor.h"
#include "vector2d.h"
#include "vector2d_functions.h"
#include "bounding_box.h"

Actor::Actor(const Vector2D& position, const Vector2D& size):
    position(position),
    size(size),
    velocity(Vector2D(0, 0)),
    acceleration(Vector2D(0, 0)),
    bounding(BoundingBox{ position, size })
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

Vector2D Actor::getAcceleration() const
{
    return acceleration;
}

BoundingBox Actor::getBounding() const
{
    return bounding;
}

void Actor::update(const Vector2D& position, const Vector2D& size, const Vector2D& velocity, const Vector2D& acceleration)
{
    this->position = position;
    this->size = size;
    this->velocity = velocity;
    this->acceleration = acceleration;
    this->bounding.update(position, size);
}

void Actor::setPosition(const Vector2D& position)
{
    this->position = position;
    this->bounding.setPosition(position);
}

void Actor::setSize(const Vector2D& size)
{
    this->size = size;
    this->bounding.setSize(size);
}

void Actor::setVelocity(const Vector2D& velocity)
{
    this->velocity = velocity;
}

void Actor::setAcceleration(const Vector2D& acceleration)
{
    this->acceleration = acceleration;
}

bool Actor::collide(const Actor& box) const
{
    return this->getBounding().collide(box.getBounding());
}

void Actor::update(float delta_time)
{
    this->velocity = velocity + (delta_time * this->getAcceleration());
    this->position = position + (delta_time * this->getVelocity());
    this->bounding.setPosition(this->position);
}
