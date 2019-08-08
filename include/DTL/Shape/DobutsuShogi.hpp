/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_DOBUTSU_SHOGI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_DOBUTSU_SHOGI_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::DobutsuShogi-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBaseDobutsuShogi.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] DobutsuShogiとは "Matrixの描画範囲に どうぶつしょうぎ の駒を初期位置に設置する" 機能を持つクラスである。
	[Summary] DobutsuShogi is a class that generates Dobutsu Shogi, a Japanese game, in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class DobutsuShogi : public ::dtl::range::RectBaseDobutsuShogi<DobutsuShogi<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<DobutsuShogi<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseDobutsuShogi<DobutsuShogi, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<DobutsuShogi, Matrix_Var_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };
				if (end_y_ <= this->start_y + 1) return true;
				const Index_Size end_x_{ this->calcEndX(matrix_.getX(this->start_y)) };
				if (end_x_ <= this->start_x + 2) return true;
				const Index_Size end_x2_{ this->calcEndX(matrix_.getX(end_y_ - 1)) };
				if (end_x2_ <= this->start_x + 2) return true;

				//香車
				matrix_.set(this->start_x, this->start_y, this->dobutsuShogiList.elephant_1, args_...);
				matrix_.set(end_x_ - 1, this->start_y, this->dobutsuShogiList.giraffe_1, args_...);
				matrix_.set(this->start_x, end_y_ - 1, this->dobutsuShogiList.giraffe_2, args_...);
				matrix_.set(end_x2_ - 1, end_y_ - 1, this->dobutsuShogiList.elephant_2, args_...);
				//王将・玉将
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, this->start_y, this->dobutsuShogiList.lion_1, args_...);
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, end_y_ - 1, this->dobutsuShogiList.lion_2, args_...);
				//飛車・角行
				const Index_Size end_2x_ = this->calcEndX(matrix_.getX(this->start_y + 1));
				if (end_2x_ <= this->start_x + 2) return true;
				const Index_Size end_2x2_ = this->calcEndX(matrix_.getX(end_y_ - 2));
				if (end_2x2_ <= this->start_x + 2) return true;
				matrix_.set(this->start_x + (end_2x_ - this->start_x) / 2, this->start_y + 1, this->dobutsuShogiList.chick_1, args_...);
				matrix_.set(this->start_x + (end_2x_ - this->start_x), end_y_ - 2, this->dobutsuShogiList.chick_2, args_...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };
				if (end_x_ <= this->start_x + 2 || end_y_ <= this->start_y + 1) return true;
				//香車
				matrix_.set(this->start_x, this->start_y, this->dobutsuShogiList.elephant_1, args_...);
				matrix_.set(end_x_ - 1, this->start_y, this->dobutsuShogiList.giraffe_1, args_...);
				matrix_.set(this->start_x, end_y_ - 1, this->dobutsuShogiList.giraffe_2, args_...);
				matrix_.set(end_x_ - 1, end_y_ - 1, this->dobutsuShogiList.elephant_2, args_...);
				//王将・玉将
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, this->start_y, this->dobutsuShogiList.lion_1, args_...);
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, end_y_ - 1, this->dobutsuShogiList.lion_2, args_...);
				//飛車・角行
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, this->start_y + 1, this->dobutsuShogiList.chick_1, args_...);
				matrix_.set(this->start_x + (end_x_ - this->start_x) / 2, end_y_ - 2, this->dobutsuShogiList.chick_2, args_...);
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
