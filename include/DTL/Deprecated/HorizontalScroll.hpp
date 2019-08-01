/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_HORIZONTAL_SCROLL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_HORIZONTAL_SCROLL_HPP

#include <cstdint>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace generator {
		namespace horizontalScroll {
			namespace stl {

				template<typename Matrix_Var_, typename Matrix_>
				void createMountain(Matrix_& matrix_, const Matrix_Var_ value_, const ::std::int_fast32_t rand_value_) noexcept {
					//if (::dtl::utility::tool::isMatrixEmpty(matrix_)) return;

					::std::int_fast32_t y{ static_cast< ::std::int_fast32_t>(matrix_.size() - 1) };

					::std::int_fast32_t matrix_height_value{};
					matrix_[static_cast<::dtl::type::size>(matrix_height_value = ::dtl::random::mersenne_twister_32bit(1, y))][0] = value_;

					for (::dtl::type::size i{ 1 }; i < matrix_[0].size(); ++i) {
						if (matrix_height_value <= 1) matrix_height_value += ::dtl::random::mersenne_twister_32bit(0, rand_value_);
						else if (matrix_height_value >= y) matrix_height_value += ::dtl::random::mersenne_twister_32bit(-rand_value_, 0);
						else matrix_height_value += ::dtl::random::mersenne_twister_32bit(-rand_value_, rand_value_);

						if (matrix_height_value <= 0) matrix_height_value = 1;
						else if (matrix_height_value >= y + 1) matrix_height_value = y;
						matrix_[matrix_height_value][i] = value_;
					}
					//上半分を埋める
					for (::dtl::type::size row{ matrix_.size() - 2 };; --row) {
						for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
							if (matrix_[row + 1][col] == value_) matrix_[row][col] = value_;
						if (row == 0) break;
					}
					//下半分を埋める
					//for (::dtl::type::size row{ 1 }; row < matrix_.size(); ++row)
					//	for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
					//		if (matrix_[row - 1][col] == value_) matrix_[row][col] = value_;
				}

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library