#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include "SDLException.h"
#include "Sprite.h"

namespace engine {
	namespace render {
		class Renderer {
		public:
			Renderer();

			int windowWidth = 800;
			int windowHeight = 600;

			~Renderer();

			void initView();
			void renderClear();
			void renderPresent();
			void renderSprite(const Sprite& sprite, const SDL_Rect& destination);

			SDL_Texture* loadTexture(const std::string& path);

		private:
			SDL_Window* sdlWindow;
			SDL_Renderer* sdlRenderer;
		};
	}
}



