/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_VORONOI_DIAGRAM_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_VORONOI_DIAGRAM_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <new>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>
#include <Random/MersenneTwister32bit.hpp>
#include <Type/Forward.hpp>
#include <Type/NumericLimits.hpp>
#include <Type/SizeT.hpp>
#include <Type/SSizeT.hpp>
#include <Type/UniquePtr.hpp>

namespace dtl {
	inline namespace utility {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_, typename UniquePair_ = DTL_TYPE_UNIQUE_PTR<std::pair<dtl::type::ssize, dtl::type::ssize>[]>, typename UniqueInt_ = DTL_TYPE_UNIQUE_PTR<Matrix_Int_[]>>
		class VoronoiDiagram {
		private:


			///// エイリアス /////

			using Index_Size = dtl::type::size;
			


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			dtl::type::size draw_value{};

			using Point_Pair_ = std::pair<dtl::type::ssize, dtl::type::ssize>;

			//原点の場所と陸地を決定する
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(UniquePair_& point_, UniqueInt_& color_, const dtl::type::ssize w_, const dtl::type::ssize h_, Function_&& function_) const noexcept {
				for (dtl::type::size i{}, array_num{}; i < this->draw_value; ++i, ++array_num) {
					point_[array_num] = Point_Pair_(dtl::random::mt32bit.get<dtl::type::ssize>(w_), dtl::random::mt32bit.get<dtl::type::ssize>(h_));
					function_(point_[array_num], color_[array_num], static_cast<dtl::type::ssize>(start_x), static_cast<dtl::type::ssize>(start_x), w_, h_);
				}
			}

			//2点間の距離を返す
			DTL_VERSIONING_CPP14_CONSTEXPR
				dtl::type::ssize distanceSqrd(const Point_Pair_& point_, dtl::type::ssize x_, dtl::type::ssize y_) const noexcept {
				x_ -= point_.first;
				y_ -= point_.second;
				return x_ * x_ + y_ * y_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createSitesDistance(const UniquePair_& point_, dtl::type::size& ind, dtl::type::ssize& dist, dtl::type::ssize& ds, const dtl::type::ssize ww, const dtl::type::ssize hh) const noexcept {
				ind = (DTL_TYPE_NUMERIC_LIMITS<dtl::type::size>::max)();
				dist = (DTL_TYPE_NUMERIC_LIMITS<dtl::type::ssize>::max)();
				for (dtl::type::size it{}; it < this->draw_value; ++it) {
					if ((ds = distanceSqrd(point_[it], ww, hh)) >= dist) continue;
					dist = ds;
					ind = it;
				}
				return (ind != (DTL_TYPE_NUMERIC_LIMITS<dtl::type::size>::max)());
			}

			//図形を描画
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSites(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const dtl::type::size w_, const dtl::type::size h_) const noexcept {
				dtl::type::ssize ds{}, dist{};
				for (dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (dtl::type::size ww{}; ww < w_; ++ww)
						if(createSitesDistance(point_, ind, dist, ds, static_cast<dtl::type::ssize>(ww), static_cast<dtl::type::ssize>(hh)))
							matrix_[hh][ww] = color_[ind];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSitesLayer(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const Index_Size layer_, const dtl::type::size w_, const dtl::type::size h_) const noexcept {
				dtl::type::ssize ds{}, dist{};
				for (dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (dtl::type::size ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<dtl::type::ssize>(ww), static_cast<dtl::type::ssize>(hh)))
							matrix_[hh][ww][layer_] = color_[ind];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSitesArray(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const Index_Size max_x_, const dtl::type::size w_, const dtl::type::size h_) const noexcept {
				dtl::type::ssize ds{}, dist{};
				for (dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (dtl::type::size ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<dtl::type::ssize>(ww), static_cast<dtl::type::ssize>(hh)))
							matrix_[hh * max_x_ + ww] = color_[ind];
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			inline void substitutionSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ new(std::nothrow) Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ new(std::nothrow) Matrix_Int_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<dtl::type::ssize>(end_x_), static_cast<dtl::type::ssize>(end_y_), function_);
				createSites(point, color, matrix_, end_x_, end_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void substitutionArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ new(std::nothrow) Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ new(std::nothrow) Matrix_Int_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<dtl::type::ssize>(end_x_), static_cast<dtl::type::ssize>(end_y_), function_);
				createSitesArray(point, color, matrix_, max_x_, end_x_, end_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void substitutionLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ new(std::nothrow) Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ new(std::nothrow) Matrix_Int_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<dtl::type::ssize>(end_x_), static_cast<dtl::type::ssize>(end_y_), function_);
				createSitesLayer(point, color, matrix_, layer_, end_x_, end_y_);
			}


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				this->substitutionSTL(matrix_, end_x_, end_y_, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				this->substitutionLayer(matrix_, layer_, end_x_, end_y_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_&& ... args_) const noexcept {
				this->substitutionArray(matrix_, end_x_, end_y_, max_x_, args_...);
				return true;
			}

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr dtl::type::size getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			constexpr bool draw(Matrix_ && matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawLayerNormal(DTL_TYPE_FORWARD<Matrix_>(matrix_), layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_, typename Function_>
			constexpr bool drawArray(Matrix_ && matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

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


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//塗り値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearValue() noexcept {
				this->draw_value = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setValue(const dtl::type::size draw_value_) noexcept {
				this->draw_value = draw_value_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr VoronoiDiagram() noexcept = default;
			constexpr explicit VoronoiDiagram(const dtl::type::size draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit VoronoiDiagram(const dtl::base::MatrixRange& matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit VoronoiDiagram(const dtl::base::MatrixRange& matrix_range_, const dtl::type::size draw_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr explicit VoronoiDiagram(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr explicit VoronoiDiagram(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const dtl::type::size draw_value_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library