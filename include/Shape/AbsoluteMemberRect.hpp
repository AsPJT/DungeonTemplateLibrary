/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_ABSOLUTE_MEMBER_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_ABSOLUTE_MEMBER_RECT_HPP

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
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class AbsoluteMemberRect {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			
			


			///// メンバ変数 /////

			dtl::shape::AbsoluteRect<Matrix_Int_> absoluteRect{};

		public:


			///// 情報取得 /////

			DTL_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->absoluteRect.getPointX();
			}
			DTL_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->absoluteRect.getPointY();
			}
			DTL_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->absoluteRect.getWidth();
			}
			DTL_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->absoluteRect.getHeight();
			}
			DTL_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->absoluteRect.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawOperator(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawOperatorArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CONSTEXPR_CPP14
				Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearPointX() noexcept {
				this->absoluteRect.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearPointY() noexcept {
				this->absoluteRect.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearWidth() noexcept {
				this->absoluteRect.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearHeight() noexcept {
				this->absoluteRect.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearValue() noexcept {
				this->absoluteRect.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setPointX(const Index_Size end_x_) noexcept {
				this->absoluteRect.setPointX(end_x_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setPointY(const Index_Size end_y_) noexcept {
				this->absoluteRect.setPointY(end_y_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setWidth(const Index_Size width_) noexcept {
				this->absoluteRect.setWidth(width_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setHeight(const Index_Size height_) noexcept {
				this->absoluteRect.setHeight(height_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->absoluteRect.setValue(draw_value_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->absoluteRect.setRange(matrix_range_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_CONSTEXPR_CPP14
				AbsoluteMemberRect& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
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
			constexpr explicit AbsoluteMemberRect(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:absoluteRect(end_x_, end_y_, width_, height_) {}
			constexpr explicit AbsoluteMemberRect(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(end_x_, end_y_, width_, height_, draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library