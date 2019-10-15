/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_SORT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_SORT_HPP

#ifndef DTL_TYPE_SORT

#if defined(SPROUT_ALGORITHM_SORT_HPP) //Platform Sprout
#define DTL_TYPE_SORT (::sprout::sort)

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Vector_>
		void sortVector(Vector_& vector_) noexcept {
			DTL_TYPE_SORT(vector_.begin(), vector_.end());
		}
	}
}

#elif defined(UE_BUILD_FINAL_RELEASE) //Platform UE4

#include <algorithm> //todo
#define DTL_TYPE_SORT (::std::sort)

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Vector_>
		void sortVector(Vector_& vector_) noexcept {
			vector_.Sort();
		}
	}
}

#else //Platform Default
#include <algorithm>
#define DTL_TYPE_SORT (::std::sort)

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する
		template<typename Vector_>
		void sortVector(Vector_& vector_) noexcept {
			DTL_TYPE_SORT(vector_.begin(), vector_.end());
		}
	}
}

#endif //Platform

#endif

#endif //Included Dungeon Template Library