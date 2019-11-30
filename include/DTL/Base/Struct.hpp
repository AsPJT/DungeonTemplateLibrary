/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_STRUCT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_STRUCT_HPP

#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する


		template<typename Int_>
		struct Coordinate1Dimensional {
			Int_ x{};
			Coordinate1Dimensional() = default;
			constexpr Coordinate1Dimensional(const Int_& x_) noexcept :x(x_) {};
		};

		template<typename Int_>
		struct Coordinate2Dimensional {
			Int_ x{};
			Int_ y{};
			Coordinate2Dimensional() = default;
			constexpr Coordinate2Dimensional(const Int_& x_, const Int_& y_) noexcept :x(x_), y(y_) {};

			constexpr bool operator==(const ::dtl::base::Coordinate2Dimensional<Int_>& vec2_) const noexcept {
				return vec2_.x == this->x && vec2_.y == this->y;
			}
			constexpr bool operator!=(const ::dtl::base::Coordinate2Dimensional<Int_>& vec2_) const noexcept {
				return vec2_.x != this->x || vec2_.y != this->y;
			}
		};
		using MatrixVec2 = ::dtl::base::Coordinate2Dimensional<::dtl::type::size>;

		template<typename Int_>
		using Vec2 = ::dtl::base::Coordinate2Dimensional<Int_>;

		template<typename Int_>
		struct Coordinate3Dimensional {
			Int_ x{};
			Int_ y{};
			Int_ z{};
			Coordinate3Dimensional() = default;
			constexpr Coordinate3Dimensional(const Int_& x_, const Int_& y_, const Int_& z_) noexcept :x(x_), y(y_), z(z_) {};

			constexpr bool operator==(const ::dtl::base::Coordinate3Dimensional<Int_>& vec3_) const noexcept {
				return vec3_.x == this->x && vec3_.y == this->y && vec3_.z == this->z;
			}
			constexpr bool operator!=(const ::dtl::base::Coordinate3Dimensional<Int_>& vec3_) const noexcept {
				return vec3_.x != this->x || vec3_.y != this->y || vec3_.z != this->z;
			}
		};
		using MatrixVec3 = ::dtl::base::Coordinate3Dimensional<::dtl::type::size>;

		//座標と幅
		template<typename Int_>
		struct Coordinate2DimensionalAndLength2Dimensional {
			Int_ x{};
			Int_ y{};
			Int_ w{};
			Int_ h{};
			Coordinate2DimensionalAndLength2Dimensional() = default;
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_) noexcept
				:x(x_), y(y_) {};
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_, const Int_& l_) noexcept
				:x(x_), y(y_), w(l_), h(l_) {};
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_, const Int_& w_, const Int_& h_) noexcept
				:x(x_), y(y_), w(w_), h(h_) {};

			//中身が一致しているか調べる
			constexpr bool operator==(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return range_.x == this->x && range_.y == this->y && range_.w == this->w && range_.h == this->h;
			}
			//中身が不一致か調べる
			constexpr bool operator!=(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return range_.x != this->x || range_.y != this->y || range_.w != this->w || range_.h != this->h;
			}

/*#######################################################################################
	[概要] 面積を比較する。(左の面積値 > 右の面積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator>(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) > (range_.w * range_.h);
			}
/*#######################################################################################
	[概要] 面積を比較する。(左の面積値 >= 右の面積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator>=(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) >= (range_.w * range_.h);
			}
/*#######################################################################################
	[概要] 面積を比較する。(左の面積値 < 右の面積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator<(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) < (range_.w * range_.h);
			}
/*#######################################################################################
	[概要] 面積を比較する。(左の面積値 <= 右の面積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator<=(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) <= (range_.w * range_.h);
			}

		};
		using MatrixRange = ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<::dtl::type::size>;

		//座標と幅
		template<typename Int_>
		struct Coordinate3DimensionalAndLength3Dimensional {
			Int_ x{};
			Int_ y{};
			Int_ z{};
			Int_ w{};
			Int_ h{};
			Int_ d{};
			Coordinate3DimensionalAndLength3Dimensional() = default;
			constexpr Coordinate3DimensionalAndLength3Dimensional(const Int_& x_, const Int_& y_, const Int_& z_) noexcept
				:x(x_), y(y_), z(z_) {};
			constexpr Coordinate3DimensionalAndLength3Dimensional(const Int_& x_, const Int_& y_, const Int_& z_, const Int_& l_) noexcept
				:x(x_), y(y_), z(z_), w(l_), h(l_), d(l_) {};
			constexpr Coordinate3DimensionalAndLength3Dimensional(const Int_& x_, const Int_& y_, const Int_& z_, const Int_& w_, const Int_& h_, const Int_& d_) noexcept
				:x(x_), y(y_), z(z_), w(w_), h(h_), d(d_) {};

			//中身が一致しているか調べる
			constexpr bool operator==(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return range_.x == this->x && range_.y == this->y && range_.z == this->z && range_.w == this->w && range_.h == this->h && range_.d == this->d;
			}
			//中身が不一致か調べる
			constexpr bool operator!=(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return range_.x != this->x || range_.y != this->y || range_.z != this->z || range_.w != this->w || range_.h != this->h || range_.d != this->d;
			}

/*#######################################################################################
	[概要] 体積を比較する。(左の体積値 > 右の体積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator>(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h * this->d) > (range_.w * range_.h * range_.d);
			}
/*#######################################################################################
	[概要] 体積を比較する。(左の体積値 >= 右の体積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator>=(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h * this->d) >= (range_.w * range_.h * range_.d);
			}
/*#######################################################################################
	[概要] 体積を比較する。(左の体積値 < 右の体積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator<(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h * this->d) < (range_.w * range_.h * range_.d);
			}
/*#######################################################################################
	[概要] 体積を比較する。(左の体積値 <= 右の体積値)
	[戻り値] 戻り値の型は bool である。
	[Return value] The return type is bool.
#######################################################################################*/
			constexpr bool operator<=(const ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h * this->d) <= (range_.w * range_.h * range_.d);
			}

		};
		using MatrixRange3D = ::dtl::base::Coordinate3DimensionalAndLength3Dimensional<::dtl::type::size>;

	}
}

#endif //Included Dungeon Template Library