
#pragma once

#include <iostream>
#include "mesh.h"
#include "dmesh.h"


namespace Engine
{

struct ColorBoxShaderProgram
{
    GPUID shaderProgram;

    ColorBoxShaderProgram();

    void setupVAO(DMesh& dMesh) const;

    void drawCall(const DMesh& dMesh) const;
};


} // namespace Engine