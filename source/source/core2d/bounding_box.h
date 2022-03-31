#pragma once
#include "vector2d.h"

class BoundingBox
{
private:
    Vector2D position;
    Vector2D size;

public:
    BoundingBox() = delete;
    BoundingBox(const Vector2D& position, const Vector2D& size);

    Vector2D getPosition() const;
    Vector2D getSize() const;

    void update(const Vector2D& position, const Vector2D& size);

    void setPosition(const Vector2D& position);
    void setSize(const Vector2D& size);

    bool collide(const BoundingBox& box) const;
};
