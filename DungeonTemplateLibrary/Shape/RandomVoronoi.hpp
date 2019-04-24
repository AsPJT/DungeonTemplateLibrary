/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RANDOM_VORONOI
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_RANDOM_VORONOI

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::RandomVoronoi-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Utility/VoronoiDiagram.hpp>
#include <Random/MersenneTwister32bit.hpp>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class RandomVoronoi {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// メンバ変数 /////

			dtl::utility::VoronoiDiagram<Matrix_Int_> voronoiDiagram{};
			double probability_value{ 0.5 };
			Matrix_Int_ true_color{};
			Matrix_Int_ false_color{};

		public:


			///// 情報取得 /////

#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getPointX() const noexcept {
				return this->voronoiDiagram.getPointX();
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getPointY() const noexcept {
				return this->voronoiDiagram.getPointY();
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getWidth() const noexcept {
				return this->voronoiDiagram.getWidth();
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr Index_Size getHeight() const noexcept {
				return this->voronoiDiagram.getHeight();
			}
#if defined(_MSVC_LANG) //C++17 use nodiscard
#if (_MSVC_LANG >= 201703L)
			[[nodiscard]]
#endif
#elif defined(__cplusplus)
#if (__cplusplus >= 201703L)
			[[nodiscard]]
#endif
#endif
			constexpr std::size_t getValue() const noexcept {
				return this->voronoiDiagram.getValue();
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_) const noexcept {
				return this->voronoiDiagram.draw(matrix_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>&, Matrix_Int_ & color_) {
						if (dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>&, Matrix_Int_ & color_) {
						if (dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>&, Matrix_Int_ & color_) {
						if (dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>&, Matrix_Int_ & color_) {
						if (dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.drawArray(matrix_, max_x_, max_y_,
					[this](const std::pair<std::int_fast32_t, std::int_fast32_t>&, Matrix_Int_ & color_) {
						if (dtl::random::mt32bit.probability(this->probability_value)) color_ = this->true_color;
						else color_ = this->false_color;
					});
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr auto clearPointX() noexcept {
				this->voronoiDiagram.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr auto clearPointY() noexcept {
				this->voronoiDiagram.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr auto clearWidth() noexcept {
				this->voronoiDiagram.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr auto clearHeight() noexcept {
				this->voronoiDiagram.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			constexpr auto clearValue() noexcept {
				this->voronoiDiagram.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr auto clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr auto clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr auto clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			constexpr auto setPointX(const Index_Size point_x_) noexcept {
				this->voronoiDiagram.setPointX(point_x_);
				return *this;
			}
			constexpr auto setPointY(const Index_Size point_y_) noexcept {
				this->voronoiDiagram.setPointY(point_y_);
				return *this;
			}
			constexpr auto setWidth(const Index_Size width_) noexcept {
				this->voronoiDiagram.setWidth(width_);
				return *this;
			}
			constexpr auto setHeight(const Index_Size height_) noexcept {
				this->voronoiDiagram.setHeight(height_);
				return *this;
			}
			constexpr auto setValue(const std::size_t draw_value_) noexcept {
				this->voronoiDiagram.setValue(draw_value_);
				return *this;
			}
			constexpr auto setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->voronoiDiagram.setRange(matrix_range_);
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			constexpr auto setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			constexpr auto setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr RandomVoronoi() noexcept = default;
			constexpr explicit RandomVoronoi(const std::size_t draw_value_) noexcept
				:voronoiDiagram(draw_value_) {}
			constexpr explicit RandomVoronoi(const std::size_t draw_value_, const double probability_value_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_) {}
			constexpr explicit RandomVoronoi(const std::size_t draw_value_, const double probability_value_, const Matrix_Int_& true_color_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_), true_color(true_color_) {}
			constexpr explicit RandomVoronoi(const std::size_t draw_value_, const double probability_value_, const Matrix_Int_& true_color_, const Matrix_Int_& false_color_) noexcept
				:voronoiDiagram(draw_value_), probability_value(probability_value_), true_color(true_color_), false_color(false_color_) {}

			constexpr explicit RandomVoronoi(const dtl::base::MatrixRange& matrix_range_) noexcept
				:voronoiDiagram(matrix_range_) {}
			constexpr explicit RandomVoronoi(const dtl::base::MatrixRange& matrix_range_, const std::size_t draw_value_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_) {}
			constexpr explicit RandomVoronoi(const dtl::base::MatrixRange& matrix_range_, const std::size_t draw_value_, const double probability_value_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_) {}
			constexpr explicit RandomVoronoi(const dtl::base::MatrixRange& matrix_range_, const std::size_t draw_value_, const double probability_value_, const Matrix_Int_& true_color_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_), true_color(true_color_) {}
			constexpr explicit RandomVoronoi(const dtl::base::MatrixRange& matrix_range_, const std::size_t draw_value_, const double probability_value_, const Matrix_Int_& true_color_, const Matrix_Int_& false_color_) noexcept
				:voronoiDiagram(matrix_range_, draw_value_), probability_value(probability_value_), true_color(true_color_), false_color(false_color_) {}
		};
	}
}

#endif //Included Dungeon Template Library