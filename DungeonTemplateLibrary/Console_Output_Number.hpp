#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_NUMBER
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <string>

//STLデータ
namespace dtl::console::output::stl {

	//数値出力
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col] << string_;
			std::cout << std::endl;
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col] << string_;
			std::cout << std::endl;
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row * x_ + col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row * x_ + col] << string_;
			std::cout << std::endl;
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << col;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::string& string_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << col << string_;
			std::cout << std::endl;
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	//数値出力
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col][layer_];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col][layer_] << string_;
			std::cout << std::endl;
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col][layer_];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void number(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::string& string_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col][layer_] << string_;
			std::cout << std::endl;
		}
	}

} //namespace

#endif //Included Dungeon Template Library