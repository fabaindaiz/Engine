#pragma once

#include <vector>
#include <string>
#include <iostream>


namespace Engine
{

using Coord = float;
using Index = unsigned int;

using Vertices = std::vector<Coord>;
using Indices = std::vector<Index>;

struct Mesh
{
    Vertices vertices;
    Indices indices;
    std::string texture = "";
    std::size_t stride;

    Mesh(std::size_t stride_) : vertices{}, indices{}, texture(""), stride(stride_) {}
};

Mesh join(const Mesh& rhs, const Mesh& lhs);

std::ostream& operator<<(std::ostream& os, const Engine::Vertices& vertices);

std::ostream& operator<<(std::ostream& os, const Engine::Indices& indices);

std::ostream& operator<<(std::ostream& os, const Engine::Mesh& shape);

} // namespace Engine
