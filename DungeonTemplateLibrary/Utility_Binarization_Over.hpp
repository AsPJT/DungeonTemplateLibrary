#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION_OVER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION_OVER
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */

#include <cstddef>

namespace dtl::utility::stl {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col] >= value_) matrix_[row][col] = static_cast<Matrix_Int_>(1);
				else matrix_[row][col] = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

namespace dtl::utility::normal {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col] >= value_) matrix_[row][col] = static_cast<Matrix_Int_>(1);
				else matrix_[row][col] = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

namespace dtl::utility::array {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row*x_ + col] >= value_) matrix_[row*x_ + col] = static_cast<Matrix_Int_>(1);
				else matrix_[row*x_ + col] = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

namespace dtl::utility::rangeBasedFor {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (col >= value_) col = static_cast<Matrix_Int_>(1);
				else col = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

namespace dtl::utility::layer::stl {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col][layer_] >= value_) matrix_[row][col][layer_] = static_cast<Matrix_Int_>(1);
				else matrix_[row][col][layer_] = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

namespace dtl::utility::layer::normal {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void binarizationOver(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_] >= value_) matrix_[row][col][layer_] = static_cast<Matrix_Int_>(1);
				else matrix_[row][col][layer_] = static_cast<Matrix_Int_>(0);
			}
	}

} //namespace

#endif //Included Dungeon Template Library