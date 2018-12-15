#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	//2ílâªèàóù
	template<typename STL_, typename Int_>
	void dungeonBinarization(STL_& stl_, const Int_ value_) {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (stl_[i][j] >= value_) stl_[i][j] = static_cast<Int_>(1);
				else stl_[i][j] = static_cast<Int_>(0);
			}
	}

	template<typename STL_, typename Int_>
	void dungeonBinarization_RangeBasedFor(STL_& stl_, const Int_ value_) {
		for (auto&& i : stl_)
			for (auto&& j : i) {
				if (j >= value_) j = static_cast<Int_>(1);
				else j = static_cast<Int_>(0);
			}
	}

	template<typename STL_>
	void dungeonBinarization(STL_& stl_) {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (stl_[i][j]) stl_[i][j] = 1;
				else stl_[i][j] = 0;
			}
	}

	template<typename STL_>
	void dungeonBinarization_RangeBasedFor(STL_& stl_) {
		for (auto&& i : stl_)
			for (auto&& j : i) {
				if (j) j = 1;
				else j = 0;
			}
	}

	template<typename STL_, typename STL2_>
	void dungeonBinarizationBool(STL_& stl_, STL2_& stl2_) {
		if (stl_.size() != stl2_.size()) return;
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (stl_[i].size() != stl2_[i].size()) continue;
				if (stl_[i][j]) stl2_[i][j] = true;
				else stl2_[i][j] = false;
			}
	}

	template<typename STL_, typename STL2_, typename Int_>
	void dungeonBinarizationBool(STL_& stl_, STL2_& stl2_, const Int_ value_) {
		if (stl_.size() != stl2_.size()) return;
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (stl_[i].size() != stl2_[i].size()) continue;
				if (stl_[i][j] >= value_) stl2_[i][j] = true;
				else stl2_[i][j] = false;
			}
	}

}

#endif //Included Dungeon Template Library