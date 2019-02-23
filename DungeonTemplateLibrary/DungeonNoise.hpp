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

#include <array>

//タイル

namespace dtl {
	namespace tile {

		enum :std::size_t {
			tile_type_empty,
			tile_type_wolf_auto_tile
		};

		//Wolfオートタイル形式の地形タイプ
		enum :std::size_t {
			wolf_auto_tile_type_circle,
			wolf_auto_tile_type_height,
			wolf_auto_tile_type_width,
			wolf_auto_tile_type_cross,
			wolf_auto_tile_type_all
		};
		//Wolfオートタイル形式の地形位置
		enum :std::size_t {
			tile_upper_left,
			tile_upper_right,
			tile_lower_left,
			tile_lower_right
		};

		//Wolfオートタイル形式の地形タイプを返す
		template<typename Matrix_Int_>
		constexpr std::size_t getWolfAutoTileType(const Matrix_Int_ center_, const Matrix_Int_ next1_, const Matrix_Int_ next2_, const Matrix_Int_ next3_) noexcept {
			return (center_ == next1_) ? ((center_ == next2_) ? ((center_ == next3_) ? wolf_auto_tile_type_all : wolf_auto_tile_type_cross) : wolf_auto_tile_type_width) : ((center_ == next2_) ? wolf_auto_tile_type_height : wolf_auto_tile_type_circle);
		}

		//Wolfオートタイル形式の配列値を返す
		constexpr std::size_t getWolfAutoTileID(const std::size_t type_, const std::size_t dir_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return anime_num_ * 2 + type_ * anime_max_ * 4 + ((dir_ <= tile_upper_right) ? dir_ : dir_ + anime_max_ * 2 - 2);
		}

		//Wolfオートタイル形式の左上の地形タイプを返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileTypeUpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の右上の地形タイプを返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileTypeUpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の左下の地形タイプを返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileTypeLowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の右下の地形タイプを返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileTypeLowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
		}

		//Wolfオートタイル形式の左上の配列番号を返す
		template<typename Matrix_>
		constexpr std::size_t getWolfAutoTileID_UpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeUpperLeft(matrix_, x_, y_, min_x_, min_y_), tile_upper_left, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右上の配列番号を返す
		template<typename Matrix_>
		constexpr std::size_t getWolfAutoTileID_UpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeUpperRight(matrix_, x_, y_, max_x_, min_y_), tile_upper_right, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の左下の配列番号を返す
		template<typename Matrix_>
		constexpr std::size_t getWolfAutoTileID_LowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeLowerLeft(matrix_, x_, y_, min_x_, max_y_), tile_lower_left, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右下の配列番号を返す
		template<typename Matrix_>
		constexpr std::size_t getWolfAutoTileID_LowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeLowerRight(matrix_, x_, y_, max_x_, max_y_), tile_lower_right, anime_num_, anime_max_);
		}

		//Wolfオートタイル形式の左上の配列値を返す
		template<typename TileArray_, typename Matrix_>
		constexpr auto getWolfAutoTileArrayUpperLeft(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_UpperLeft(matrix_, x_, y_, min_x_, min_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の右上の配列値を返す
		template<typename TileArray_, typename Matrix_>
		constexpr auto getWolfAutoTileArrayUpperRight(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_UpperRight(matrix_, x_, y_, max_x_, min_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の左下の配列値を返す
		template<typename TileArray_, typename Matrix_>
		constexpr auto getWolfAutoTileArrayLowerLeft(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_LowerLeft(matrix_, x_, y_, min_x_, max_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の右下の配列値を返す
		template<typename TileArray_, typename Matrix_>
		constexpr auto getWolfAutoTileArrayLowerRight(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_LowerRight(matrix_, x_, y_, max_x_, max_y_, anime_num_, anime_max_)];
		}

		constexpr std::array<char[3], 20> wolf_auto_tile_string{
"|-","-|","|_","_|",
"| "," |","| "," |",
"--","--","__","__",
"` "," `",", "," ,",
"  ","  ","  ","  "
		};

		//Wolfオートタイル形式の左上の配列値を返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileStringUpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayUpperLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, min_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右上の配列値を返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileStringUpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayUpperRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, min_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の左下の配列値を返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileStringLowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayLowerLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, max_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右下の配列値を返す
		template<typename Matrix_>
		constexpr auto getWolfAutoTileStringLowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayLowerRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, max_y_, anime_num_, anime_max_);
		}

		namespace stl {
			template<typename Matrix_>
			void outputWolfAutoTile(const Matrix_& matrix_) noexcept {
				for (size_t y{}; y < matrix_.size(); ++y) {
					//上方向のオートタイルを描画
					for (size_t x{}; x < matrix_[y].size(); ++x) {
						if (matrix_[y][x]) {
							std::cout << dtl::tile::getWolfAutoTileStringUpperLeft(matrix_, x, y, 0, 0);
							std::cout << dtl::tile::getWolfAutoTileStringUpperRight(matrix_, x, y, matrix_[y].size() - 1, 0);
						}
						else std::cout << "    ";
					}
					std::cout << std::endl;
					//下方向のオートタイルを描画
					for (size_t x{}; x < matrix_[y].size(); ++x) {
						if (matrix_[y][x]) {
							std::cout << dtl::tile::getWolfAutoTileStringLowerLeft(matrix_, x, y, 0, matrix_.size() - 1);
							std::cout << dtl::tile::getWolfAutoTileStringLowerRight(matrix_, x, y, matrix_[y].size() - 1, matrix_.size() - 1);
						}
						else std::cout << "    ";
					}
					std::cout << std::endl;
				}
			}
		}


	} //namespace
}

#endif //Included Dungeon Template Library