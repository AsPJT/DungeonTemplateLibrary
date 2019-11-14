/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_THREAD_LOCAL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_THREAD_LOCAL_HPP

#ifndef DTL_TYPE_THREAD_LOCAL

#if defined(__clang_major__) && defined(__clang_minor__)
#if __clang_major__ == 3 && __clang_minor__ <= 5
#define DTL_TYPE_THREAD_LOCAL
#endif
#endif

#endif

#ifndef DTL_TYPE_THREAD_LOCAL
#define DTL_TYPE_THREAD_LOCAL thread_local
#endif



#ifndef DTL_TYPE_THREAD_LOCAL_RAND

#if defined(__GNUC__) && defined(__GNUC_MINOR__)
#if __GNUC__ == 4 && __GNUC_MINOR__ < 9
#define DTL_TYPE_THREAD_LOCAL_RAND
#endif
#if defined(__GNUC_PATCHLEVEL__)
#if __GNUC__ == 4 && __GNUC_MINOR__ == 9 && __GNUC_PATCHLEVEL__ < 2
#define DTL_TYPE_THREAD_LOCAL_RAND
#endif
#endif
#endif

#endif

#ifndef DTL_TYPE_THREAD_LOCAL_RAND
#define DTL_TYPE_THREAD_LOCAL_RAND thread_local
#endif


#endif //Included Dungeon Template Library