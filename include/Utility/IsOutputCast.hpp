/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_IS_OUTPUT_CAST_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_IS_OUTPUT_CAST_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <Macros/nodiscard.hpp>

namespace dtl {
	inline namespace utility {

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

	}
}

#endif //Included Dungeon Template Library