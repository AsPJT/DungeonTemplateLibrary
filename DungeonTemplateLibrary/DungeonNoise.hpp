#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename STL_, typename Int_>
	constexpr void noiseBool(STL_& vec_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) {
		for (auto&& i : vec_)
			for (auto&& j : i) {
				if (!rnd.randBool(rbool_)) continue;
				if (j) j = false_tile_;
				else j = true_tile_;
			}
	}

	//ÉmÉCÉYÇî≠ê∂Ç≥ÇπÇÈ
	template<typename STL_>
	constexpr void noiseShoreBool(STL_& vec_, const double rbool_) {
		for (std::size_t i{ 1 }; i < vec_.size(); ++i)
			for (std::size_t j{ 1 }; j < vec_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (vec_[i][j] == vec_[i][j - 1] && vec_[i][j] == vec_[i - 1][j])) continue;
				if (vec_[i][j]) vec_[i][j] = false;
				else vec_[i][j] = true;
			}
	}
	template<typename STL_, typename Int_>
	constexpr void noiseShore(STL_& vec_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) {
		for (std::size_t i{ 1 }; i < vec_.size(); ++i)
			for (std::size_t j{ 1 }; j < vec_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (vec_[i][j] == vec_[i][j - 1] && vec_[i][j] == vec_[i - 1][j])) continue;
				if (vec_[i][j]) vec_[i][j] = false_tile_;
				else vec_[i][j] = true_tile_;
			}
	}
}

#endif //Included Dungeon Template Library