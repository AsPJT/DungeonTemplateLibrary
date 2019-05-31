/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECTANGULAR_BASE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECTANGULAR_BASE_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRectangular.hpp>

//共有データ
namespace dtl {
	inline namespace range { //"dtl::range"名前空間に属する

		//四角形クラス
		template<typename Derived_>
		class RectangularBase : public ::dtl::range::BasicRectangular<Derived_> {
		private:

			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRectangular<Derived_>;


		public:


			///// 消去 /////

//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ /////

			constexpr RectangularBase() = default;
			constexpr explicit RectangularBase(const ::dtl::base::MatrixRange3D& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr explicit RectangularBase(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size size_x_, const Index_Size size_y_, const Index_Size size_z_) noexcept
				:RectBase_t(start_x_, start_y_, start_z_, size_x_, size_y_, size_z_) {}
		};
	}
}

#endif //Included Dungeon Template Library
