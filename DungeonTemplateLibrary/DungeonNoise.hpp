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

//--------------------
//noiseBool関数
//--------------------

namespace dtl {
	namespace utility {
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
	}
}

namespace dtl {
	namespace utility {
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
	}
}

//--------------------
//noise_tool
//--------------------

namespace dtl {
	namespace utility {
		namespace tool {


			//noiseShoreBool関数から取得したマップデータの値を1/2の確率でノイズさせるか判定する
			template<typename Matrix_Int_>
			constexpr bool isNoise_noiseShoreBool(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				return (value_ != value2_ || value_ != value3_) && mersenne_twister_32bit.probability();
			}
			//noiseShoreBool関数から取得したマップデータの値を[rbool_]の確率でノイズさせるか判定する
			template<typename Matrix_Int_>
			constexpr bool isNoise_noiseShoreBool(const Matrix_Int_ value_, const Matrix_Int_ value2_, const Matrix_Int_ value3_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;

				return (value_ != value2_ || value_ != value3_) && mersenne_twister_32bit.probability(rbool_);
			}


		} //namespace
	}
}

//--------------------
//noiseShoreBool関数
//--------------------

namespace dtl {
	namespace utility {
		namespace stl {


			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false;
						else matrix_[row][col] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void noiseShoreBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ 1 }; row < matrix_.size(); ++row)
					for (std::size_t col{ 1 }; col < matrix_[row].size(); ++col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row][col], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}


		} //namespace
	}
}

//--------------------
//rnoiseShoreBool関数
//--------------------

namespace dtl {
	namespace utility {
		namespace stl {


			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_& matrix_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col])) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_& matrix_, const double rbool_) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false;
						else matrix_[row - 1][col - 1] = true;
					}
			}

			//[rbool_]の確率でマップデータの値がtrueの場合は[true_tile_]、falseの場合は[false_tile_]を代入する
			template<typename Matrix_Int_, typename Matrix_>
			constexpr void rnoiseShoreBool(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_, const Matrix_Int_ false_tile_ = 0) noexcept {

				using dtl::random::mersenne_twister_32bit;
				using dtl::utility::tool::isNoise_noiseShoreBool;

				for (std::size_t row{ matrix_.size() - 1 }; row >= 1; --row)
					for (std::size_t col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						//ノイズを発生させるか判定する
						if (!isNoise_noiseShoreBool(matrix_[row - 1][col - 1], matrix_[row][col - 1], matrix_[row - 1][col], rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}


		} //namespace
	}
}

//--------------------
//noiseShoreBothBool関数
//--------------------

namespace dtl {
	namespace utility {
		namespace stl {


			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void noiseShoreBothBool(Matrix_& matrix_) noexcept {
				dtl::utility::stl::noiseShoreBool(matrix_);
				dtl::utility::stl::rnoiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
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
			//1/2の確率で岸(地形)にノイズを発生させる
			template<typename Matrix_>
			constexpr void rnoiseShoreBothBool(Matrix_& matrix_) noexcept {
				dtl::utility::stl::rnoiseShoreBool(matrix_);
				dtl::utility::stl::noiseShoreBool(matrix_);
			}
			//[rbool_]の確率で岸(地形)にノイズを発生させる
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


		} //namespace
	}
}

//--------------------
//その他
//--------------------

namespace dtl {
	namespace utility {
		namespace stl {


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


		} //namespace
	}
}

#endif //Included Dungeon Template Library