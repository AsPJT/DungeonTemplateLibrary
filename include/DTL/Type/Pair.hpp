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

#if defined(UE_BUILD_FINAL_RELEASE) //UE4

#define DTL_TYPE_PAIR ::TPair

namespace dtl {
	namespace type {
		template<typename Value1_, typename Value2_>
		DTL_TYPE_PAIR<Value1_, Value2_> makePair(const Value1_& value1_, const Value2_& value2_) noexcept {
			DTL_TYPE_PAIR<Value1_, Value2_> pair(value1_, value2_);
			return pair;
		}
	}
}

#else
#include <utility>
#define DTL_TYPE_PAIR ::std::pair

namespace dtl {
	namespace type {
		template<typename Value1_, typename Value2_>
		DTL_TYPE_PAIR<Value1_, Value2_> makePair(const Value1_& value1_, const Value2_& value2_) noexcept {
			return ::std::make_pair(value1_, value2_);
		}
	}
}

#endif

#endif

#endif //Included Dungeon Template Library