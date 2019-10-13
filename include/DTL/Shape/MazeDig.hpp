/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_DIG_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_DIG_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::MazeDig-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBaseMaze.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		/*#######################################################################################
	[概要] MazeDigとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] MazeDig is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<::dtl::type::size[]>>
		class MazeDig : public ::dtl::range::RectBaseMaze<MazeDig<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<MazeDig<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseMaze<MazeDig, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<MazeDig, Matrix_Var_, Random_Engine_>;

			friend DrawBase_t;

			//穴掘り
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void mazeDig_Dig(Matrix_&& matrix_, Random_Engine_& random_engine_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, ::dtl::type::size x_, ::dtl::type::size y_, Args_&& ... args_) const noexcept {
				::dtl::type::ssize dx{}, dy{};
				for (::dtl::type::size random{ static_cast<::dtl::type::size>(random_engine_.get()) }, counter{}; counter < 4;) {
					switch ((random + counter) & 3) {
					case 0:dx = 0; dy = -2; break;
					case 1:dx = -2; dy = 0; break;
					case 2:dx = 0; dy = 2; break;
					case 3:dx = 2; dy = 0; break;
					default:dx = 0; dy = 0; break;
					}
					if (static_cast<::dtl::type::ssize>(x_ + dx) <= static_cast<::dtl::type::ssize>(this->start_x) ||
						static_cast<::dtl::type::ssize>(y_ + dy) <= static_cast<::dtl::type::ssize>(this->start_y) ||
						(x_ + dx) >= j_max || (y_ + dy) >= i_max || static_cast<Matrix_Var_>(matrix_.get(x_ + dx, y_ + dy)) == this->empty_value) {
						++counter;
					}
					else if (matrix_.get(x_ + dx, y_ + dy) == this->wall_value) {
						matrix_.set(x_ + (dx / 2), y_ + (dy / 2), this->empty_value, args_...);
						matrix_.set(x_ + dx, y_ + dy, this->empty_value, args_...);
						x_ += dx;
						y_ += dy;
						counter = 0;
						random = static_cast<::dtl::type::size>(random_engine_.get());
					}
				}
				return;
			}
			//迷路生成
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size mazeDig_CreateLoop(Matrix_&& matrix_, const ::dtl::type::size j_max, const ::dtl::type::size i_max, UniquePtr_& select_x, UniquePtr_& select_y) const noexcept {
				::dtl::type::size select_id{};
				for (::dtl::type::size i{ this->start_y + 1 }; i < i_max; i += 2)
					for (::dtl::type::size j{ this->start_x + 1 }; j < j_max; j += 2) {
						if (matrix_.get(j, i) != this->empty_value) continue;
						if ((i >= this->start_y + 2 && matrix_.get(j, i - 2) == this->wall_value) || (j >= this->start_x + 2 && matrix_.get(j - 2, i) == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
						else if ((j >= j_max - 1) && (i >= i_max - 1)) break;
						else if ((i + 2 < (i_max + 1) && matrix_.get(j, i + 2) == this->wall_value) || (j + 2 < (j_max + 1) && matrix_.get(j + 2, i) == this->wall_value)) {
							select_x[select_id] = j;
							select_y[select_id] = i;
							++select_id;
						}
					}
				return select_id;
			}


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
			bool drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				matrix_.set(this->start_x + 1, this->start_y + 1, this->empty_value, args_...);

				UniquePtr_ select_x{ DTL_TYPE_NEW ::dtl::type::size[(end_x_ - this->start_x) * (end_y_ - this->start_y)] };
				if (!select_x) return false;
				UniquePtr_ select_y{ DTL_TYPE_NEW ::dtl::type::size[(end_x_ - this->start_x) * (end_y_ - this->start_y)] };
				if (!select_y) return false;

				const ::dtl::type::size i_max{ ((((end_y_ - this->start_y) & 1) == 0) ? end_y_ - 2 : end_y_ - 1) };
				const ::dtl::type::size j_max{ ((((end_x_ - this->start_x) & 1) == 0) ? end_x_ - 2 : end_x_ - 1) };

				//座標を選ぶ
				for (::dtl::type::size select_id{};;) {
					select_id = this->mazeDig_CreateLoop(matrix_, j_max, i_max, select_x, select_y);
					if (select_id == 0) break;
					select_id = static_cast<::dtl::type::size>(random_engine_.get(select_id));
					this->mazeDig_Dig(matrix_, random_engine_, j_max, i_max, select_x[select_id], select_y[select_id], args_...);
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