#include "pch.h"
#include "CppUnitTest.h"

#include "UnitGrid.h"
#include "Unit.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EmissariesTest {
	TEST_CLASS(UnitGridTest) {
public:

	TEST_METHOD(addUnitTest) {
		game::combat::UnitGrid unitGrid;
		auto unit = std::make_shared<game::combat::Unit>();
		unitGrid.addUnit(1, 2, unit);
	}
	TEST_METHOD(getAllTest) {
		game::combat::UnitGrid unitGrid;

	}
	};
}
