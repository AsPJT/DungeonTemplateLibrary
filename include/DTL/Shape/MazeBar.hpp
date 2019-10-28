/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_BAR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_MAZE_BAR_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::MazeBar-(形状クラス)/
#######################################################################################*/

#include <array>

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBaseMaze.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		/*#######################################################################################
	[概要] MazeBarとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] MazeBar is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM>
		class MazeBar : public ::dtl::range::RectBaseMaze<MazeBar<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<MazeBar<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseMaze<MazeBar, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<MazeBar, Matrix_Var_, Random_Engine_>;

			friend DrawBase_t;


			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				if (end_x_ <= this->start_x || end_y_ <= this->start_y) return true;
				for (Index_Size col{ this->start_x }; col < end_x_; ++col) {
					matrix_.set(col, this->start_y, this->wall_value, args_...);
					if ((end_y_ - this->start_y) % 2 == 0) matrix_.set(col, end_y_ - 2, this->wall_value, args_...);
					matrix_.set(col, end_y_ - 1, this->wall_value, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					matrix_.set(this->start_x, row, this->wall_value, args_...);
					if ((end_x_ - this->start_x) % 2 == 0) matrix_.set(end_x_ - 2, row, this->wall_value, args_...);
					matrix_.set(end_x_ - 1, row, this->wall_value, args_...);
				}
				for (Index_Size row{ this->start_y }; row < end_y_; row += 2)
					for (Index_Size col{ this->start_x }; col < end_x_; col += 2)
						matrix_.set(col, row, this->wall_value, args_...);

				const Index_Size size_x{ end_x_ - this->start_x };
				const Index_Size size_y{ end_y_ - this->start_y };

				//4つのベクトルを用意しておく
				::std::array<::dtl::type::ssize, 4> dx{ { 1, 0, -1, 0 } };
				::std::array<::dtl::type::ssize, 4> dy{ { 0, 1, 0, -1 } };

				//乱数エンジンを構築 (Clang3.7以下で実行するために{}ではなく=で初期化する)
				auto&& random_range_0to3 = random_engine_.makeUniformDistribution(0, 3);
				auto&& random_range_0to2 = random_engine_.makeUniformDistribution(0, 2);
				auto&& re = random_engine_.getEngine();

				for (::dtl::type::size y{ 2 }; y < size_y - 2; y += 2)
					for (::dtl::type::size x{ 2 }; x < size_x - 2; x += 2)
						for (::dtl::type::size i{}; i < 4; ++i) {
							::dtl::type::size direction{ (y == 2) ? static_cast<::dtl::type::size>(random_range_0to3(re)) : static_cast<::dtl::type::size>(random_range_0to2(re)) };
							if (matrix_.get(this->start_x + x + dx[direction], this->start_y + y + dy[direction]) == this->empty_value) {
								matrix_.set(this->start_x + x + dx[direction], this->start_y + y + dy[direction], this->wall_value, args_...);
								break;
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