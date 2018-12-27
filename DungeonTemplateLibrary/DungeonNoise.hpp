#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Int_, typename STL_>
	constexpr void noiseBool(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (!rnd.randBool(rbool_)) continue;
				if (stl_[i][j]) stl_[i][j] = false_tile_;
				else stl_[i][j] = true_tile_;
			}
	}

	template<typename Int_, typename STL_>
	constexpr void noiseBool_RangeBasedFor(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (auto&& i : stl_)
			for (auto&& j : i) {
				if (!rnd.randBool(rbool_)) continue;
				if (j) j = false_tile_;
				else j = true_tile_;
			}
	}

	//ノイズを発生させる
	template<typename STL_>
	constexpr void noiseShoreBool(STL_& stl_, const double rbool_) noexcept {
		for (std::size_t i{ 1 }; i < stl_.size(); ++i)
			for (std::size_t j{ 1 }; j < stl_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (stl_[i][j] == stl_[i][j - 1] && stl_[i][j] == stl_[i - 1][j])) continue;
				if (stl_[i][j]) stl_[i][j] = false;
				else stl_[i][j] = true;
			}
	}
	template<typename STL_>
	constexpr void rnoiseShoreBool(STL_& stl_, const double rbool_) noexcept {
		for (std::size_t i{ stl_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ stl_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (stl_[i - 1][j - 1] == stl_[i][j - 1] && stl_[i - 1][j - 1] == stl_[i - 1][j])) continue;
				if (stl_[i - 1][j - 1]) stl_[i - 1][j - 1] = false;
				else stl_[i - 1][j - 1] = true;
			}
	}

	template<typename STL_>
	constexpr void noiseShoreBothBool(STL_& stl_, const double rbool_) noexcept {
		noiseShoreBool(stl_, rbool_);
		rnoiseShoreBool(stl_, rbool_);
	}
	template<typename STL_>
	constexpr void noiseShoreBothBool(STL_& stl_, const double rbool1_, const double rbool2_) noexcept {
		noiseShoreBool(stl_, rbool1_);
		rnoiseShoreBool(stl_, rbool2_);
	}
	template<typename STL_>
	constexpr void rnoiseShoreBothBool(STL_& stl_, const double rbool_) noexcept {
		rnoiseShoreBool(stl_, rbool_);
		noiseShoreBool(stl_, rbool_);
	}
	template<typename STL_>
	constexpr void rnoiseShoreBothBool(STL_& stl_, const double rbool1_, const double rbool2_) noexcept {
		rnoiseShoreBool(stl_, rbool1_);
		noiseShoreBool(stl_, rbool2_);
	}

	template<typename Int_, typename STL_>
	constexpr void noiseShore(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ 1 }; i < stl_.size(); ++i)
			for (std::size_t j{ 1 }; j < stl_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (stl_[i][j] == stl_[i][j - 1] && stl_[i][j] == stl_[i - 1][j])) continue;
				if (stl_[i][j]) stl_[i][j] = false_tile_;
				else stl_[i][j] = true_tile_;
			}
	}
	template<typename Int_, typename STL_>
	constexpr void rnoiseShore(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ stl_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ stl_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (stl_[i - 1][j - 1] == stl_[i][j - 1] && stl_[i - 1][j - 1] == stl_[i - 1][j])) continue;
				if (stl_[i - 1][j - 1]) stl_[i - 1][j - 1] = false_tile_;
				else stl_[i - 1][j - 1] = true_tile_;
			}
	}

	template<typename Int_, typename STL_>
	constexpr void noiseShoreOver(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ 1 }; i < stl_.size(); ++i)
			for (std::size_t j{ 1 }; j < stl_[i].size(); ++j) {
				if (!rnd.randBool(rbool_) || (stl_[i][j] == stl_[i][j - 1] && stl_[i][j] == stl_[i - 1][j])) continue;
				if (stl_[i][j] >= true_tile_) stl_[i][j] = false_tile_;
				else stl_[i][j] = true_tile_;
			}
	}
	template<typename Int_, typename STL_>
	constexpr void rnoiseShoreOver(STL_& stl_, const double rbool_, const Int_ true_tile_ = 1, const Int_ false_tile_ = 0) noexcept {
		for (std::size_t i{ stl_.size() - 1 }; i >= 1; --i)
			for (std::size_t j{ stl_[i].size() - 1 }; j >= 1; --j) {
				if (!rnd.randBool(rbool_) || (stl_[i - 1][j - 1] == stl_[i][j - 1] && stl_[i - 1][j - 1] == stl_[i - 1][j])) continue;
				if (stl_[i - 1][j - 1] >= true_tile_) stl_[i - 1][j - 1] = false_tile_;
				else stl_[i - 1][j - 1] = true_tile_;
			}
	}

}

#endif //Included Dungeon Template Library