/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_ROGUE_LIKE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_ROGUE_LIKE_HPP

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する

		template<typename Matrix_Var_>
		struct RogueLikeList {
			Matrix_Var_ outside_wall_id{};
			Matrix_Var_ inside_wall_id{};
			Matrix_Var_ room_id{};
			Matrix_Var_ entrance_id{};
			Matrix_Var_ way_id{};

			RogueLikeList() = default;

			constexpr RogueLikeList(
				const Matrix_Var_& wall_id_,
				const Matrix_Var_& way_id_) noexcept :
				outside_wall_id(wall_id_),
				inside_wall_id(wall_id_),
				room_id(way_id_),
				entrance_id(way_id_),
				way_id(way_id_) {}

			constexpr RogueLikeList(
				const Matrix_Var_& wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& way_id_) noexcept :
				outside_wall_id(wall_id_),
				inside_wall_id(wall_id_),
				room_id(room_id_),
				entrance_id(way_id_),
				way_id(way_id_) {}

			constexpr RogueLikeList(
				const Matrix_Var_& wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_) noexcept :
				outside_wall_id(wall_id_),
				inside_wall_id(wall_id_),
				room_id(room_id_),
				entrance_id(entrance_id_),
				way_id(way_id_) {}

			constexpr RogueLikeList(
				const Matrix_Var_& outside_wall_id_,
				const Matrix_Var_& inside_wall_id_,
				const Matrix_Var_& room_id_,
				const Matrix_Var_& entrance_id_,
				const Matrix_Var_& way_id_) noexcept :
				outside_wall_id(outside_wall_id_),
				inside_wall_id(inside_wall_id_),
				room_id(room_id_),
				entrance_id(entrance_id_),
				way_id(way_id_) {}
		};

		template<typename Matrix_Var_>
		constexpr ::dtl::base::RogueLikeList<Matrix_Var_> defaultRogueLikeList() noexcept {
			return ::dtl::base::RogueLikeList<Matrix_Var_>(0, 1, 2, 3, 4);
		}

	}
}

#endif //Included Dungeon Template Library