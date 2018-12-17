#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>

//Dungeon Template Library Namespace
namespace dtl {

	template<typename STL_>
	constexpr void dungeonInit(STL_& stl_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				j = 0;
	}

	template<typename Int_, typename STL_>
	constexpr void dungeonInit(STL_& stl_, const Int_ value_) noexcept {
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				j = value_;
	}

	template<typename STL_>
	constexpr void dungeonInit_RangeBasedFor(STL_& stl_) noexcept {
		for (auto&& i : stl_)
			for (auto&& j : i)
				j = 0;
	}

	template<typename Int_, typename STL_>
	constexpr void dungeonInit_RangeBasedFor(STL_& stl_, const Int_ value_) noexcept {
		for (auto&& i : stl_)
			for (auto&& j : i)
				j = value_;
	}

	template<typename STL_>
	constexpr bool dungeonArrayCheckBitset(const STL_& stl_) noexcept {
		if (stl_.size() < 1 || stl_[0].size() < 1) return false;
		const auto& stl_value{ stl_[0][0] };
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (stl_value != stl_[i][j]) return false;
		return true;
	}

	//
	template<typename STL_>
	constexpr bool dungeonArrayCheck(const STL_& stl_) noexcept {
		if (stl_.empty() || stl_.front().empty()) return false;
		const auto& stl_value{ stl_.front().front() };
		for (std::size_t i{}; i < stl_.size(); ++i)
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				if (stl_value != stl_[i][j]) return false;
		return true;
	}

	template<typename STL_>
	constexpr bool dungeonArrayCheck_RangeBasedFor(const STL_& stl_) noexcept {
		if (stl_.empty() || stl_.front().empty()) return false;
		const auto& stl_value{ stl_.front().front() };
		for (const auto& i : stl_)
			for (const auto& j : i)
				if (stl_value != j) return false;
		return true;
	}

}

#endif //Included Dungeon Template Library