#include <DTL.hpp>
#include <cstdint>
#include <array>
#include <bitset>

int main() {

	constexpr std::size_t width{ 8 };
	constexpr std::size_t height{ 8 };
	//std::array<std::bitset<width>, height> matrix{ {} };
	std::array<std::array<char, width>, height> matrix{ {} };

	//dtl::WhiteNoise<bool>(1).draw(matrix);

	dtl::shape::Reversi<char>(1, 2).draw(matrix);

	//const dtl::SimpleRogueLike<bool> srl(1, 1, 5, 5, 3, 3, 3, 3);
	
	//for (std::size_t i{}; i < 10000; ++i) {
	//	dtl::Init<bool>(0).draw(matrix);
	//	srl.draw(matrix);
	//}
	//dtl::SimpleVoronoiIsland<bool>(dtl::MatrixRange(10, 10, 44, 44), 100, 0.5, 1, 0).draw(matrix);

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

	//	}).writePNG("svi.png");

	//dtl::OutputNumber<bool>(",").draw(matrix);
	dtl::OutputString<bool>("//", "##", "%%").draw(matrix);
	//std::cout;
	//dtl::FileTerrainOBJ<bool>("wn.obj").write(matrix);

	return 0;
}