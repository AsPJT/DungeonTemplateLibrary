/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_DOBUTSU_SHOGI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_DOBUTSU_SHOGI_HPP

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する

		template<typename Matrix_Var_>
		struct DobutsuShogiList {
			Matrix_Var_ chick_1{};
			Matrix_Var_ chick_2{};
			Matrix_Var_ hen_1{};
			Matrix_Var_ hen_2{};
			Matrix_Var_ giraffe_1{};
			Matrix_Var_ giraffe_2{};
			Matrix_Var_ elephant_1{};
			Matrix_Var_ elephant_2{};
			Matrix_Var_ lion_1{};
			Matrix_Var_ lion_2{};

			DobutsuShogiList() = default;

			constexpr DobutsuShogiList(
				const Matrix_Var_& chick_1_,
				const Matrix_Var_& chick_2_,
				const Matrix_Var_& hen_1_,
				const Matrix_Var_& hen_2_,
				const Matrix_Var_& giraffe_1_,
				const Matrix_Var_& giraffe_2_,
				const Matrix_Var_& elephant_1_,
				const Matrix_Var_& elephant_2_,
				const Matrix_Var_& lion_1_,
				const Matrix_Var_& lion_2_) noexcept :
				chick_1(chick_1_),
				chick_2(chick_2_),
				hen_1(hen_1_),
				hen_2(hen_2_),
				giraffe_1(giraffe_1_),
				giraffe_2(giraffe_2_),
				elephant_1(elephant_1_),
				elephant_2(elephant_2_),
				lion_1(lion_1_),
				lion_2(lion_2_) {}

			constexpr DobutsuShogiList(
				const Matrix_Var_& chick_,
				const Matrix_Var_& hen_,
				const Matrix_Var_& giraffe_,
				const Matrix_Var_& elephant_,
				const Matrix_Var_& lion_) noexcept :
				chick_1(chick_),
				chick_2(chick_),
				hen_1(hen_),
				hen_2(hen_),
				giraffe_1(giraffe_),
				giraffe_2(giraffe_),
				elephant_1(elephant_),
				elephant_2(elephant_),
				lion_1(lion_),
				lion_2(lion_) {}
		};

		template<typename Matrix_Var_>
		constexpr ::dtl::base::DobutsuShogiList<Matrix_Var_> defaultDobutsuShogiList() noexcept {
			return ::dtl::base::DobutsuShogiList<Matrix_Var_>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		}

	}
}

#endif //Included Dungeon Template Library