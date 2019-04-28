#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL.hpp>
#include <cstdint>
#include <array>
#include <bitset>

int main() {

	constexpr std::size_t width{ 64 };
	constexpr std::size_t height{ 64 };
	std::array<std::bitset<width>, height> matrix{ {} };

	//dtl::WhiteNoise<bool>(1).draw(matrix);

	dtl::SimpleVoronoiIsland<bool>(100, 0.5, 1, 0).draw(matrix);

	//dtl::thirdParty::stb::FileSTB<bool, width, height>(matrix, [](const bool value_, unsigned char* color_) {
	//	if (value_) {
	//		color_[0] = 255;
	//		color_[1] = 255;
	//		color_[2] = 255;
	//	}
	//	else {
	//		color_[0] = 0;
	//		color_[1] = 0;
	//		color_[2] = 0;
	//	}

	//	}).writePNG("w.png");

	dtl::OutputNumber<bool>(",").draw(matrix);
	dtl::OutputString<bool>("//", "##").draw(matrix);
	std::cout;
	dtl::FileTerrainOBJ<bool>("wn.obj").write(matrix);

	return 0;
}