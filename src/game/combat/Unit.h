#pragma once

#include "Sprite.h"

namespace game {
	namespace combat {
		class Unit {
		public:
			Unit(const engine::render::Sprite& sprit);

			engine::render::Sprite sprite;

			~Unit();

		private:

		};
	}
}


