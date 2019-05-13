#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 33>, 33> matrix{ {} };

	dtl::shape::DiamondSquareAverageIsland<shape_t>(0, 80, 60).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("##", "//").drawOperator(matrix, [](const shape_t value_) {return value_ > 50; });

	return 0;
}