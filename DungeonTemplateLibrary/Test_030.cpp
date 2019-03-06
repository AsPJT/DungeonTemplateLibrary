#include <cstdint>
#include <cstddef>
#include <array>
#include "DTL.hpp"

#define TERRAIN_TYPE_NAME common
#define CLASS_NAME PointGridField
#define FUNCTION_NAME createPointGridField

int main() {

	using dungeon_t = std::uint8_t;
	constexpr std::size_t x{ 9 };
	constexpr std::size_t y{ 9 };
	constexpr std::size_t layer{ 2 };
	std::array<std::array<dungeon_t, x>, y> matrix{ {} };
	std::array<std::array<std::array<dungeon_t, layer>, x>, y> matrix_layer{ {} };
	std::array<dungeon_t, x*y> matrix_array{ {} };

	dtl::utility::stl::init(matrix);
	dtl::generator::TERRAIN_TYPE_NAME::stl::CLASS_NAME<dungeon_t>().create(matrix);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::normal::CLASS_NAME<dungeon_t>().create(matrix, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::array::CLASS_NAME<dungeon_t>().create(matrix_array, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::TERRAIN_TYPE_NAME::layer::stl::CLASS_NAME<dungeon_t>().create(matrix_layer, layer);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::layer::normal::CLASS_NAME<dungeon_t>().create(matrix_layer, layer, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");



	dtl::utility::stl::init(matrix);
	dtl::generator::TERRAIN_TYPE_NAME::stl::CLASS_NAME<dungeon_t>().create(matrix, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::normal::CLASS_NAME<dungeon_t>().create(matrix, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::array::CLASS_NAME<dungeon_t>().create(matrix_array, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::TERRAIN_TYPE_NAME::layer::stl::CLASS_NAME<dungeon_t>().create(matrix_layer, layer, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::layer::normal::CLASS_NAME<dungeon_t>().create(matrix_layer, layer, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");



	dtl::utility::stl::init(matrix);
	dtl::generator::TERRAIN_TYPE_NAME::stl::FUNCTION_NAME(matrix);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::normal::FUNCTION_NAME(matrix, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::array::FUNCTION_NAME(matrix_array, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::TERRAIN_TYPE_NAME::layer::stl::FUNCTION_NAME(matrix_layer, layer);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::layer::normal::FUNCTION_NAME(matrix_layer, layer, x, y);
	dtl::console::output::stl::stringBool(matrix, "##", "//");



	dtl::utility::stl::init(matrix);
	dtl::generator::TERRAIN_TYPE_NAME::stl::FUNCTION_NAME<dungeon_t>(matrix, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::normal::FUNCTION_NAME<dungeon_t>(matrix, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::array::FUNCTION_NAME<dungeon_t>(matrix_array, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::TERRAIN_TYPE_NAME::layer::stl::FUNCTION_NAME<dungeon_t>(matrix_layer, layer, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::TERRAIN_TYPE_NAME::layer::normal::FUNCTION_NAME<dungeon_t>(matrix_layer, layer, x, y, 2);
	dtl::console::output::stl::string(matrix, "//", "  ", "##");

	return 0;
}