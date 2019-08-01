/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_ASSIGN_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_ASSIGN_HPP

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		template<typename Matrix_Var_, typename Matrix_, typename Loop_Int_ = ::dtl::type::size, typename Array_Int_ = ::dtl::type::size>
		DTL_VERSIONING_CPP14_CONSTEXPR
			void assignMatrix(const Matrix_Var_& value_, Matrix_& matrix_) noexcept {
			for (Loop_Int_ row{}; row < static_cast<Loop_Int_>(matrix_.size()); ++row)
				for (Loop_Int_ col{}; col < static_cast<Loop_Int_>(matrix_[row].size()); ++col)
					matrix_[static_cast<Array_Int_>(row)][static_cast<Array_Int_>(col)] = value_;
		}

		template<typename Matrix_Var_, typename Matrix_, typename Loop_Int_ = ::dtl::type::size, typename Array_Int_ = ::dtl::type::size>
		DTL_VERSIONING_CPP14_CONSTEXPR
			void assignMatrix(const Matrix_Var_ & value_, Matrix_ & matrix_, const Loop_Int_ size_x_, const Loop_Int_ size_y_) noexcept {
			for (Loop_Int_ row{}; row < size_y_; ++row)
				for (Loop_Int_ col{}; col < size_x_; ++col)
					matrix_[static_cast<Array_Int_>(row)][static_cast<Array_Int_>(col)] = value_;
		}

	}
}

#endif //Included Dungeon Template Library