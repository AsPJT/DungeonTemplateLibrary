/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RECT_BASE_WITH_VALUE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RECT_BASE_WITH_VALUE_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */

#include <cstddef>
#include <Base/Struct.hpp>
#include <Macros/constexpr.hpp>
#include <Macros/nodiscard.hpp>

//共有データ
namespace dtl {
	inline namespace utility {

		//四角形クラス
		template<typename Derived, typename Matrix_Int_>
		class RectBaseWithValue {
		private:

			///// エイリアス /////

			using Index_Size = std::size_t;


		protected:


			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			Matrix_Int_ draw_value{};


			///// 計算補助 /////

			constexpr Index_Size calcEndX(const Index_Size max_x_) const noexcept {
				return (this->width == 0 || this->start_x + this->width >= max_x_)
					? max_x_
					: this->start_x + this->width;
			}

			constexpr Index_Size calcEndY(const Index_Size max_y_) const noexcept {
				return (this->height == 0 || this->start_y + this->height >= max_y_)
					? max_y_
					: this->start_y + this->height;
			}


		public:


			///// 情報取得 /////

			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DUNGEON_TEMPLATE_LIBRARY_NODISCARD
			constexpr Matrix_Int_ getValue() const noexcept {
				return this->draw_value;
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearPointX() noexcept {
				this->start_x = 0;
				return static_cast<Derived&>(*this);
			}
			//始点座標Yを初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearPointY() noexcept {
				this->start_y = 0;
				return static_cast<Derived&>(*this);
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearWidth() noexcept {
				this->width = 0;
				return static_cast<Derived&>(*this);
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearHeight() noexcept {
				this->height = 0;
				return static_cast<Derived&>(*this);
			}
			//塗り値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearValue() noexcept {
				const Matrix_Int_ new_draw_value{};
				this->draw_value = new_draw_value;
				return static_cast<Derived&>(*this);
			}
			//始点座標(X,Y)を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return static_cast<Derived&>(*this);
			}
			//描画範囲を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return static_cast<Derived&>(*this);
			}
			//全ての値を初期値に戻す
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& clear() noexcept {
				this->clearRange();
				this->clearValue();
				return static_cast<Derived&>(*this);
			}


			///// 代入 /////

			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setValue(const Matrix_Int_& draw_value_) noexcept {
				this->draw_value = draw_value_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return static_cast<Derived&>(*this);
			}
			DUNGEON_TEMPLATE_LIBRARY_CPP14_CONSTEXPR
				Derived& setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return static_cast<Derived&>(*this);
			}


			///// コンストラクタ /////

			constexpr RectBaseWithValue() noexcept = default;
			constexpr explicit RectBaseWithValue(const Matrix_Int_ & draw_value_) noexcept
				:draw_value(draw_value_) {}
			constexpr explicit RectBaseWithValue(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit RectBaseWithValue(const dtl::base::MatrixRange & matrix_range_, const Matrix_Int_ & draw_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				draw_value(draw_value_) {}
			constexpr explicit RectBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}
			constexpr explicit RectBaseWithValue(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_ & draw_value_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_),
				draw_value(draw_value_) {}
		};
	}
}

#endif //Included Dungeon Template Library
