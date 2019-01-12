#include "DTL.hpp"
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	std::array<std::array<dungeon_t, 21>, 21> dungeon{ {} };

	dtl::PointGridField<dungeon_t> point_grid_field(dungeon);
	dtl::dungeonStringOutputBool(dungeon, "#", " ");

	return 0;
}