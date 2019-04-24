#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL.hpp>
#include <cstdint>
#include <memory>
#include <new>
#include <bitset>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 2160 };
	constexpr std::size_t height{ 2160 };

	std::unique_ptr<std::bitset<width>[]> matrix(new(std::nothrow) std::bitset<width>[height]);

	dtl::RandomVoronoi<shape_t>(1000, 0.3, true, false).draw(matrix, width, height);

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