#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_HORIZONTAL_SCROLL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_HORIZONTAL_SCROLL
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include "Random_MersenneTwister32bit.hpp"
#include "Utility_Matrix.hpp"

//Dungeon Template Library Namespace
namespace dtl::generator::horizontalScroll::stl {

	template<typename Matrix_Int_, typename Matrix_>
	void createMountain(Matrix_& matrix_, const Matrix_Int_ value_, const std::int_fast32_t rand_value_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		std::int_fast32_t y{ static_cast<std::int_fast32_t>(matrix_.size() - 1) };

		std::int_fast32_t matrix_height_value{};
		matrix_[static_cast<std::size_t>(matrix_height_value = mersenne_twister_32bit(1, y))][0] = value_;

		for (std::size_t i{ 1 }; i < matrix_[0].size(); ++i) {
			if (matrix_height_value <= 1) matrix_height_value += mersenne_twister_32bit(0, rand_value_);
			else if (matrix_height_value >= y) matrix_height_value += mersenne_twister_32bit(-rand_value_, 0);
			else matrix_height_value += mersenne_twister_32bit(-rand_value_, rand_value_);

			if (matrix_height_value <= 0) matrix_height_value = 1;
			else if (matrix_height_value >= y + 1) matrix_height_value = y;
			matrix_[matrix_height_value][i] = value_;
		}

		//上半分を埋める
		for (std::size_t row{ matrix_.size() - 2 };; --row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row + 1][col] == value_) matrix_[row][col] = value_;
			if (row == 0) break;
		}

		//下半分を埋める
		//for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
		//	for (std::size_t col{}; col < matrix_[row].size(); ++col)
		//		if (matrix_[row - 1][col] == value_) matrix_[row][col] = value_;
	}

} //namespace

#endif //Included Dungeon Template Library