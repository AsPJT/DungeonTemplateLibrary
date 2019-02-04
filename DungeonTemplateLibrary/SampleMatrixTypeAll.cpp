#include "DTL.hpp"
#include <array>
#include <bitset>
#include <vector>
#include <deque>
#include <memory>

template<typename Generation_, typename Generation2_, typename Generation3_, typename Matrix_, typename Matrix2_, typename Matrix3_>
constexpr void dungeonGeneration(const std::size_t x_size, const std::size_t y_size, Matrix_ dungeon_stl_matrix_array, Matrix2_ dungeon_default_matrix_default_array, Matrix3_ dungeon_default_array_default_array) noexcept {

}

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t x_size{ 17 };
	constexpr std::size_t y_size{ 11 };

	//---------- std::array STL ----------
	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix_array{ {} };
	//---------- default array Default ----------
	dungeon_t dungeon_default_matrix_default_array[y_size][x_size]{};
	//---------- default array Array ----------
	dungeon_t dungeon_default_array_default_array[x_size*y_size]{};

	//---------- std::array STL ----------
	dtl::console::output::puts("-- std::array STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_array);
	dtl::generation::stl::DungeonInit<dungeon_t> a(dungeon_stl_matrix_array);
	dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	//---------- default array Default ----------
	dtl::console::output::puts("-- default array Default --");
	dtl::generation::normal::dungeonInit(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::generation::normal::DungeonInit<dungeon_t> b(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	//---------- default array Array ----------
	dtl::console::output::puts("-- default array Array --");
	dtl::generation::array::dungeonInit(dungeon_default_array_default_array, x_size, y_size);
	dtl::generation::array::DungeonInit<dungeon_t> c(dungeon_default_array_default_array, x_size, y_size);
	dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	//---------- std::array STL ----------
	dtl::console::output::puts("-- std::array STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_array);
	dtl::generation::stl::PointGridFieldPutBlock<dungeon_t> a2(dungeon_stl_matrix_array);
	dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	//---------- default array Default ----------
	dtl::console::output::puts("-- default array Default --");
	dtl::generation::normal::dungeonInit(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::generation::normal::PointGridFieldPutBlock<dungeon_t> b2(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	//---------- default array Array ----------
	dtl::console::output::puts("-- default array Array --");
	dtl::generation::array::dungeonInit(dungeon_default_array_default_array, x_size, y_size);
	dtl::generation::array::PointGridFieldPutBlock<dungeon_t> c2(dungeon_default_array_default_array, x_size, y_size);
	dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	////---------- std::array STL ----------
	//dtl::console::output::puts("-- std::array STL --");
	//dtl::generation::stl::dungeonInit(dungeon_stl_matrix_array);
	//Generation_ a(dungeon_stl_matrix_array);
	//dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	////---------- default array Default ----------
	//dtl::console::output::puts("-- default array Default --");
	//dtl::generation::normal::dungeonInit(dungeon_default_matrix_default_array, x_size, y_size);
	//Generation2_ b(dungeon_default_matrix_default_array, x_size, y_size);
	//dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	////---------- default array Array ----------
	//dtl::console::output::puts("-- default array Array --");
	//dtl::generation::array::normal::dungeonInit(dungeon_default_array_default_array, x_size, y_size);
	//Generation3_ c(dungeon_default_array_default_array, x_size, y_size);
	//dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	/*dungeonGeneration<dtl::generation::stl::DungeonInit<dungeon_t>, dtl::generation::normal::DungeonInit<dungeon_t>, dtl::generation::array::normal::DungeonInit<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	dungeonGeneration<dtl::generation::stl::Border<dungeon_t>, dtl::generation::normal::Border<dungeon_t>, dtl::generation::array::Border<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	dungeonGeneration<dtl::generation::stl::PointGrid<dungeon_t>, dtl::generation::normal::PointGrid<dungeon_t>, dtl::generation::array::PointGrid<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	*///dungeonGeneration<dtl::generation::stl::PointGridField<dungeon_t>, dtl::generation::normal::PointGridField<dungeon_t>, dtl::generation::array::PointGridField<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);


	return 0;
}