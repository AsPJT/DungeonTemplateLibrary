/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_TYPE_FORWARD_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_TYPE_FORWARD_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#ifndef DUNGEON_TEMPLATE_LIBRARY_FORWARD

#if defined(UE_BUILD_FINAL_RELEASE) //UE4
#define DUNGEON_TEMPLATE_LIBRARY_FORWARD ::Forward
#else
#include <utility>
#define DUNGEON_TEMPLATE_LIBRARY_FORWARD std::forward
#endif

#endif

#endif //Included Dungeon Template Library