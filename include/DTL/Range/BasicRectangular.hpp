/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_BASIC_RECTANGULAR_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RANGE_BASIC_RECTANGULAR_HPP

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
		class BasicRectangular {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;


		protected:


			///// メンバ変数 (Member Variable) /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size start_z{};
			Index_Size size_x{};
			Index_Size size_y{};
			Index_Size size_z{};


			///// 計算補助 /////

			constexpr Index_Size calcEndX(const Index_Size max_x_) const noexcept {
				return (this->size_x == 0 || this->start_x + this->size_x >= max_x_)
					? max_x_
					: this->start_x + this->size_x;
			}

			constexpr Index_Size calcEndY(const Index_Size max_y_) const noexcept {
				return (this->size_y == 0 || this->start_y + this->size_y >= max_y_)
					? max_y_
					: this->start_y + this->size_y;
			}

			constexpr Index_Size calcEndZ(const Index_Size max_z_) const noexcept {
				return (this->size_z == 0 || this->start_z + this->size_z >= max_z_)
					? max_z_
					: this->start_z + this->size_z;
			}

			///// コンストラクタ (Constructor) /////

			BasicRectangular() = default;
			constexpr explicit BasicRectangular(const ::dtl::base::MatrixRange3D & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y), start_z(matrix_range_.z),
				size_x(matrix_range_.w), size_y(matrix_range_.h), size_z(matrix_range_.d) {}
			constexpr BasicRectangular(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size size_x_, const Index_Size size_y_, const Index_Size size_z_) noexcept
				:start_x(start_x_), start_y(start_y_), start_z(start_z_),
				size_x(size_x_), size_y(size_y_), size_z(size_z_) {}
			constexpr BasicRectangular(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size length_) noexcept
				:start_x(start_x_), start_y(start_y_), start_z(start_z_),
				size_x(length_), size_y(length_), size_z(length_) {}

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
				return this->start_x;
			}

/*#######################################################################################
	[概要] 描画始点座標Yを取得する。
	[戻り値] 戻り値の型は std::size_t である。
	[Summary] Gets the drawing start point coordinate Y.
	[Return value] The return type is std::size_t.
#######################################################################################*/
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getPointZ() const noexcept {
				return this->start_z;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getSizeX() const noexcept {
				return this->size_x;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getSizeY() const noexcept {
				return this->size_y;
			}
			DTL_VERSIONING_CPP17_NODISCARD
				constexpr Index_Size getSizeZ() const noexcept {
				return this->size_z;
			}


			///// 消去 (Clear) /////

/*#######################################################################################
	[概要] 描画始点座標Xを初期値に戻す(描画始点座標Xを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
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
	[Summary] Resets the drawing start coordinate Y to the initial value (deletes the drawing start coordinate Y).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointY() noexcept {
				this->start_y = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標Zを初期値に戻す(描画始点座標Zを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate Z to the initial value (deletes the drawing start coordinate Z).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPointZ() noexcept {
				this->start_z = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(X軸方向)を初期値に戻す(描画横幅Wを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the width of the range (X axis direction) to the initial value (deletes the drawing width).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearSizeX() noexcept {
				this->size_x = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Y軸方向)を初期値に戻す(描画縦幅Hを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the height of the range (Y axis direction) to the initial value (deletes the drawing height).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearSizeY() noexcept {
				this->size_y = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 範囲の大きさ(Z軸方向)を初期値に戻す(描画奥幅Dを消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the depth of the range (Z axis direction) to the initial value (deletes the drawing depth).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearSizeZ() noexcept {
				this->size_z = 0;
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画始点座標(X,Y)を初期値に戻す(描画始点座標(X,Y)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing start coordinate (X, Y) to the initial value (deletes the drawing start coordinate (X, Y)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearPointZ();
				return static_cast<Derived_&>(*this);
			}

/*#######################################################################################
	[概要] 描画範囲を初期値に戻す(描画範囲(X,Y,W,H)を消去する)。
	[戻り値] 戻り値の型は 当クラスの参照値 である。
	[Summary] Resets the drawing range to the initial value (deletes the drawing range (X, Y, W, H)).
	[Return value] The return type is a reference value of this class.
#######################################################################################*/
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearPointZ();
				this->clearSizeX();
				this->clearSizeY();
				this->clearSizeZ();
				return static_cast<Derived_&>(*this);
			}


			///// 代入 /////

			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointX(const Index_Size start_x_) noexcept {
				this->start_x = start_x_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointY(const Index_Size start_y_) noexcept {
				this->start_y = start_y_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPointZ(const Index_Size start_z_) noexcept {
				this->start_z = start_z_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setSizeX(const Index_Size size_x_) noexcept {
				this->size_x = size_x_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setSizeY(const Index_Size size_y_) noexcept {
				this->size_y = size_y_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setSizeZ(const Index_Size size_z_) noexcept {
				this->size_z = size_z_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				this->start_z = point_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setPoint(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->start_z = start_z_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size length_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->start_z = start_z_;
				this->size_x = length_;
				this->size_y = length_;
				this->size_z = length_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const Index_Size start_x_, const Index_Size start_y_, const Index_Size start_z_, const Index_Size size_x_, const Index_Size size_y_, const Index_Size size_z_) noexcept {
				this->start_x = start_x_;
				this->start_y = start_y_;
				this->start_z = start_z_;
				this->size_x = size_x_;
				this->size_y = size_y_;
				this->size_z = size_z_;
				return static_cast<Derived_&>(*this);
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				Derived_& setRange(const ::dtl::base::MatrixRange3D & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->start_z = matrix_range_.z;
				this->size_x = matrix_range_.w;
				this->size_y = matrix_range_.h;
				this->size_z = matrix_range_.d;
				return static_cast<Derived_&>(*this);
			}

		};
	}
}

#endif //Included Dungeon Template Library
