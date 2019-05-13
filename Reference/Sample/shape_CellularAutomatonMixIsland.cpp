#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 32>, 24> matrix{ {} };

	dtl::shape::CellularAutomatonMixIsland<shape_t>(5, 0, 1, 2, 3, 4, 5).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("//", "AA", "BB", "CC", "DD", "EE").draw(matrix);

	return 0;
}