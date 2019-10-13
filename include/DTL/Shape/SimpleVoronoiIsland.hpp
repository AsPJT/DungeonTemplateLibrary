/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_VORONOI_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_SIMPLE_VORONOI_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::SimpleVoronoiIsland-(形状クラス)/
#######################################################################################*/

#include <utility>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Utility/VoronoiDiagram.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Var_, typename UniquePair_ = DTL_TYPE_UNIQUE_PTR< ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>[]>, typename UniqueInt_ = DTL_TYPE_UNIQUE_PTR<Matrix_Var_[]>>
		class SimpleVoronoiIsland {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;




			///// メンバ変数 (Member Variable) /////

			::dtl::utility::VoronoiDiagram<Matrix_Var_, UniquePair_, UniqueInt_> voronoiDiagram{};
			double probability_value{ 0.5 };
			Matrix_Var_ land_value{};
			Matrix_Var_ sea_value{};

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
				return this->voronoiDiagram.getPointX();
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->voronoiDiagram.getPointY();
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing width.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->voronoiDiagram.getWidth();
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->voronoiDiagram.getHeight();
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr ::dtl::type::size getValue() const noexcept {
				return this->voronoiDiagram.getValue();
			}

			constexpr bool isIsland(const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>& point_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_, const ::dtl::type::ssize numerator_, const ::dtl::type::ssize denominator_) const noexcept {
				//return true;
				return (point_.first > ((w_ - sx_) * numerator_ / denominator_ + sx_) && point_.first < ((w_ - sx_) * (denominator_ - numerator_) / denominator_ + sx_)) && (point_.second > ((h_ - sy_) * numerator_ / denominator_ + sy_) && point_.second < ((h_ - sy_) * (denominator_ - numerator_) / denominator_ + sy_));
			}


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_) const noexcept {
				return this->voronoiDiagram.draw(matrix_,
					[this](const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize> & point_, Matrix_Var_ & color_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && DTL_RANDOM_ENGINE.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_,
					[this](const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>& point_, Matrix_Var_ & color_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && DTL_RANDOM_ENGINE.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, max_x_, max_y_,
					[this](const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>& point_, Matrix_Var_ & color_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && DTL_RANDOM_ENGINE.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_&& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.draw(matrix_, layer_, max_x_, max_y_,
					[this](const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>& point_, Matrix_Var_ & color_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && DTL_RANDOM_ENGINE.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_&& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return this->voronoiDiagram.drawArray(matrix_, max_x_, max_y_,
					[this](const ::std::pair<::dtl::type::ssize, ::dtl::type::ssize>& point_, Matrix_Var_ & color_, const ::dtl::type::ssize sx_, const ::dtl::type::ssize sy_, const ::dtl::type::ssize w_, const ::dtl::type::ssize h_) {
						if ((this->isIsland(point_, sx_, sy_, w_, h_, 2, 5) || this->isIsland(point_, sx_, sy_, w_, h_, 1, 5)) && DTL_RANDOM_ENGINE.probability(this->probability_value)) color_ = this->land_value;
						else color_ = this->sea_value;
					});
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
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
				SimpleVoronoiIsland& clearPointX() noexcept {
				this->voronoiDiagram.clearPointX();
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearPointY() noexcept {
				this->voronoiDiagram.clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearWidth() noexcept {
				this->voronoiDiagram.clearWidth();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearHeight() noexcept {
				this->voronoiDiagram.clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearValue() noexcept {
				this->voronoiDiagram.clearValue();
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& clearPoint() noexcept {
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
				SimpleVoronoiIsland& clearRange() noexcept {
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
				SimpleVoronoiIsland& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPointX(const Index_Size end_x_) noexcept {
				this->voronoiDiagram.setPointX(end_x_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPointY(const Index_Size end_y_) noexcept {
				this->voronoiDiagram.setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setWidth(const Index_Size width_) noexcept {
				this->voronoiDiagram.setWidth(width_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setHeight(const Index_Size height_) noexcept {
				this->voronoiDiagram.setHeight(height_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setValue(const ::dtl::type::size voronoi_num_) noexcept {
				this->voronoiDiagram.setValue(voronoi_num_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->voronoiDiagram.setRange(matrix_range_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				SimpleVoronoiIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			SimpleVoronoiIsland() = default;
			constexpr explicit SimpleVoronoiIsland(const ::dtl::type::size voronoi_num_) noexcept
				:voronoiDiagram(voronoi_num_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::type::size voronoi_num_, const double probability_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Var_& land_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_), land_value(land_value_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Var_& land_value_, const Matrix_Var_& sea_value_) noexcept
				:voronoiDiagram(voronoi_num_), probability_value(probability_value_), land_value(land_value_), sea_value(sea_value_) {}

			constexpr explicit SimpleVoronoiIsland(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:voronoiDiagram(matrix_range_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size voronoi_num_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size voronoi_num_, const double probability_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Var_& land_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_), land_value(land_value_) {}
			constexpr SimpleVoronoiIsland(const ::dtl::base::MatrixRange& matrix_range_, const ::dtl::type::size voronoi_num_, const double probability_value_, const Matrix_Var_& land_value_, const Matrix_Var_& sea_value_) noexcept
				:voronoiDiagram(matrix_range_, voronoi_num_), probability_value(probability_value_), land_value(land_value_), sea_value(sea_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library