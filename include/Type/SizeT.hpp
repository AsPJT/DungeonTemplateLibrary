/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_TYPE_SIZE_T_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_TYPE_SIZE_T_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#if defined(UE_BUILD_FINAL_RELEASE) //UE4
namespace dtl { namespace type { using size = SIZE_T; } }
#else
#include <cstddef>
namespace dtl { namespace type { using size = std::size_t; } }
#endif

#endif //Included Dungeon Template Library