/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BASE_STRUCT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_BASE_STRUCT_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>

namespace dtl {
	inline namespace base {


		template<typename Int_>
		struct Coordinate1Dimensional {
			Int_ x{};
			constexpr Coordinate1Dimensional() noexcept = default;
			constexpr Coordinate1Dimensional(const Int_& x_) noexcept :x(x_) {};
		};

		template<typename Int_>
		struct Coordinate2Dimensional {
			Int_ x{};
			Int_ y{};
			constexpr Coordinate2Dimensional() noexcept = default;
			constexpr Coordinate2Dimensional(const Int_& x_, const Int_& y_) noexcept :x(x_), y(y_) {};
		};

		//座標と幅
		template<typename Int_>
		struct Coordinate2DimensionalAndLength2Dimensional {
			Int_ x{};
			Int_ y{};
			Int_ w{};
			Int_ h{};
			constexpr Coordinate2DimensionalAndLength2Dimensional() noexcept = default;
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_) noexcept
				:x(x_), y(y_) {};
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_, const Int_& l_) noexcept
				:x(x_), y(y_), w(l_), h(l_) {};
			constexpr Coordinate2DimensionalAndLength2Dimensional(const Int_& x_, const Int_& y_, const Int_& w_, const Int_& h_) noexcept
				:x(x_), y(y_), w(w_), h(h_) {};
		};
		using MatrixRange = Coordinate2DimensionalAndLength2Dimensional<std::size_t>;

	}
}

#endif //Included Dungeon Template Library