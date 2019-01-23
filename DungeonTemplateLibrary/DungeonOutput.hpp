#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_OUTPUT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

//Dungeon Template Library Namespace
namespace dtl {
	//数値出力
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				std::cout << matrix_[i][j];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j)
				std::cout << matrix_[i][j];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j)
				std::cout << matrix_[i * x_ + j];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const Matrix_& matrix_) noexcept {
		for (const auto& i : matrix_) {
			for (const auto& j : i)
				std::cout << j;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				std::cout << matrix_[i][j] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j)
				std::cout << matrix_[i][j] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j)
				std::cout << matrix_[i * x_ + j] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const Matrix_& matrix_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (const auto& i : matrix_) {
			for (const auto& j : i)
				std::cout << j << string_;
			std::cout << std::endl;
		}
	}
	//文字出力
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool(const Matrix_& matrix_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if (matrix_[i][j]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j) {
				if (matrix_[i][j]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t i{}; i < y_; ++i) {
			for (std::size_t j{}; j < x_; ++j) {
				if (matrix_[i * x_ + j]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool_RangeBasedFor(const Matrix_& matrix_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (const auto& i : matrix_) {
			for (const auto& j : i) {
				if (j) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}

	bool dungeonStringOutput_String(std::vector<std::string>& string_) noexcept { return string_.empty(); }
	template<typename First_, typename ...Args_>
	constexpr void dungeonStringOutput_String(std::vector<std::string>& string_vector_, const First_& first_, const Args_&... args_) noexcept {
		string_vector_.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector_, args_...);
	}
	template<typename Matrix_, typename First_, typename ...Args_>
	void dungeonStringOutput(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {
		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector, args_...);

		for (std::size_t i{}; i < matrix_.size(); ++i) {
			for (std::size_t j{}; j < matrix_[i].size(); ++j) {
				if ((std::size_t)matrix_[i][j] >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)matrix_[i][j])];
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_, typename First_, typename ...Args_>
	void dungeonStringOutput_RangeBasedFor(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {
		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector, args_...);

		for (const auto& i : matrix_) {
			for (const auto& j : i) {
				if ((std::size_t)j >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)j)];
			}
			std::cout << std::endl;
		}
	}

	void dungeonEndl() noexcept {
		std::cout << std::endl;
	}
	void dungeonPuts(const char* const str_) noexcept {
		if (str_ == nullptr) return;
		std::cout << str_ << std::endl;
	}


}

#endif //Included Dungeon Template Library