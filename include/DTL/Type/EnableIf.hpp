/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_ENABLE_IF_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_ENABLE_IF_HPP

#ifndef DTL_TYPE_ENABLE_IF

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_ENABLE_IF ::TEnableIf

#ifndef DTL_TYPE_EITYPE
#define DTL_TYPE_EITYPE Type
#endif

#else //Platform Default
#include <type_traits>
#define DTL_TYPE_ENABLE_IF ::std::enable_if

#ifndef DTL_TYPE_EITYPE
#define DTL_TYPE_EITYPE type
#endif

#endif //Platform

#endif

#endif //Included Dungeon Template Library