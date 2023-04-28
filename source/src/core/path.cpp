#include <cmath>
#include <vector>
#include "path.h"
#include "vec2.h"
#include "vec2_functions.h"


namespace Engine
{

Path& Path::addDestination(const Vec2& point)
{
    this -> mPoints.push_back(point);
    return *this;
}

Path& Path::reverse()
{
    std::reverse(mPoints.begin(), mPoints.end());
    return *this;
}

float Path::length() const
{
    float length = 0;
    for (int i = 0; i < mPoints.size() - 1; i++) {
        length += distance(mPoints[i], mPoints[i + 1]);
    }
    return length;
}

Vec2 Path::travel(float t) const
{
    float total_dist = length() * fmod(t, 1.f);
    float dist = 0;
    for (int i = 0; i < mPoints.size() - 1; i++) {
        float dist_to_next = distance(mPoints[i], mPoints[i + 1]);

        if (dist + dist_to_next < total_dist) {
            dist += dist_to_next;
            continue;
        }
        
        float d = (total_dist - dist) / dist_to_next;
        return mPoints[i] + (d * (mPoints[i + 1] - mPoints[i]));
    }
}

std::ostream& operator<< (std::ostream& os, const Path& path)
{
    return os << "Path " << "( " << path.length() << " )";
}

} // namespace Engine