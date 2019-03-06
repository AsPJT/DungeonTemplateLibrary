#include <cstdint>
#include <cstddef>
#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = std::uint8_t;
	constexpr std::size_t x{ 9 };
	constexpr std::size_t y{ 9 };
	constexpr std::size_t layer{ 2 };
	std::array<std::array<dungeon_t, x>, y> matrix{ {} };
	std::array<std::array<std::array<dungeon_t, layer>, x>, y> matrix_layer{ {} };
	std::array<dungeon_t, x*y> matrix_array{ {} };

	dtl::utility::stl::init(matrix);
	dtl::generator::common::stl::PointGridField<dungeon_t>().create(matrix);
	dtl::console::output::stl::stringBool(matrix, "##", "//");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::common::normal::PointGridField<dungeon_t>().create(matrix, x, y);
	dtl::console::output::normal::stringBool(matrix, x, y, "##", "//");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::common::array::PointGridField<dungeon_t>().create(matrix_array, x, y);
	dtl::console::output::array::stringBool(matrix_array, x, y, "##", "//");

	dtl::utility::rangeBasedFor::init(matrix);
	dtl::generator::common::stl::PointGridField<dungeon_t>().create(matrix);
	dtl::console::output::rangeBasedFor::stringBool(matrix, "##", "//");

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::common::layer::stl::PointGridField<dungeon_t>().create(matrix_layer, layer);
	dtl::console::output::layer::stl::stringBool(matrix_layer, layer, "##", "//");

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::common::layer::normal::PointGridField<dungeon_t>().create(matrix_layer, layer, x, y);
	dtl::console::output::layer::normal::stringBool(matrix_layer, layer, x, y, "##", "//");


	dtl::utility::stl::init(matrix);
	dtl::generator::common::stl::PointGridField<dungeon_t>().create(matrix);
	dtl::console::output::stl::stringBool(matrix, "##", "//", 2);

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::common::normal::PointGridField<dungeon_t>().create(matrix, x, y);
	dtl::console::output::normal::stringBool(matrix, x, y, "##", "//", 2);

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::common::array::PointGridField<dungeon_t>().create(matrix_array, x, y);
	dtl::console::output::array::stringBool(matrix_array, x, y, "##", "//", 2);

	dtl::utility::rangeBasedFor::init(matrix);
	dtl::generator::common::stl::PointGridField<dungeon_t>().create(matrix);
	//dtl::console::output::rangeBasedFor::stringBool(matrix, "##", "//", 2);

	dtl::utility::layer::stl::init(matrix_layer, layer);
	dtl::generator::common::layer::stl::PointGridField<dungeon_t>().create(matrix_layer, layer);
	dtl::console::output::layer::stl::stringBool(matrix_layer, layer, "##", "//", 2);

	dtl::utility::layer::normal::init(matrix_layer, layer, x, y);
	dtl::generator::common::layer::normal::PointGridField<dungeon_t>().create(matrix_layer, layer, x, y);
	dtl::console::output::layer::normal::stringBool(matrix_layer, layer, x, y, "##", "//", 2);

	return 0;
}