#pragma once

#include "SDL.h"


namespace engine {
	namespace render {
		struct Sprite {
			SDL_Texture* texture;
			SDL_Rect source;
		};
	}
}