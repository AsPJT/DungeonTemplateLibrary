/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECTANGULAR_BASE_WITH_VALUE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_RECTANGULAR_BASE_WITH_VALUE_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/BasicRectangular.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace range { //"dtl::range"名前空間に属する

		//四角形クラス
		template<typename Derived_, typename Matrix_Var_>
		class RectangularBaseWithValue : public ::dtl::range::BasicRectangular<Derived_> {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using RectBase_t = ::dtl::range::BasicRectangular<Derived_>;


		protected:


			///// メンバ変数 (Member Variable) /////

			Matrix_Var_ draw_value{};


		public:


			///// メンバ変数の値を取得 (Get Value) /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Var_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 消去 (Clear) /////


/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearValue() noexcept {
				const Matrix_Var_ new_draw_value{};
				this->draw_value = new_draw_value;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 全ての値を初期値に戻す。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset all values to their initial values.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return static_cast<Derived_&>(*this);
			}


			///// コンストラクタ (Constructor) /////

			RectangularBaseWithValue() = default;
			constexpr explicit RectangularBaseWithValue(const Matrix_Var_& draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit RectangularBaseWithValue(const ::dtl::base::MatrixRange3D& matrix_range_) noexcept
				:RectBase_t(matrix_range_) {}
			constexpr RectangularBaseWithValue(const ::dtl::base::MatrixRange3D& matrix_range_, const Matrix_Var_& draw_value_) noexcept
				:RectBase_t(matrix_range_), draw_value(draw_value_) {}
			constexpr RectangularBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size size_x_, const Index_Size size_y_, const Index_Size size_z_) noexcept
				:RectBase_t(start_x_, start_y_, start_z_, size_x_, size_y_, size_z_) {}
			constexpr RectangularBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size size_x_, const Index_Size size_y_, const Index_Size size_z_, const Matrix_Var_& draw_value_) noexcept
				:RectBase_t(start_x_, start_y_, start_z_, size_x_, size_y_, size_z_), draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library
