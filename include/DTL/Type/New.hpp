/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_NEW_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_NEW_HPP

#ifndef DTL_TYPE_NEW

#if defined(__clang_major__) && defined(__clang_minor__)
#if __clang_major__ == 3 && __clang_minor__ <= 4
#define DTL_TYPE_NEW new
#endif
#endif

#endif

#ifndef DTL_TYPE_NEW

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_NEW new
#else //Platform Default

#ifndef DTL_DOES_NOT_INCLUDE_NEW
#include <new>
#define DTL_TYPE_NEW new(::std::nothrow)
#else
#define DTL_TYPE_NEW new
#endif

#endif //Platform

#endif

#endif //Included Dungeon Template Library