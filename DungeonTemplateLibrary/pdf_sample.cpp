#include <DTL.hpp>
#include <array>
#include <bitset>
#include <algorithm>
#include <limits>

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

template<typename Matrix_Int_,typename Matrix_>
void randomTerrain(Matrix_&& matrix_, const std::size_t width, const std::size_t height, const std::int_fast32_t min_value_, const std::int_fast32_t max_value_, const std::int_fast32_t min_size, const std::int_fast32_t max_size, const Matrix_Int_& sub_) noexcept {

	matrix_[0][0] = dtl::random::mt32bit.get<Matrix_Int_>(min_value_, max_value_);

	for (std::size_t row{ 1 }; row < height; ++row) {
		if (matrix_[row - 1][0] < min_size + sub_) {
			matrix_[row][0] = matrix_[row - 1][0]+dtl::random::mt32bit.get<Matrix_Int_>(sub_);
			continue;
		}
		const Matrix_Int_& rand_value{ dtl::random::mt32bit.get<Matrix_Int_>(sub_ * 2 + 1) };
		if (matrix_[row - 1][0] >= max_size - rand_value) {
			matrix_[row][0] = matrix_[row - 1][0]-dtl::random::mt32bit.get<Matrix_Int_>(sub_);
			continue;
		}

		matrix_[row][0] = matrix_[row - 1][0] + rand_value - sub_;
	}
	for (std::size_t col{ 1 }; col < width; ++col) {
		if (matrix_[0][col - 1] < min_size + sub_) {
			matrix_[0][col] = matrix_[0][col - 1]+dtl::random::mt32bit.get<Matrix_Int_>(sub_);
			continue;
		}
		const Matrix_Int_& rand_value{ dtl::random::mt32bit.get<Matrix_Int_>(sub_ * 2 + 1) };
		if (matrix_[0][col - 1] >= max_size - rand_value) {
			matrix_[0][col] = matrix_[0][col - 1]-dtl::random::mt32bit.get<Matrix_Int_>(sub_);
			continue;
		}

		matrix_[0][col] = matrix_[0][col - 1] + rand_value - sub_;
	}
	for (std::size_t row{ 1 }; row < height; ++row)
		for (std::size_t col{ 1 }; col < width; ++col) {
			if ((std::min)(matrix_[row][col - 1], matrix_[row - 1][col]) < min_size + sub_) {
				matrix_[row][col] = (std::min)(matrix_[row][col - 1], matrix_[row - 1][col])+dtl::random::mt32bit.get<Matrix_Int_>(sub_);
				continue;
			}
			const Matrix_Int_& rand_value{ dtl::random::mt32bit.get<Matrix_Int_>((std::max)(matrix_[row][col - 1], matrix_[row - 1][col]) - (std::min)(matrix_[row][col - 1], matrix_[row - 1][col]) + sub_ * 2 + 1) };
			if ((std::min)(matrix_[row][col], matrix_[row - 1][col]) >= max_size - rand_value) {
				matrix_[row][col] = (std::min)(matrix_[row][col], matrix_[row - 1][col])-dtl::random::mt32bit.get<Matrix_Int_>(sub_);
				continue;
			}

			matrix_[row][col] = (std::min)(matrix_[row][col - 1], matrix_[row - 1][col]) + rand_value - sub_;
		}

}

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 256 };
	constexpr std::size_t height{ 256 };
	std::array<std::array<shape_t, width>, height> matrix{ {} };
	//dtl::shape::PointGridWithBorder<bool>(1).draw(matrix);

	randomTerrain<shape_t>(matrix, width, height, 110, 120, 0, 255, 3);

	//dtl::console::OutputNumber<bool>(",").draw(matrix);
	//dtl::console::OutputStringBool<bool>("##", "  ").drawOperator(matrix, [](const shape_t a) {return a > 150; });

	dtl::storage::FileImage<shape_t, width, height, dtl::storage::primary_colors_rgb>(matrix, FileImageFunc()).writeJPG("island256_256_6.jpg");

}