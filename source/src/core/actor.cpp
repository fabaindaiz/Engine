#include "actor.h"
#include "vec2.h"
#include "vec2_functions.h"
#include "bounding_box.h"


namespace Engine
{

void Actor::update(const Vec2& position, const Vec2& size, const Vec2& velocity, const Vec2& acceleration)
{
    this -> mPosition = position;
    this -> mSize = size;
    this -> mVelocity = velocity;
    this -> mAcceleration = acceleration;
    this -> mBounding.update(position, size);
}

void Actor::setPosition(const Vec2& position)
{
    this -> mPosition = position;
    this -> mBounding.setPosition(position);
}

void Actor::setSize(const Vec2& size)
{
    this -> mSize = size;
    this -> mBounding.setSize(size);
}

void Actor::setVelocity(const Vec2& velocity)
{
    this -> mVelocity = velocity;
}

void Actor::setAcceleration(const Vec2& acceleration)
{
    this -> mAcceleration = acceleration;
}

bool Actor::collide(const Actor& actor) const
{
    return this -> bounding().collide(actor.bounding());
}

void Actor::update(float delta_time)
{
    this -> mVelocity = mVelocity + (delta_time * this -> acceleration());
    this -> mPosition = mPosition + (delta_time * this -> velocity());
    this -> mBounding.setPosition(this -> mPosition);
}

std::ostream& operator<< (std::ostream& os, const Actor& actor)
{
    return os << "Actor " << "( " << actor.position() << ", " << actor.size() << " )";
}

} // namespace Engine