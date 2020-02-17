#pragma once

#include <array>
#include <vector>
#include <memory>
#include "Unit.h"

namespace game {
	namespace combat {
		class UnitGrid {
		public:
			UnitGrid();

			static const unsigned int GRID_WIDTH = 3;
			static const unsigned int GRID_DEPTH = 2;
			std::array<std::array < std::shared_ptr<Unit>, GRID_DEPTH>, GRID_WIDTH> units;
			
			~UnitGrid();
			void addUnit(unsigned int row, unsigned int column, std::shared_ptr<Unit> unit);
			std::vector<std::shared_ptr<Unit>> getAll();

		};
	}
}



