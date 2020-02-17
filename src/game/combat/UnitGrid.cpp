#include "UnitGrid.h"

using namespace game::combat;

game::combat::UnitGrid::UnitGrid() {}

game::combat::UnitGrid::~UnitGrid() {}

void game::combat::UnitGrid::addUnit(unsigned int row, unsigned int column, std::shared_ptr<Unit> unit) {
	units[row][column] = unit;
}

std::vector<std::shared_ptr<Unit>> game::combat::UnitGrid::getAll() {
	std::vector<std::shared_ptr<Unit>> allUnits;
	for (auto column : units) {
		for (auto unit : column) {
			allUnits.push_back(unit);
		}
	}
	return allUnits;
}
