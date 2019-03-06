#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING_BOOL
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */

#include <cstddef>
#include <iostream>
#include <string>

//STLデータ
namespace dtl::console::output::stl {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (matrix_.size()*loop_num_); ++row) {
			for (std::size_t col{}; col < (matrix_[row].size()*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row * x_ + col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_ * x_ + col / loop_num_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (col) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (matrix_.size()*loop_num_); ++row) {
			for (std::size_t col{}; col < (matrix_[row].size()*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

	template<typename Matrix_>
	constexpr void stringBool(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& true_, const std::string& false_, const std::size_t loop_num_) noexcept {
		if (loop_num_ == 0) return;
		for (std::size_t row{}; row < (y_*loop_num_); ++row) {
			for (std::size_t col{}; col < (x_*loop_num_); ++col) {
				if (matrix_[row / loop_num_][col / loop_num_][layer_]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library