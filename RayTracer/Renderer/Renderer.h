#pragma once
#include "Canvas.h"
#include <SDL.h>

struct Ray;
class Object;

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();

	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, Object* object);

	friend class Canvas;

private:
	color3 GetBackgroundFromRay(const Ray& ray);
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
};