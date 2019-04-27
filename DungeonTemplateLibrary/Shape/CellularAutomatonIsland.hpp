/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_ISLAND_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_ISLAND_HPP

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
#include <Shape/Border.hpp>
#include <Shape/RandomRect.hpp>
#include <Utility/CellularAutomaton.hpp>
#include <Base/Struct.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class CellularAutomatonIsland {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// メンバ変数 /////

			dtl::shape::Border<Matrix_Int_> border{};
			dtl::shape::RandomRect<Matrix_Int_> randomRect{};
			dtl::utility::CellularAutomation<Matrix_Int_> cellularAutomation{};
			Index_Size loop_num{ 1 };

		public:


			///// 情報取得 /////

			DTL_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->border.getPointX();
			}
			DTL_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->border.getPointY();
			}
			DTL_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->border.getWidth();
			}
			DTL_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->border.getHeight();
			}
			DTL_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->border.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->randomRect.draw(matrix_, args_...);
				this->border.draw(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				bool drawOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawOperator(matrix_, args_...);
				this->border.drawOperator(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				bool drawArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawArray(matrix_, args_...);
				this->border.drawArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				bool drawOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->randomRect.drawOperatorArray(matrix_, args_...);
				this->border.drawOperatorArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					this->cellularAutomation.draw(matrix_, args_...);
				return true;
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearPointX() noexcept {
				this->randomRect.clearPointX();
				this->border.clearPointX();
				this->cellularAutomation.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearPointY() noexcept {
				this->randomRect.clearPointY();
				this->border.clearPointY();
				this->cellularAutomation.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearWidth() noexcept {
				this->randomRect.clearWidth();
				this->border.clearWidth();
				this->cellularAutomation.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearHeight() noexcept {
				this->randomRect.clearHeight();
				this->border.clearHeight();
				this->cellularAutomation.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearValue() noexcept {
				this->randomRect.clearValue();
				this->border.clearValue();
				this->cellularAutomation.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setPointX(const Index_Size point_x_) noexcept {
				this->randomRect.setPointX(point_x_);
				this->border.setPointX(point_x_);
				this->cellularAutomation.setPointX(point_x_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setPointY(const Index_Size point_y_) noexcept {
				this->randomRect.setPointY(point_y_);
				this->border.setPointY(point_y_);
				this->cellularAutomation.setPointY(point_y_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setWidth(const Index_Size width_) noexcept {
				this->randomRect.setWidth(width_);
				this->border.setWidth(width_);
				this->cellularAutomation.setWidth(width_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setHeight(const Index_Size height_) noexcept {
				this->randomRect.setHeight(height_);
				this->border.setHeight(height_);
				this->cellularAutomation.setHeight(height_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->randomRect.setValue(draw_value_);
				this->border.setValue(draw_value_);
				this->cellularAutomation.setValue(draw_value_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->randomRect.setRange(matrix_range_);
				this->border.setRange(matrix_range_);
				this->cellularAutomation.setRange(matrix_range_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				CellularAutomatonIsland& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr CellularAutomatonIsland() noexcept = default;
			constexpr explicit CellularAutomatonIsland(const Matrix_Int_ & draw_value_) noexcept
				:border(draw_value_), randomRect(draw_value_) {}
			constexpr explicit CellularAutomatonIsland(const PairMatrixInt & pair_value_) noexcept
				:border(pair_value_.second), randomRect(pair_value_.first) {}
			constexpr explicit CellularAutomatonIsland(const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_) noexcept
				:border(draw_value2_), randomRect(draw_value_) {}
			constexpr explicit CellularAutomatonIsland(const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_, const Index_Size & loop_num_) noexcept
				:border(draw_value2_), randomRect(draw_value_), loop_num(loop_num_) {}
			constexpr explicit CellularAutomatonIsland(const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_, const Index_Size & loop_num_, const double probability_) noexcept
				:border(draw_value2_), randomRect(draw_value_, probability_), loop_num(loop_num_) {}

			constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:border(point_x_, point_y_, width_, height_), randomRect(point_x_, point_y_, width_, height_) {}
			constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:border(point_x_, point_y_, width_, height_, draw_value_), randomRect(point_x_, point_y_, width_, height_, draw_value_) {}
			constexpr explicit CellularAutomatonIsland(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt & pair_value_) noexcept
				:border(point_x_, point_y_, width_, height_, pair_value_.second), randomRect(point_x_, point_y_, width_, height_, pair_value_.first) {}

			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_) noexcept
				:border(matrix_range_), randomRect(matrix_range_), cellularAutomation(matrix_range_) {}
			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:border(matrix_range_, draw_value_), randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_) {}
			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_, const PairMatrixInt & pair_value_) noexcept
				:border(matrix_range_, pair_value_.second), randomRect(matrix_range_, pair_value_.first), cellularAutomation(matrix_range_) {}
			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_) {}
			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_, const Index_Size & loop_num_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
			constexpr explicit CellularAutomatonIsland(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_, const Matrix_Int_ & draw_value2_, const Index_Size & loop_num_, const double probability_) noexcept
				:border(matrix_range_, draw_value2_), randomRect(matrix_range_, draw_value_, probability_), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library