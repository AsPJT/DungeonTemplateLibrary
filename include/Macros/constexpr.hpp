/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_CONSTEXPR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_CONSTEXPR_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#ifndef DTL_CONSTEXPR_CPP14

#if defined(_MSC_VER)

#if (_MSC_VER <= 1900)
#define DTL_CONSTEXPR_CPP14

#elif defined(_MSC_VER) && defined(_MSVC_LANG)
#if (_MSVC_LANG >= 201402L)
#define DTL_CONSTEXPR_CPP14 constexpr
#endif
#endif

#elif defined(__cplusplus)

#if (__cplusplus >= 201402L)
#define DTL_CONSTEXPR_CPP14 constexpr
#endif

#endif

#endif

///// もしDTL_CONSTEXPR_CPP14が無かったらつくる /////
#ifndef DTL_CONSTEXPR_CPP14
#define DTL_CONSTEXPR_CPP14
#endif

#endif //Included Dungeon Template Library