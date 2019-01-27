

#include "DTL.hpp"
#include <array>
#include <bitset>

template<typename Matrix_Int_, typename Matrix_>
void createMountain(Matrix_& matrix_, const Matrix_Int_ value_ = 1, const std::int_fast32_t rand_value_ = 1) noexcept {
	if (matrix_.size() == 0 || matrix_[0].size() == 0) return;
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


int main() {

	std::array<std::bitset<128>, 64> matrix{ {} };
	//dtl::SimpleVoronoiIsland<bool> generation(matrix);
	//dtl::noiseShoreBothBool(matrix, 0.3);

	createMountain<bool>(matrix);
	dtl::dungeonStringOutputBool(matrix, "##", "  ");

	return 0;
}