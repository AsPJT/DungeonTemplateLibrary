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

namespace dtl::console::output::tool {

	void endl() noexcept {
		std::cout << std::endl;
	}
	void puts(const std::string& str_) noexcept {
		std::cout << str_ << std::endl;
	}

} //namespace

#endif //Included Dungeon Template Library