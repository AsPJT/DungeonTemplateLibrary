#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RANDOM_INNER_RANDOM_VALUE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_RANDOM_INNER_RANDOM_VALUE
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
#include <Utility/Matrix.hpp>
#include <Utility/Copy.hpp>

//STLデータ
namespace dtl::utility::stl {

	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_, const std::size_t inner_length_ = 1) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < matrix_.size() - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < matrix_[row].size() - inner_length_; ++col)
				if (mersenne_twister_32bit.probability()) dtl::utility::tool::castCopyValue(matrix_[row][col], mersenne_twister_32bit(value_min_, value_max_));
	}
	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_, const double probability_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < matrix_.size() - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < matrix_[row].size() - inner_length_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) dtl::utility::tool::castCopyValue(matrix_[row][col] , mersenne_twister_32bit(value_min_,value_max_));
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_ = 1) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability()) dtl::utility::tool::castCopyValue(matrix_[row][col] , mersenne_twister_32bit(value_min_,value_max_));
	}
	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_, const double probability_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) dtl::utility::tool::castCopyValue(matrix_[row][col] , mersenne_twister_32bit(value_min_,value_max_));
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_ = 1) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability()) dtl::utility::tool::castCopyValue(matrix_[row*x_ + col] , mersenne_twister_32bit(value_min_,value_max_));
	}
	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_, const double probability_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) dtl::utility::tool::castCopyValue(matrix_[row*x_ + col] , mersenne_twister_32bit(value_min_,value_max_));
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t layer_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_ = 1) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < matrix_.size() - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < matrix_[row].size() - inner_length_; ++col)
				if (mersenne_twister_32bit.probability()) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_] , mersenne_twister_32bit(value_min_,value_max_));
	}
	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t layer_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_,const std::size_t inner_length_, const double probability_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(matrix_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < matrix_.size() - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < matrix_[row].size() - inner_length_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_] , mersenne_twister_32bit(value_min_,value_max_));
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_, const std::size_t inner_length_ = 1) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability()) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], mersenne_twister_32bit(value_min_, value_max_));
	}
	template<typename Matrix_>
	constexpr void randomInnerRandomValue(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const std::int_fast32_t value_min_, const std::int_fast32_t value_max_, const std::size_t inner_length_, const double probability_) noexcept {
		if (dtl::utility::tool::isMatrixEmpty(x_, y_)) return;

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{ inner_length_ }; row < y_ - inner_length_; ++row)
			for (std::size_t col{ inner_length_ }; col < x_ - inner_length_; ++col)
				if (mersenne_twister_32bit.probability(probability_)) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], mersenne_twister_32bit(value_min_, value_max_));
	}

} //namespace

#endif //Included Dungeon Template Library