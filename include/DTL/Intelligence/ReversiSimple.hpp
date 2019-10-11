/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_INTELLIGENCE_REVERSI_SIMPLE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_INTELLIGENCE_REVERSI_SIMPLE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::intelligence::ReversiSimple-(知能クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/IntX.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBaseWithBattle.hpp>
#include <DTL/Utility/DrawJagged.hpp>

#include <memory>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace intelligence { //"dtl::intelligence"名前空間に属する

/*#######################################################################################
	[概要] ReversiSimpleとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] ReversiSimple is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class ReversiSimple : public ::dtl::range::RectBaseWithBattle<ReversiSimple<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<ReversiSimple<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithBattle<ReversiSimple, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<ReversiSimple, Matrix_Var_>;

			friend DrawBase_t;

			//指定した場所に駒を置く
			template<typename Matrix_, typename ...Args_>
			Index_Size reversiPutPiece(Matrix_& matrix_, const Index_Size  col_, const Index_Size row_, ::std::unique_ptr< ::dtl::type::int_fast32[]>& stl_tmp_x, ::std::unique_ptr< ::dtl::type::int_fast32[]>& stl_tmp_y, const Index_Size w_, const Index_Size h_, Args_&& ... args_) const noexcept {
				Index_Size piece_turn_num{};
				if (matrix_.get(col_, row_) != this->empty_value) return 0;

				for (::dtl::type::int_fast32 y{ -1 }; y <= 1; ++y)
					for (::dtl::type::int_fast32 x{ -1 }; x <= 1; ++x) {
						for (Index_Size i{}; i < w_; ++i) stl_tmp_x[i] = 0;
						for (Index_Size i{}; i < h_; ++i) stl_tmp_y[i] = 0;
						for (Index_Size turn_tmp_id{};; ++turn_tmp_id) {
							::dtl::type::int_fast32 turn_x{ static_cast<::dtl::type::int_fast32>(col_) + x * (static_cast<::dtl::type::int_fast32>(turn_tmp_id) + 1) };
							::dtl::type::int_fast32 turn_y{ static_cast<::dtl::type::int_fast32>(row_) + y * (static_cast<::dtl::type::int_fast32>(turn_tmp_id) + 1) };
							if (turn_x < 0 || turn_x >= w_ || turn_y < 0 || turn_y >= h_ || matrix_.get(turn_x, turn_y) == this->empty_value) break;
							if (matrix_.get(turn_x, turn_y) == this->friend_value) {
								for (Index_Size i{}; i < turn_tmp_id; ++i)
									matrix_.set(static_cast<Index_Size>(stl_tmp_x[i]), static_cast<Index_Size>(stl_tmp_y[i]), this->friend_value, args_...);
								piece_turn_num += turn_tmp_id;
								break;
							}
							stl_tmp_x[turn_tmp_id] = turn_x; stl_tmp_y[turn_tmp_id] = turn_y;
						}
					}
				if (piece_turn_num > 0) matrix_.set(col_, row_, this->friend_value, args_...);
				return piece_turn_num;
			}


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			//DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const Index_Size w_{ end_x_ - this->start_x };
				const Index_Size h_{ end_y_ - this->start_y };
				if (h_ == 0) return 0;

				::std::unique_ptr< ::dtl::type::int_fast32[]> stl_tmp_x{ DTL_TYPE_NEW::dtl::type::int_fast32[w_] };
				if (!stl_tmp_x) return 0;
				::std::unique_ptr< ::dtl::type::int_fast32[]> stl_tmp_y{ DTL_TYPE_NEW::dtl::type::int_fast32[h_] };
				if (!stl_tmp_y) return 0;

				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						if (this->reversiPutPiece(matrix_, col, row, stl_tmp_x, stl_tmp_y, w_, h_, args_...)) return true;
				return false;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
