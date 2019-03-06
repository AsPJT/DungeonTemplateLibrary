#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_BOOL
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_BOOL
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */

#include <cstddef>
#include "Random_MersenneTwister32bit.hpp"

//STLデータ
namespace dtl::utility::stl {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (matrix_[row][col]) matrix_[row][col] = false;
				else matrix_[row][col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col]) matrix_[row][col] = false;
				else matrix_[row][col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col]) matrix_[row][col] = false_tile_;
				else matrix_[row][col] = true_tile_;
			}
	}

} //namespace

//通常データ
namespace dtl::utility::normal {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (matrix_[row][col]) matrix_[row][col] = false;
				else matrix_[row][col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col]) matrix_[row][col] = false;
				else matrix_[row][col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col]) matrix_[row][col] = false_tile_;
				else matrix_[row][col] = true_tile_;
			}
	}

} //namespace

//配列データ
namespace dtl::utility::array {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (matrix_[row * x_ + col]) matrix_[row * x_ + col] = false;
				else matrix_[row * x_ + col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row * x_ + col]) matrix_[row * x_ + col] = false;
				else matrix_[row * x_ + col] = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row * x_ + col]) matrix_[row * x_ + col] = false_tile_;
				else matrix_[row * x_ + col] = true_tile_;
			}
	}

} //namespace

//範囲forデータ
namespace dtl::utility::rangeBasedFor {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (col) col = false;
				else col = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (col) col = false;
				else col = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (auto&& row : matrix_)
			for (auto&& col : row) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (col) col = false_tile_;
				else col = true_tile_;
			}
	}

} //namespace

//レイヤーSTLデータ
namespace dtl::utility::layer::stl {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
				else matrix_[row][col][layer_] = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
				else matrix_[row][col][layer_] = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < matrix_.size(); ++row)
			for (std::size_t col{}; col < matrix_[row].size(); ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false_tile_;
				else matrix_[row][col][layer_] = true_tile_;
			}
	}

} //namespace

//レイヤー通常データ
namespace dtl::utility::layer::normal {

	//1/2の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability()) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
				else matrix_[row][col][layer_] = true;
			}
	}

	//[rbool_]の確率でマップデータの値をbit反転させる
	template<typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
				else matrix_[row][col][layer_] = true;
			}
	}

	//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

		using dtl::random::mersenne_twister_32bit;

		for (std::size_t row{}; row < y_; ++row)
			for (std::size_t col{}; col < y_; ++col) {
				if (!mersenne_twister_32bit.probability(rbool_)) continue;
				if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false_tile_;
				else matrix_[row][col][layer_] = true_tile_;
			}
	}

} //namespace

#endif //Included Dungeon Template Library