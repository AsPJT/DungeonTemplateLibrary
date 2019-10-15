/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_MIN_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_MIN_HPP

#ifndef DTL_TYPE_MIN

#if defined(SPROUT_ALGORITHM_MIN_HPP) //Platform Sprout
#define DTL_TYPE_MIN (::sprout::min)
#elif defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_MIN (::FGenericPlatformMath::Min)
#else //Platform Default

#ifndef DTL_DOES_NOT_INCLUDE_ALGORITHM
#include <algorithm>
#define DTL_TYPE_MIN (::std::min)
#else
namespace dtl {
	namespace algo {
		template <typename T_>
		constexpr const T_& min(const T_& a_, const T_& b_) noexcept {
			return (a_ < b_) ? a_ : b_;
		}
	}
}
#define DTL_TYPE_MIN (::dtl::algo::min)
#endif

#endif //Platform

#endif

#endif //Included Dungeon Template Library