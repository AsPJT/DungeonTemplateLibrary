#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 32>, 24> matrix{ {} };

	dtl::shape::RandomVoronoi<shape_t>(20, 0.5, 1, 0).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputStringBool<shape_t>("//", "##").draw(matrix);

	return 0;
}