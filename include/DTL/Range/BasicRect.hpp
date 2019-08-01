/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_BASIC_RECT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_BASIC_RECT_HPP

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace range { //"dtl::range"名前空間に属する

		//四角形クラス
		template<typename Derived_>
		class BasicRect {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;


		protected:


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};


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

			///// コンストラクタ (Constructor) /////

/*#######################################################################################
	[概要] デフォルトのコンストラクタ
#######################################################################################*/
			BasicRect() = default;

/*#######################################################################################
	[概要] 描画範囲指定のコンストラクタ
#######################################################################################*/
			constexpr explicit BasicRect(const ::dtl::base::MatrixRange& matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}

/*#######################################################################################
	[概要] 描画範囲指定のコンストラクタ
#######################################################################################*/
			constexpr BasicRect(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(start_x_), start_y(start_y_),
				width(width_), height(height_) {}


			///// メンバ変数の値を取得 (Get Value) /////

/*#######################################################################################
	[概要] 描画始点座標Xを取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPointX-(形状描画)/
	[Summary] Gets the drawing start point coordinate X.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getPointX(Matrix_Var_& value_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->start_x);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPointY-(形状描画)/
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getPointY(Matrix_Var_& value_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->start_y);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画横幅Wを取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getWidth-(形状描画)/
	[Summary] Gets the drawing width.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getWidth(Matrix_Var_& value_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->width);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画縦幅Hを取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getHeight-(形状描画)/
	[Summary] Gets the drawing height.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getHeight(Matrix_Var_& value_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->height);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPoint-(形状描画)/
	[Summary] Gets the drawing start coordinate (X, Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getPoint(Matrix_Var_& value_) noexcept {
				const Matrix_Var_ value{ this->start_x ,this->start_y };
				value_ = value;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPoint-(形状描画)/
	[Summary] Gets the drawing start coordinate (X, Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_, typename Matrix_Int2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getPoint(Matrix_Var_& value_, Matrix_Int2_& value2_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->start_x);
				value2_ = static_cast<Matrix_Int2_>(this->start_y);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲(X,Y,W,H)を取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getRange-(形状描画)/
	[Summary] Gets the drawing range.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_, typename Matrix_Int2_, typename Matrix_Int3_, typename Matrix_Int4_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getRange(Matrix_Var_& value_, Matrix_Int2_& value2_, Matrix_Int3_& value3_, Matrix_Int4_& value4_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->start_x);
				value2_ = static_cast<Matrix_Int2_>(this->start_y);
				value3_ = static_cast<Matrix_Int3_>(this->width);
				value4_ = static_cast<Matrix_Int4_>(this->height);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲(X,Y,W)を取得する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getRange-(形状描画)/
	[Summary] Gets the drawing range.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			template<typename Matrix_Var_, typename Matrix_Int2_, typename Matrix_Int3_, typename Matrix_Int4_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& getRange(Matrix_Var_& value_, Matrix_Int2_& value2_, Matrix_Int3_& value3_) noexcept {
				value_ = static_cast<Matrix_Var_>(this->start_x);
				value2_ = static_cast<Matrix_Int2_>(this->start_y);
				value3_ = static_cast<Matrix_Int3_>(this->width);
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標Xを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPointX-(形状描画)/
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
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getPointY-(形状描画)/
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
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getWidth-(形状描画)/
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
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::getHeight-(形状描画)/
	[Summary] Gets the drawing height.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearPointX-(形状描画)/
	[Summary] Resets the drawing start coordinate X to the initial value (deletes the drawing start coordinate X).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointX() noexcept {
				this->start_x = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標Yを初期値に戻す(描画始点座標Yを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearPointY-(形状描画)/
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointY() noexcept {
				this->start_y = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearWidth-(形状描画)/
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearWidth() noexcept {
				this->width = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearHeight-(形状描画)/
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearHeight() noexcept {
				this->height = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Width, Height)を初期値に戻す(描画幅(W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Reset the drawing range length (Width, Height) to the initial value (delete the drawing length (W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearLength() noexcept {
				this->clearWidth();
				this->clearHeight();
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearPoint-(形状描画)/
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲を初期値に戻す(描画範囲(X,Y,W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[参考ページ] https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::XX::YY::clearRange-(形状描画)/
	[Summary] Resets the drawing range to the initial value (deletes the drawing range (X, Y, W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return static_cast<Derived_&>(*this);
			}


			///// 代入 /////

/*#######################################################################################
	[概要] 描画始点座標Xを設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing start point coordinate X.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標Yを設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing start point coordinate Y.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画横幅Wを設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing width.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画縦幅Hを設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing height.
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing start point coordinates (X, Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing start point coordinates (X, Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size start_x_, const Index_Size start_y_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲(X,Y,W,H)を設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing range (X, Y, W, H).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = length_;
				this->height = length_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲(X,Y,W,H)を設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing range (X, Y, W, H).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->width = width_;
				this->height = height_;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲(X,Y,W,H)を設定する。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Set the drawing range (X, Y, W, H).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const ::dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return static_cast<Derived_&>(*this);
			}

		};
	}
}

#endif //Included Dungeon Template Library
