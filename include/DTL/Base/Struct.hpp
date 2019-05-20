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

namespace dtl {
	inline namespace base {


		template<typename Int_>
		struct Coordinate1Dimensional {
			Int_ x{};
			constexpr Coordinate1Dimensional() = default;
			constexpr Coordinate1Dimensional(const Int_& x_) noexcept :x(x_) {};
		};

		template<typename Int_>
		struct Coordinate2Dimensional {
			Int_ x{};
			Int_ y{};
			constexpr Coordinate2Dimensional() = default;
			constexpr Coordinate2Dimensional(const Int_& x_, const Int_& y_) noexcept :x(x_), y(y_) {};

			constexpr bool operator==(const ::dtl::base::Coordinate2Dimensional<Int_>& vec2_) const noexcept {
				return vec2_.x == this->x && vec2_.y == this->y;
			}
			constexpr bool operator!=(const ::dtl::base::Coordinate2Dimensional<Int_>& vec2_) const noexcept {
				return vec2_.x != this->x || vec2_.y != this->y;
			}
		};
		using MatrixVec2 = Coordinate2Dimensional<::dtl::type::size>;

		//座標と幅
		template<typename Int_>
		struct Coordinate2DimensionalAndLength2Dimensional {
			Int_ x{};
			Int_ y{};
			Int_ w{};
			Int_ h{};
			constexpr Coordinate2DimensionalAndLength2Dimensional() = default;
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

			//面積比較
			constexpr bool operator>(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) > (range_.w * range_.h);
			}
			constexpr bool operator>=(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) >= (range_.w * range_.h);
			}
			constexpr bool operator<(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) < (range_.w * range_.h);
			}
			constexpr bool operator<=(const ::dtl::base::Coordinate2DimensionalAndLength2Dimensional<Int_>& range_) const noexcept {
				return (this->w * this->h) <= (range_.w * range_.h);
			}

		};
		using MatrixRange = Coordinate2DimensionalAndLength2Dimensional<::dtl::type::size>;

	}
}

#endif //Included Dungeon Template Library