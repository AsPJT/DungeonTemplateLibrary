#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_TERRAIN1
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_TERRAIN1
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Int_>
	class SimpleTerrain1 {
	public:
		//コンストラクタ
		constexpr SimpleTerrain1() noexcept = default;
		template<typename STL_>
		constexpr explicit SimpleTerrain1(STL_& stl_, const Int_ v1_, const std::size_t v2_ = 2) noexcept {
			create(stl_, v1_, v2_);
		}
		template<typename STL_>
		constexpr void create(STL_& stl_, const Int_ v1_, const std::size_t v2_ = 2) noexcept {

			for (std::size_t i{}; i < stl_.size(); i += v2_) {
				for (std::size_t j{}; j < stl_[i].size(); j += v2_) {
					stl_[i][j] = static_cast<Int_>(v1_);
				}
			}

		}


	};

}

#endif //Included Dungeon Template Library