/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_FRACTAL_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_FRACTAL_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::FractalIsland-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <new>
#include <Random/MersenneTwister32bit.hpp>
#include <Shape/DiamondSquareAverage.hpp>
//#include <Deprecated/FractalIsland.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace shape {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_, std::size_t chunk_size = 16>
		class FractalIsland {
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


			///// 基本処理 /////

			//チャンク生成の呼び出し・実行
			template<typename Matrix2_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimple(Matrix2_&& matrix_, Function_&& function_) const noexcept {
				createDiamondSquareAverageSTL<Matrix_Int_, Matrix2_>(matrix_, 0, 0, chunk_size / 2, chunk_size / 2, chunk_size / 2, matrix_[0][0], matrix_[chunk_size][0], matrix_[0][chunk_size], matrix_[chunk_size][chunk_size], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix2_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimple(Matrix2_&& matrix_) const noexcept {
				createWorldMapSimple(matrix_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			//チャンク生成の呼び出し・実行
			template<typename Matrix2_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimpleLayer(Matrix2_&& matrix_, const Index_Size layer_, Function_&& function_) const noexcept {
				createDiamondSquareAverageLayer<Matrix_Int_, Matrix2_>(matrix_, layer_, 0, 0, chunk_size / 2, chunk_size / 2, chunk_size / 2, matrix_[0][0][layer_], matrix_[chunk_size][0][layer_], matrix_[0][chunk_size][layer_], matrix_[chunk_size][chunk_size][layer_], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix2_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimpleLayer(Matrix2_&& matrix_, const Index_Size layer_) const noexcept {
				createWorldMapSimpleLayer(matrix_, layer_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}
			//チャンク生成の呼び出し・実行
			template<typename Matrix2_, typename Function_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimpleArray(Matrix2_&& matrix_, const Index_Size max_x_, Function_&& function_) const noexcept {
				createDiamondSquareAverageArray<Matrix_Int_, Matrix2_>(matrix_, max_x_, 0, 0, chunk_size / 2, chunk_size / 2, chunk_size / 2, matrix_[0], matrix_[chunk_size * max_x_], matrix_[chunk_size], matrix_[chunk_size * max_x_ + chunk_size], this->min_value + this->altitude, this->add_altitude, function_);
			}
			template<typename Matrix2_>
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				void createWorldMapSimpleArray(Matrix2_ && matrix_, const Index_Size max_x_) const noexcept {
				createWorldMapSimpleArray(matrix_, max_x_, [](const Matrix_Int_ & value_) {return value_ / 2; });
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			bool drawNormal(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				std::array<std::array<Matrix_Int_, chunk_size + 1>, chunk_size + 1> chunk_matrix{ {} };
				const std::size_t chunk_x{ ((end_x_ - this->start_x) / chunk_size) };
				const std::size_t chunk_y{ ((end_y_ - this->start_y) / chunk_size) };

				std::unique_ptr<std::int_fast32_t[]> rand_up{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_up) return false;
				std::unique_ptr<std::int_fast32_t[]> rand_down{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_down) return false;

				for (std::size_t col{}; col <= chunk_x; ++col)
					rand_up[col] = 0;

				for (std::size_t row{}; row < chunk_y; ++row) {

					if ((row + 1) == chunk_y)
						for (std::size_t col{}; col <= chunk_x; ++col)
							rand_down[col] = 0;
					else {
						for (std::size_t col{ 1 }; col < chunk_x; ++col)
							rand_down[col] = dtl::random::mt32bit.get<std::int_fast32_t>(this->altitude);
						rand_down[0] = 0;
						rand_down[chunk_x] = rand_down[0];
					}
					for (std::size_t col{}; col < chunk_x; ++col) {
						//四角形の4点の高さを決定
						chunk_matrix[0][0] = static_cast<Matrix_Int_>(rand_up[col]);
						chunk_matrix[chunk_size][0] = static_cast<Matrix_Int_>(rand_down[col]);
						chunk_matrix[0][chunk_size] = static_cast<Matrix_Int_>(rand_up[col + 1]);
						chunk_matrix[chunk_size][chunk_size] = static_cast<Matrix_Int_>(rand_down[col + 1]);
						//チャンク生成
						createWorldMapSimple(chunk_matrix, args_...);
						//生成したチャンクをワールドマップにコピペ
						for (std::size_t row2{}; row2 < chunk_size; ++row2)
							for (std::size_t col2{}; col2 < chunk_size; ++col2)
								matrix_[this->start_y + row * chunk_size + row2][this->start_x + col * chunk_size + col2] = chunk_matrix[row2][col2];
					}
					for (std::size_t col{}; col <= chunk_x; ++col)
						rand_up[col] = rand_down[col];
				}
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			bool drawLayerNormal(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				std::array<std::array<Matrix_Int_, chunk_size + 1>, chunk_size + 1> chunk_matrix{ {} };
				const std::size_t chunk_x{ ((end_x_ - this->start_x) / chunk_size) };
				const std::size_t chunk_y{ ((end_y_ - this->start_y) / chunk_size) };

				std::unique_ptr<std::int_fast32_t[]> rand_up{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_up) return false;
				std::unique_ptr<std::int_fast32_t[]> rand_down{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_down) return false;

				for (std::size_t col{}; col <= chunk_x; ++col)
					rand_up[col] = 0;

				for (std::size_t row{}; row < chunk_y; ++row) {

					if ((row + 1) == chunk_y)
						for (std::size_t col{}; col <= chunk_x; ++col)
							rand_down[col] = 0;
					else {
						for (std::size_t col{ 1 }; col < chunk_x; ++col)
							rand_down[col] = dtl::random::mt32bit.get<std::int_fast32_t>(this->altitude);
						rand_down[0] = 0;
						rand_down[chunk_x] = rand_down[0];
					}
					for (std::size_t col{}; col < chunk_x; ++col) {
						//四角形の4点の高さを決定
						chunk_matrix[0][0] = static_cast<Matrix_Int_>(rand_up[col]);
						chunk_matrix[chunk_size][0] = static_cast<Matrix_Int_>(rand_down[col]);
						chunk_matrix[0][chunk_size] = static_cast<Matrix_Int_>(rand_up[col + 1]);
						chunk_matrix[chunk_size][chunk_size] = static_cast<Matrix_Int_>(rand_down[col + 1]);
						//チャンク生成
						createWorldMapSimple(chunk_matrix, args_...);
						//生成したチャンクをワールドマップにコピペ
						for (std::size_t row2{}; row2 < chunk_size; ++row2)
							for (std::size_t col2{}; col2 < chunk_size; ++col2)
								matrix_[this->start_y + row * chunk_size + row2][this->start_x + col * chunk_size + col2][layer_] = chunk_matrix[row2][col2];
					}
					for (std::size_t col{}; col <= chunk_x; ++col)
						rand_up[col] = rand_down[col];
				}
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			bool drawArray(Matrix_ && matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				if (this->altitude < 2) return false;
				std::array<std::array<Matrix_Int_, chunk_size + 1>, chunk_size + 1> chunk_matrix{ {} };
				const std::size_t chunk_x{ ((end_x_ - this->start_x) / chunk_size) };
				const std::size_t chunk_y{ ((end_y_ - this->start_y) / chunk_size) };

				std::unique_ptr<std::int_fast32_t[]> rand_up{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_up) return false;
				std::unique_ptr<std::int_fast32_t[]> rand_down{ new(std::nothrow) std::int_fast32_t[chunk_x + 1] };
				if (!rand_down) return false;

				for (std::size_t col{}; col <= chunk_x; ++col)
					rand_up[col] = 0;

				for (std::size_t row{}; row < chunk_y; ++row) {

					if ((row + 1) == chunk_y)
						for (std::size_t col{}; col <= chunk_x; ++col)
							rand_down[col] = 0;
					else {
						for (std::size_t col{ 1 }; col < chunk_x; ++col)
							rand_down[col] = dtl::random::mt32bit.get<std::int_fast32_t>(this->altitude);
						rand_down[0] = 0;
						rand_down[chunk_x] = rand_down[0];
					}
					for (std::size_t col{}; col < chunk_x; ++col) {
						//四角形の4点の高さを決定
						chunk_matrix[0][0] = static_cast<Matrix_Int_>(rand_up[col]);
						chunk_matrix[chunk_size][0] = static_cast<Matrix_Int_>(rand_down[col]);
						chunk_matrix[0][chunk_size] = static_cast<Matrix_Int_>(rand_up[col + 1]);
						chunk_matrix[chunk_size][chunk_size] = static_cast<Matrix_Int_>(rand_down[col + 1]);
						//チャンク生成
						createWorldMapSimple(chunk_matrix, args_...);
						//生成したチャンクをワールドマップにコピペ
						for (std::size_t row2{}; row2 < chunk_size; ++row2)
							for (std::size_t col2{}; col2 < chunk_size; ++col2)
								matrix_[(this->start_y + row * chunk_size + row2) * max_x_ + start_x + col * chunk_size + col2] = chunk_matrix[row2][col2];
					}
					for (std::size_t col{}; col <= chunk_x; ++col)
						rand_up[col] = rand_down[col];
				}
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
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height);
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
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
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
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

			constexpr FractalIsland() noexcept = default;
			constexpr explicit FractalIsland(const Matrix_Int_ & min_value_) noexcept
				:min_value(min_value_) {}
			constexpr explicit FractalIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:min_value(min_value_), altitude(altitude_) {}
			constexpr explicit FractalIsland(const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit FractalIsland(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit FractalIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_) {}
			constexpr explicit FractalIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit FractalIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
			constexpr explicit FractalIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit FractalIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_) {}
			constexpr explicit FractalIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_) {}
			constexpr explicit FractalIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & min_value_, const Matrix_Int_ & altitude_, const Matrix_Int_ & add_altitude_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				min_value(min_value_), altitude(altitude_), add_altitude(add_altitude_) {}
		};

	} //namespace
}

#endif //Included Dungeon Template Library