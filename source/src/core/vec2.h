#pragma once

#include <iostream>


namespace Engine
{

class Vec2
{
private:
    float mX, mY;

public:
    Vec2() = delete;

    Vec2(float x, float y) :
        mX(x), mY(y)
    {
    }

    float& x()
    {
        return mX;
    }

    const float& x() const
    {
        return mX;
    }

    float& y()
    {
        return mY;
    }

    const float& y() const
    {
        return mY;
    }

    void update(float x, float y);

    float length() const;
    Vec2 normalized() const;

    bool is_normalized() const;
};

} // namespace Engine