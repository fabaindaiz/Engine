#pragma once
#include <iostream>
#include "vector2d.h"

std::ostream& operator<< (std::ostream& os, const Vector2D& vector);

bool operator== (const Vector2D& lhs, const Vector2D& rhs);

Vector2D operator+ (const Vector2D& lhs, const Vector2D& rhs);

Vector2D operator- (const Vector2D& lhs, const Vector2D& rhs);

Vector2D operator* (const Vector2D& lhs, float rhs);

Vector2D operator* (float lhs, const Vector2D& rhs);

Vector2D operator/ (const Vector2D& lhs, float rhs);

Vector2D operator/ (float lhs, const Vector2D& rhs);