#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_COPY
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_COPY
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>

namespace dtl::utility::tool {

	//キャストしてコピー
	template<typename Matrix_Int_, typename Value_Int_>
	constexpr void castCopyValue(Matrix_Int_& value_, const Value_Int_& value2_) noexcept {
		value_ = static_cast<Matrix_Int_>(value2_);
	}

	template<typename Matrix_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix_& matrix2_) noexcept {
		matrix_ = matrix2_;
	}

} //namespace

namespace dtl::utility::stl {

	template<typename Matrix_, typename Matrix2_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = matrix2_[row][col];
	}

} //namespace

namespace dtl::utility::normal {

	template<typename Matrix_, typename Matrix2_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = matrix2_[row][col];
	}

} //namespace

namespace dtl::utility::array {

	template<typename Matrix_, typename Matrix2_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row*x_ + col] = matrix2_[row*x_ + col];
	}

} //namespace

namespace dtl::utility::layer::stl {

	template<typename Matrix_, typename Matrix2_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = matrix2_[row][col][layer_];
	}

} //namespace

namespace dtl::utility::layer::normal {

	template<typename Matrix_, typename Matrix2_>
	constexpr void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col][layer_] = matrix2_[row][col][layer_];
	}

} //namespace

#endif //Included Dungeon Template Library