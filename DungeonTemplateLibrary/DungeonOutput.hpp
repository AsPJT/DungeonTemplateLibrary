#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace dtl::console::output::stl {

	//文字出力
	template<typename Matrix_>
	constexpr void stringMirrorBool(const Matrix_& matrix_, const std::string& true_, const std::string& false_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{ matrix_[row].size() / 2 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			for (std::size_t col{}; col < matrix_[row].size() / 2; ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}

} //namespace

namespace dtl::console::output::hiding {

	void string_String([[maybe_unused]] const std::vector<std::string>& string_) noexcept {}

	template<typename First_, typename ...Args_>
	constexpr void string_String(std::vector<std::string>& string_vector_, const First_& first_, const Args_&... args_) noexcept {
		string_vector_.emplace_back(std::string(first_));
		string_String(string_vector_, args_...);
	}

} //namespace

namespace dtl::console::output::stl {

	template<typename Matrix_, typename First_, typename ...Args_>
	void string(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_String;

		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		string_String(string_vector, args_...);

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (static_cast<std::size_t>(matrix_[row][col]) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(matrix_[row][col])];
			}
			std::cout << std::endl;
		}
	}

} //namespace

namespace dtl::console::output::rangeBasedFor {

	template<typename Matrix_, typename First_, typename ...Args_>
	void string(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {

		using dtl::console::output::hiding::string_String;

		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		string_String(string_vector, args_...);

		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (static_cast<std::size_t>(col) >= string_vector.size()) continue;
				std::cout << string_vector[static_cast<std::size_t>(col)];
			}
			std::cout << std::endl;
		}
	}

} //namespace

namespace dtl::console::output::tool {

	void endl() noexcept {
		std::cout << std::endl;
	}
	void puts(const std::string& str_) noexcept {
		std::cout << str_ << std::endl;
	}

} //namespace

#endif //Included Dungeon Template Library