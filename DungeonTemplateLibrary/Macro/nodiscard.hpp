/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#ifndef DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD

#if defined(_MSVC_LANG)

#if (_MSVC_LANG >= 201703L)
#define DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD [[nodiscard]]
#endif

#elif defined(__cplusplus)

#if (__cplusplus >= 201703L)
#define DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD [[nodiscard]]
#endif

#else

#define DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD

#endif //_MSVC_LANG and __cplusplus

#endif

#endif //Included Dungeon Template Library