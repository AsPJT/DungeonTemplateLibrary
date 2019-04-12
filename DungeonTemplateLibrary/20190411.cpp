#include <DTL.hpp>
#include <cstddef>
#include <cstdint>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 16 };
	constexpr std::size_t height{ 8 };

	shape_t matrix[height * width]{};

	auto&& catch_matrix{ dtl::shape::Border<shape_t>(1).createArray(matrix, width, height) };

	dtl::console::OutputString<shape_t>("//", "##").createArray(catch_matrix, width, height);

	return 0;
}