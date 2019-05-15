/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ABSOLUTE_MEMBER_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_ABSOLUTE_MEMBER_RECT_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/::dtl::shape::Rect-(形状クラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Shape/AbsoluteRect.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class AbsoluteMemberRect {
		private:


			///// エイリアス /////

			using Index_Size = ::dtl::type::size;
			
			


			///// メンバ変数 /////

			::dtl::shape::AbsoluteRect<Matrix_Int_> absoluteRect{};

		public:


			///// 情報取得 /////

			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->absoluteRect.getPointX();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->absoluteRect.getPointY();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->absoluteRect.getWidth();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->absoluteRect.getHeight();
			}
			DTL_VERSIONING_CPP17_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->absoluteRect.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.draw(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawOperator(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->absoluteRect.drawOperatorArray(DTL_TYPE_FORWARD<Matrix_>(matrix_), DTL_TYPE_FORWARD<Args_>(args_)...);
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

			//始点座標Xを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearPointX() noexcept {
				this->absoluteRect.clearPointX();
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearPointY() noexcept {
				this->absoluteRect.clearPointY();
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearWidth() noexcept {
				this->absoluteRect.clearWidth();
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearHeight() noexcept {
				this->absoluteRect.clearHeight();
				return *this;
			}
			//塗り値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearValue() noexcept {
				this->absoluteRect.clearValue();
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return *this;
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setPointX(const Index_Size end_x_) noexcept {
				this->absoluteRect.setPointX(end_x_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setPointY(const Index_Size end_y_) noexcept {
				this->absoluteRect.setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setWidth(const Index_Size width_) noexcept {
				this->absoluteRect.setWidth(width_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setHeight(const Index_Size height_) noexcept {
				this->absoluteRect.setHeight(height_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->absoluteRect.setValue(draw_value_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setRange(const ::dtl::base::MatrixRange& matrix_range_) noexcept {
				this->absoluteRect.setRange(matrix_range_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setPoint(const Index_Size point_) noexcept {
				this->setPointX(point_);
				this->setPointY(point_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				AbsoluteMemberRect& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->setPointX(end_x_);
				this->setPointY(end_y_);
				this->setWidth(length_);
				this->setHeight(length_);
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
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
			constexpr explicit AbsoluteMemberRect(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:absoluteRect(matrix_range_) {}
			constexpr explicit AbsoluteMemberRect(const ::dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(matrix_range_, draw_value_) {}
			constexpr explicit AbsoluteMemberRect(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:absoluteRect(end_x_, end_y_, width_, height_) {}
			constexpr explicit AbsoluteMemberRect(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
				:absoluteRect(end_x_, end_y_, width_, height_, draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library