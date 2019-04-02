#include "DTL.hpp"
#include <cstddef>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 15 };
	constexpr std::size_t height{ 7 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };

	dtl::shape::Rect<shape_t>({ 1,1,4,4 }, 1).draw(matrix);

	dtl::console::OutputNumber<shape_t>(" [", "],").draw(matrix);

}