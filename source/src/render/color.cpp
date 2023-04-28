#include "color.h"

namespace Engine
{

std::ostream& operator<<(std::ostream& os, const Color& color)
{
    return os << "(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
}

} // namespace Engine