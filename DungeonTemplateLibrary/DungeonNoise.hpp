#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (!rnd.randBool(rbool_)) continue;
				if (matrix_[i][j]) matrix_[i][j] = false_tile_;
				else matrix_[i][j] = true_tile_;
			}
	}

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool_RangeBasedFor(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (auto&& i : matrix_)
			for (auto&& j : i) {
				if (!rnd.randBool(rbool_)) continue;
				if (j) j = false_tile_;
				else j = true_tile_;
			}
	}

	//ノイズを発生させる
	template<typename Matrix_>
	constexpr void noiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {
		for (std::size_t i{ 1 }; i < matrix_.size(); ++i)
			for (std::size_t j{ 1 }; j < matrix_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
				if (matrix_[i][j]) matrix_[i][j] = false;
				else matrix_[i][j] = true;
			}
	}
	template<typename Matrix_>
	constexpr void rnoiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {
		for (std::size_t i{ matrix_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ matrix_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
				if (matrix_[i - 1][j - 1]) matrix_[i - 1][j - 1] = false;
				else matrix_[i - 1][j - 1] = true;
			}
	}

	template<typename Matrix_>
	constexpr void noiseShoreBothBool(Matrix_& matrix_, const double rbool_) noexcept {
		noiseShoreBool(matrix_, rbool_);
		rnoiseShoreBool(matrix_, rbool_);
	}
	template<typename Matrix_>
	constexpr void noiseShoreBothBool(Matrix_& matrix_, const double rbool1_, const double rbool2_) noexcept {
		noiseShoreBool(matrix_, rbool1_);
		rnoiseShoreBool(matrix_, rbool2_);
	}
	template<typename Matrix_>
	constexpr void rnoiseShoreBothBool(Matrix_& matrix_, const double rbool_) noexcept {
		rnoiseShoreBool(matrix_, rbool_);
		noiseShoreBool(matrix_, rbool_);
	}
	template<typename Matrix_>
	constexpr void rnoiseShoreBothBool(Matrix_& matrix_, const double rbool1_, const double rbool2_) noexcept {
		rnoiseShoreBool(matrix_, rbool1_);
		noiseShoreBool(matrix_, rbool2_);
	}

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseShore(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ 1 }; i < matrix_.size(); ++i)
			for (std::size_t j{ 1 }; j < matrix_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
				if (matrix_[i][j]) matrix_[i][j] = false_tile_;
				else matrix_[i][j] = true_tile_;
			}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void rnoiseShore(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ matrix_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ matrix_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
				if (matrix_[i - 1][j - 1]) matrix_[i - 1][j - 1] = false_tile_;
				else matrix_[i - 1][j - 1] = true_tile_;
			}
	}

	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseShoreOver(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ 1 }; i < matrix_.size(); ++i)
			for (std::size_t j{ 1 }; j < matrix_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
				if (matrix_[i][j] >= true_tile_) matrix_[i][j] = false_tile_;
				else matrix_[i][j] = true_tile_;
			}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void rnoiseShoreOver(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ matrix_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ matrix_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
				if (matrix_[i - 1][j - 1] >= true_tile_) matrix_[i - 1][j - 1] = false_tile_;
				else matrix_[i - 1][j - 1] = true_tile_;
			}
	}

}

#endif //Included Dungeon Template Library