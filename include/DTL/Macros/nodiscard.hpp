/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_MACROS_NODISCARD_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_MACROS_NODISCARD_HPP

///// DTL_VERSIONING_CPP17_NODISCARDがない場合 /////

#ifndef DTL_VERSIONING_CPP17_NODISCARD
# if defined(__has_cpp_attribute) && 201402 < __cplusplus

#   if __has_cpp_attribute(nodiscard)
/*#######################################################################################
	[概要] [[nodiscard]] (C++17) のバージョン分けマクロ。
	[Summary] Versioning macros for [[nodiscard]] (C++17).
#######################################################################################*/
#     define DTL_VERSIONING_CPP17_NODISCARD [[nodiscard]]
#   endif

# elif defined(__clang__) || defined(__GNUC__)
/*#######################################################################################
	[概要] [[nodiscard]] (C++17) のバージョン分けマクロ。
	[Summary] Versioning macros for [[nodiscard]] (C++17).
#######################################################################################*/
#   define DTL_VERSIONING_CPP17_NODISCARD __attribute__((warn_unused_result))

# elif defined(_MSC_VER)
#   if 1911 <= _MSC_VER && 201402 < _MSVC_LANG
/*#######################################################################################
	[概要] [[nodiscard]] (C++17) のバージョン分けマクロ。
	[Summary] Versioning macros for [[nodiscard]] (C++17).
#######################################################################################*/
#     define DTL_VERSIONING_CPP17_NODISCARD [[nodiscard]]
#   else
// _Must_inspect_result_ expands into this
#     define DTL_VERSIONING_CPP17_NODISCARD                                                                                                                                                                                                                                                                                                \
      __declspec( "SAL_name"                                                                                                                                                                                                                                                                                                        \
                  "("                                                                                                                                                                                                                                                                                                               \
                  "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                       \
                  ","                                                                                                                                                                                                                                                                                                               \
                  "\"\""                                                                                                                                                                                                                                                                                                            \
                  ","                                                                                                                                                                                                                                                                                                               \
                  "\"2\""                                                                                                                                                                                                                                                                                                           \
                  ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")
#   endif

# endif
#endif

///// もしDTL_VERSIONING_CPP17_NODISCARDが無かったらつくる /////

#ifndef DTL_VERSIONING_CPP17_NODISCARD
/*#######################################################################################
	[概要] [[nodiscard]] (C++17) のバージョン分けマクロ。
	[Summary] Versioning macros for [[nodiscard]] (C++17).
#######################################################################################*/
#define DTL_VERSIONING_CPP17_NODISCARD
#endif

#endif
