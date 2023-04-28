
#pragma once

#include <iostream>
#include "glad/glad.h"
#include "mesh.h"
#include "dmesh.h"


namespace Engine
{

/* Convenience function to ease initialization */
template <typename PipelineT>
DMesh toDevice(const PipelineT& pipeline, const Mesh& mesh, GPUID usage = GL_STATIC_DRAW)
{
    DMesh dMesh;
    dMesh.initBuffers();
    pipeline.setupVAO(dMesh);
    dMesh.fillBuffers(mesh, usage);
    return dMesh;
}

struct ColorBoxShaderProgram
{
    GPUID shaderProgram;

    ColorBoxShaderProgram();

    void setupVAO(DMesh& dMesh) const;

    void drawCall(const DMesh& dMesh) const;
};


} // namespace Engine