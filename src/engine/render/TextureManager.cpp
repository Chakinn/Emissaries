#include "TextureManager.h"

using namespace engine::render;

TextureManager::TextureManager(SDL_Renderer * sdlRend) : sdlRenderer{ sdlRend } {}

TextureManager::~TextureManager() {}

SDL_Texture* TextureManager::loadTexture(const std::string& path) {
	SDL_Texture* tex = IMG_LoadTexture(sdlRenderer, path.c_str());
	if (tex == nullptr) {
		std::string errorMsg = "SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError());
		SDL_Quit();
	}
	return tex;
}

void TextureManager::initTextures() {
	std::string spritePath = "res/images/breakout_spritesheet.png";
	SDL_Texture* sprites = loadTexture(spritePath);
}