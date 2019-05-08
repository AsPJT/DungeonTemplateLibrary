/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_DIAMOND_SQARE_AVERAGE_CORNER_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_DIAMOND_SQARE_AVERAGE_CORNER_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::DiamondSquareAverageCornerIsland-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Random/MersenneTwister32bit.hpp>
#include <Shape/DiamondSquareAverage.hpp>

namespace dtl {
	inline namespace shape {


		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class DiamondSquareAverageCornerIsland {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			Matrix_Int_ min_value{};
			Matrix_Int_ altitude{};
			Matrix_Int_ add_altitude{};


			///// サイズ取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				std::size_t getMatrixSize(const Index_Size matrix_size) const noexcept {
				std::size_t map_size{ 2 };
				while (true) {
					if ((map_size + 1) > matrix_size) return map_size >>= 1;
					map_size <<= 1;
				}
				return 0;
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_ && matrix_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[this->start_y][this->start_x] = this->min_value + this->altitude;
				matrix_[this->start_y][this->start_x + map_size_] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x + map_size_] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[this->start_y][this->start_x], matrix_[this->start_y + map_size_][this->start_x], matrix_[this->start_y][this->start_x + map_size_], matrix_[this->start_y + map_size_][this->start_x + map_size_], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_, Function_ && function_) const noexcept {
				matrix_[(this->start_y)* max_x_ + (this->start_x)] = this->min_value + this->altitude;
				matrix_[(this->start_y)* max_x_ + (this->start_x + map_size_)] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x)] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x + map_size_)] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				createDiamondSquareAverageArray<Matrix_Int_, Matrix_>(matrix_, max_x_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[(this->start_y)* max_x_ + (this->start_x)], matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x)], matrix_[(this->start_y)* max_x_ + (this->start_x + map_size_)], matrix_[(this->start_y + map_size_) * max_x_ + (this->start_x + map_size_)], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[this->start_y][this->start_x][layer_] = this->min_value + this->altitude;
				matrix_[this->start_y][this->start_x + map_size_][layer_] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x][layer_] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				matrix_[this->start_y + map_size_][this->start_x + map_size_][layer_] = this->min_value + dtl::random::mt32bit.get<Matrix_Int_>(this->altitude);
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix_>(matrix_, layer_, this->start_x, this->start_y, map_size_ / 2, map_size_ / 2, map_size_ / 2, matrix_[this->start_y][this->start_x][layer_], matrix_[this->start_y + map_size_][this->start_x][layer_], matrix_[this->start_y][this->start_x + map_size_][layer_], matrix_[this->start_y + map_size_][this->start_x + map_size_][layer_], this->min_value + this->altitude, this->add_altitude, function_);
			}

			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionSTL(Matrix_ && matrix_, const Index_Size map_size_) const noexcept {
				this->substitutionSTL(std::forward<Matrix_>(matrix_), map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_) const noexcept {
				this->substitutionArray(std::forward<Matrix_>(matrix_), max_x_, map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_) const noexcept {
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawSTL(Matrix_ && matrix_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((end_y_ > matrix_[0].size()) ? matrix_[0].size() : end_y_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawWidthSTL(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((end_y_ > (std::min)(matrix_[0].size(), end_x_)) ? (std::min)(matrix_[0].size(), end_x_) : end_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > matrix_[0].size()) ? matrix_[0].size() : end_y_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > (std::min)(matrix_[0].size(), end_x_)) ? (std::min)(matrix_[0].size(), end_x_) : end_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				this->substitutionArray(std::forward<Matrix_>(matrix_), getMatrixSize((end_y_ > end_x_) ? end_x_ : end_y_), max_x_, std::forward<Args_>(args_)...);
				return true;
			}

		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Matrix_Int_ getMinValue() const noexcept {
				return this->min_value;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Matrix_Int_ getAltitude() const noexcept {
				return this->altitude;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Matrix_Int_ getAddAltitude() const noexcept {
				return this->add_altitude;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawWidthSTL(matrix_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (this->width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_) : this->drawLayerWidthSTL(matrix_, layer_, this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// コンストラクタ /////

			constexpr DiamondSquareAverageCornerIsland() noexcept = default;
			constexpr explicit DiamondSquareAverageCornerIsland(const Matrix_Int_ & min_value_) noexcept
				:min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageCornerIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
		};

	} //namespace
}

#endif //Included Dungeon Template Library