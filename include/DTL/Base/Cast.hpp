/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_CAST_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_CAST_HPP

#include <DTL/Type/NumericLimits.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する

		template<typename Var_,typename Var2_>
		constexpr Var_ cast(Var2_ value_) noexcept {
			return static_cast<Var_>(
				(value_ < static_cast<Var2_>((DTL_TYPE_NUMERIC_LIMITS<Var_>::DTL_TYPE_NUMERIC_LIMITS_MIN)())) ?
				(DTL_TYPE_NUMERIC_LIMITS<Var_>::DTL_TYPE_NUMERIC_LIMITS_MIN)() :

				((value_ > static_cast<Var2_>((DTL_TYPE_NUMERIC_LIMITS<Var_>::DTL_TYPE_NUMERIC_LIMITS_MAX)())) ?
				(DTL_TYPE_NUMERIC_LIMITS<Var_>::DTL_TYPE_NUMERIC_LIMITS_MAX)() :
					value_));
		}

	}
}

#endif //Included Dungeon Template Library