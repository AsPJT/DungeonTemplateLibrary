//#include <DTL.hpp>
//#include <cstdint>
//#include <cstddef>
//#include <memory>
//#include <new>
//
//int main() {
//
//	using shape_t = std::uint_fast8_t;
//	constexpr std::size_t width{ 256 };
//	constexpr std::size_t height{ 256 };
//	constexpr dtl::storage::Image_Palette color_sub{ 32 };
//
//	std::unique_ptr<shape_t[][width]> matrix(new(std::nothrow) shape_t[height][width]);
//
//	const dtl::utility::Init<shape_t> init(0);
//	const dtl::shape::FractalLoopIsland<shape_t> dsai(0, 160, 90);
//
//	for (std::size_t i{}; i < 1; ++i) {
//
//		init.draw(matrix, width, height);
//		dsai.draw(matrix, width, height);
//
//		dtl::storage::FileImage<shape_t, width, height, dtl::storage::primary_colors_rgb>(matrix,
//			[color_sub](const shape_t value_, dtl::storage::Image_Palette * color) {
//				color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(28 + 120 * value_ / 255) / color_sub * color_sub;
//				color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(26 + 189 * value_ / 255) / color_sub * color_sub;
//				color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(162 - 83 * value_ / 255) / color_sub * color_sub;
//			}).writePNG("flisland256_32_" + std::to_string(i) + ".png");
//
//	}
//
//	return 0;
//}

#include <DTL.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>
#include <new>

class FileImageFunc {
public:
	template<typename Matrix_Int_>
	void operator()(const Matrix_Int_& value_, dtl::storage::Image_Palette* color) noexcept {
		constexpr dtl::storage::Image_Palette color_sub{ 8 };
		constexpr Matrix_Int_ deep_max_value{ 100 };
		constexpr Matrix_Int_ sea_max_value{ 130 };
		constexpr Matrix_Int_ sand_max_value{ 152 };
		constexpr Matrix_Int_ land_max_value{ 230 };

		if (value_ <= deep_max_value) {
			color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(30);
			color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(88);
			color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(126);
		}
		else if (value_ <= sea_max_value) {
			color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(30 + 135 * (value_ - deep_max_value) / (sea_max_value - deep_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(88 + 133 * (value_ - deep_max_value) / (sea_max_value - deep_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(126 + 84 * (value_ - deep_max_value) / (sea_max_value - deep_max_value)) / color_sub * color_sub;
		}
		else if (value_ <= sand_max_value) {
			color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(244 - 20 * (value_ - sea_max_value) / (sand_max_value - sea_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(236 - 27 * (value_ - sea_max_value) / (sand_max_value - sea_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(215 - 25 * (value_ - sea_max_value) / (sand_max_value - sea_max_value)) / color_sub * color_sub;
		}
		else if (value_ <= sand_max_value + 2) {
			color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(224 / 2 + 166 / 2);
			color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(209 / 2 + 193 / 2);
			color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(190 / 2 + 98 / 2);
		}
		else {
			color[dtl::storage::image_red] = static_cast<dtl::storage::Image_Palette>(166 - 30 * (value_ - sand_max_value) / (land_max_value - sand_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_green] = static_cast<dtl::storage::Image_Palette>(193 + 12 * (value_ - sand_max_value) / (land_max_value - sand_max_value)) / color_sub * color_sub;
			color[dtl::storage::image_blue] = static_cast<dtl::storage::Image_Palette>(98 + 1 * (value_ - sand_max_value) / (land_max_value - sand_max_value)) / color_sub * color_sub;
		}

		color[dtl::storage::image_red] += dtl::random::mt32bit.get<dtl::storage::Image_Palette>(20) - 10;
		color[dtl::storage::image_green] += dtl::random::mt32bit.get<dtl::storage::Image_Palette>(20) - 10;
		color[dtl::storage::image_blue] += dtl::random::mt32bit.get<dtl::storage::Image_Palette>(20) - 10;

	}
};

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 256 };
	constexpr std::size_t height{ 256 };

	std::unique_ptr<shape_t[][width]> matrix(new(std::nothrow) shape_t[height][width]);

	const dtl::utility::Init<shape_t> init(0);
	const dtl::shape::FractalLoopIsland<shape_t> dsai(0, 165, 85);

	for (std::size_t i{}; i < 10; ++i) {

		init.draw(matrix, width, height);
		dsai.draw(matrix, width, height);

		dtl::storage::FileImage<shape_t, width, height, dtl::storage::primary_colors_rgb>(matrix, FileImageFunc()).writePNG("flislandc256_" + std::to_string(i) + ".png");

	}

	return 0;
}

//#include <DTL.hpp>
//#include <cstdint>
//#include <array>
//
//int main() {
//
//	using shape_t = std::uint_fast8_t;
//	constexpr std::size_t width{ 256 };
//	constexpr std::size_t height{ 256 };
//	std::array<std::array<shape_t, width>, height> matrix{ {} };
//	//std::array<shape_t, width * height> matrix_array{ {} };
//	//std::array<std::array<std::array<shape_t, 2>, width>, height> matrix_layer{ {} };
//
//	dtl::FractalIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 170, 80).draw(matrix);
//	dtl::thirdParty::stb::FileSTB<shape_t, width, height, 3>().writePNG("fi.png", [](unsigned char* a) {});
//	//dtl::console::OutputStringBool<shape_t>("■", "・").drawOperator(matrix, [](const shape_t value_) {return value_ > 50; });
//
//	//dtl::FractalIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 170, 80).draw(matrix_layer, 0, width, height);
//	//dtl::console::OutputStringBool<shape_t>("■", "・").drawOperator(matrix_layer, 0, width, height, [](const shape_t value_) {return value_ > 50; });
//
//	//dtl::FractalIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 170, 80).draw(matrix, width, height);
//	//dtl::console::OutputStringBool<shape_t>("■", "・").drawOperator(matrix, width, height, [](const shape_t value_) {return value_ > 50; });
//
//	//dtl::FractalIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 170, 80).draw(matrix_layer, 0);
//	//dtl::console::OutputStringBool<shape_t>("■", "・").drawOperator(matrix_layer, 0, [](const shape_t value_) {return value_ > 50; });
//
//	//dtl::FractalIsland<shape_t>(dtl::MatrixRange(32, 16, 0, 0), 0, 170, 80).drawArray(matrix_array, width, height);
//	//dtl::console::OutputStringBool<shape_t>("■", "・").drawOperatorArray(matrix_array, width, height, [](const shape_t value_) {return value_ > 50; });
//
//	return 0;
//}