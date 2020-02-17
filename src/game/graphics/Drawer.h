#pragma once

#include "Renderer.h"
#include "Board.h"

namespace game {
	namespace graphics {
		class Drawer {
		public:
			Drawer(engine::render::Renderer* rend);
			~Drawer();

			void drawUnit(const game::combat::Unit& unit, int x, int y, int width, int height);
			void drawUnitGrid(const game::combat::UnitGrid& unitGrid, int x, int y, int width, int height);
			void drawBoard(const game::combat::Board& board);
		private:
			engine::render::Renderer* renderer;

		};
	}
}



