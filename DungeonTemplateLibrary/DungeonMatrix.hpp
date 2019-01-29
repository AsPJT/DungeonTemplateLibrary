#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_MATRIX
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_MATRIX
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	//ダンジョン内の値を操作
	namespace matrix {

		//指定位置に値を代入する
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void set(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			matrix_[y_][x_] = value_;
		}
		template<typename Matrix_>
		constexpr void set(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			matrix_[y_][x_] = 0;
		}
		//指定位置の値を取得する
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void get(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, Matrix_Int_& value_) noexcept {
			value_ = matrix_[y_][x_];
		}
		template<typename Matrix_>
		auto get(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			return matrix_[y_][x_];
		}

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

}

#endif //Included Dungeon Template Library