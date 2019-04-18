#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RANDOM_BOOL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RANDOM_BOOL
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>

//STLデータ
namespace dtl::utility::stl {

	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (mersenne_twister_32bit.probability()) matrix_[row][col] = 1;
	}
	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const double probability_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = 1;
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability()) matrix_[row][col] = 1;
	}
	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = 1;
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability()) matrix_[row*x_ + col] = 1;
	}
	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) matrix_[row*x_ + col] = 1;
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t layer_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (mersenne_twister_32bit.probability()) matrix_[row][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t layer_, const double probability_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col)
				if (mersenne_twister_32bit.probability(probability_)) matrix_[row][col][layer_] = 1;
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability()) matrix_[row][col][layer_] = 1;
	}
	template<typename Matrix_>
	constexpr void randomBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double probability_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < x_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) matrix_[row][col][layer_] = 1;
	}

} //namespace

#endif //Included Dungeon Template Library