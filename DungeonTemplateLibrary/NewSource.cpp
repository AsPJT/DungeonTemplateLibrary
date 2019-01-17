#include "DTL.hpp"
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t x_size{ 12 };
	constexpr std::size_t y_size{ 8 };

	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_array{ {} };
	dungeon_t dungeon_default_array[y_size][x_size]{};

	dtl::dungeonInit(dungeon_default_array, x_size, y_size);

	dtl::Chess<dungeon_t> chess(dungeon_stl_array);
	dtl::dungeonStringOutput(dungeon_stl_array, "　", "１", "一", "２", "二", "３", "三", "４", "四", "５", "五", "６", "六");

	dtl::PointGridField<dungeon_t> pgf(dungeon_default_array, x_size, y_size);
	dtl::dungeonStringOutputBool(dungeon_default_array, x_size, y_size, "■", "　");

	return 0;
}