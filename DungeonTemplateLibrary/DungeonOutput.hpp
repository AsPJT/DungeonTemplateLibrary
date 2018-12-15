#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <string>

//Dungeon Template Library Namespace
namespace dtl {
	//数値出力
	template<typename STL_>
	constexpr void dungeonNumberOutput(const STL_& stl_) {
		for (std::size_t i{}; i < stl_.size(); ++i) {
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				std::cout << stl_[i][j];
			std::cout << std::endl;
		}
	}
	template<typename STL_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const STL_& stl_) {
		for (const auto& i : stl_) {
			for (const auto& j : i)
				std::cout << j;
			std::cout << std::endl;
		}
	}
	template<typename STL_>
	constexpr void dungeonNumberOutput(const STL_& stl_, const char* const string_) {
		if (string_ == nullptr) return;
		for (std::size_t i{}; i < stl_.size(); ++i) {
			for (std::size_t j{}; j < stl_[i].size(); ++j)
				std::cout << stl_[i][j] << string_;
			std::cout << std::endl;
		}
	}
	template<typename STL_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const STL_& stl_, const char* const string_) {
		if (string_ == nullptr) return;
		for (const auto& i : stl_) {
			for (const auto& j : i)
				std::cout << j << string_;
			std::cout << std::endl;
		}
	}
	//文字出力
	template<typename STL_>
	constexpr void dungeonStringOutputBool(const STL_& stl_, const char* const true_, const char* const false_) {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t i{}; i < stl_.size(); ++i) {
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if (stl_[i][j]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename STL_>
	constexpr void dungeonStringOutputBool_RangeBasedFor(const STL_& stl_, const char* const true_, const char* const false_) {
		if (true_ == nullptr || false_ == nullptr) return;
		for (const auto& i : stl_) {
			for (const auto& j : i) {
				if (j) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}

	bool dungeonStringOutput_String(std::vector<std::string>& string_) { return string_.empty(); }
	template<typename First_, typename ...Args_>
	constexpr void dungeonStringOutput_String(std::vector<std::string>& string_vector_, const First_& first_, const Args_&... args_) {
		string_vector_.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector_, args_...);
	}
	template<typename STL_, typename First_, typename ...Args_>
	void dungeonStringOutput(const STL_& stl_, const First_& first_, const Args_&... args_) {
		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector, args_...);

		for (std::size_t i{}; i < stl_.size(); ++i) {
			for (std::size_t j{}; j < stl_[i].size(); ++j) {
				if ((std::size_t)stl_[i][j] >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)stl_[i][j])];
			}
			std::cout << std::endl;
		}
	}
	template<typename STL_, typename First_, typename ...Args_>
	void dungeonStringOutput_RangeBasedFor(const STL_& stl_, const First_& first_, const Args_&... args_) {
		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector, args_...);

		for (const auto& i : stl_) {
			for (const auto& j : i) {
				if ((std::size_t)j >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)j)];
			}
			std::cout << std::endl;
		}
	}



}

#endif //Included Dungeon Template Library