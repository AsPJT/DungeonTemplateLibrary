/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_NODISCARD_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MACROS_NODISCARD_HPP

///// DUNGEON_TEMPLATE_LIBRARY_NODISCARDÇ™Ç»Ç¢èÍçá /////
#ifndef DUNGEON_TEMPLATE_LIBRARY_NODISCARD
#ifdef __has_cpp_attribute

#if __has_cpp_attribute(nodiscard)
#define DUNGEON_TEMPLATE_LIBRARY_NODISCARD [[nodiscard]]
#endif

#elif defined(__clang__)
#define DUNGEON_TEMPLATE_LIBRARY_NODISCARD __attribute__((warn_unused_result))

#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define DUNGEON_TEMPLATE_LIBRARY_NODISCARD                                                                                                                                                                                                                                                                                                \
  __declspec("SAL_name"                                                                                                                                                                                                                                                                                                        \
             "("                                                                                                                                                                                                                                                                                                               \
             "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                       \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"\""                                                                                                                                                                                                                                                                                                            \
             ","                                                                                                                                                                                                                                                                                                               \
             "\"2\""                                                                                                                                                                                                                                                                                                           \
             ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")

#endif
#endif

///// Ç‡ÇµDUNGEON_TEMPLATE_LIBRARY_NODISCARDÇ™ñ≥Ç©Ç¡ÇΩÇÁÇ¬Ç≠ÇÈ /////
#ifndef DUNGEON_TEMPLATE_LIBRARY_NODISCARD
#define DUNGEON_TEMPLATE_LIBRARY_NODISCARD
#endif

#endif
