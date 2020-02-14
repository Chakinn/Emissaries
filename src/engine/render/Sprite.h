#pragma once

#include "SDL.h"
#include "Rectangle.h"

namespace engine {
	namespace render {
		struct Sprite {
			SDL_Texture* texture;
			Rectangle source;
		};
	}
}