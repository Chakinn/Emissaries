#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <string>

namespace engine {
	namespace render {
		class TextureManager {
		public:
			TextureManager(SDL_Renderer* sdlRend);
			~TextureManager();

			SDL_Texture* loadTexture(const std::string& path);
			void initTextures();


		private:
			SDL_Renderer* sdlRenderer;
		};
	}
}
