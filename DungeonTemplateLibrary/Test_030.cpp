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
	dtl::console::output::stl::number(matrix);

	dtl::utility::normal::init(matrix, x, y);
	dtl::generator::common::normal::PointGridField<dungeon_t>().create(matrix, x, y);
	dtl::console::output::normal::number(matrix, x, y);

	//using dungeon_t = std::uint_fast8_t;
	//std::array<std::array<dungeon_t, 32>, 32> matrix{ {} };

	//dtl::generator::terrain::stl::SimpleCellularAutomatonIsland<dungeon_t> a(matrix, 5);
	//dtl::generator::horizontalScroll::stl::createMountain<dungeon_t>(matrix, 1, 1);
	//dtl::generator::common::stl::PointGridFieldPutBlock<dungeon_t>().create(matrix);

	//dtl::console::output::stl::string(matrix, "・", "■", "□");
	//dtl::console::output::stl::number(matrix);

	return 0;
}