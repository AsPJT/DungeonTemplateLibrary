/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_INT_X_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_TYPE_INT_X_HPP

#if defined(UE_BUILD_FINAL_RELEASE) //UE4

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する

		using int8 = ::int8;
		using int16 = ::int16;
		using int32 = ::int32;
		using int64 = ::int64;
		using uint8 = ::uint8;
		using uint16 = ::uint16;
		using uint32 = ::uint32;
		using uint64 = ::uint64;

		using int_fast8 = ::int8;
		using int_fast16 = ::int16;
		using int_fast32 = ::int32;
		using int_fast64 = ::int64;
		using uint_fast8 = ::uint8;
		using uint_fast16 = ::uint16;
		using uint_fast32 = ::uint32;
		using uint_fast64 = ::uint64;

		using int_least8 = ::int8;
		using int_least16 = ::int16;
		using int_least32 = ::int32;
		using int_least64 = ::int64;
		using uint_least8 = ::uint8;
		using uint_least16 = ::uint16;
		using uint_least32 = ::uint32;
		using uint_least64 = ::uint64;

	}
}
#else //Platform Default

#ifndef DTL_DOES_NOT_INCLUDE_CSTDINT
#include <cstdint>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する

#ifdef INT8_MAX
		using int8 = ::std::int8_t;
#else
		using int8 = ::std::int_least8_t;
#endif
#ifdef INT16_MAX
		using int16 = ::std::int16_t;
#else
		using int16 = ::std::int_least16_t;
#endif
#ifdef INT32_MAX
		using int32 = ::std::int32_t;
#else
		using int32 = ::std::int_least32_t;
#endif
#ifdef INT64_MAX
		using int64 = ::std::int64_t;
#else
		using int64 = ::std::int_least64_t;
#endif
#ifdef UINT8_MAX
		using uint8 = ::std::uint8_t;
#else
		using uint8 = ::std::uint_least8_t;
#endif
#ifdef UINT16_MAX
		using uint16 = ::std::uint16_t;
#else
		using uint16 = ::std::uint_least16_t;
#endif
#ifdef UINT32_MAX
		using uint32 = ::std::uint32_t;
#else
		using uint32 = ::std::uint_least32_t;
#endif
#ifdef UINT64_MAX
		using uint64 = ::std::uint64_t;
#else
		using uint64 = ::std::uint_least64_t;
#endif

		using int_fast8 = ::std::int_fast8_t;
		using int_fast16 = ::std::int_fast16_t;
		using int_fast32 = ::std::int_fast32_t;
		using int_fast64 = ::std::int_fast64_t;
		using uint_fast8 = ::std::uint_fast8_t;
		using uint_fast16 = ::std::uint_fast16_t;
		using uint_fast32 = ::std::uint_fast32_t;
		using uint_fast64 = ::std::uint_fast64_t;

		using int_least8 = ::std::int_least8_t;
		using int_least16 = ::std::int_least16_t;
		using int_least32 = ::std::int_least32_t;
		using int_least64 = ::std::int_least64_t;
		using uint_least8 = ::std::uint_least8_t;
		using uint_least16 = ::std::uint_least16_t;
		using uint_least32 = ::std::uint_least32_t;
		using uint_least64 = ::std::uint_least64_t;

	}
}
#else
/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	namespace type { //"dtl::type"名前空間に属する

		using int8 = signed char;
		using int16 = short;
		using int32 = long;
		using int64 = long long;
		using uint8 = unsigned char;
		using uint16 = unsigned short;
		using uint32 = unsigned long;
		using uint64 = unsigned long long;

		using int_fast8 = signed char;
		using int_fast16 = int;
		using int_fast32 = long;
		using int_fast64 = long long;
		using uint_fast8 = unsigned char;
		using uint_fast16 = unsigned int;
		using uint_fast32 = unsigned long;
		using uint_fast64 = unsigned long long;

		using int_least8 = signed char;
		using int_least16 = short;
		using int_least32 = long;
		using int_least64 = long long;
		using uint_least8 = unsigned char;
		using uint_least16 = unsigned short;
		using uint_least32 = unsigned long;
		using uint_least64 = unsigned long long;

	}
}
#endif

#endif //Platform

#endif //Included Dungeon Template Library