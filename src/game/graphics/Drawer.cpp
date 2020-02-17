#include "Drawer.h"

using namespace game::graphics;

Drawer::Drawer(engine::render::Renderer * rend) : renderer{ rend } {}

Drawer::~Drawer() {}

void Drawer::drawUnit(const game::combat::Unit & unit, int x, int y, int width, int height) {
	renderer->renderSprite(unit.sprite, { x ,y,width,height });
}

void Drawer::drawUnitGrid(const game::combat::UnitGrid & unitGrid, int x, int y, int width, int height) {
	int unitWidth = width / unitGrid.GRID_DEPTH;
	int unitHeight = height / unitGrid.GRID_WIDTH;
	for (int i = 0; i < unitGrid.GRID_DEPTH; i++) {
		for (int j = 0; j < unitGrid.GRID_WIDTH; j++) {
			game::combat::Unit* unit = unitGrid.units[j][i].get();
			if (unit != nullptr) {
				drawUnit(*unit, x + i * unitWidth, y + j * unitHeight, unitWidth, unitHeight);
			}

		}
	}
}

void Drawer::drawBoard(const game::combat::Board & board) {

}
