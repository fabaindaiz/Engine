#pragma once

#include "vec2.h"
#include "bounding_box.h"


namespace Engine
{

class Actor
{
private:
    Engine::Vec2 mPosition;
    Engine::Vec2 mSize;
    Engine::Vec2 mVelocity;
    Engine::Vec2 mAcceleration;
    Engine::BoundingBox mBounding;

public:
    Actor() = delete;
    Actor(const Vec2& position, const Vec2& size) :
        mPosition(position),
        mSize(size),
        mVelocity(Vec2(0, 0)),
        mAcceleration(Vec2(0, 0)),
        mBounding(BoundingBox{ position, size })
    {
    }

    Vec2& position()
    {
        return mPosition;
    }

    const Vec2& position() const
    {
        return mPosition;
    }

    Vec2& size()
    {
        return mSize;
    }

    const Vec2& size() const
    {
        return mSize;
    }

    Vec2& velocity()
    {
        return mVelocity;
    }

    const Vec2& velocity() const
    {
        return mVelocity;
    }

    Vec2& acceleration()
    {
        return mAcceleration;
    }

    const Vec2& acceleration() const
    {
        return mAcceleration;
    }

    BoundingBox& bounding()
    {
        return mBounding;
    }

    const BoundingBox& bounding() const
    {
        return mBounding;
    }

    void update(const Vec2& position, const Vec2& size, const Vec2& velocity, const Vec2& acceleration);

    void setPosition(const Vec2& position);
    void setSize(const Vec2& size);
    void setVelocity(const Vec2& velocity);
    void setAcceleration(const Vec2& acceleration);

    bool collide(const Actor& actor) const;

    void update(float delta_time);
};

} // namespace Engine