/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_NUMERIC_LIMITS_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_NUMERIC_LIMITS_HPP

#ifndef DTL_TYPE_NUMERIC_LIMITS

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_NUMERIC_LIMITS ::TNumericLimits
#else //Platform Default
#include <limits>
#define DTL_TYPE_NUMERIC_LIMITS ::std::numeric_limits
#endif //Platform

#endif


#ifndef DTL_TYPE_NUMERIC_LIMITS_MIN

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_NUMERIC_LIMITS_MIN Min
#else //Platform Default
#define DTL_TYPE_NUMERIC_LIMITS_MIN min
#endif //Platform

#endif


#ifndef DTL_TYPE_NUMERIC_LIMITS_MAX

#if defined(UE_BUILD_FINAL_RELEASE) //Platform UE4
#define DTL_TYPE_NUMERIC_LIMITS_MAX Max
#else //Platform Default
#define DTL_TYPE_NUMERIC_LIMITS_MAX max
#endif //Platform

#endif

#endif //Included Dungeon Template Library