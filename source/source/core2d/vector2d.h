#pragma once

class Vector2D
{
private:
    float x, y;

public:
    Vector2D() = delete;
    Vector2D(float A, float B);

    float getX() const;
    float getY() const;

    void update(float A, float B);

    float length() const;
    Vector2D normalized() const;

    bool is_normalized() const;
};
