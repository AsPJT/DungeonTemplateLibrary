#include <DTL.hpp>
#include <cstdint>
#include <cstddef>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 257 };
	constexpr std::size_t height{ 257 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };

	//dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(1, 1, 2).draw(matrix);
	

	//dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	//dtl::console::OutputStringBool<shape_t>("##", "//").drawOperator(matrix, [](const shape_t value_) {return value_ > 70; });

	//dtl::storage::FileTerrainOBJ<shape_t>("dsaci.obj").write(matrix);

	//dtl::thirdParty::stb::FileSTB

	for (std::size_t i{}; i < 20; ++i) {

		dtl::utility::Init<shape_t>(0).draw(matrix);
		dtl::shape::DiamondSquareAverageIsland<shape_t>(0, 170, 80).draw(matrix);

		dtl::storage::FileImage<shape_t, width, height, dtl::storage::primary_colors_rgb>(matrix,
			[](const shape_t value_, dtl::storage::Image_Palette * color) {
				color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(28 + 90 * value_ / 255) / 10 * 10;
				color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(26 + 159 * value_ / 255) / 10 * 10;
				color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(162 - 113 * value_ / 255) / 10 * 10;
			}).writeBMP("png/island170-80-bmp/shima" + std::to_string(i) + ".bmp");

	}

		return 0;
}