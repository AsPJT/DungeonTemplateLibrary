#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 48>, 48> matrix{ {} };

	dtl::shape::FractalIsland<shape_t>(10, 150, 75).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("##", "//").drawOperator(matrix, [](const shape_t value_) {return value_ > 60; });

	return 0;
}