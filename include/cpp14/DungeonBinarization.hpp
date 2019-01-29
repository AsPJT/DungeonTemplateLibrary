#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	//2値化処理
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonBinarization(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<Matrix_Int_>(matrix_[row][col]) >= value_) matrix_[row][col] = static_cast<Matrix_Int_>(1);
				else matrix_[row][col] = static_cast<Matrix_Int_>(0);
			}
	}

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonBinarization_RangeBasedFor(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (col >= value_) col = static_cast<Matrix_Int_>(1);
				else col = static_cast<Matrix_Int_>(0);
			}
	}

	template<typename Matrix_>
	constexpr void dungeonBinarization(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) matrix_[row][col] = 1;
				else matrix_[row][col] = 0;
			}
	}

	template<typename Matrix_>
	constexpr void dungeonBinarization_RangeBasedFor(Matrix_& matrix_) noexcept {
		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (col) col = 1;
				else col = 0;
			}
	}

	template<typename Matrix_, typename STL2_>
	constexpr void dungeonBinarizationBool(Matrix_& matrix_, STL2_& stl2_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row].size() != stl2_[row].size()) continue;
				if (matrix_[row][col]) stl2_[row][col] = true;
				else stl2_[row][col] = false;
			}
	}

	template<typename Matrix_, typename STL2_, typename Matrix_Int_>
	constexpr void dungeonBinarizationBool(Matrix_& matrix_, STL2_& stl2_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row].size() != stl2_[row].size()) continue;
				if (matrix_[row][col] >= value_) stl2_[row][col] = true;
				else stl2_[row][col] = false;
			}
	}

}

#endif //Included Dungeon Template Library