/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_DIAMOND_SQARE_AVERAGE_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_DIAMOND_SQARE_AVERAGE_ISLAND

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>
#include <algorithm>
#include <Random/MersenneTwister32bit.hpp>
#include <Shape/DiamondSquareAverage.hpp>

namespace dtl {
	inline namespace shape {


		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class DiamondSquareAverageIsland {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};
			Matrix_Int_ min_value{};
			Matrix_Int_ altitude{ 10 };
			Matrix_Int_ add_altitude{};


			///// サイズ取得 /////

			[[nodiscard]] constexpr std::size_t getMatrixSize(const Index_Size matrix_size) const noexcept {
				std::size_t map_size{ 2 };
				while (true) {
					if ((map_size + 1) > matrix_size) return map_size >>= 1;
					map_size <<= 1;
				}
				return 0;
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[point_y][point_x] = matrix_[point_y + map_size_ / 2][point_x] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y][point_x + map_size_] = matrix_[point_y][point_x + map_size_ / 2] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_][point_x] = matrix_[point_y + map_size_][point_x + map_size_ / 2] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_][point_x + map_size_] = matrix_[point_y + map_size_][point_x + map_size_ / 2] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2] = min_value + altitude;
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, point_x, point_y, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[point_y][point_x], matrix_[point_y + map_size_ / 2][point_x], matrix_[point_y][point_x + map_size_ / 2], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, point_x, point_y, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[point_y + map_size_ / 2][point_x], matrix_[point_y + map_size_][point_x], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2], matrix_[point_y + map_size_][point_x + map_size_ / 2], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, point_x, point_y, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[point_y][point_x + map_size_ / 2], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2], matrix_[point_y][point_x + map_size_], matrix_[point_y + map_size_ / 2][point_x + map_size_], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix_>(matrix_, point_x, point_y, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2], matrix_[point_y + map_size_][point_x + map_size_ / 2], matrix_[point_y + map_size_ / 2][point_x + map_size_], matrix_[point_y + map_size_][point_x + map_size_], min_value + altitude, add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_, Function_ && function_) const noexcept {
				matrix_[(point_y)* max_x_ + (point_x)] = matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x)] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[(point_y)* max_x_ + (point_x + map_size_)] = matrix_[(point_y)* max_x_ + (point_x + map_size_ / 2)] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[(point_y + map_size_) * max_x_ + (point_x)] = matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_ / 2)] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_)] = matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_ / 2)] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_ / 2)] = min_value + altitude;
				createDiamondSquareAverageArray<Matrix_Int_, Matrix_>(matrix_, max_x_, point_x, point_y, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[(point_y)* max_x_ + (point_x)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x)], matrix_[(point_y)* max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_ / 2)], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageArray<Matrix_Int_, Matrix_>(matrix_, max_x_, point_x, point_y, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x)], matrix_[(point_y + map_size_) * max_x_ + (point_x)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_ / 2)], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageArray<Matrix_Int_, Matrix_>(matrix_, max_x_, point_x, point_y, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[(point_y)* max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y)* max_x_ + (point_x + map_size_)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_)], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageArray<Matrix_Int_, Matrix_>(matrix_, max_x_, point_x, point_y, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_ / 2)], matrix_[(point_y + map_size_ / 2) * max_x_ + (point_x + map_size_)], matrix_[(point_y + map_size_) * max_x_ + (point_x + map_size_)], min_value + altitude, add_altitude, function_);
			}
			template<typename Matrix_, typename Function_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_, Function_ && function_) const noexcept {
				matrix_[point_y][point_x][layer_] = matrix_[point_y + map_size_ / 2][point_x][layer_] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y][point_x + map_size_][layer_] = matrix_[point_y][point_x + map_size_ / 2][layer_] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_][point_x][layer_] = matrix_[point_y + map_size_][point_x + map_size_ / 2][layer_] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_][point_x + map_size_][layer_] = matrix_[point_y + map_size_][point_x + map_size_ / 2][layer_] = dtl::random::mt32bit.get<Matrix_Int_>(min_value, min_value + altitude / 2);
				matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2][layer_] = min_value + altitude;
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix_>(matrix_, layer_, point_x, point_y, map_size_ / 4, map_size_ / 4, map_size_ / 4, matrix_[point_y][point_x][layer_], matrix_[point_y + map_size_ / 2][point_x][layer_], matrix_[point_y][point_x + map_size_ / 2][layer_], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2][layer_], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix_>(matrix_, layer_, point_x, point_y, map_size_ / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[point_y + map_size_ / 2][point_x][layer_], matrix_[point_y + map_size_][point_x][layer_], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2][layer_], matrix_[point_y + map_size_][point_x + map_size_ / 2][layer_], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix_>(matrix_, layer_, point_x, point_y, map_size_ * 3 / 4, map_size_ / 4, map_size_ / 4, matrix_[point_y][point_x + map_size_ / 2][layer_], matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2][layer_], matrix_[point_y][point_x + map_size_][layer_], matrix_[point_y + map_size_ / 2][point_x + map_size_][layer_], min_value + altitude, add_altitude, function_);
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix_>(matrix_, layer_, point_x, point_y, map_size_ * 3 / 4, map_size_ * 3 / 4, map_size_ / 4, matrix_[point_y + map_size_ / 2][point_x + map_size_ / 2][layer_], matrix_[point_y + map_size_][point_x + map_size_ / 2][layer_], matrix_[point_y + map_size_ / 2][point_x + map_size_][layer_], matrix_[point_y + map_size_][point_x + map_size_][layer_], min_value + altitude, add_altitude, function_);
			}

			template<typename Matrix_>
			constexpr inline void substitutionSTL(Matrix_ && matrix_, const Index_Size map_size_) const noexcept {
				substitutionSTL(std::forward<Matrix_>(matrix_), map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			constexpr inline void substitutionArray(Matrix_ && matrix_, const Index_Size map_size_, const Index_Size max_x_) const noexcept {
				substitutionArray(std::forward<Matrix_>(matrix_), max_x_, map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			template<typename Matrix_>
			constexpr inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size map_size_) const noexcept {
				substitutionLayer(std::forward<Matrix_>(matrix_), layer_, map_size_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawSTL(Matrix_ && matrix_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((point_y_ > matrix_[0].size()) ? matrix_[0].size() : point_y_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawWidthSTL(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((point_y_ > (std::min)(matrix_[0].size(), point_x_)) ? (std::min)(matrix_[0].size(), point_x_) : point_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//LayerSTL
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((point_y_ > matrix_[0].size()) ? matrix_[0].size() : point_y_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerWidthSTL(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((point_y_ > (std::min)(matrix_[0].size(), point_x_)) ? (std::min)(matrix_[0].size(), point_x_) : point_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionSTL(std::forward<Matrix_>(matrix_), getMatrixSize((point_y_ > point_x_) ? point_x_ : point_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionLayer(std::forward<Matrix_>(matrix_), layer_, getMatrixSize((point_y_ > point_x_) ? point_x_ : point_y_), std::forward<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (altitude < 2) return false;
				this->substitutionArray(std::forward<Matrix_>(matrix_), getMatrixSize((point_y_ > point_x_) ? point_x_ : point_y_), max_x_, std::forward<Args_>(args_)...);
				return true;
			}

		public:


			///// 情報取得 /////

			[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
				return this->point_x;
			}
			[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
				return this->point_y;
			}
			[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			[[nodiscard]] constexpr Matrix_Int_ getMinValue() const noexcept {
				return this->min_value;
			}
			[[nodiscard]] constexpr Matrix_Int_ getMaxValue() const noexcept {
				return this->max_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_) const noexcept {
				return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return (width == 0) ? this->drawSTL(std::forward<Matrix_>(matrix_), (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawWidthSTL(matrix_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return (width == 0) ? this->drawLayerSTL(std::forward<Matrix_>(matrix_), layer_, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_) : this->drawLayerWidthSTL(matrix_, layer_, point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// コンストラクタ /////

			constexpr DiamondSquareAverageIsland() noexcept = default;
			constexpr explicit DiamondSquareAverageIsland(const Matrix_Int_ & min_value_) noexcept
				:min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				min_value(min_value_) {}
			constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit DiamondSquareAverageIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
		};

	} //namespace
}

#endif //Included Dungeon Template Library