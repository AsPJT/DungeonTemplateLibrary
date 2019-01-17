#include "DTL.hpp"
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t x_size{ 17 };
	constexpr std::size_t y_size{ 11 };

	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix{ {} };
	dungeon_t dungeon_default_matrix[y_size][x_size]{};
	dungeon_t dungeon_array_matrix[x_size*y_size]{};

	dtl::dungeonInit(dungeon_default_matrix, x_size, y_size);
	dtl::dungeonInit_Array(dungeon_array_matrix, x_size, y_size);

	dtl::Chess<dungeon_t> chess(dungeon_stl_matrix);
	dtl::dungeonStringOutput(dungeon_stl_matrix, "　", "１", "一", "２", "二", "３", "三", "４", "四", "５", "五", "６", "六");

	dtl::PointGridField<dungeon_t> pgf(dungeon_default_matrix, x_size, y_size);
	dtl::dungeonStringOutputBool(dungeon_default_matrix, x_size, y_size, "■", "　");

	dtl::createBorder_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::PointGridFieldPutBlock_Array<dungeon_t> pgfpb(dungeon_array_matrix, x_size, y_size);
	//dtl::createPointGridField_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createBorderOdd_Array(dungeon_array_matrix, x_size, y_size);
	//dtl::createPointGrid_Array(dungeon_array_matrix, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_array_matrix, x_size, y_size, "■", "　");

	

	return 0;
}