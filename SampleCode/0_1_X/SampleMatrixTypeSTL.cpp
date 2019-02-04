#include "DTL.hpp"
#include <array>
#include <bitset>
#include <vector>
#include <deque>

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t x_size{ 17 };
	constexpr std::size_t y_size{ 11 };

	//---------- std::array STL ----------

	std::array<std::array<dungeon_t, x_size>, y_size> dungeon_stl_matrix_array{ {} };

	dtl::dungeonPuts("-- std::array STL --");
	dtl::dungeonInit(dungeon_stl_matrix_array);
	dtl::createPointGridField(dungeon_stl_matrix_array);
	dtl::dungeonStringOutputBool(dungeon_stl_matrix_array, "■", "　");

	//---------- std::bitset STL ----------

	std::array<std::bitset<x_size>, y_size> dungeon_stl_matrix_bitset{ {} };

	dtl::dungeonPuts("-- std::bitset STL --");
	dtl::dungeonInit(dungeon_stl_matrix_bitset);
	dtl::createPointGridField(dungeon_stl_matrix_bitset);
	dtl::dungeonStringOutputBool(dungeon_stl_matrix_bitset, "■", "　");

	//---------- std::vector STL ----------

	std::vector<std::vector<dungeon_t>> dungeon_stl_matrix_vector(y_size, std::vector<dungeon_t>(x_size, 0));

	dtl::dungeonPuts("-- std::vector STL --");
	dtl::dungeonInit(dungeon_stl_matrix_vector);
	dtl::createPointGridField(dungeon_stl_matrix_vector);
	dtl::dungeonStringOutputBool(dungeon_stl_matrix_vector, "■", "　");

	//---------- std::duque STL ----------

	std::deque<std::deque<dungeon_t>> dungeon_stl_matrix_deque(y_size, std::deque<dungeon_t>(x_size, 0));

	dtl::dungeonPuts("-- std::deque STL --");
	dtl::dungeonInit(dungeon_stl_matrix_deque);
	dtl::createPointGridField(dungeon_stl_matrix_deque);
	dtl::dungeonStringOutputBool(dungeon_stl_matrix_deque, "■", "　");

	//---------- default array Array ----------

	dungeon_t dungeon_default_matrix_default_array[x_size*y_size]{};

	dtl::dungeonPuts("-- default array Array --");
	dtl::dungeonInit_Array(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::createPointGridField_Array(dungeon_default_matrix_default_array, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_default_matrix_default_array, x_size, y_size, "■", "　");

	//---------- std::array Array ----------

	std::array<dungeon_t, x_size*y_size> dungeon_default_matrix_array{ {} };

	dtl::dungeonPuts("-- std::array Array --");
	dtl::dungeonInit_Array(dungeon_default_matrix_array, x_size, y_size);
	dtl::createPointGridField_Array(dungeon_default_matrix_array, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_default_matrix_array, x_size, y_size, "■", "　");

	//---------- std::bitset Array ----------

	std::bitset<x_size*y_size> dungeon_default_matrix_bitset{ {} };

	dtl::dungeonPuts("-- std::bitset Array --");
	dtl::dungeonInit_Array(dungeon_default_matrix_bitset, x_size, y_size);
	dtl::createPointGridField_Array(dungeon_default_matrix_bitset, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_default_matrix_bitset, x_size, y_size, "■", "　");

	//---------- std::vector Array ----------

	std::vector<dungeon_t> dungeon_default_matrix_vector(y_size*x_size, 0);

	dtl::dungeonPuts("-- std::vector Array --");
	dtl::dungeonInit_Array(dungeon_default_matrix_vector, x_size, y_size);
	dtl::createPointGridField_Array(dungeon_default_matrix_vector, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_default_matrix_vector, x_size, y_size, "■", "　");

	//---------- std::duque Array ----------

	std::deque<dungeon_t> dungeon_default_matrix_deque(y_size*x_size, 0);

	dtl::dungeonPuts("-- std::deque Array --");
	dtl::dungeonInit_Array(dungeon_default_matrix_deque, x_size, y_size);
	dtl::createPointGridField_Array(dungeon_default_matrix_deque, x_size, y_size);
	dtl::dungeonStringOutputBool_Array(dungeon_default_matrix_deque, x_size, y_size, "■", "　");

	return 0;
}