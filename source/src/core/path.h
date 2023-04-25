#pragma once

#include <vector>
#include "vec2.h"


namespace Engine
{

class Path
{
private:
    std::vector<Vec2> mPoints;

public:
    Path() = default;

    Path& addDestination(const Vec2& point);

    Path& reverse();

    float length() const;

    Vec2 travel(float t) const;
};

} // namespace Engine