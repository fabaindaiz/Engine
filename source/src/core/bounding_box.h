#pragma once

#include "Vec2.h"


namespace Engine
{

class BoundingBox
{
private:
    Vec2 mPosition;
    Vec2 mSize;

public:
    BoundingBox() = delete;
    BoundingBox(const Vec2& position, const Vec2& size) :
        mPosition(position),
        mSize(size)
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

    void update(const Vec2& position, const Vec2& size);

    void setPosition(const Vec2& position);
    void setSize(const Vec2& size);

    bool inside(const Vec2& point);
    void enclose(const Vec2& point);

    bool collide(const BoundingBox& box) const;
};

std::ostream& operator<< (std::ostream& os, const BoundingBox& box);

} // namespace Engine