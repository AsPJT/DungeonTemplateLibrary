#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 32>, 24> matrix{ {} };

	dtl::shape::CellularAutomatonIsland<shape_t>(1, 0, 5, 0.4).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("//", "##").draw(matrix);

	return 0;
}