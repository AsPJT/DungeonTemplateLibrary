/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_NOISE

/* Character Code : UTF-8 (BOM) */
/* [2019/03/08] Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <Random/MersenneTwister32bit.hpp>

namespace dtl::utility::stl {

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

#include <array>
#include <iostream>

//タイル

namespace dtl::tile {

	//タイル形式
	enum :std::size_t {
		tile_type_empty,
		tile_type_wolf_auto_tile,
		tile_type_one_tile,
		tile_type_default_tile
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
	[[nodiscard]] constexpr std::size_t getWolfAutoTileType(const Matrix_Int_ center_, const Matrix_Int_ next1_, const Matrix_Int_ next2_, const Matrix_Int_ next3_) noexcept {
		return (center_ == next1_) ?
			((center_ == next2_) ?
			((center_ == next3_) ? wolf_auto_tile_type_all : wolf_auto_tile_type_cross)
				: wolf_auto_tile_type_width)
			: ((center_ == next2_) ? wolf_auto_tile_type_height : wolf_auto_tile_type_circle);
	}

	//Wolfオートタイル形式の配列値を返す
	[[nodiscard]] constexpr std::size_t getWolfAutoTileID(const std::size_t type_, const std::size_t dir_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return anime_num_ * 2 + type_ * anime_max_ * 4 + ((dir_ <= tile_upper_right) ? dir_ : dir_ + anime_max_ * 2 - 2);
	}

	//Wolfオートタイル形式の左上の地形タイプを返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileTypeUpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0) noexcept {
		return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
	}
	//Wolfオートタイル形式の右上の地形タイプを返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileTypeUpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0) noexcept {
		return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
	}
	//Wolfオートタイル形式の左下の地形タイプを返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileTypeLowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_) noexcept {
		return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
	}
	//Wolfオートタイル形式の右下の地形タイプを返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileTypeLowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_) noexcept {
		return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
	}

	//Wolfオートタイル形式の左上の配列番号を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr std::size_t getWolfAutoTileID_UpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileID(getWolfAutoTileTypeUpperLeft(matrix_, x_, y_, min_x_, min_y_), tile_upper_left, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の右上の配列番号を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr std::size_t getWolfAutoTileID_UpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileID(getWolfAutoTileTypeUpperRight(matrix_, x_, y_, max_x_, min_y_), tile_upper_right, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の左下の配列番号を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr std::size_t getWolfAutoTileID_LowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileID(getWolfAutoTileTypeLowerLeft(matrix_, x_, y_, min_x_, max_y_), tile_lower_left, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の右下の配列番号を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr std::size_t getWolfAutoTileID_LowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileID(getWolfAutoTileTypeLowerRight(matrix_, x_, y_, max_x_, max_y_), tile_lower_right, anime_num_, anime_max_);
	}

	//Wolfオートタイル形式の左上の配列値を返す
	template<typename TileArray_, typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileArrayUpperLeft(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return tile_array_[getWolfAutoTileID_UpperLeft(matrix_, x_, y_, min_x_, min_y_, anime_num_, anime_max_)];
	}
	//Wolfオートタイル形式の右上の配列値を返す
	template<typename TileArray_, typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileArrayUpperRight(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return tile_array_[getWolfAutoTileID_UpperRight(matrix_, x_, y_, max_x_, min_y_, anime_num_, anime_max_)];
	}
	//Wolfオートタイル形式の左下の配列値を返す
	template<typename TileArray_, typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileArrayLowerLeft(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return tile_array_[getWolfAutoTileID_LowerLeft(matrix_, x_, y_, min_x_, max_y_, anime_num_, anime_max_)];
	}
	//Wolfオートタイル形式の右下の配列値を返す
	template<typename TileArray_, typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileArrayLowerRight(const Matrix_& matrix_, const TileArray_& tile_array_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return tile_array_[getWolfAutoTileID_LowerRight(matrix_, x_, y_, max_x_, max_y_, anime_num_, anime_max_)];
	}

	//WolfオートタイルのConsole出力用文字
	constexpr std::array<char[3], 20> wolf_auto_tile_string{ {
"|-","-|","|_","_|",
"| "," |","| "," |",
"--","--","__","__",
"` "," `",", "," ,",
"  ","  ","  ","  "
		} };

	//Wolfオートタイル形式の左上の配列値を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileStringUpperLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_ = 0, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileArrayUpperLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, min_y_, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の右上の配列値を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileStringUpperRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t min_y_ = 0, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileArrayUpperRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, min_y_, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の左下の配列値を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileStringLowerLeft(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t min_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileArrayLowerLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, max_y_, anime_num_, anime_max_);
	}
	//Wolfオートタイル形式の右下の配列値を返す
	template<typename Matrix_>
	[[nodiscard]] constexpr auto getWolfAutoTileStringLowerRight(const Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const std::size_t max_x_, const std::size_t max_y_, const std::size_t anime_num_ = 0, const std::size_t anime_max_ = 1) noexcept {
		return getWolfAutoTileArrayLowerRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, max_y_, anime_num_, anime_max_);
	}

	namespace stl {
		template<typename Matrix_>
		void outputWolfAutoTile(const Matrix_& matrix_, const char space_char_ = ' ') noexcept {
			for (size_t y{}; y < matrix_.size(); ++y) {
				//上方向のオートタイルを描画
				for (size_t x{}; x < matrix_[y].size(); ++x) {
					if (matrix_[y][x]) {
						std::cout << dtl::tile::getWolfAutoTileStringUpperLeft(matrix_, x, y, 0, 0);
						std::cout << dtl::tile::getWolfAutoTileStringUpperRight(matrix_, x, y, matrix_[y].size() - 1, 0);
					}
					else std::cout << space_char_ << space_char_ << space_char_ << space_char_;
				}
				std::cout << '\n';
				//下方向のオートタイルを描画
				for (size_t x{}; x < matrix_[y].size(); ++x) {
					if (matrix_[y][x]) {
						std::cout << dtl::tile::getWolfAutoTileStringLowerLeft(matrix_, x, y, 0, matrix_.size() - 1);
						std::cout << dtl::tile::getWolfAutoTileStringLowerRight(matrix_, x, y, matrix_[y].size() - 1, matrix_.size() - 1);
					}
					else std::cout << space_char_ << space_char_ << space_char_ << space_char_;
				}
				std::cout << '\n';
			}
		}

		template<typename Matrix_>
		void outputTileCUI(const Matrix_& matrix_, const char space_char_ = ' ') noexcept {
			dtl::tile::stl::outputWolfAutoTile(matrix_, space_char_);
		}
	}
	namespace normal {
		template<typename Matrix_>
		void outputWolfAutoTile(const Matrix_& matrix_, const std::size_t x_, std::size_t y_, const char space_char_ = ' ') noexcept {
			for (size_t y{}; y < y_; ++y) {
				//上方向のオートタイルを描画
				for (size_t x{}; x < x_; ++x) {
					if (matrix_[y][x]) {
						std::cout << dtl::tile::getWolfAutoTileStringUpperLeft(matrix_, x, y, 0, 0);
						std::cout << dtl::tile::getWolfAutoTileStringUpperRight(matrix_, x, y, x_ - 1, 0);
					}
					else std::cout << space_char_ << space_char_ << space_char_ << space_char_;
				}
				std::cout << '\n';
				//下方向のオートタイルを描画
				for (size_t x{}; x < x_; ++x) {
					if (matrix_[y][x]) {
						std::cout << dtl::tile::getWolfAutoTileStringLowerLeft(matrix_, x, y, 0, y_ - 1);
						std::cout << dtl::tile::getWolfAutoTileStringLowerRight(matrix_, x, y, x_ - 1, y_ - 1);
					}
					else std::cout << space_char_ << space_char_ << space_char_ << space_char_;
				}
				std::cout << '\n';
			}
		}

		template<typename Matrix_>
		void outputTileCUI(const Matrix_& matrix_, const std::size_t x_, std::size_t y_, const char space_char_ = ' ') noexcept {
			dtl::tile::normal::outputWolfAutoTile(matrix_, x_, y_, space_char_);
		}
	}


} //namespace

#endif //Included Dungeon Template Library