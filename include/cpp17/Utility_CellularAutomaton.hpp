#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_CELLULAR_AUTOMATON
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include "Random_MersenneTwister32bit.hpp"
#include "Utility_Matrix.hpp"

//STLデータ
namespace dtl::utility::stl {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < matrix_.size() - 1; ++row)
			for (std::size_t col{ 1 }; col < matrix_[row].size() - 1; ++col) {
				if (matrix_[row][col - 1] == matrix_[row][col + 1] && matrix_[row][col + 1] == matrix_[row - 1][col] && matrix_[row - 1][col] == matrix_[row + 1][col])
					matrix_[row][col] = matrix_[row][col + 1];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
				case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
				case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
				case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
				}
			}
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[row][col - 1] == matrix_[row][col + 1] && matrix_[row][col + 1] == matrix_[row - 1][col] && matrix_[row - 1][col] == matrix_[row + 1][col])
					matrix_[row][col] = matrix_[row][col + 1];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col] = matrix_[row][col - 1]; break;
				case 1:matrix_[row][col] = matrix_[row][col + 1]; break;
				case 2:matrix_[row][col] = matrix_[row - 1][col]; break;
				case 3:matrix_[row][col] = matrix_[row + 1][col]; break;
				}
			}
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[(row)*x_ + (col - 1)] == matrix_[(row)*x_ + (col + 1)] && matrix_[(row)*x_ + (col + 1)] == matrix_[(row - 1)*x_ + (col)] && matrix_[(row - 1)*x_ + (col)] == matrix_[(row + 1)*x_ + (col)])
					matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col + 1)];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col - 1)]; break;
				case 1:matrix_[(row)*x_ + (col)] = matrix_[(row)*x_ + (col + 1)]; break;
				case 2:matrix_[(row)*x_ + (col)] = matrix_[(row - 1)*x_ + (col)]; break;
				case 3:matrix_[(row)*x_ + (col)] = matrix_[(row + 1)*x_ + (col)]; break;
				}
			}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < matrix_.size() - 1; ++row)
			for (std::size_t col{ 1 }; col < matrix_[row].size() - 1; ++col) {
				if (matrix_[row][col - 1][layer_] == matrix_[row][col + 1][layer_] && matrix_[row][col + 1][layer_] == matrix_[row - 1][col][layer_] && matrix_[row - 1][col][layer_] == matrix_[row + 1][col][layer_])
					matrix_[row][col][layer_] = matrix_[row][col + 1][layer_];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col][layer_] = matrix_[row][col - 1][layer_]; break;
				case 1:matrix_[row][col][layer_] = matrix_[row][col + 1][layer_]; break;
				case 2:matrix_[row][col][layer_] = matrix_[row - 1][col][layer_]; break;
				case 3:matrix_[row][col][layer_] = matrix_[row + 1][col][layer_]; break;
				}
			}
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	constexpr void cellularAutomation(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ 1 }; row < y_ - 1; ++row)
			for (std::size_t col{ 1 }; col < x_ - 1; ++col) {
				if (matrix_[row][col - 1][layer_] == matrix_[row][col + 1][layer_] && matrix_[row][col + 1][layer_] == matrix_[row - 1][col][layer_] && matrix_[row - 1][col][layer_] == matrix_[row + 1][col][layer_])
					matrix_[row][col][layer_] = matrix_[row][col + 1][layer_];
				else switch (mersenne_twister_32bit(4)) {
				case 0:matrix_[row][col][layer_] = matrix_[row][col - 1][layer_]; break;
				case 1:matrix_[row][col][layer_] = matrix_[row][col + 1][layer_]; break;
				case 2:matrix_[row][col][layer_] = matrix_[row - 1][col][layer_]; break;
				case 3:matrix_[row][col][layer_] = matrix_[row + 1][col][layer_]; break;
				}
			}
	}

} //namespace

#endif //Included Dungeon Template Library