/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGrid-(形状クラス)/
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

		//偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class PointGrid : public RectBaseWithValue<PointGrid<Matrix_Int_>, Matrix_Int_>,
		                  public DrawJagged<PointGrid<Matrix_Int_>, Matrix_Int_> {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;
			using ShapeBase_t = RectBaseWithValue<PointGrid<Matrix_Int_>, Matrix_Int_>;
			using DrawBase_t = DrawJagged<PointGrid<Matrix_Int_>, Matrix_Int_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_, typename = typename std::enable_if<Matrix_::is_jagged::value>::type>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				for (Index_Size row{ this->start_y }; row < end_y_; row += 2) {
					const Index_Size end_x_ = this->calcEndX(matrix_.getX(row));
					for (Index_Size col{ this->start_x }; col < end_x_; col += 2)
						matrix_.set(col, row, this->draw_value, args_...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_x_ = this->calcEndX(matrix_.getX());
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				for (Index_Size row{ this->start_y }; row < end_y_; row += 2)
					for (Index_Size col{ this->start_x }; col < end_x_; col += 2)
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
