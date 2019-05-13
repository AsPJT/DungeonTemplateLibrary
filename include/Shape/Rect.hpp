/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RECT_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::Rect-(形状クラス)/
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

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class Rect : public RectBaseWithValue<Rect<Matrix_Int_>, Matrix_Int_>,
		             public DrawJagged<Rect<Matrix_Int_>, Matrix_Int_> {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;
			using ShapeBase_t = RectBaseWithValue<Rect<Matrix_Int_>, Matrix_Int_>;
			using DrawBase_t = DrawJagged<Rect<Matrix_Int_>, Matrix_Int_>;

			friend DrawBase_t;


			///// 代入処理 /////

			template<typename Matrix_Value_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void substitutionList(Matrix_Value_& matrix_) const noexcept {
				matrix_ = this->draw_value;
			}

			template<typename Matrix_Value_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void substitutionList(Matrix_Value_& matrix_, Function_&& function_) const noexcept {
				if (function_(matrix_)) matrix_ = this->draw_value;
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_, typename = typename std::enable_if<Matrix_::is_jagged::value>::type>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				const Index_Size end_y_ = this->calcEndY(matrix_.getY());
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					const Index_Size end_x_ = this->calcEndX(matrix_.getX(row));
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
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
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						matrix_.set(col, row, this->draw_value, args_...);
				return true;
			}

			//List
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawListImpl(Matrix_& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_ = this->start_x + this->width + 1;
				const Index_Size end_y_ = this->start_y + this->height + 1;
				dtl::type::size row_count{}, col_count{};
				for (auto&& row : matrix_) {
					++row_count;
					if (row_count <= this->start_y) continue;
					if (end_y_ != 1 && row_count >= end_y_) break;
					col_count = 0;
					for (auto&& col : row) {
						++col_count;
						if (col_count <= this->start_x) continue;
						if (end_x_ != 1 && col_count >= end_x_) break;
						this->substitutionList(col, args_...);
					}
				}
				return true;
			}

		public:


			///// 生成呼び出し /////

			//List
			template<typename Matrix_>
			constexpr bool drawList(Matrix_& matrix_) const noexcept {
				return this->drawListImpl(matrix_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorList(Matrix_& matrix_, Function_&& function_) const noexcept {
				return this->drawListImpl(matrix_, function_);
			}


			///// コンストラクタ /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
