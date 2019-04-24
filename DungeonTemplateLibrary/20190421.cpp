#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 64 };
	constexpr std::size_t height{ 64 };
	std::array<std::array<shape_t, width>, height> matrix{ {} };

	dtl::RandomVoronoi<shape_t>(50, 0.3, 2, 1).draw(matrix);

	dtl::console::OutputString<shape_t>("■", "○","●").draw(matrix);

	return 0;
}