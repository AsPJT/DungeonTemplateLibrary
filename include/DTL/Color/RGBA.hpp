/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_RGBA_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_RGBA_HPP

#include <DTL/Macros/constexpr.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace color { //"dtl::color"名前空間に属する

		//座標と幅
		template<typename Int_>
		struct RGBA {
			Int_ r{};
			Int_ g{};
			Int_ b{};
			Int_ a{};
			RGBA() = default;
			constexpr RGBA(const Int_& rgb_) noexcept
				:r(rgb_), g(rgb_), b(rgb_) {};
			constexpr RGBA(const Int_& rgb_, const Int_& a_) noexcept
				:r(rgb_), g(rgb_), b(rgb_), a(a_) {};
			constexpr RGBA(const Int_& r_, const Int_& g_, const Int_& b_) noexcept
				:r(r_), g(g_), b(b_) {};
			constexpr RGBA(const Int_& r_, const Int_& g_, const Int_& b_, const Int_& a_) noexcept
				:r(r_), g(g_), b(b_), a(a_) {};

			//中身が一致しているか調べる
			constexpr bool operator==(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return range_.r == this->r && range_.g == this->g && range_.b == this->b && range_.a == this->a;
			}
			//中身が不一致か調べる
			constexpr bool operator!=(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return range_.r != this->r || range_.g != this->g || range_.b != this->b || range_.a != this->a;
			}

			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator+=(const Int_& add_) noexcept {
				this->r += add_;
				this->g += add_;
				this->b += add_;
				this->a += add_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator-=(const Int_& sub_) noexcept {
				this->r -= sub_;
				this->g -= sub_;
				this->b -= sub_;
				this->a -= sub_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator*=(const Int_& mul_) noexcept {
				this->r *= mul_;
				this->g *= mul_;
				this->b *= mul_;
				this->a *= mul_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator/=(const Int_& div_) noexcept {
				this->r /= div_;
				this->g /= div_;
				this->b /= div_;
				this->a /= div_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator%=(const Int_& mod_) noexcept {
				this->r %= mod_;
				this->g %= mod_;
				this->b %= mod_;
				this->a %= mod_;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator+=(const ::dtl::color::RGBA<Int_>& add_) noexcept {
				this->r += add_.r;
				this->g += add_.g;
				this->b += add_.b;
				this->a += add_.a;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator-=(const ::dtl::color::RGBA<Int_>& sub_) noexcept {
				this->r -= sub_.r;
				this->g -= sub_.g;
				this->b -= sub_.b;
				this->a -= sub_.a;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator*=(const ::dtl::color::RGBA<Int_>& mul_) noexcept {
				this->r *= mul_.r;
				this->g *= mul_.g;
				this->b *= mul_.b;
				this->a *= mul_.a;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator/=(const ::dtl::color::RGBA<Int_>& div_) noexcept {
				this->r /= div_.r;
				this->g /= div_.g;
				this->b /= div_.b;
				this->a /= div_.a;
				return *this;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				const RGBA& operator%=(const ::dtl::color::RGBA<Int_>& mod_) noexcept {
				this->r %= mod_.r;
				this->g %= mod_.g;
				this->b %= mod_.b;
				this->a %= mod_.a;
				return *this;
			}

			constexpr bool operator>(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return (this->a) > (range_.a);
			}
			constexpr bool operator>=(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return (this->a) >= (range_.a);
			}
			constexpr bool operator<(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return (this->a) < (range_.a);
			}
			constexpr bool operator<=(const ::dtl::color::RGBA<Int_>& range_) const noexcept {
				return (this->a) <= (range_.a);
			}

		};

	}
}

#endif //Included Dungeon Template Library