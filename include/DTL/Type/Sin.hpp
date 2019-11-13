/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_SIN_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_SIN_HPP

#ifndef DTL_TYPE_SIN

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_SIN ::FMath::Sin
#else //Platform Default
#include <cmath>
#define DTL_TYPE_SIN ::std::sin
#endif //Platform

#endif

#endif //Included Dungeon Template Library