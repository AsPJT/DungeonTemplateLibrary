/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_MATRIX
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_MATRIX

/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl::utility::stl {

	//サイズ変更(std::vector, std::deque等)
	template<typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		matrix_.resize(y_);
		for (std::size_t row{}; row < y_; ++row)
			matrix_[row].resize(x_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		matrix_.resize(y_);
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row].resize(x_);
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col] = value_;
		}
	}

}
namespace dtl::utility::layer::stl {

	template<typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t layer_) noexcept {
		matrix_.resize(y_);
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row].resize(x_);
			for (std::size_t col{}; col < x_; ++col)
				matrix_[row][col].resize(layer_);
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		matrix_.resize(y_);
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row].resize(x_);
			for (std::size_t col{}; col < x_; ++col) {
				matrix_[row][col].resize(layer_);
				for (std::size_t layer{}; layer < layer_; ++layer)
					matrix_[row][col][layer_] = value_;
			}
		}
	}
	template<typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col].resize(layer_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void resize(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				matrix_[row][col].resize(layer_);
				for (std::size_t layer{}; layer < layer_; ++layer)
					matrix_[row][col][layer_] = value_;
			}
	}

}

namespace dtl::utility::stl::tool {

	//上下反転
	template<typename Matrix_>
	constexpr void flip(Matrix_& matrix_) noexcept {
		for (std::size_t row{}, row2{ matrix_.size() - 1 };; ++row, --row2) {
			if (row >= row2) break;
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				const auto&& tmp{ (matrix_[row][col] + 0) };
				matrix_[row][col] = matrix_[row2][col];
				matrix_[row2][col] = std::move(tmp);
			}
		}
	}
	//左右反転
	template<typename Matrix_>
	constexpr void mirror(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}, col2{ matrix_[row].size() - 1 };; ++col, --col2) {
				if (col >= col2) break;
				const auto&& tmp{ (matrix_[row][col] + 0) };
				matrix_[row][col] = matrix_[row][col2];
				matrix_[row][col2] = std::move(tmp);
			}
	}

}

namespace dtl::utility::tool {

	template<typename Matrix_, typename Matrix2_>
	constexpr void convertSTL_intoDefault(Matrix_& matrix_, std::size_t& x_, std::size_t& y_, const Matrix2_& matrix2_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col] = matrix2_[row][col];
		((y_ = matrix2_.size()) == 0) ? (x_ = 0) : (x_ = matrix2_[0].size());
	}
	template<typename Matrix_, typename Matrix2_>
	constexpr void convertSTL_intoArray(Matrix_& matrix_, std::size_t& x_, std::size_t& y_, const Matrix2_& matrix2_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row*x_ + col] = matrix2_[row][col];
		((y_ = matrix2_.size()) == 0) ? (x_ = 0) : (x_ = matrix2_[0].size());
	}
	template<typename Matrix_, typename Matrix2_>
	constexpr void convertSTL_intoLayer(Matrix_& matrix_, std::size_t& layer_, const Matrix2_& matrix2_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				matrix_[row][col][layer_] = matrix2_[row][col];
	}

}

#endif //Included Dungeon Template Library