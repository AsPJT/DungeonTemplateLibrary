/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FAST_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FAST_RECT_HPP

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/Assign.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace fast { //"dtl::fast"名前空間に属する

		template<typename Matrix_Int_, typename Matrix_>
		DTL_VERSIONING_CPP14_CONSTEXPR
			bool drawRect(const Matrix_Int_ & value_, Matrix_ & matrix_) noexcept {
			::dtl::utility::assignMatrix<Matrix_Int_, Matrix_>(value_, matrix_);
			return true;
		}

		template<typename Matrix_Int_, typename Matrix_>
		DTL_VERSIONING_CPP14_CONSTEXPR
			bool drawRect(const Matrix_Int_ & value_, Matrix_ & matrix_, const ::dtl::type::size size_x_, const ::dtl::type::size size_y_) noexcept {
			::dtl::utility::assignMatrix<Matrix_Int_, Matrix_>(value_, matrix_, size_x_, size_y_);
			return true;
		}

	}
}

#endif //Included Dungeon Template Library