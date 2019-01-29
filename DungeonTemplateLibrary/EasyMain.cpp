#include "DTL.hpp"
#include <array>
#include <bitset>

namespace dtl {
	//ダンジョン内の値を操作
	namespace mat {

		//指定位置に値を代入する
		template<typename Matrix_Int_, typename Matrix_>
		void set(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			matrix_[y_][x_] = value_;
		}
		//指定位置の値を取得する
		template<typename Matrix_Int_, typename Matrix_>
		void get(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, Matrix_Int_& value_) noexcept {
			value_ = matrix_[y_][x_];
		}
		template<typename Matrix_>
		auto get(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			return matrix_[y_][x_];
		}

		//上下反転
		template<typename Matrix_>
		void flip(Matrix_& matrix_) noexcept {
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
		void mirror(Matrix_& matrix_) noexcept {
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}, col2{ matrix_[row].size() - 1 };; ++col, --col2) {
					if (col >= col2) break;
					const auto&& tmp{ (matrix_[row][col] + 0) };
					matrix_[row][col] = matrix_[row][col2];
					matrix_[row][col2] = std::move(tmp);
				}
		}
	}

	template<typename Matrix_>
	constexpr bool isMatrixEmpty(const Matrix_& matrix_) noexcept {
		return (matrix_.size() == 0 || matrix_[0].size() == 0);
	}
	template<typename Matrix_>
	constexpr bool isMatrixEmpty(const Matrix_& matrix_, const std::size_t num_) noexcept {
		return (matrix_.size() < num_ || matrix_[0].size() < num_);
	}

	template<typename Matrix_Int_, typename Matrix_>
	void createMountain(Matrix_& matrix_, const Matrix_Int_ value_ = 1, const std::int_fast32_t rand_value_ = 1) noexcept {
		if (isMatrixEmpty(matrix_)) return;
		std::int_fast32_t y{ static_cast<std::int_fast32_t>(matrix_.size() - 1) };

		std::int_fast32_t rand_value{};
		matrix_[static_cast<std::size_t>(rand_value = dtl::rnd(1, y))][0] = value_;

		for (std::size_t i{ 1 }; i < matrix_[0].size(); ++i) {
			if (rand_value <= 1) rand_value += dtl::rnd(0, rand_value_);
			else if (rand_value >= y) rand_value += dtl::rnd(-rand_value_, 0);
			else rand_value += dtl::rnd(-rand_value_, rand_value_);

			if (rand_value <= 0) rand_value = 1;
			else if (rand_value >= y + 1) rand_value = y;
			matrix_[rand_value][i] = value_;
		}

		for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row - 1][col] == value_) matrix_[row][col] = value_;
	}

}


int main() {

	std::array<std::bitset<128>, 64> matrix{ {} };
	dtl::SimpleVoronoiIsland<bool> generation(matrix);
	dtl::noiseShoreBothBool(matrix, 0.3);

	//dtl::createMountain<bool>(matrix);
	dtl::dungeonStringOutputBool(matrix, "##", "  ");

	dtl::mat::flip(matrix);
	dtl::mat::mirror(matrix);
	dtl::dungeonStringOutputBool(matrix, "##", "  ");

	return 0;
}