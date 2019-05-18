#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 48>, 48> matrix{ {} };

	dtl::shape::FractalLoopIsland<shape_t>(10, 150, 70).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("##", "//").drawOperator(matrix, [](const shape_t value_) {return value_ > 80; });

	return 0;
}