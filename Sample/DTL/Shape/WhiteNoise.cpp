#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 16>, 12> matrix{ {} };

	dtl::shape::WhiteNoise<shape_t>(1).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("//", "##").draw(matrix);

	return 0;
}