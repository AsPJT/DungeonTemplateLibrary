/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_VORONOI_DIAGRAM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_VORONOI_DIAGRAM

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <memory>
#include <new>
#include <Random/MersenneTwister32bit.hpp>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace utility {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class VoronoiDiagram {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;


			///// メンバ変数 /////

			Index_Size point_x{};
			Index_Size point_y{};
			Index_Size width{};
			Index_Size height{};
			std::size_t draw_value{};

			using Point_Pair_ = std::pair<std::int_fast32_t, std::int_fast32_t>;

			//原点の場所と陸地を決定する
			template<typename Function_>
			constexpr void createPoint(std::unique_ptr<Point_Pair_[]>& point_, std::unique_ptr<Matrix_Int_[]>& color_, const std::int_fast32_t w_, const std::int_fast32_t h_, Function_&& function_) const noexcept {
				const Matrix_Int_ land_{ 1 };
				const Matrix_Int_ sea_{};
				for (std::size_t i{}, array_num{}; i < draw_value; ++i, ++array_num) {
					point_[array_num] = Point_Pair_(dtl::random::mt32bit.get<std::int_fast32_t>(w_), dtl::random::mt32bit.get<std::int_fast32_t>(h_));
					function_(point_[array_num], color_[array_num]);
				}
			}

			//2点間の距離を返す
			constexpr std::int_fast32_t distanceSqrd(const Point_Pair_& point_, std::int_fast32_t x_, std::int_fast32_t y_) const noexcept {
				x_ -= point_.first;
				y_ -= point_.second;
				return x_ * x_ + y_ * y_;
			}

			constexpr bool createSitesDistance(const std::unique_ptr<Point_Pair_[]>& point_, std::size_t& ind, std::int_fast32_t& dist, std::int_fast32_t& ds, const std::int_fast32_t ww, const std::int_fast32_t hh) const noexcept {
				ind = (std::numeric_limits<std::size_t>::max)();
				dist = (std::numeric_limits<std::int_fast32_t>::max)();
				for (std::size_t it{}; it < draw_value; ++it) {
					if ((ds = distanceSqrd(point_[it], ww, hh)) >= dist) continue;
					dist = ds;
					ind = it;
				}
				return (ind != (std::numeric_limits<std::size_t>::max)());
			}

			//図形を描画
			template<typename Matrix_>
			constexpr void createSites(const std::unique_ptr<Point_Pair_[]>& point_, const std::unique_ptr<Matrix_Int_[]>& color_, Matrix_& matrix_, const std::size_t w_, const std::size_t h_) const noexcept {
				std::int_fast32_t ds{}, dist{};
				for (std::size_t hh{}, ind{}; hh < h_; ++hh)
					for (std::size_t ww{}; ww < w_; ++ww)
						if(createSitesDistance(point_, ind, dist, ds, static_cast<std::int_fast32_t>(ww), static_cast<std::int_fast32_t>(hh)))
							matrix_[hh][ww] = color_[ind];
			}
			template<typename Matrix_>
			constexpr void createSitesLayer(const std::unique_ptr<Point_Pair_[]>& point_, const std::unique_ptr<Matrix_Int_[]>& color_, Matrix_& matrix_, const Index_Size layer_, const std::size_t w_, const std::size_t h_) const noexcept {
				std::int_fast32_t ds{}, dist{};
				for (std::size_t hh{}, ind{}; hh < h_; ++hh)
					for (std::size_t ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<std::int_fast32_t>(ww), static_cast<std::int_fast32_t>(hh)))
							matrix_[hh][ww] = color_[ind];
			}
			template<typename Matrix_>
			constexpr void createSitesArray(const std::unique_ptr<Point_Pair_[]>& point_, const std::unique_ptr<Matrix_Int_[]>& color_, Matrix_& matrix_, const Index_Size max_x_, const std::size_t w_, const std::size_t h_) const noexcept {
				std::int_fast32_t ds{}, dist{};
				for (std::size_t hh{}, ind{}; hh < h_; ++hh)
					for (std::size_t ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<std::int_fast32_t>(ww), static_cast<std::int_fast32_t>(hh)))
							matrix_[hh][ww] = color_[ind];
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			inline void substitutionSTL(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				std::unique_ptr<Point_Pair_[]> point{ new(std::nothrow) Point_Pair_[draw_value] };
				if (!point) return;
				std::unique_ptr<Matrix_Int_[]> color{ new(std::nothrow) Matrix_Int_[draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<std::int_fast32_t>(point_x_), static_cast<std::int_fast32_t>(point_y_), function_);
				createSites(point, color, matrix_, point_x_, point_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void substitutionArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				std::unique_ptr<Point_Pair_[]> point{ new(std::nothrow) Point_Pair_[draw_value] };
				if (!point) return;
				std::unique_ptr<Matrix_Int_[]> color{ new(std::nothrow) Matrix_Int_[draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<std::int_fast32_t>(point_x_), static_cast<std::int_fast32_t>(point_y_), function_);
				createSitesArray(point, color, matrix_, max_x_, point_x_, point_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Function_ && function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				std::unique_ptr<Point_Pair_[]> point{ new(std::nothrow) Point_Pair_[draw_value] };
				if (!point) return;
				std::unique_ptr<Matrix_Int_[]> color{ new(std::nothrow) Matrix_Int_[draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<std::int_fast32_t>(point_x_), static_cast<std::int_fast32_t>(point_y_), function_);
				createSitesLayer(point, color, matrix_, layer_, point_x_, point_y_);
			}


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawNormal(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, Args_&& ... args_) const noexcept {
				this->substitutionSTL(matrix_, point_x_, point_y_, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size point_x_, const Index_Size point_y_, Args_&& ... args_) const noexcept {
				this->substitutionLayer(matrix_, layer_, point_x_, point_y_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_&& matrix_, const Index_Size point_x_, const Index_Size point_y_, const Index_Size max_x_, Args_&& ... args_) const noexcept {
				this->substitutionArray(matrix_, point_x_, point_y_, max_x_, args_...);
				return true;
			}

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
				return this->point_x;
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
				return this->point_y;
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
				return this->width;
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
				return this->height;
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
				return this->draw_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : point_x + width, (height == 0 || point_y + height >= matrix_.size()) ? matrix_.size() : point_y + height, function_);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(std::forward<Matrix_>(matrix_), layer_, (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, function_);
			}

			//Array
			template<typename Matrix_, typename Function_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(std::forward<Matrix_>(matrix_), (width == 0 || point_x + width >= max_x_) ? max_x_ : point_x + width, (height == 0 || point_y + height >= max_y_) ? max_y_ : point_y + height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr VoronoiDiagram& clearPointX() noexcept {
				this->point_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr VoronoiDiagram& clearPointY() noexcept {
				this->point_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr VoronoiDiagram& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr VoronoiDiagram& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//塗り値を初期値に戻す
			constexpr VoronoiDiagram& clearValue() noexcept {
				this->draw_value = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr VoronoiDiagram& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr VoronoiDiagram& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr VoronoiDiagram& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			constexpr VoronoiDiagram& setPointX(const Index_Size point_x_) noexcept {
				this->point_x = point_x_;
				return *this;
			}
			constexpr VoronoiDiagram& setPointY(const Index_Size point_y_) noexcept {
				this->point_y = point_y_;
				return *this;
			}
			constexpr VoronoiDiagram& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			constexpr VoronoiDiagram& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			constexpr VoronoiDiagram& setValue(const std::size_t draw_value_) noexcept {
				this->draw_value = draw_value_;
				return *this;
			}
			constexpr VoronoiDiagram& setPoint(const Index_Size point_) noexcept {
				this->point_x = point_;
				this->point_y = point_;
				return *this;
			}
			constexpr VoronoiDiagram& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				return *this;
			}
			constexpr VoronoiDiagram& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			constexpr VoronoiDiagram& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->point_x = point_x_;
				this->point_y = point_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			constexpr VoronoiDiagram& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->point_x = matrix_range_.x;
				this->point_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr VoronoiDiagram() noexcept = default;
			constexpr explicit VoronoiDiagram(const std::size_t draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit VoronoiDiagram(const dtl::base::MatrixRange& matrix_range_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit VoronoiDiagram(const dtl::base::MatrixRange& matrix_range_, const std::size_t draw_value_) noexcept
				:point_x(matrix_range_.x), point_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr explicit VoronoiDiagram(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_) {}
			constexpr explicit VoronoiDiagram(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const std::size_t draw_value_) noexcept
				:point_x(point_x_), point_y(point_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library