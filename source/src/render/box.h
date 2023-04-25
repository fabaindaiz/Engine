#pragma once

#include <iostream>
#include "core/vec2.h"
#include "color.h"


namespace Engine
{

class Box
{
private:
    Vec2 mPosition;
    Vec2 mSize;
    Color mColor;

public:
    Box() = delete;

    Box(const Vec2& position, const Vec2& size, const Color& color) :
        mPosition(position),
        mSize(size),
        mColor(color)
    {}

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

    Color& color()
    {
        return mColor;
    }

    const Color& color() const
    {
        return mColor;
    }

    Vec2 bottomLeft() const
    {
        return { mSize.x() / -2.0f, mSize.y() / -2.0f };
    }

    Vec2 bottomRight() const
    {
        return { mSize.x() / 2.0f, mSize.y() / -2.0f };
    }

    Vec2 upperLeft() const
    {
        return { mSize.x() / -2.0f, mSize.y() / 2.0f };
    }

    Vec2 upperRight() const
    {
        return { mSize.x() / 2.0f, mSize.y() / 2.0f };
    }

    void setPosition(const Vec2& position);
};

std::ostream& operator<<(std::ostream& os, const Box& box);

} // namespace Engine