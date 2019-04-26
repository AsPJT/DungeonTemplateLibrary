#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 64 };
	constexpr std::size_t height{ 64 };
	std::array<std::array<shape_t, width>, height> matrix{ {} };

	dtl::RandomVoronoi<shape_t>(50, 0.3, 2, 0).draw(matrix);
	
	dtl::console::OutputString<shape_t>("//", "##", "%%").draw(matrix);

	dtl::thirdParty::stb::FileSTB<shape_t, width, height>(matrix, [](const shape_t value_, unsigned char* color_) {
		if (value_) {
			color_[0] = 255;
			color_[1] = 255;
			color_[2] = 255;
		}
		else {
			color_[0] = 0;
			color_[1] = 0;
			color_[2] = 0;
		}

		}).writePNG("a.png");

		return 0;
}