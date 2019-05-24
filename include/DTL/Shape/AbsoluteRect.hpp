/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ABSOLUTE_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ABSOLUTE_RECT_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Rect-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/DrawJagged.hpp>
#include <DTL/Range/RectBaseWithValue.hpp>

namespace dtl {
	inline namespace shape {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class AbsoluteRect : public RectBaseWithValue<AbsoluteRect<Matrix_Int_>, Matrix_Int_>,
		                     public DrawJagged<AbsoluteRect<Matrix_Int_>, Matrix_Int_> {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = RectBaseWithValue<AbsoluteRect<Matrix_Int_>, Matrix_Int_>;
			using DrawBase_t = DrawJagged<AbsoluteRect<Matrix_Int_>, Matrix_Int_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_x_ = this->calcEndX(matrix_.getX());
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						matrix_.set(col, row, this->draw_value, args_...);
				return true;
			}

		public:


			///// コンストラクタ /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
