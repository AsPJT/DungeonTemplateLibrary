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
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row * x_ + col];
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const Matrix_& matrix_) noexcept {
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << col;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				std::cout << matrix_[row][col] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row][col] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col)
				std::cout << matrix_[row * x_ + col] << string_;
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonNumberOutput_RangeBasedFor(const Matrix_& matrix_, const char* const string_) noexcept {
		if (string_ == nullptr) return;
		for (const auto& row : matrix_) {
			for (const auto& col : row)
				std::cout << col << string_;
			std::cout << std::endl;
		}
	}

	template<typename Matrix_>
	constexpr void dungeonStringOutputHalfBool(const Matrix_& matrix_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{ matrix_[row].size() / 2 }; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			for (std::size_t col{}; col < matrix_[row].size() / 2; ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}


	//文字出力
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool(const Matrix_& matrix_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row][col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool_Array(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (std::size_t row{}; row < y_; ++row) {
			for (std::size_t col{}; col < x_; ++col) {
				if (matrix_[row * x_ + col]) std::cout << true_;
				else std::cout << false_;
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_>
	constexpr void dungeonStringOutputBool_RangeBasedFor(const Matrix_& matrix_, const char* const true_, const char* const false_) noexcept {
		if (true_ == nullptr || false_ == nullptr) return;
		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if (col) std::cout << true_;
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

		for (std::size_t row{}; row < matrix_.size(); ++row) {
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if ((std::size_t)matrix_[row][col] >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)matrix_[row][col])];
			}
			std::cout << std::endl;
		}
	}
	template<typename Matrix_, typename First_, typename ...Args_>
	void dungeonStringOutput_RangeBasedFor(const Matrix_& matrix_, const First_& first_, const Args_&... args_) noexcept {
		std::vector<std::string> string_vector;
		string_vector.emplace_back(std::string(first_));
		dungeonStringOutput_String(string_vector, args_...);

		for (const auto& row : matrix_) {
			for (const auto& col : row) {
				if ((std::size_t)col >= string_vector.size()) continue;
				std::cout << string_vector[((std::size_t)col)];
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