﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_WITH_VALUE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECT_BASE_WITH_VALUE_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRect.hpp>

//共有データ
namespace dtl {
	inline namespace utility {

		//四角形クラス
		template<typename Derived_, typename Matrix_Int_>
		class RectBaseWithValue : public ::dtl::utility::BasicRect<Derived_> {
		private:

			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::utility::BasicRect<Derived_>;


		protected:


			///// メンバ変数 /////

			Matrix_Int_ draw_value{};


		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 消去 /////

			//塗り値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearValue() noexcept {
				const Matrix_Int_ new_draw_value{};
				this->draw_value = new_draw_value;
				return static_cast<Derived_&>(*this);
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return static_cast<Derived_&>(*this);
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->draw_value = draw_value_;
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ /////

			constexpr RectBaseWithValue() = default;
			constexpr explicit RectBaseWithValue(const Matrix_Int_ & draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit RectBaseWithValue(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr explicit RectBaseWithValue(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:RectBase_t(matrix_range_),
				draw_value(draw_value_) {}
			constexpr explicit RectBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_) {}
			constexpr explicit RectBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, width_, height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library