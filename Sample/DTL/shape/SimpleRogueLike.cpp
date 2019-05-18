#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 48>, 36> matrix{ {} };

	dtl::shape::SimpleRogueLike<shape_t>(1, 2, 3, 4, 5, 2, 5, 2).draw(matrix);

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("//", "##", "%%").draw(matrix);

	return 0;
}