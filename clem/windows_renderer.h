// Copyright 2020 SMS
// License(Apache-2.0)
// Windows äÖÈ¾Æ÷

#ifndef CLEM_WINDOWS_RENDERER_H_
#define CLEM_WINDOWS_RENDERER_H_

#include "common.hpp"
#include <clem/renderer.h>

#ifdef OS_WIN

#include <vector>
#include <windows.h>

class WindowsRenderer : public Renderer
{
public:
	void render() override;
	void draw(const Texture& texture, const Coord& coord) override;
	void clear() override;

private:
	std::vector<CHAR_INFO> buffer;
};

#endif OS_WIN

#endif // CLEM_WINDOWS_RENDERER_H_
