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


	dtl::generator::stl::initDungeon(dungeon_stl_matrix_array);
	dtl::generator::stl::DungeonInit<dungeon_t> a(dungeon_stl_matrix_array);
	dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	
	
	//---------- default array Default ----------
	dtl::console::output::puts("-- default array Default --");
	dtl::generator::normal::initDungeon(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::generator::normal::DungeonInit<dungeon_t> b(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	//---------- default array Array ----------
	dtl::console::output::puts("-- default array Array --");
	dtl::generator::array::initDungeon(dungeon_default_array_default_array, x_size, y_size);
	dtl::generator::array::DungeonInit<dungeon_t> c(dungeon_default_array_default_array, x_size, y_size);
	dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	//---------- std::array STL ----------
	dtl::console::output::puts("-- std::array STL --");
	dtl::generator::stl::initDungeon(dungeon_stl_matrix_array);
	dtl::generator::stl::PointGridFieldPutBlock<dungeon_t> a2(dungeon_stl_matrix_array);
	dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	//---------- default array Default ----------
	dtl::console::output::puts("-- default array Default --");
	dtl::generator::normal::initDungeon(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::generator::normal::PointGridFieldPutBlock<dungeon_t> b2(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	//---------- default array Array ----------
	dtl::console::output::puts("-- default array Array --");
	dtl::generator::array::initDungeon(dungeon_default_array_default_array, x_size, y_size);
	dtl::generator::array::PointGridFieldPutBlock<dungeon_t> c2(dungeon_default_array_default_array, x_size, y_size);
	dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	////---------- std::array STL ----------
	//dtl::console::output::puts("-- std::array STL --");
	//dtl::generator::stl::initDungeon(dungeon_stl_matrix_array);
	//Generation_ a(dungeon_stl_matrix_array);
	//dtl::console::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");
	////---------- default array Default ----------
	//dtl::console::output::puts("-- default array Default --");
	//dtl::generator::normal::initDungeon(dungeon_default_matrix_default_array, x_size, y_size);
	//Generation2_ b(dungeon_default_matrix_default_array, x_size, y_size);
	//dtl::console::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");
	////---------- default array Array ----------
	//dtl::console::output::puts("-- default array Array --");
	//dtl::generator::array::normal::initDungeon(dungeon_default_array_default_array, x_size, y_size);
	//Generation3_ c(dungeon_default_array_default_array, x_size, y_size);
	//dtl::console::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	/*dungeonGeneration<dtl::generator::stl::DungeonInit<dungeon_t>, dtl::generator::normal::DungeonInit<dungeon_t>, dtl::generator::array::normal::DungeonInit<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	dungeonGeneration<dtl::generator::stl::Border<dungeon_t>, dtl::generator::normal::Border<dungeon_t>, dtl::generator::array::Border<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	dungeonGeneration<dtl::generator::stl::PointGrid<dungeon_t>, dtl::generator::normal::PointGrid<dungeon_t>, dtl::generator::array::PointGrid<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);
	*///dungeonGeneration<dtl::generator::stl::PointGridField<dungeon_t>, dtl::generator::normal::PointGridField<dungeon_t>, dtl::generator::array::PointGridField<dungeon_t>>(x_size, y_size, dungeon_stl_matrix_array, dungeon_default_matrix_default_array, dungeon_default_array_default_array);



	

	return 0;
}

void aaaaaaaa() {




}