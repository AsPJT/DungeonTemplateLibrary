#include <cstdint>
#include <cstddef>
#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = std::uint8_t;
	constexpr std::size_t x{ 64 };
	constexpr std::size_t y{ 64 };
	constexpr std::size_t layer{ 2 };
	std::array<std::array<dungeon_t, x>, y> matrix{ {} };
	std::array<std::array<std::array<dungeon_t, layer>, x>, y> matrix_layer{ {} };
	std::array<dungeon_t, x*y> matrix_array{ {} };

	dtl::utility::stl::init(matrix);
	dtl::generator::terrain::stl::SimpleBiomeIsland<dungeon_t>().create(matrix, 10, 4);
	dtl::utility::stl::setItem<dungeon_t>(matrix, 10, 4);
	dtl::utility::stl::replace(matrix, 0, 1);
	dtl::utility::stl::replace(matrix, 0, 2);
	dtl::utility::stl::replace(matrix, 0, 3);
	dtl::console::output::stl::string(matrix, "・", "□", "○","△","▲");

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::terrain::normal::SimpleBiomeIsland<dungeon_t>().create(matrix, x, y, 10, 4);
	dtl::utility::normal::setItem<dungeon_t>(matrix, x, y, 10, 4);
	dtl::utility::normal::replace(matrix, x, y, 0, 1);
	dtl::utility::normal::replace(matrix, x, y, 0, 2);
	dtl::utility::normal::replace(matrix, x, y, 0, 3);
	dtl::console::output::normal::string(matrix, x, y, "・", "□", "○", "△", "▲");

	dtl::utility::array::init(matrix_array, x, y);
	dtl::generator::terrain::array::SimpleBiomeIsland<dungeon_t>().create(matrix_array, x, y, 10, 4);
	dtl::utility::array::setItem<dungeon_t>(matrix_array, x, y, 10, 4);
	dtl::utility::array::replace(matrix_array, x, y, 0, 1);
	dtl::utility::array::replace(matrix_array, x, y, 0, 2);
	dtl::utility::array::replace(matrix_array, x, y, 0, 3);
	dtl::console::output::array::string(matrix_array, x, y, "・", "□", "○", "△", "▲");

	dtl::utility::layer::stl::init(matrix_layer, 0);
	dtl::generator::terrain::layer::stl::SimpleBiomeIsland<dungeon_t>().create(matrix_layer, 0, 10, 4);
	dtl::utility::layer::stl::setItem<dungeon_t>(matrix_layer, 0, 10, 4);
	dtl::utility::layer::stl::replace(matrix_layer, 0, 0, 1);
	dtl::utility::layer::stl::replace(matrix_layer, 0, 0, 2);
	dtl::utility::layer::stl::replace(matrix_layer, 0, 0, 3);
	dtl::console::output::layer::stl::string(matrix_layer, 0, "・", "□", "○", "△", "▲");

	dtl::utility::layer::normal::init(matrix_layer, 0, x, y);
	dtl::generator::terrain::layer::normal::SimpleBiomeIsland<dungeon_t>().create(matrix_layer, 0, x, y, 10, 4);
	dtl::utility::layer::normal::setItem<dungeon_t>(matrix_layer, 0, x, y, 10, 4);
	dtl::utility::layer::normal::replace(matrix_layer, 0, x, y, 0, 1);
	dtl::utility::layer::normal::replace(matrix_layer, 0, x, y, 0, 2);
	dtl::utility::layer::normal::replace(matrix_layer, 0, x, y, 0, 3);
	dtl::console::output::layer::normal::string(matrix_layer, 0, x, y, "・", "□", "○", "△", "▲");

	return 0;
}