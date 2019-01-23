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
	template<typename Matrix_, typename Matrix_Int_>
	constexpr void dungeonBinarization(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (matrix_[i][j] >= value_) matrix_[i][j] = static_cast<Matrix_Int_>(1);
				else matrix_[i][j] = static_cast<Matrix_Int_>(0);
			}
	}

	template<typename Matrix_, typename Matrix_Int_>
	constexpr void dungeonBinarization_RangeBasedFor(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& i : matrix_)
			for (auto&& j : i) {
				if (j >= value_) j = static_cast<Matrix_Int_>(1);
				else j = static_cast<Matrix_Int_>(0);
			}
	}

	template<typename Matrix_>
	constexpr void dungeonBinarization(Matrix_& matrix_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (matrix_[i][j]) matrix_[i][j] = 1;
				else matrix_[i][j] = 0;
			}
	}

	template<typename Matrix_>
	constexpr void dungeonBinarization_RangeBasedFor(Matrix_& matrix_) noexcept {
		for (auto&& i : matrix_)
			for (auto&& j : i) {
				if (j) j = 1;
				else j = 0;
			}
	}

	template<typename Matrix_, typename STL2_>
	constexpr void dungeonBinarizationBool(Matrix_& matrix_, STL2_& stl2_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (matrix_[i].size() != stl2_[i].size()) continue;
				if (matrix_[i][j]) stl2_[i][j] = true;
				else stl2_[i][j] = false;
			}
	}

	template<typename Matrix_, typename STL2_, typename Matrix_Int_>
	constexpr void dungeonBinarizationBool(Matrix_& matrix_, STL2_& stl2_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() != stl2_.size()) return;
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (matrix_[i].size() != stl2_[i].size()) continue;
				if (matrix_[i][j] >= value_) stl2_[i][j] = true;
				else stl2_[i][j] = false;
			}
	}

}

#endif //Included Dungeon Template Library