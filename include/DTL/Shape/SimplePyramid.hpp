/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_PYRAMID_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_PYRAMID_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::SimplePyramid-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/Min.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBaseWithMaxMin.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] SimplePyramidとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] SimplePyramid is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class SimplePyramid : public ::dtl::range::RectBaseWithMaxMin<SimplePyramid<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<SimplePyramid<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithMaxMin<SimplePyramid, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<SimplePyramid, Matrix_Var_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) - this->start_y };
				const Index_Size mid_y_{ end_y_ / 2 };

				for (Index_Size row{}; row < end_y_; ++row) {
					Index_Size row2{ (row > mid_y_) ? end_y_ - row - 1 : row };
					const Index_Size end_x_{ this->calcEndX(matrix_.getX()) - this->start_x };
					const Index_Size mid_x_{ end_x_ / 2 };
					for (Index_Size col{}; col < end_x_; ++col) {
						Index_Size col2{ (col > mid_x_) ? end_x_ - col - 1 : col };
						matrix_.set(col + this->start_x, row + this->start_y, this->min_value +
							static_cast<Matrix_Var_>(DTL_TYPE_MIN(
								static_cast<double>(this->max_value - this->min_value) * row2 / mid_y_,
								static_cast<double>(this->max_value - this->min_value) * col2 / mid_x_)), args_...);
					}
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) - this->start_x };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) - this->start_y };
				const Index_Size mid_x_{ end_x_ / 2 };
				const Index_Size mid_y_{ end_y_ / 2 };

				for (Index_Size row{}; row < end_y_; ++row) {
					Index_Size row2{ (row > mid_y_) ? end_y_ - row - 1 : row };
					for (Index_Size col{}; col < end_x_; ++col) {
						Index_Size col2{ (col > mid_x_) ? end_x_ - col - 1 : col };
						matrix_.set(col + this->start_x, row + this->start_y, this->min_value +
							static_cast<Matrix_Var_>(DTL_TYPE_MIN(
								(static_cast<double>(this->max_value) - static_cast<double>(this->min_value)) * row2 / mid_y_,
								(static_cast<double>(this->max_value) - static_cast<double>(this->min_value)) * col2 / mid_x_)), args_...);
					}
				}
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
