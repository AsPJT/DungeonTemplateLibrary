/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_UNIQUE_PTR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_UNIQUE_PTR_HPP

#ifndef DTL_TYPE_UNIQUE_PTR

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_UNIQUE_PTR ::TUniquePtr
#else //Platform Default
#include <memory>
#define DTL_TYPE_UNIQUE_PTR ::std::unique_ptr
#endif //Platform

#endif

#endif //Included Dungeon Template Library