/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_BOOL_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_UTILITY_NOISE_BOOL_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>
#include <Utility/Copy.hpp>

//STLデータ
namespace dtl {
	inline namespace utility {
		namespace stl {

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
			template<typename True_Int_, typename False_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) dtl::utility::tool::castCopyValue(matrix_[row][col], false_tile_);
						else dtl::utility::tool::castCopyValue(matrix_[row][col], true_tile_);
					}
			}

		} //namespace

		//通常データ
		namespace normal {

			//1/2の確率でマップデータの値をbit反転させる
			template<typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const std::size_t, const std::size_t y_) noexcept {

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
			constexpr void noiseBool(Matrix_& matrix_, const std::size_t, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < y_; ++row)
					for (std::size_t col{}; col < y_; ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename True_Int_, typename False_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const std::size_t, const std::size_t y_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < y_; ++row)
					for (std::size_t col{}; col < y_; ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) dtl::utility::tool::castCopyValue(matrix_[row][col], false_tile_);
						else dtl::utility::tool::castCopyValue(matrix_[row][col], true_tile_);
					}
			}

		} //namespace

		//配列データ
		namespace array {

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
			constexpr void noiseBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < y_; ++row)
					for (std::size_t col{}; col < y_; ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row * x_ + col]) matrix_[row * x_ + col] = false;
						else matrix_[row * x_ + col] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename True_Int_, typename False_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_ & matrix_, const std::size_t x_, const std::size_t y_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < y_; ++row)
					for (std::size_t col{}; col < y_; ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row * x_ + col]) dtl::utility::tool::castCopyValue(matrix_[row * x_ + col], false_tile_);
						else dtl::utility::tool::castCopyValue(matrix_[row * x_ + col], true_tile_);
					}
			}

		} //namespace

		//範囲forデータ
		namespace rangeBasedFor {

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
			template<typename True_Int_, typename False_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (auto&& row : matrix_)
					for (auto&& col : row) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (col) dtl::utility::tool::castCopyValue(col, false_tile_);
						else dtl::utility::tool::castCopyValue(col, true_tile_);
					}
			}

		} //namespace

		//レイヤーSTLデータ
		namespace layer {
			namespace stl {

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
				template<typename True_Int_, typename False_Int_, typename Matrix_>
				constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;

					for (std::size_t row{}; row < matrix_.size(); ++row)
						for (std::size_t col{}; col < matrix_[row].size(); ++col) {
							if (!mersenne_twister_32bit.probability(rbool_)) continue;
							if (matrix_[row][col][layer_]) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], false_tile_);
							else dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], true_tile_);
						}
				}

			} //namespace
		}

		//レイヤー通常データ
		namespace layer {
			namespace normal {

				//1/2の確率でマップデータの値をbit反転させる
				template<typename Matrix_>
				constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t, const std::size_t y_) noexcept {

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
				constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t, const std::size_t y_, const double rbool_) noexcept {

					using dtl::random::mersenne_twister_32bit;

					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < y_; ++col) {
							if (!mersenne_twister_32bit.probability(rbool_)) continue;
							if (matrix_[row][col][layer_]) matrix_[row][col][layer_] = false;
							else matrix_[row][col][layer_] = true;
						}
				}

				//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
				template<typename True_Int_, typename False_Int_, typename Matrix_>
				constexpr void noiseBool(Matrix_& matrix_, const std::size_t layer_, const std::size_t, const std::size_t y_, const double rbool_, const True_Int_ true_tile_, const False_Int_ false_tile_ = 0) noexcept {

					using dtl::random::mersenne_twister_32bit;

					for (std::size_t row{}; row < y_; ++row)
						for (std::size_t col{}; col < y_; ++col) {
							if (!mersenne_twister_32bit.probability(rbool_)) continue;
							if (matrix_[row][col][layer_]) dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], false_tile_);
							else dtl::utility::tool::castCopyValue(matrix_[row][col][layer_], true_tile_);
						}
				}

			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library