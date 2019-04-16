#include <DTL.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>
#include <new>

class FileImageFunc {
public:
	template<typename Matrix_Int_>
	void operator()(const Matrix_Int_& value_, dtl::storage::Image_Palette* color) noexcept {
		constexpr dtl::storage::Image_Palette color_sub{ 1 };
		constexpr Matrix_Int_ deep_max_value{ 80 };
		constexpr Matrix_Int_ sea_max_value{ 120 };
		constexpr Matrix_Int_ sand_max_value{ 142 };
		constexpr Matrix_Int_ land_max_value{ 160 };

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
	constexpr std::size_t width{ 1025 };
	constexpr std::size_t height{ 1025 };

	std::unique_ptr<shape_t[][width]> matrix(new(std::nothrow) shape_t[height][width]);

	const dtl::utility::Init<shape_t> init(0);
	const dtl::shape::DiamondSquareAverageCornerIsland<shape_t> dsai(0, 165, 85);

	init.draw(matrix, width, height);
	dsai.draw(matrix, width, height);

	dtl::storage::FileImage<shape_t, width, height, dtl::storage::primary_colors_rgb>(matrix, FileImageFunc()).writePNG("corner_island1025_new_.png");
	dtl::storage::FileTerrainOBJ<shape_t>("corner_island1025_new_.obj", 1, 1, 4).write(matrix, width, height);

	return 0;
}