/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DUNGEON_NOISE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DUNGEON_NOISE_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する
		namespace stl {

			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void noiseShore(Matrix_& matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using ::dtl::random::mersenne_twister_32bit;

				for (::dtl::type::size row{ 1 }; row < matrix_.size(); ++row)
					for (::dtl::type::size col{ 1 }; col < matrix_[row].size(); ++col) {
						if ((matrix_[row][col] == matrix_[row][col - 1] && matrix_[row][col] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col]) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void rnoiseShore(Matrix_ & matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using ::dtl::random::mersenne_twister_32bit;

				for (::dtl::type::size row{ matrix_.size() - 1 }; row >= 1; --row)
					for (::dtl::type::size col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						if ((matrix_[row - 1][col - 1] == matrix_[row][col - 1] && matrix_[row - 1][col - 1] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row - 1][col - 1]) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void noiseShoreOver(Matrix_ & matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using ::dtl::random::mersenne_twister_32bit;

				for (::dtl::type::size row{ 1 }; row < matrix_.size(); ++row)
					for (::dtl::type::size col{ 1 }; col < matrix_[row].size(); ++col) {
						if ((matrix_[row][col] == matrix_[row][col - 1] && matrix_[row][col] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row][col] >= true_tile_) matrix_[row][col] = false_tile_;
						else matrix_[row][col] = true_tile_;
					}
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void rnoiseShoreOver(Matrix_ & matrix_, const double rbool_, const Matrix_Int_ true_tile_ = 1, const Matrix_Int_ false_tile_ = 0) noexcept {

				using ::dtl::random::mersenne_twister_32bit;

				for (::dtl::type::size row{ matrix_.size() - 1 }; row >= 1; --row)
					for (::dtl::type::size col{ matrix_[row].size() - 1 }; col >= 1; --col) {
						if ((matrix_[row - 1][col - 1] == matrix_[row][col - 1] && matrix_[row - 1][col - 1] == matrix_[row - 1][col]) || !mersenne_twister_32bit.probability(rbool_)) continue;
						if (matrix_[row - 1][col - 1] >= true_tile_) matrix_[row - 1][col - 1] = false_tile_;
						else matrix_[row - 1][col - 1] = true_tile_;
					}
			}

		} //namespace
	}
}

#include <array>
#include <iostream>

//タイル

namespace dtl {
	inline namespace tile {

		//タイル形式
		enum : ::dtl::type::size {
			tile_type_empty,
			tile_type_wolf_auto_tile,
			tile_type_one_tile,
			tile_type_default_tile
		};

		//Wolfオートタイル形式の地形タイプ
		enum : ::dtl::type::size {
			wolf_auto_tile_type_circle,
			wolf_auto_tile_type_height,
			wolf_auto_tile_type_width,
			wolf_auto_tile_type_cross,
			wolf_auto_tile_type_all
		};
		//Wolfオートタイル形式の地形位置
		enum : ::dtl::type::size {
			tile_upper_left,
			tile_upper_right,
			tile_lower_left,
			tile_lower_right
		};

		//Wolfオートタイル形式の地形タイプを返す
		template<typename Matrix_Int_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileType(const Matrix_Int_ center_, const Matrix_Int_ next1_, const Matrix_Int_ next2_, const Matrix_Int_ next3_) noexcept {
			return (center_ == next1_) ?
				((center_ == next2_) ?
				((center_ == next3_) ? wolf_auto_tile_type_all : wolf_auto_tile_type_cross)
					: wolf_auto_tile_type_width)
				: ((center_ == next2_) ? wolf_auto_tile_type_height : wolf_auto_tile_type_circle);
		}

		//Wolfオートタイル形式の配列値を返す
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileID(const ::dtl::type::size type_, const ::dtl::type::size dir_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return anime_num_ * 2 + type_ * anime_max_ * 4 + ((dir_ <= tile_upper_right) ? dir_ : dir_ + anime_max_ * 2 - 2);
		}

		//Wolfオートタイル形式の左上の地形タイプを返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileTypeUpperLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_ = 0, const ::dtl::type::size min_y_ = 0) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の右上の地形タイプを返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileTypeUpperRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size min_y_ = 0) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_], matrix_[y_ - ((y_ <= min_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の左下の地形タイプを返す
		template<typename Matrix_>
			DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileTypeLowerLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_, const ::dtl::type::size max_y_) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ - ((x_ <= min_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ - ((x_ <= min_x_) ? 0 : 1)]);
		}
		//Wolfオートタイル形式の右下の地形タイプを返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileTypeLowerRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size max_y_) noexcept {
			return getWolfAutoTileType(matrix_[y_][x_], matrix_[y_][x_ + ((x_ >= max_x_) ? 0 : 1)], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_], matrix_[y_ + ((y_ >= max_y_) ? 0 : 1)][x_ + ((x_ >= max_x_) ? 0 : 1)]);
		}

		//Wolfオートタイル形式の左上の配列番号を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileID_UpperLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_ = 0, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeUpperLeft(matrix_, x_, y_, min_x_, min_y_), tile_upper_left, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右上の配列番号を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileID_UpperRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeUpperRight(matrix_, x_, y_, max_x_, min_y_), tile_upper_right, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の左下の配列番号を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileID_LowerLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeLowerLeft(matrix_, x_, y_, min_x_, max_y_), tile_lower_left, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右下の配列番号を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr ::dtl::type::size getWolfAutoTileID_LowerRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileID(getWolfAutoTileTypeLowerRight(matrix_, x_, y_, max_x_, max_y_), tile_lower_right, anime_num_, anime_max_);
		}

		//Wolfオートタイル形式の左上の配列値を返す
		template<typename TileArray_, typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileArrayUpperLeft(const Matrix_ & matrix_, const TileArray_ & tile_array_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_ = 0, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_UpperLeft(matrix_, x_, y_, min_x_, min_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の右上の配列値を返す
		template<typename TileArray_, typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileArrayUpperRight(const Matrix_ & matrix_, const TileArray_ & tile_array_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_UpperRight(matrix_, x_, y_, max_x_, min_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の左下の配列値を返す
		template<typename TileArray_, typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileArrayLowerLeft(const Matrix_ & matrix_, const TileArray_ & tile_array_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_LowerLeft(matrix_, x_, y_, min_x_, max_y_, anime_num_, anime_max_)];
		}
		//Wolfオートタイル形式の右下の配列値を返す
		template<typename TileArray_, typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileArrayLowerRight(const Matrix_ & matrix_, const TileArray_ & tile_array_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return tile_array_[getWolfAutoTileID_LowerRight(matrix_, x_, y_, max_x_, max_y_, anime_num_, anime_max_)];
		}

		//WolfオートタイルのConsole出力用文字
		constexpr ::std::array<char[3], 20> wolf_auto_tile_string{ {
	"|-","-|","|_","_|",
	"| "," |","| "," |",
	"--","--","__","__",
	"` "," `",", "," ,",
	"  ","  ","  ","  "
			} };

		//Wolfオートタイル形式の左上の配列値を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileStringUpperLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_ = 0, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayUpperLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, min_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右上の配列値を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileStringUpperRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size min_y_ = 0, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayUpperRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, min_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の左下の配列値を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileStringLowerLeft(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size min_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayLowerLeft(matrix_, wolf_auto_tile_string, x_, y_, min_x_, max_y_, anime_num_, anime_max_);
		}
		//Wolfオートタイル形式の右下の配列値を返す
		template<typename Matrix_>
		DTL_VERSIONING_CPP17_NODISCARD
		constexpr auto getWolfAutoTileStringLowerRight(const Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size max_x_, const ::dtl::type::size max_y_, const ::dtl::type::size anime_num_ = 0, const ::dtl::type::size anime_max_ = 1) noexcept {
			return getWolfAutoTileArrayLowerRight(matrix_, wolf_auto_tile_string, x_, y_, max_x_, max_y_, anime_num_, anime_max_);
		}

		namespace stl {
			template<typename Matrix_>
			void outputWolfAutoTile(const Matrix_& matrix_, const char space_char_ = ' ') noexcept {
				for (::dtl::type::size y{}; y < matrix_.size(); ++y) {
					//上方向のオートタイルを描画
					for (::dtl::type::size x{}; x < matrix_[y].size(); ++x) {
						if (matrix_[y][x]) {
							::std::cout << ::dtl::tile::getWolfAutoTileStringUpperLeft(matrix_, x, y, 0, 0);
							::std::cout << ::dtl::tile::getWolfAutoTileStringUpperRight(matrix_, x, y, matrix_[y].size() - 1, 0);
						}
						else ::std::cout << space_char_ << space_char_ << space_char_ << space_char_;
					}
					::std::cout << '\n';
					//下方向のオートタイルを描画
					for (::dtl::type::size x{}; x < matrix_[y].size(); ++x) {
						if (matrix_[y][x]) {
							::std::cout << ::dtl::tile::getWolfAutoTileStringLowerLeft(matrix_, x, y, 0, matrix_.size() - 1);
							::std::cout << ::dtl::tile::getWolfAutoTileStringLowerRight(matrix_, x, y, matrix_[y].size() - 1, matrix_.size() - 1);
						}
						else ::std::cout << space_char_ << space_char_ << space_char_ << space_char_;
					}
					::std::cout << '\n';
				}
			}

			template<typename Matrix_>
			void outputTileCUI(const Matrix_ & matrix_, const char space_char_ = ' ') noexcept {
				::dtl::tile::stl::outputWolfAutoTile(matrix_, space_char_);
			}
		}
		namespace normal {
			template<typename Matrix_>
			void outputWolfAutoTile(const Matrix_& matrix_, const ::dtl::type::size x_, ::dtl::type::size y_, const char space_char_ = ' ') noexcept {
				for (::dtl::type::size y{}; y < y_; ++y) {
					//上方向のオートタイルを描画
					for (::dtl::type::size x{}; x < x_; ++x) {
						if (matrix_[y][x]) {
							::std::cout << ::dtl::tile::getWolfAutoTileStringUpperLeft(matrix_, x, y, 0, 0);
							::std::cout << ::dtl::tile::getWolfAutoTileStringUpperRight(matrix_, x, y, x_ - 1, 0);
						}
						else ::std::cout << space_char_ << space_char_ << space_char_ << space_char_;
					}
					::std::cout << '\n';
					//下方向のオートタイルを描画
					for (::dtl::type::size x{}; x < x_; ++x) {
						if (matrix_[y][x]) {
							::std::cout << ::dtl::tile::getWolfAutoTileStringLowerLeft(matrix_, x, y, 0, y_ - 1);
							::std::cout << ::dtl::tile::getWolfAutoTileStringLowerRight(matrix_, x, y, x_ - 1, y_ - 1);
						}
						else ::std::cout << space_char_ << space_char_ << space_char_ << space_char_;
					}
					::std::cout << '\n';
				}
			}

			template<typename Matrix_>
			void outputTileCUI(const Matrix_ & matrix_, const ::dtl::type::size x_, ::dtl::type::size y_, const char space_char_ = ' ') noexcept {
				::dtl::tile::normal::outputWolfAutoTile(matrix_, x_, y_, space_char_);
			}
		}


	} //namespace
}

#endif //Included Dungeon Template Library