#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_CONSOLE_OUTPUT_STRING
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>

//隠ぺいデータ
namespace dtl::console::output::hiding {

	constexpr void string_String([[maybe_unused]] const std::vector<std::string>& string_) noexcept {}

	template<typename First_, typename ...Args_>
	constexpr void string_String(std::vector<std::string>& string_vector_, const First_& first_, const Args_&... args_) noexcept {
		string_vector_.emplace_back(std::string(first_));
		string_String(string_vector_, args_...);
	}
	template<typename ...Args_>
	void string_Split(std::vector<std::string>& string_vector_, const Args_&... args_) noexcept {
		string_String(string_vector_, args_...);
	}

} //namespace

//STLデータ
namespace dtl::console::output::stl {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//通常データ
namespace dtl::console::output::normal {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//配列データ
namespace dtl::console::output::array {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row*x_ + col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row*x_ + col])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//範囲forデータ
namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (static_cast<std::size_t>(col) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(col)];
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::console::output::layer::stl {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t layer_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<std::size_t>(matrix_[row][col][layer_]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col][layer_])];
			}
			std::cout << '\n';
		}
	}

} //namespace

//レイヤー通常データ
namespace dtl::console::output::layer::normal {

	template<typename Matrix_, typename ...Args_>
	void string(const Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_Split;

		std::vector<std::string> string_vector;
		string_Split(string_vector, args_...);

		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (static_cast<std::size_t>(matrix_[row][col][layer_]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col][layer_])];
			}
			std::cout << '\n';
		}
	}

} //namespace

#endif //Included Dungeon Template Library