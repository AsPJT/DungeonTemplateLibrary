#include "DTL.hpp"
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	std::array<std::array<dungeon_t, 8>, 8> dungeon{ {} };

	dtl::Chess<dungeon_t> chess(dungeon);
	dtl::dungeonStringOutput(dungeon, "　", "１", "一", "２", "二", "３", "三", "４", "四", "５", "五", "６", "六");

	return 0;
}