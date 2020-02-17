#pragma once

#include "UnitGrid.h"

namespace game {
	namespace combat {
		class Board {
		public:
			Board();

			UnitGrid allyUnitGrid;
			UnitGrid enemyUnitGrid;

			~Board();

		private:

		};
	}
}



