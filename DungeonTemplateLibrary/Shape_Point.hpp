#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>

//STLデータ
namespace dtl::shape::stl {

	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		matrix_[set_y_][set_x_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		matrix_[set_y_][set_x_] = value_;
	}

} //namespace

namespace dtl::shape::normal {

	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		matrix_[set_y_][set_x_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		matrix_[set_y_][set_x_] = value_;
	}
	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_][set_x_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_][set_x_] = value_;
	}

}

namespace dtl::shape::array {

	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_*x_ + set_x_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_*x_ + set_x_] = value_;
	}

}

namespace dtl::shape::layer::stl {

	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, std::size_t set_x_, const std::size_t set_y_) noexcept {
		matrix_[set_y_][set_x_][layer_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		matrix_[set_y_][set_x_][layer_] = value_;
	}

} //namespace

namespace dtl::shape::layer::normal {

	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		matrix_[set_y_][set_x_][layer_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		matrix_[set_y_][set_x_][layer_] = value_;
	}
	template<typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_][set_x_][layer_] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPoint(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t set_x_, const std::size_t set_y_, const Matrix_Int_ value_) noexcept {
		if (x_ <= set_x_ || y_ <= set_y_) return;
		matrix_[set_y_][set_x_][layer_] = value_;
	}

}

#endif //Included Dungeon Template Library