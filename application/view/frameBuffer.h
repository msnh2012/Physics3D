#pragma once

#include "texture.h"
#include "renderBuffer.h"
#include "bindable.h"
#include "../engine/math/vec2.h"

class FrameBuffer : public Bindable {
public:
	Vec2i dimension;

	Texture* texture = nullptr;
	RenderBuffer* renderBuffer = nullptr;
	
	FrameBuffer();
	FrameBuffer(unsigned int width, unsigned int height);
	FrameBuffer(Texture* colorAttachment, RenderBuffer* depthStencilAttachment);

	void resize(Vec2i dimension);

	void bind() override;
	void unbind() override;
	void close() override;

	void attach(Texture* texture); 
	void attach(RenderBuffer* renderBuffer);
};

class DepthFrameBuffer : public Bindable {
public:
	unsigned int width;
	unsigned int height;
	DepthTexture* texture = nullptr;

	DepthFrameBuffer(unsigned int width, unsigned int height);

	void bind() override;
	void unbind() override;
	void close() override;
};