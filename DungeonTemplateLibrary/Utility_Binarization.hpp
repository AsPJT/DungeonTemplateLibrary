#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */

#include <cstddef>

//STLデータ
namespace dtl::utility::stl {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) matrix_[row][col] = 1;
				else matrix_[row][col] = 0;
			}
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col]) matrix_[row][col] = 1;
				else matrix_[row][col] = 0;
			}
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row*x_ + col]) matrix_[row*x_ + col] = 1;
				else matrix_[row*x_ + col] = 0;
			}
	}

} //namespace

//範囲forデータ
namespace dtl::utility::rangeBasedFor {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (col) col = 1;
				else col = 0;
			}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = 1;
				else matrix_[row][col][layer_] = 0;
			}
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	//2値化処理
	template<typename Matrix_>
	constexpr void binarization(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = 1;
				else matrix_[row][col][layer_] = 0;
			}
	}

} //namespace

#endif //Included Dungeon Template Library