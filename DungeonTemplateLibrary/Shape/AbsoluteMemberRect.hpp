/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_ABSOLUTE_MEMBER_RECT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_ABSOLUTE_MEMBER_RECT

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::AbsoluteMemberRect-(%E5%BD%A2%E7%8A%B6%E3%82%AF%E3%83%A9%E3%82%B9)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Shape/AbsoluteRect.hpp>
#include <Base/Struct.hpp>
#include <Macro/nodiscard.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class AbsoluteMemberRect {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// メンバ変数 /////

			dtl::shape::AbsoluteRect<Matrix_Int_> absoluteRect{};

		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->absoluteRect.getPointX();
			}
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->absoluteRect.getPointY();
			}
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->absoluteRect.getWidth();
			}
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->absoluteRect.getHeight();
			}
			DUNGEON_TEMPLATE_LIBRARY_MACRO_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->absoluteRect.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->absoluteRect.draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->absoluteRect.drawOperator(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->absoluteRect.drawArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->absoluteRect.drawOperatorArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			constexpr AbsoluteMemberRect& clearPointX() noexcept {
				this->absoluteRect.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			constexpr AbsoluteMemberRect& clearPointY() noexcept {
				this->absoluteRect.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			constexpr AbsoluteMemberRect& clearWidth() noexcept {
				this->absoluteRect.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			constexpr AbsoluteMemberRect& clearHeight() noexcept {
				this->absoluteRect.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			constexpr AbsoluteMemberRect& clearValue() noexcept {
				this->absoluteRect.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			constexpr AbsoluteMemberRect& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			constexpr AbsoluteMemberRect& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			constexpr AbsoluteMemberRect& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			constexpr AbsoluteMemberRect& setPointX(const Index_Size point_x_) noexcept {
				this->absoluteRect.setPointX(point_x_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setPointY(const Index_Size point_y_) noexcept {
				this->absoluteRect.setPointY(point_y_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setWidth(const Index_Size width_) noexcept {
				this->absoluteRect.setWidth(width_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setHeight(const Index_Size height_) noexcept {
				this->absoluteRect.setHeight(height_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->absoluteRect.setValue(draw_value_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->absoluteRect.setRange(matrix_range_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setPoint(const Index_Size point_x_, const Index_Size point_y_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size length_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			constexpr AbsoluteMemberRect& setRange(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(point_x_);
				this->setPointY(point_y_);
				this->setWidth(width_);
				this->setHeight(height_);
				return *this;
			}


			///// コンストラクタ /////

			constexpr AbsoluteMemberRect() noexcept = default;
			constexpr explicit AbsoluteMemberRect(const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(draw_value_) {}
			constexpr explicit AbsoluteMemberRect(const dtl::base::MatrixRange& matrix_range_) noexcept
				:absoluteRect(matrix_range_) {}
			constexpr explicit AbsoluteMemberRect(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(matrix_range_, draw_value_) {}
			constexpr explicit AbsoluteMemberRect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:absoluteRect(point_x_, point_y_, width_, height_) {}
			constexpr explicit AbsoluteMemberRect(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(point_x_, point_y_, width_, height_, draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library