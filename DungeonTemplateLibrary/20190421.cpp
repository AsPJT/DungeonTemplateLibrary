#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 128>, 64> matrix{ {} };

	//dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(1, 2, 3).draw(matrix);
	//dtl::SimpleRogueLike<shape_t>(2, 3, 3, 4, 5, 2, 5, 2).draw(matrix);

	//dtl::generator::dungeon::stl::MazeDig<shape_t>().create(matrix, 0, 1);

	//dtl::MazeDig<shape_t>(dtl::MatrixRange(0, 7, 0, 0), 1, 0).draw(matrix);

	//dtl::generator::terrain::stl::FractalLoopIsland<shape_t>().create(matrix, 255);
	dtl::FractalLoopIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 255, 0).draw(matrix);

	//dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("■", "・").drawOperator(matrix, [](const shape_t value_) {return value_ > 150; });

	return 0;
}