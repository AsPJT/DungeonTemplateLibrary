#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {
	namespace utility {


		namespace rangeBasedFor {

			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (auto&& row : matrix_)
					for (auto&& col : row) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (col) col = false_tile_;
						else col = true_tile_;
					}
			}

		}

		namespace stl {

			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{}; row < matrix_.size(); ++row)
					for (std::size_t col{}; col < matrix_[row].size(); ++col) {
						if (!mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}

			//ノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						if ((matrix_[row][col] == matrix_[row][col - 1] && matrix_[row][col] == matrix_[row - 1][col]) || mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						if ((matrix_[row - 1][col - 1] == matrix_[row][col - 1] && matrix_[row - 1][col - 1] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_& matrix_, const double rbool_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_, rbool_);
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_& matrix_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_, rbool1_);
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool2_);
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_& matrix_, const double rbool_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool_);
				dtl::utility::stl::noiseShoreBool(matrix_, rbool_);
			}
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_& matrix_, const double rbool1_, const double rbool2_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_, rbool1_);
				dtl::utility::stl::noiseShoreBool(matrix_, rbool2_);
			}

			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShore(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						if ((matrix_[row][col] == matrix_[row][col - 1] && matrix_[row][col] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShore(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						if ((matrix_[row - 1][col - 1] == matrix_[row][col - 1] && matrix_[row - 1][col - 1] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShoreOver(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						if ((matrix_[row][col] == matrix_[row][col - 1] && matrix_[row][col] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col] >= true_tile_) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShoreOver(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						if ((matrix_[row - 1][col - 1] == matrix_[row][col - 1] && matrix_[row - 1][col - 1] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row - 1][col - 1] >= true_tile_) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

		}



	} //namespace
}

#endif //Included Dungeon Template Library