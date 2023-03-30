#pragma once
#include "vector2d.h"
#include "bounding_box.h"

class Actor
{
private:
    Vector2D position;
    Vector2D size;
    Vector2D velocity;
    Vector2D acceleration;
    BoundingBox bounding;

public:
    Actor() = delete;
    Actor(const Vector2D& position, const Vector2D& size);

    Vector2D getPosition() const;
    Vector2D getSize() const;
    Vector2D getVelocity() const;
    Vector2D getAcceleration() const;
    BoundingBox getBounding() const;

    void update(const Vector2D& position, const Vector2D& size, const Vector2D& velocity, const Vector2D& acceleration);

    void setPosition(const Vector2D& position);
    void setSize(const Vector2D& size);
    void setVelocity(const Vector2D& velocity);
    void setAcceleration(const Vector2D& acceleration);

    bool collide(const Actor& box) const;

    void update(float delta_time);
};
