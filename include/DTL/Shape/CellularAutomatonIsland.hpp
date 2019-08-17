/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_CELLULAR_AUTOMATON_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_CELLULAR_AUTOMATON_ISLAND_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::CellularAutomatonIsland-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Shape/Border.hpp>
#include <DTL/Shape/RandomRect.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Retouch/CellularAutomaton.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Var_>
		class CellularAutomatonIsland {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			
			


			///// メンバ変数 (Member Variable) /////

			::dtl::shape::Border<Matrix_Var_> border{};
			::dtl::shape::RandomRect<Matrix_Var_> randomRect{};
			::dtl::retouch::CellularAutomaton<Matrix_Var_> cellularAutomation{};
			Index_Size loop_num{ 1 };

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
				return this->border.getPointX();
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->border.getPointY();
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing width.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->border.getWidth();
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->border.getHeight();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Matrix_Var_ getValue() const noexcept {
				return this->border.getValue();
			}


			///// 生成呼び出し (Drawing Function Call) /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.draw(matrix_, args_...);
				this->border.draw(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawOperator(matrix_, args_...);
				this->border.drawOperator(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawArray(matrix_, args_...);
				this->border.drawArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawOperatorArray(matrix_, args_...);
				this->border.drawOperatorArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
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


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearPointX() noexcept {
				this->randomRect.clearPointX();
				this->border.clearPointX();
				this->cellularAutomation.clearPointX();
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearPointY() noexcept {
				this->randomRect.clearPointY();
				this->border.clearPointY();
				this->cellularAutomation.clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearWidth() noexcept {
				this->randomRect.clearWidth();
				this->border.clearWidth();
				this->cellularAutomation.clearWidth();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearHeight() noexcept {
				this->randomRect.clearHeight();
				this->border.clearHeight();
				this->cellularAutomation.clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearValue() noexcept {
				this->randomRect.clearValue();
				this->border.clearValue();
				this->cellularAutomation.clearValue();
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& clearPoint() noexcept {
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
				CellularAutomatonIsland& clearRange() noexcept {
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
				CellularAutomatonIsland& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setPointX(const Index_Size end_x_) noexcept {
				this->randomRect.setPointX(end_x_);
				this->border.setPointX(end_x_);
				this->cellularAutomation.setPointX(end_x_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setPointY(const Index_Size end_y_) noexcept {
				this->randomRect.setPointY(end_y_);
				this->border.setPointY(end_y_);
				this->cellularAutomation.setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setWidth(const Index_Size width_) noexcept {
				this->randomRect.setWidth(width_);
				this->border.setWidth(width_);
				this->cellularAutomation.setWidth(width_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setHeight(const Index_Size height_) noexcept {
				this->randomRect.setHeight(height_);
				this->border.setHeight(height_);
				this->cellularAutomation.setHeight(height_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setValue(const Matrix_Var_& draw_value_) noexcept {
				this->randomRect.setValue(draw_value_);
				this->border.setValue(draw_value_);
				this->cellularAutomation.setValue(draw_value_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->randomRect.setRange(matrix_range_);
				this->border.setRange(matrix_range_);
				this->cellularAutomation.setRange(matrix_range_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				CellularAutomatonIsland& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ (Constructor) /////

			CellularAutomatonIsland() = default;
			constexpr explicit CellularAutomatonIsland(const Matrix_Var_ & draw_value_) noexcept
				:randomRect(draw_value_) {}

			constexpr CellularAutomatonIsland(const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_) noexcept
				:border(draw_value2_), randomRect(draw_value_) {}
			constexpr CellularAutomatonIsland(const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_, const Index_Size & loop_num_) noexcept
				:border(draw_value2_), randomRect(draw_value_), loop_num(loop_num_) {}
			constexpr CellularAutomatonIsland(const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_, const Index_Size & loop_num_, const double probability_) noexcept
				:border(draw_value2_), randomRect(draw_value_, probability_), loop_num(loop_num_) {}

			constexpr CellularAutomatonIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:border(end_x_, end_y_, width_, height_), randomRect(end_x_, end_y_, width_, height_) {}
			constexpr CellularAutomatonIsland(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Var_ & draw_value_) noexcept
				:border(end_x_, end_y_, width_, height_), randomRect(end_x_, end_y_, width_, height_, draw_value_) {}

			constexpr explicit CellularAutomatonIsland(const ::dtl::base::MatrixRange & matrix_range_) noexcept
				:border(matrix_range_), randomRect(matrix_range_), cellularAutomation(matrix_range_) {}
			constexpr CellularAutomatonIsland(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Var_ & draw_value_) noexcept
				:randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_) {}

			constexpr CellularAutomatonIsland(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_) {}
			constexpr CellularAutomatonIsland(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_, const Index_Size & loop_num_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
			constexpr CellularAutomatonIsland(const ::dtl::base::MatrixRange & matrix_range_, const Matrix_Var_ & draw_value_, const Matrix_Var_ & draw_value2_, const Index_Size & loop_num_, const double probability_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_, probability_), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library