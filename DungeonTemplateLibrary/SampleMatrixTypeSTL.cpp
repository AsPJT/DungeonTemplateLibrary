#include "DTL.hpp"
#include <array>
#include <bitset>
#include <vector>
#include <deque>
#include <memory>

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t x_size{ 17 };
	constexpr std::size_t y_size{ 11 };

	//---------- std::array STL ----------

	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix_array{ {} };

	dtl::output::puts("-- std::array STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_array);
	dtl::generation::stl::createPointGridField(dungeon_stl_matrix_array);
	dtl::output::stl::stringBool(dungeon_stl_matrix_array, "■", "　");

	//---------- std::bitset STL ----------

	std::array<std::bitset<x_size>, y_size> dungeon_stl_matrix_bitset{ {} };

	dtl::output::puts("-- std::bitset STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_bitset);
	dtl::generation::stl::createPointGridField(dungeon_stl_matrix_bitset);
	dtl::output::stl::stringBool(dungeon_stl_matrix_bitset, "■", "　");

	//---------- std::vector STL ----------

	std::vector<std::vector<dungeon_t>> dungeon_stl_matrix_vector(y_size, std::vector<dungeon_t>(x_size, 0));

	dtl::output::puts("-- std::vector STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_vector);
	dtl::generation::stl::createPointGridField(dungeon_stl_matrix_vector);
	dtl::output::stl::stringBool(dungeon_stl_matrix_vector, "■", "　");

	//---------- std::deque STL ----------

	std::deque<std::deque<dungeon_t>> dungeon_stl_matrix_deque(y_size, std::deque<dungeon_t>(x_size, 0));

	dtl::output::puts("-- std::deque STL --");
	dtl::generation::stl::dungeonInit(dungeon_stl_matrix_deque);
	dtl::generation::stl::createPointGridField(dungeon_stl_matrix_deque);
	dtl::output::stl::stringBool(dungeon_stl_matrix_deque, "■", "　");

	//---------- default array Default ----------

	dungeon_t dungeon_default_matrix_default_array[y_size][x_size]{};

	dtl::output::puts("-- default array Default --");
	dtl::generation::normal::dungeonInit(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::generation::normal::createPointGridField(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::output::normal::stringBool(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");

	//---------- std::unique_ptr Default ----------

	std::unique_ptr<dungeon_t[][x_size]> dungeon_default_matrix_unique_ptr(new dungeon_t[y_size][x_size]);

	dtl::output::puts("-- std::unique_ptr Default --");
	dtl::generation::normal::dungeonInit(dungeon_default_matrix_unique_ptr, x_size, y_size);
	dtl::generation::normal::createPointGridField(dungeon_default_matrix_unique_ptr, x_size, y_size);
	dtl::output::normal::stringBool(dungeon_default_matrix_unique_ptr, x_size, y_size, "■", "　");

	//---------- default array Array ----------

	dungeon_t dungeon_default_array_default_array[x_size*y_size]{};

	dtl::output::puts("-- default array Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_default_array, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_default_array, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_default_array, x_size, y_size, "■", "　");

	//---------- std::array Array ----------

	std::array<dungeon_t, x_size*y_size> dungeon_default_array_array{ {} };

	dtl::output::puts("-- std::array Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_array, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_array, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_array, x_size, y_size, "■", "　");

	//---------- std::bitset Array ----------

	std::bitset<x_size*y_size> dungeon_default_array_bitset{ {} };

	dtl::output::puts("-- std::bitset Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_bitset, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_bitset, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_bitset, x_size, y_size, "■", "　");

	//---------- std::vector Array ----------

	std::vector<dungeon_t> dungeon_default_array_vector(y_size*x_size, 0);

	dtl::output::puts("-- std::vector Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_vector, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_vector, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_vector, x_size, y_size, "■", "　");

	//---------- std::deque Array ----------

	std::deque<dungeon_t> dungeon_default_array_deque(y_size*x_size, 0);

	dtl::output::puts("-- std::deque Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_deque, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_deque, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_deque, x_size, y_size, "■", "　");

	//---------- std::unique_ptr Array ----------

	std::unique_ptr<dungeon_t[]> dungeon_default_array_unique_ptr(new dungeon_t[y_size*x_size]);

	dtl::output::puts("-- std::unique_ptr Array --");
	dtl::generation::array::normal::dungeonInit(dungeon_default_array_unique_ptr, x_size, y_size);
	dtl::generation::array::createPointGridField(dungeon_default_array_unique_ptr, x_size, y_size);
	dtl::output::array::stringBool(dungeon_default_array_unique_ptr, x_size, y_size, "■", "　");

	return 0;
}