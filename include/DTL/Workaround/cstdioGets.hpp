/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_WORKAROUND_CSTDIO_GETS_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_WORKAROUND_CSTDIO_GETS_HPP

#if defined(__clang_major__) && defined(__clang_minor__)
#if __clang_major__ == 3 && __clang_minor__ <= 5
/*#######################################################################################
	[概要] Clang 3.4.2に対応するためにgets関数を定義する。
	[Summary] Support Clang 3.4.2.
#######################################################################################*/
extern "C" char *gets(char *s);
#endif
#endif

#endif //Included Dungeon Template Library