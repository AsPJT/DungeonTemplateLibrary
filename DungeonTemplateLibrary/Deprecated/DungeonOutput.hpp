/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT

/* Character Code : UTF-8 (BOM) */
/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <iostream>
#include <string>

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
			std::cout << '\n';
		}
	}

} //namespace

namespace dtl::console::output::tool {

	void endl() noexcept {
		std::cout << '\n';
	}
	void puts(const std::string& str_) noexcept {
		std::cout << str_ << '\n';
	}

} //namespace

#endif //Included Dungeon Template Library