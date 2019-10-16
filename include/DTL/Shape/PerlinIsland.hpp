/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_PERLIN_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_PERLIN_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PerlinIsland-(形状クラス)/
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PerlinIsland-in-Unreal-Engine-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/IntX.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBasePerlin.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>
#include <DTL/Utility/PerlinNoise.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] PerlinIslandとは "Matrixの描画範囲にパーリンノイズを使用して地形を生成する" 機能を持つクラスである。
	[Summary] PerlinIsland is a class that generates terrain using perlin noise in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM>
		class PerlinIsland : public ::dtl::range::RectBasePerlin<PerlinIsland<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<PerlinIsland<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBasePerlin<PerlinIsland, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<PerlinIsland, Matrix_Var_, Random_Engine_>;

			friend DrawBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			//DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const ::dtl::utility::PerlinNoise<double> perlin(static_cast<::dtl::type::uint_fast32>(random_engine_.get()));
				const double frequency_y{ (end_y_ - this->start_y) / this->frequency };

				for (Index_Size row{ this->start_y }; row < end_y_; ++row) {
					const Index_Size end_x_{ this->calcEndX(matrix_.getX(row)) };
					const double frequency_x{ (end_x_ - this->start_x) / this->frequency };
					for (::dtl::type::size col{ this->start_x }; col < end_x_; ++col)
						matrix_.set(col, row,
							this->min_height + static_cast<Matrix_Var_>((this->max_height - this->min_height) * perlin.octaveNoise(this->octaves, col / frequency_x, row / frequency_y)), args_...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const ::dtl::utility::PerlinNoise<double> perlin(static_cast<::dtl::type::uint_fast32>(random_engine_.get()));
				const double frequency_x{ (end_x_ - this->start_x) / this->frequency };
				const double frequency_y{ (end_y_ - this->start_y) / this->frequency };

				for (::dtl::type::size row{ this->start_y }; row < end_y_; ++row)
					for (::dtl::type::size col{ this->start_x }; col < end_x_; ++col)
						matrix_.set(col, row,
							this->min_height + static_cast<Matrix_Var_>((this->max_height - this->min_height) * perlin.octaveNoise(this->octaves, col / frequency_x, row / frequency_y)), args_...);
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
