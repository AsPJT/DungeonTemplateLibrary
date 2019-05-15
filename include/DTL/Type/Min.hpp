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

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#ifndef DTL_TYPE_MIN

#if defined(SPROUT_ALGORITHM_MIN_HPP) //Sprout
#define DTL_TYPE_MIN (sprout::min)
#else
#include <algorithm>
#define DTL_TYPE_MIN (std::min)
#endif

#endif

#endif //Included Dungeon Template Library