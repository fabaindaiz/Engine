#include "box.h"
#include "core2d/vec2_functions.h"


namespace Engine
{

std::ostream& operator<<(std::ostream& os, const Box& box)
{
    return os << "[color=" << box.color() << "; bottomLeft=" << box.bottomLeft() << "; upperRight=" << box.upperRight() << "]";
}

} // namespace Engine