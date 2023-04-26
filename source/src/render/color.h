#pragma once

#include <iostream>


namespace Engine
{

struct Color
{
    float r,g,b,a;

    Color(): r(1.f), g(1.f), b(1.f), a(1.f) {}
    Color(float gray): r(gray), g(gray), b(gray), a(1.f) {}
    Color(float r_, float g_, float b_): r(r_), g(g_), b(b_), a(1.f) {}
    Color(float r_, float g_, float b_, float a_): r(r_), g(g_), b(b_), a(a_) {}

    static Color Black(){   return Color(0,0,0);}
    static Color Gray(){    return Color(0.5,0.5,0.5);}
    static Color Silver(){  return Color(0.75,0.75,0.75);}
    static Color White(){   return Color(1,1,1);}
    
    static Color Navy(){    return Color(0,0,0.5);}
    static Color Blue(){    return Color(0,0,1);}
    static Color Teal(){    return Color(0,0.5,0.5);}
    static Color Aqua(){    return Color(0,1,1);}
    
    static Color Green(){   return Color(0,0.5,0);}
    static Color Lime(){    return Color(0,1,0);}
    static Color Olive(){   return Color(0.5,0.5,0);}
    static Color Yellow(){  return Color(1,1,0);}
    
    static Color Maroon(){  return Color(0.5,0,0);}
    static Color Red(){     return Color(1,0,0);}
    static Color Purple(){  return Color(0.5,0,0.5);}
    static Color Fuchsia(){ return Color(1,0,1);}
};

std::ostream& operator<<(std::ostream& os, const Color& color);

} // namespace Engine