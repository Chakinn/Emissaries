#pragma once

#include <unordered_map>
#include <string>
#include "Sprite.h"

namespace game {
	namespace graphics {
		class SpriteManager {
		public:
			SpriteManager();
			~SpriteManager();

			std::string addSprite(const engine::render::Sprite& sprite);
			engine::render::Sprite getSprite(const std::string& spriteId);

		private:
			std::unordered_map<std::string, engine::render::Sprite> sprites;
			unsigned int currentSpriteId = 0;
			std::string newId();
		};
	}
}

