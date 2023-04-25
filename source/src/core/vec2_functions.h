#pragma once

#include <iostream>
#include "vec2.h"


namespace Engine
{

std::ostream& operator<< (std::ostream& os, const Vec2& vector);

bool operator== (const Vec2& lhs, const Vec2& rhs);

Vec2 operator+ (const Vec2& lhs, const Vec2& rhs);

Vec2 operator- (const Vec2& lhs, const Vec2& rhs);

Vec2 operator* (const Vec2& lhs, float rhs);

Vec2 operator* (float lhs, const Vec2& rhs);

Vec2 operator/ (const Vec2& lhs, float rhs);

Vec2 operator/ (float lhs, const Vec2& rhs);

float distance(const Vec2& lhs, const Vec2& rhs);

} // namespace Engine