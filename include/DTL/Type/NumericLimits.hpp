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

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#ifndef DTL_TYPE_NUMERIC_LIMITS

#if defined(UE_BUILD_FINAL_RELEASE) //UE4
#define DTL_TYPE_NUMERIC_LIMITS ::TNumericLimits
#else
#include <limits>
#define DTL_TYPE_NUMERIC_LIMITS std::numeric_limits
#endif

#endif


#ifndef DTL_TYPE_NUMERIC_LIMITS_MIN

#if defined(UE_BUILD_FINAL_RELEASE) //UE4
#define DTL_TYPE_NUMERIC_LIMITS_MIN Min
#else
#define DTL_TYPE_NUMERIC_LIMITS_MIN min
#endif

#endif


#ifndef DTL_TYPE_NUMERIC_LIMITS_MAX

#if defined(UE_BUILD_FINAL_RELEASE) //UE4
#define DTL_TYPE_NUMERIC_LIMITS_MAX Max
#else
#define DTL_TYPE_NUMERIC_LIMITS_MAX max
#endif

#endif

#endif //Included Dungeon Template Library