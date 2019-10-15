/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_PAIR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_PAIR_HPP

#ifndef DTL_TYPE_PAIR

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4

#define DTL_TYPE_PAIR ::TPair

#ifndef DTL_TYPE_PFIRST
#define DTL_TYPE_PFIRST Get<0>()
#endif
#ifndef DTL_TYPE_PSECOND
#define DTL_TYPE_PSECOND Get<1>()
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Value1_, typename Value2_>
		DTL_TYPE_PAIR<Value1_, Value2_> makePair(const Value1_& value1_, const Value2_& value2_) noexcept {
			return DTL_TYPE_PAIR<Value1_, Value2_>(value1_, value2_);
		}
	}
}

#else //Platform Default
#include <utility>
#define DTL_TYPE_PAIR ::std::pair

#ifndef DTL_TYPE_PFIRST
#define DTL_TYPE_PFIRST first
#endif
#ifndef DTL_TYPE_PSECOND
#define DTL_TYPE_PSECOND second
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Value1_, typename Value2_>
		DTL_TYPE_PAIR<Value1_, Value2_> makePair(const Value1_& value1_, const Value2_& value2_) noexcept {
			return ::std::make_pair(value1_, value2_);
		}
	}
}

#endif //Platform

#endif

#endif //Included Dungeon Template Library