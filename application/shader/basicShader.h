#pragma once

#include "shaderBase.h"

namespace P3D::Application {
using namespace Graphics;

namespace Comp {
struct Material;
};

struct ExtendedPart;

struct BasicShader : public StandardMeshShaderBase, public BasicShaderBase {
	inline BasicShader() : StandardMeshShaderBase(), BasicShaderBase(), ShaderResource() {}
	inline BasicShader(ShaderSource shaderSource) : StandardMeshShaderBase(shaderSource.name, shaderSource.path, shaderSource), BasicShaderBase(shaderSource.name, shaderSource.path, shaderSource), ShaderResource(shaderSource.name, shaderSource.path, shaderSource) {}

	void updatePart(const ExtendedPart& part);
	void updateTexture(bool textured);
	void updateMaterial(const Comp::Material& material);
};

struct InstanceShader : public InstancedMeshShaderBase, public BasicShaderBase {
	inline InstanceShader() : InstancedMeshShaderBase(), BasicShaderBase(), ShaderResource() {}
	inline InstanceShader(ShaderSource shaderSource) : InstancedMeshShaderBase(shaderSource.name, shaderSource.path, shaderSource), BasicShaderBase(shaderSource.name, shaderSource.path, shaderSource), ShaderResource(shaderSource.name, shaderSource.path, shaderSource) {}

	void updateTexture(bool textured);
};

};