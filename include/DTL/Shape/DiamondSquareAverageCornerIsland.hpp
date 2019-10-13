/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_DIAMOND_SQARE_AVERAGE_CORNER_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_DIAMOND_SQARE_AVERAGE_CORNER_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::DiamondSquareAverageCornerIsland-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBaseFractal.hpp>
#include <DTL/Shape/DiamondSquareAverage.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/Min.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] DiamondSquareAverageCornerIslandとは
			"Matrixの描画範囲にダイヤモンドスクエア法に従って描画値を設置する" 機能を持つクラスである。
#######################################################################################*/
		template<typename Matrix_Var_>
		class DiamondSquareAverageCornerIsland : public ::dtl::range::RectBaseFractal<DiamondSquareAverageCornerIsland<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseFractal<DiamondSquareAverageCornerIsland, Matrix_Var_>;


			///// サイズ取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
				DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size getMatrixSize(const Index_Size matrix_size) const noexcept {
				::dtl::type::size map_size{ 2 };
				while (true) {
					if ((map_size + 1) > matrix_size) return map_size >>= 1;
					map_size <<= 1;
				}
				return 0;
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignSTL(Matrix_ && matrix_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[this->start_y][this->start_x] = this->min_value + this->altitude;
				matrix_[this->start_y][this->start_x + map_size_] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x + map_size_] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				createDiamondSquareAverageSTL<Matrix_Var_, Matrix_>(matrix_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[this->start_y][this->start_x], matrix_[this->start_y + map_size_][this->start_x], matrix_[this->start_y][this->start_x + map_size_], matrix_[this->start_y + map_size_][this->start_x + map_size_], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_, Function_ && function_) const noexcept {
				matrix_[(this->start_y) * max_x_ + (this->start_x)] = this->min_value + this->altitude;
				matrix_[(this->start_y) * max_x_ + (this->start_x + map_size_)] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x)] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x + map_size_)] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				createDiamondSquareAverageArray<Matrix_Var_, Matrix_>(matrix_, max_x_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[(this->start_y) * max_x_ + (this->start_x)], matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x)], matrix_[(this->start_y) * max_x_ + (this->start_x + map_size_)], matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x + map_size_)], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[this->start_y][this->start_x][layer_] = this->min_value + this->altitude;
				matrix_[this->start_y][this->start_x + map_size_][layer_] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x][layer_] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x + map_size_][layer_] = this->min_value + DTL_RANDOM_ENGINE.get<Matrix_Var_>(this->altitude);
				createDiamondSquareAverageLayer<Matrix_Var_, Matrix_>(matrix_, layer_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[this->start_y][this->start_x][layer_], matrix_[this->start_y + map_size_][this->start_x][layer_], matrix_[this->start_y][this->start_x + map_size_][layer_], matrix_[this->start_y + map_size_][this->start_x + map_size_][layer_], this->min_value + this->altitude, this->add_altitude, function_);
			}

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignSTL(Matrix_ && matrix_, const Index_Size map_size_) const noexcept {
				this->assignSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), map_size_, [](const Matrix_Var_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_) const noexcept {
				this->assignArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), max_x_, map_size_, [](const Matrix_Var_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				inline void assignLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_) const noexcept {
				this->assignLayer(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, map_size_, [](const Matrix_Var_ & value_) {return value_ / 2; });
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawSTL(Matrix_ && matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), getMatrixSize((end_y_ > matrix_[0].size()) ? matrix_[0].size() : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawWidthSTL(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), getMatrixSize((end_y_ > DTL_TYPE_MIN(matrix_[0].size(), end_x_)) ? DTL_TYPE_MIN(matrix_[0].size(), end_x_) : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignLayer(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > matrix_[0].size()) ? matrix_[0].size() : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignLayer(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > DTL_TYPE_MIN(matrix_[0].size(), end_x_)) ? DTL_TYPE_MIN(matrix_[0].size(), end_x_) : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignLayer(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->assignArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), max_x_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

		public:


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndY(matrix_.size())) : this->drawWidthSTL(matrix_, this->start_x + this->width, this->calcEndY(matrix_.size()));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndY(matrix_.size()), function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, this->calcEndY(matrix_.size()), function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, this->calcEndY(matrix_.size())) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, this->calcEndY(matrix_.size()));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, this->calcEndY(matrix_.size()), function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, this->calcEndY(matrix_.size()), function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, this->calcEndX(max_x_), this->calcEndY(max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, this->calcEndX(max_x_), this->calcEndY(max_y_), function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), this->calcEndX(max_x_), this->calcEndY(max_y_), max_x_, function_);
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}

			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};

	} //namespace
}

#endif //Included Dungeon Template Library
