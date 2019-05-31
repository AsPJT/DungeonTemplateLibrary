/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_POINT_GRID_AND_SOME_BLOCKS_WITH_BORDER_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_POINT_GRID_AND_SOME_BLOCKS_WITH_BORDER_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::PointGridAndSomeBlocksWithBorder-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Shape/BorderOdd.hpp>
#include <DTL/Shape/PointGrid.hpp>
#include <DTL/Shape/RandomRect.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>

namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class PointGridAndSomeBlocksWithBorder {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			
			


			///// メンバ変数 /////

			::dtl::shape::RandomRect<Matrix_Int_> randomRect{};
			::dtl::shape::BorderOdd<Matrix_Int_> borderOdd{};
			::dtl::shape::PointGrid<Matrix_Int_> pointGrid{};

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointX() const noexcept {
				return this->borderOdd.getPointX();
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->borderOdd.getPointY();
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->borderOdd.getWidth();
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->borderOdd.getHeight();
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Matrix_Int_ getValue() const noexcept {
				return this->borderOdd.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.draw(matrix_, args_...);
				this->pointGrid.draw(matrix_, args_...);
				this->borderOdd.draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.draw(matrix_, args_...);
				this->pointGrid.drawOperator(matrix_, args_...);
				this->borderOdd.drawOperator(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.drawArray(matrix_, args_...);
				this->pointGrid.drawArray(matrix_, args_...);
				this->borderOdd.drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.drawOperatorArray(matrix_, args_...);
				this->pointGrid.drawOperatorArray(matrix_, args_...);
				this->borderOdd.drawOperatorArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
				return true;
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

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


			///// 消去 /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearPointX() noexcept {
				this->randomRect.clearPointX();
				this->borderOdd.clearPointX();
				this->pointGrid.clearPointX();
				return *this;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearPointY() noexcept {
				this->randomRect.clearPointY();
				this->borderOdd.clearPointY();
				this->pointGrid.clearPointY();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearWidth() noexcept {
				this->randomRect.clearWidth();
				this->borderOdd.clearWidth();
				this->pointGrid.clearWidth();
				return *this;
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearHeight() noexcept {
				this->randomRect.clearHeight();
				this->borderOdd.clearHeight();
				this->pointGrid.clearHeight();
				return *this;
			}

/*#######################################################################################
	[概要] 塗り値を初期値に戻す(描画値を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing value to the initial value (deletes the drawing value).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearValue() noexcept {
				this->randomRect.clearValue();
				this->borderOdd.clearValue();
				this->pointGrid.clearValue();
				return *this;
			}
//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setPointX(const Index_Size end_x_) noexcept {
				this->randomRect.setPointX(end_x_);
				this->borderOdd.setPointX(end_x_);
				this->pointGrid.setPointX(end_x_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setPointY(const Index_Size end_y_) noexcept {
				this->randomRect.setPointY(end_y_);
				this->borderOdd.setPointY(end_y_);
				this->pointGrid.setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setWidth(const Index_Size width_) noexcept {
				this->randomRect.setWidth(width_);
				this->borderOdd.setWidth(width_);
				this->pointGrid.setWidth(width_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setHeight(const Index_Size height_) noexcept {
				this->randomRect.setHeight(height_);
				this->borderOdd.setHeight(height_);
				this->pointGrid.setHeight(height_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->randomRect.setValue(draw_value_);
				this->borderOdd.setValue(draw_value_);
				this->pointGrid.setValue(draw_value_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->randomRect.setRange(matrix_range_);
				this->borderOdd.setRange(matrix_range_);
				this->pointGrid.setRange(matrix_range_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				PointGridAndSomeBlocksWithBorder& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr PointGridAndSomeBlocksWithBorder() = default;
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_) noexcept
				:randomRect(draw_value_), borderOdd(draw_value_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
				:borderOdd(draw_value2_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_) noexcept
				:randomRect(draw_value3_), borderOdd(draw_value2_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_, const double probability_) noexcept
				:randomRect(draw_value3_, probability_), borderOdd(draw_value2_), pointGrid(draw_value_) {}


			constexpr explicit PointGridAndSomeBlocksWithBorder(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:randomRect(matrix_range_), borderOdd(matrix_range_), pointGrid(matrix_range_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
				:randomRect(matrix_range_, draw_value_), borderOdd(matrix_range_, draw_value_), pointGrid(matrix_range_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
				:borderOdd(matrix_range_, draw_value2_), pointGrid(matrix_range_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_) noexcept
				:randomRect(matrix_range_, draw_value3_), borderOdd(matrix_range_, draw_value2_), pointGrid(matrix_range_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_, const double probability_) noexcept
				:randomRect(matrix_range_, draw_value3_, probability_), borderOdd(matrix_range_, draw_value2_), pointGrid(matrix_range_, draw_value_) {}

		};
	}
}

#endif //Included Dungeon Template Library