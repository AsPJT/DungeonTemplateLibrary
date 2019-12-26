/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_VORONOI_DIAGRAM_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_VORONOI_DIAGRAM_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/NumericLimits.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		//マスを指定した数値で埋める
		template<typename Matrix_Var_, typename UniquePair_ = DTL_TYPE_UNIQUE_PTR< ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>[]>, typename UniqueInt_ = DTL_TYPE_UNIQUE_PTR<Matrix_Var_[]>>
		class VoronoiDiagram {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			::dtl::type::size draw_value{};

			using Point_Pair_ = ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>;

			//原点の場所と陸地を決定する
			template<typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createPoint(UniquePair_& point_, UniqueInt_& color_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_, Function_&& function_) const noexcept {
				for (::dtl::type::size array_num{}; array_num < this->draw_value; ++array_num) {
					point_[array_num] = Point_Pair_(DTL_RANDOM_ENGINE.get<::dtl::type::ssize>(w_), DTL_RANDOM_ENGINE.get<::dtl::type::ssize>(h_));
					function_(point_[array_num], color_[array_num], static_cast<::dtl::type::ssize>(start_x), static_cast<::dtl::type::ssize>(start_y), w_, h_);
				}
			}

			//2点間の距離を返す
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::ssize distanceSqrd(const Point_Pair_& point_, ::dtl::type::ssize x_, ::dtl::type::ssize y_) const noexcept {
				x_ -= point_.first;
				y_ -= point_.second;
				return x_ * x_ + y_ * y_;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				bool createSitesDistance(const UniquePair_& point_, ::dtl::type::size& ind, ::dtl::type::ssize& dist, ::dtl::type::ssize& ds, const ::dtl::type::ssize ww, const ::dtl::type::ssize hh) const noexcept {
				ind = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)();
				dist = (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::ssize>::DTL_TYPE_NUMERIC_LIMITS_MAX)();
				for (::dtl::type::size it{}; it < this->draw_value; ++it) {
					if ((ds = this->distanceSqrd(point_[it], ww, hh)) >= dist) continue;
					dist = ds;
					ind = it;
				}
				return (ind != (DTL_TYPE_NUMERIC_LIMITS<::dtl::type::size>::DTL_TYPE_NUMERIC_LIMITS_MAX)());
			}

			//図形を描画
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSites(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const ::dtl::type::size w_, const ::dtl::type::size h_) const noexcept {
				::dtl::type::ssize ds{}, dist{};
				for (::dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (::dtl::type::size ww{}; ww < w_; ++ww)
						if(createSitesDistance(point_, ind, dist, ds, static_cast<::dtl::type::ssize>(ww), static_cast<::dtl::type::ssize>(hh)))
							matrix_[hh][ww] = color_[ind];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSitesLayer(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const Index_Size layer_, const ::dtl::type::size w_, const ::dtl::type::size h_) const noexcept {
				::dtl::type::ssize ds{}, dist{};
				for (::dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (::dtl::type::size ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<::dtl::type::ssize>(ww), static_cast<::dtl::type::ssize>(hh)))
							matrix_[hh][ww][layer_] = color_[ind];
			}
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void createSitesArray(const UniquePair_& point_, const UniqueInt_& color_, Matrix_& matrix_, const Index_Size max_x_, const ::dtl::type::size w_, const ::dtl::type::size h_) const noexcept {
				::dtl::type::ssize ds{}, dist{};
				for (::dtl::type::size hh{}, ind{}; hh < h_; ++hh)
					for (::dtl::type::size ww{}; ww < w_; ++ww)
						if (createSitesDistance(point_, ind, dist, ds, static_cast<::dtl::type::ssize>(ww), static_cast<::dtl::type::ssize>(hh)))
							matrix_[hh * max_x_ + ww] = color_[ind];
			}


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			inline void assignSTL(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ DTL_TYPE_NEW Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ DTL_TYPE_NEW Matrix_Var_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<::dtl::type::ssize>(end_x_), static_cast<::dtl::type::ssize>(end_y_), function_);
				createSites(point, color, matrix_, end_x_, end_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void assignArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_&& function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ DTL_TYPE_NEW Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ DTL_TYPE_NEW Matrix_Var_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<::dtl::type::ssize>(end_x_), static_cast<::dtl::type::ssize>(end_y_), function_);
				createSitesArray(point, color, matrix_, max_x_, end_x_, end_y_);
			}
			template<typename Matrix_, typename Function_>
			inline void assignLayer(Matrix_ && matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				//原点の座標と各面の色(もしくは地形データ)を記録する変数
				UniquePair_ point{ DTL_TYPE_NEW Point_Pair_[this->draw_value] };
				if (!point) return;
				UniqueInt_ color{ DTL_TYPE_NEW Matrix_Var_[this->draw_value] };
				if (!color) return;

				createPoint(point, color, static_cast<::dtl::type::ssize>(end_x_), static_cast<::dtl::type::ssize>(end_y_), function_);
				createSitesLayer(point, color, matrix_, layer_, end_x_, end_y_);
			}


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				this->assignSTL(matrix_, end_x_, end_y_, args_...);
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawLayerNormal(Matrix_&& matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_&& ... args_) const noexcept {
				this->assignLayer(matrix_, layer_, end_x_, end_y_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawArray(Matrix_&& matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_&& ... args_) const noexcept {
				this->assignArray(matrix_, end_x_, end_y_, max_x_, args_...);
				return true;
			}

		public:


			///// メンバ変数の値を取得 (Get Value) /////

/*#######################################################################################
	[概要] 描画始点座標Xを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate X.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing width.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr ::dtl::type::size getValue() const noexcept {
				return this->draw_value;
			}


			///// 生成呼び出し (Drawing Function Call) /////

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


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearValue() noexcept {
				this->draw_value = 0;
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 描画範囲を初期値に戻す(描画範囲(X,Y,W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing range to the initial value (deletes the drawing range (X, Y, W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				VoronoiDiagram& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 全ての値を初期値に戻す。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset all values to their initial values.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
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
				VoronoiDiagram& setValue(const ::dtl::type::size draw_value_) noexcept {
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
				VoronoiDiagram& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			VoronoiDiagram() = default;
			constexpr explicit VoronoiDiagram(const ::dtl::type::size draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit VoronoiDiagram(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr VoronoiDiagram(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size draw_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr VoronoiDiagram(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr VoronoiDiagram(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const ::dtl::type::size draw_value_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library