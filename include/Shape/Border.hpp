/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BORDER_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Border-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Type/Forward.hpp>
#include <Type/SizeT.hpp>
#include <Utility/DrawJagged.hpp>
#include <Utility/RectBaseWithValue.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋める
		template<typename Matrix_Int_>
		class Border : public RectBaseWithValue<Border<Matrix_Int_>, Matrix_Int_>,
		               public DrawJagged<Border<Matrix_Int_>, Matrix_Int_> {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;
			using ShapeBase_t = RectBaseWithValue<Border<Matrix_Int_>, Matrix_Int_>;
			using DrawBase_t = DrawJagged<Border<Matrix_Int_>, Matrix_Int_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_, typename = typename std::enable_if<Matrix_::is_jagged::value>::type>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				if (end_y_ <= this->start_y) return true;
				const Index_Size last_x1 = this->calcEndX(matrix_.getX(this->start_y));
				for (Index_Size col{ this->start_x }; col < last_x1; ++col)
					matrix_.set(col, this->start_y, this->draw_value, args_...);
				const Index_Size last_x2 = this->calcEndX(matrix_.getX(end_y_ - 1));
				for (Index_Size col{ this->start_x }; col < last_x2; ++col)
					matrix_.set(col, end_y_ - 1, this->draw_value, args_...);
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					const Index_Size last_x3 = this->calcEndX(matrix_.getX(row));
					if (last_x3 <= this->start_x) continue;
					matrix_.set(this->start_x, row, this->draw_value, args_...);
					matrix_.set(last_x3 - 1, row, this->draw_value, args_...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_x_ = this->calcEndX(matrix_.getX());
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				if (end_x_ <= this->start_x || end_y_ <= this->start_y) return true;
				for (Index_Size col{ this->start_x }; col < end_x_; ++col) {
					matrix_.set(col, this->start_y, this->draw_value, args_...);
					matrix_.set(col, end_y_ - 1, this->draw_value, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					matrix_.set(this->start_x, row, this->draw_value, args_...);
					matrix_.set(end_x_ - 1, row, this->draw_value, args_...);
				}
				return true;
			}

		public:


			///// コンストラクタ /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
