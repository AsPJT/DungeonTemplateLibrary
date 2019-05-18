#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 64>, 48> matrix{ {} };

	dtl::shape::SimpleVoronoiIsland<shape_t>(40, 0.5, 1, 0).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("//", "##").draw(matrix);

	return 0;
}