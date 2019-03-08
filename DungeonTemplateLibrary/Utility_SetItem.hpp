#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_SET_ITEM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_SET_ITEM
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <vector>
#include <utility>
#include <algorithm>

//STLデータ
namespace dtl::utility::stl {

	template<typename Matrix_Int_, typename Matrix_>
	bool setItem(Matrix_& matrix_, const std::size_t n_, const Matrix_Int_ set_value_ = 2, const Matrix_Int_ clear_value_ = 1) noexcept {
		if (n_ == 0) return true;
		std::vector<std::pair<std::size_t, std::size_t>> value_pairs{};

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row][col] == clear_value_) value_pairs.emplace_back(std::make_pair(row, col));
		if (value_pairs.size() == 0) return false;
		value_pairs.shrink_to_fit();

		if (n_ >= value_pairs.size()) {
			for (auto&& i : value_pairs)
				matrix_[i.first][i.second] = set_value_;
			return true;
		}

		std::size_t index{ static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size()))) };
		for (std::size_t modify_count{}; modify_count < n_; ++modify_count) {

			const auto& [modify_y, modify_x] {value_pairs[index]};
			if (matrix_[modify_y][modify_x] != clear_value_) return false;

			matrix_[modify_y][modify_x] = set_value_;
			value_pairs.erase(std::remove(value_pairs.begin(), value_pairs.end(), value_pairs[index]), value_pairs.end());

			if (value_pairs.size() == 0) break;
			index = static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size())));
		}
		return true;
	}

} //namespace

namespace dtl::utility::normal {

	template<typename Matrix_Int_, typename Matrix_>
	bool setItem(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t n_, const Matrix_Int_ set_value_ = 2, const Matrix_Int_ clear_value_ = 1) noexcept {
		if (n_ == 0) return true;
		std::vector<std::pair<std::size_t, std::size_t>> value_pairs{};

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row][col] == clear_value_) value_pairs.emplace_back(std::make_pair(row, col));
		if (value_pairs.size() == 0) return false;
		value_pairs.shrink_to_fit();

		if (n_ >= value_pairs.size()) {
			for (auto&& i : value_pairs)
				matrix_[i.first][i.second] = set_value_;
			return true;
		}

		std::size_t index{ static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size()))) };
		for (std::size_t modify_count{}; modify_count < n_; ++modify_count) {

			const auto& [modify_y, modify_x] {value_pairs[index]};
			if (matrix_[modify_y][modify_x] != clear_value_) return false;

			matrix_[modify_y][modify_x] = set_value_;
			value_pairs.erase(std::remove(value_pairs.begin(), value_pairs.end(), value_pairs[index]), value_pairs.end());

			if (value_pairs.size() == 0) break;
			index = static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size())));
		}
		return true;
	}

} //namespace

namespace dtl::utility::array {

	template<typename Matrix_Int_, typename Matrix_>
	bool setItem(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t n_, const Matrix_Int_ set_value_ = 2, const Matrix_Int_ clear_value_ = 1) noexcept {
		if (n_ == 0) return true;
		std::vector<std::pair<std::size_t, std::size_t>> value_pairs{};

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row*x_+col] == clear_value_) value_pairs.emplace_back(std::make_pair(row, col));
		if (value_pairs.size() == 0) return false;
		value_pairs.shrink_to_fit();

		if (n_ >= value_pairs.size()) {
			for (auto&& i : value_pairs)
				matrix_[i.first*x_+i.second] = set_value_;
			return true;
		}

		std::size_t index{ static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size()))) };
		for (std::size_t modify_count{}; modify_count < n_; ++modify_count) {

			const auto& [modify_y, modify_x] {value_pairs[index]};
			if (matrix_[modify_y*x_+modify_x] != clear_value_) return false;

			matrix_[modify_y*x_+modify_x] = set_value_;
			value_pairs.erase(std::remove(value_pairs.begin(), value_pairs.end(), value_pairs[index]), value_pairs.end());

			if (value_pairs.size() == 0) break;
			index = static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size())));
		}
		return true;
	}

} //namespace

namespace dtl::utility::layer::stl {

	template<typename Matrix_Int_, typename Matrix_>
	bool setItem(Matrix_& matrix_, const std::size_t layer_, const std::size_t n_, const Matrix_Int_ set_value_ = 2, const Matrix_Int_ clear_value_ = 1) noexcept {
		if (n_ == 0) return true;
		std::vector<std::pair<std::size_t, std::size_t>> value_pairs{};

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (matrix_[row][col][layer_] == clear_value_) value_pairs.emplace_back(std::make_pair(row, col));
		if (value_pairs.size() == 0) return false;
		value_pairs.shrink_to_fit();

		if (n_ >= value_pairs.size()) {
			for (auto&& i : value_pairs)
				matrix_[i.first][i.second][layer_] = set_value_;
			return true;
		}

		std::size_t index{ static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size()))) };
		for (std::size_t modify_count{}; modify_count < n_; ++modify_count) {

			const auto& [modify_y, modify_x] {value_pairs[index]};
			if (matrix_[modify_y][modify_x][layer_] != clear_value_) return false;

			matrix_[modify_y][modify_x][layer_] = set_value_;
			value_pairs.erase(std::remove(value_pairs.begin(), value_pairs.end(), value_pairs[index]), value_pairs.end());

			if (value_pairs.size() == 0) break;
			index = static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size())));
		}
		return true;
	}

} //namespace

namespace dtl::utility::layer::normal {

	template<typename Matrix_Int_, typename Matrix_>
	bool setItem(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::size_t n_, const Matrix_Int_ set_value_ = 2, const Matrix_Int_ clear_value_ = 1) noexcept {
		if (n_ == 0) return true;
		std::vector<std::pair<std::size_t, std::size_t>> value_pairs{};

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (matrix_[row][col][layer_] == clear_value_) value_pairs.emplace_back(std::make_pair(row, col));
		if (value_pairs.size() == 0) return false;
		value_pairs.shrink_to_fit();

		if (n_ >= value_pairs.size()) {
			for (auto&& i : value_pairs)
				matrix_[i.first][i.second][layer_] = set_value_;
			return true;
		}

		std::size_t index{ static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size()))) };
		for (std::size_t modify_count{}; modify_count < n_; ++modify_count) {

			const auto& [modify_y, modify_x] {value_pairs[index]};
			if (matrix_[modify_y][modify_x][layer_] != clear_value_) return false;

			matrix_[modify_y][modify_x][layer_] = set_value_;
			value_pairs.erase(std::remove(value_pairs.begin(), value_pairs.end(), value_pairs[index]), value_pairs.end());

			if (value_pairs.size() == 0) break;
			index = static_cast<std::size_t>(dtl::random::mersenne_twister_32bit(static_cast<std::int_fast32_t>(value_pairs.size())));
		}
		return true;
	}

} //namespace

#endif //Included Dungeon Template Library