#include "Renderer.h"
using namespace engine::render;

Renderer::Renderer() {
	initView();
}

Renderer::~Renderer() {
	if (sdlRenderer != nullptr) {
		SDL_DestroyRenderer(sdlRenderer);
	}
	if (sdlWindow != nullptr) {
		SDL_DestroyWindow(sdlWindow);
	}
	SDL_Quit();
}

void Renderer::initView() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::string errorMsg = "SDL_Init Error: " + std::string(SDL_GetError());
		throw SDLException(errorMsg);
	}
	sdlWindow = SDL_CreateWindow("hello world", 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (sdlWindow == nullptr) {
		std::string errorMsg = "SDL_CreateWindow Error: " + std::string(SDL_GetError());
		throw SDLException(errorMsg);
	}
	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (sdlRenderer == nullptr) {
		std::string errorMsg = "SDL_CreateRenderer Error: " + std::string(SDL_GetError());
		throw SDLException(errorMsg);
	}
}

void Renderer::renderClear() {
	SDL_RenderClear(sdlRenderer);
}

void Renderer::renderPresent() {
	SDL_RenderPresent(sdlRenderer);
}

void Renderer::renderSprite(const Sprite& sprite, const Rectangle& destination) {
	SDL_Rect src = createSDLRect(sprite.source);
	SDL_Rect dst = createSDLRect(destination);

	SDL_RenderCopy(sdlRenderer, sprite.texture, &src, &dst);
}

SDL_Texture * engine::render::Renderer::loadTexture(const std::string & path) {
	SDL_Texture* tex = IMG_LoadTexture(sdlRenderer, path.c_str());
	if (tex == nullptr) {
		std::string errorMsg = "SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError());
		throw SDLException(errorMsg);
	}
	return tex;
}

SDL_Rect Renderer::createSDLRect(const Rectangle& rectangle) {
	SDL_Rect sdlRect = { rectangle.x,rectangle.y,rectangle.width,rectangle.height };
	return sdlRect;
}


