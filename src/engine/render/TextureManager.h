#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDLException.h"
#include <string>
#include <unordered_map>

namespace engine {
	namespace render {
		class TextureManager {
		public:
			std::unordered_map<std::string, SDL_Texture*> textures;
			TextureManager();
			void setSDLRenderer(SDL_Renderer* renderer);
			~TextureManager();

			SDL_Texture* loadTexture(const std::string& path);
			void initTextures();


		private:
			SDL_Renderer* sdlRenderer;

		};
	}
}
