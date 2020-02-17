#include "TextureManager.h"

using namespace engine::render;

engine::render::TextureManager::TextureManager() {}

void engine::render::TextureManager::setSDLRenderer(SDL_Renderer * renderer) {
	sdlRenderer = renderer;
}

TextureManager::~TextureManager() {}

SDL_Texture* TextureManager::loadTexture(const std::string& path) {
	SDL_Texture* tex = IMG_LoadTexture(sdlRenderer, path.c_str());
	if (tex == nullptr) {
		std::string errorMsg = "SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError());
		throw SDLException(errorMsg);
	}
	return tex;
}

void TextureManager::initTextures() {
	std::string spritePath = "res/spritesheets/weapons.png";
	SDL_Texture* weapons = loadTexture(spritePath);
	textures.insert(std::make_pair("weapons", weapons));
}