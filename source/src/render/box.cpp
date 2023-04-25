#include "box.h"
#include "core/vec2_functions.h"


namespace Engine
{

void Box::setPosition(const Vec2& position)
{
    this -> mPosition = position;
}

std::ostream& operator<<(std::ostream& os, const Box& box)
{
    return os << "[color=" << box.color() << "; bottomLeft=" << box.bottomLeft() << "; upperRight=" << box.upperRight() << "]";
}

} // namespace Engine