/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_CELLULAR_AUTOMATON_MIX_ISLAND

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::CellularAutomatonMixIsland-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Shape/Border.hpp>
#include <Shape/HalfMixRect.hpp>
#include <Utility/CellularAutomaton.hpp>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class CellularAutomatonMixIsland {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// メンバ変数 /////

			dtl::shape::Border<Matrix_Int_> border{};
			dtl::shape::HalfMixRect<Matrix_Int_> mixRect{};
			dtl::utility::CellularAutomation<Matrix_Int_> cellularAutomation{};
			Index_Size loop_num{ 1 };

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
				return this->border.getPointX();
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
				return this->border.getPointY();
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
				return this->border.getWidth();
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
				return this->border.getHeight();
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
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->border.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				mixRect.draw(matrix_, args_...);
				border.draw(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.draw(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawOperator(matrix_, args_...);
				border.drawOperator(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.draw(matrix_, args_...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawArray(matrix_, args_...);
				border.drawArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				mixRect.drawOperatorArray(matrix_, args_...);
				border.drawOperatorArray(matrix_, args_...);
				for (Index_Size i{}; i < loop_num; ++i)
					cellularAutomation.drawArray(matrix_, args_...);
				return true;
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
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
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr CellularAutomatonMixIsland& clearPointX() noexcept {
				this->mixRect.clearPointX();
				this->border.clearPointX();
				this->cellularAutomation.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr CellularAutomatonMixIsland& clearPointY() noexcept {
				this->mixRect.clearPointY();
				this->border.clearPointY();
				this->cellularAutomation.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr CellularAutomatonMixIsland& clearWidth() noexcept {
				this->mixRect.clearWidth();
				this->border.clearWidth();
				this->cellularAutomation.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr CellularAutomatonMixIsland& clearHeight() noexcept {
				this->mixRect.clearHeight();
				this->border.clearHeight();
				this->cellularAutomation.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			constexpr CellularAutomatonMixIsland& clearValue() noexcept {
				this->mixRect.clearValue();
				this->border.clearValue();
				this->cellularAutomation.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr CellularAutomatonMixIsland& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr CellularAutomatonMixIsland& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr CellularAutomatonMixIsland& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			constexpr CellularAutomatonMixIsland& setPointX(const Index_Size point_x_) noexcept {
				this->mixRect.setPointX(point_x_);
				this->border.setPointX(point_x_);
				this->cellularAutomation.setPointX(point_x_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setPointY(const Index_Size point_y_) noexcept {
				this->mixRect.setPointY(point_y_);
				this->border.setPointY(point_y_);
				this->cellularAutomation.setPointY(point_y_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setWidth(const Index_Size width_) noexcept {
				this->mixRect.setWidth(width_);
				this->border.setWidth(width_);
				this->cellularAutomation.setWidth(width_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setHeight(const Index_Size height_) noexcept {
				this->mixRect.setHeight(height_);
				this->border.setHeight(height_);
				this->cellularAutomation.setHeight(height_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->mixRect.setValue(draw_value_);
				this->border.setValue(draw_value_);
				this->cellularAutomation.setValue(draw_value_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->mixRect.setRange(matrix_range_);
				this->border.setRange(matrix_range_);
				this->cellularAutomation.setRange(matrix_range_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			constexpr CellularAutomatonMixIsland& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr CellularAutomatonMixIsland() noexcept = default;
			template<typename ...Args_>
			explicit CellularAutomatonMixIsland(const Index_Size & loop_num_, const Matrix_Int_ & first_, const Args_ & ... args_) noexcept
				:border(first_), mixRect(first_, args_...), loop_num(loop_num_) {}
			template<typename ...Args_>
			constexpr explicit CellularAutomatonMixIsland(const dtl::base::MatrixRange & matrix_range_, const Index_Size & loop_num_, const Matrix_Int_ & first_, const Args_ & ... args_) noexcept
				:border(matrix_range_, first_), mixRect(matrix_range_, first_, args_...), cellularAutomation(matrix_range_), loop_num(loop_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library