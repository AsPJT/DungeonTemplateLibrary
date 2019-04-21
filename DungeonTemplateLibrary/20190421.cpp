#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 64>, 64> matrix{ {} };

	//dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(1, 2, 3).draw(matrix);

	dtl::generator::dungeon::stl::SimpleRogueLike<shape_t>().create(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("■", "・", "□", "・").draw(matrix);

	return 0;
}