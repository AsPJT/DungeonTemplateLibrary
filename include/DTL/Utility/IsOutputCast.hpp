/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_IS_OUTPUT_CAST_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_IS_OUTPUT_CAST_HPP

///// DTL Only /////

#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/EnableIf.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		template<typename Int_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr bool isOutputCast() noexcept {
			return false;
		}
		template<>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr bool isOutputCast<char>() noexcept {
			return true;
		}
		template<>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr bool isOutputCast<signed char>() noexcept {
			return true;
		}
		template<>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr bool isOutputCast<unsigned char>() noexcept {
			return true;
		}

		template<typename Int_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr typename DTL_TYPE_ENABLE_IF<isOutputCast<Int_>(), int>::DTL_TYPE_EITYPE
		CastForOutput(const Int_ v) noexcept(noexcept(static_cast<int>(v))) {
			return static_cast<int>(v);
		}
		template<typename Int_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr typename DTL_TYPE_ENABLE_IF<!isOutputCast<Int_>(), Int_>::DTL_TYPE_EITYPE
		CastForOutput(const Int_ v) noexcept {
			return v;
		}

	}
}

#endif //Included Dungeon Template Library
