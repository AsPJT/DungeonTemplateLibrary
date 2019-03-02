#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_MAZE_DIG
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <memory>
#include "Random_MersenneTwister32bit.hpp"

//Dungeon Template Library Namespace
namespace dtl {
	namespace generator {
		namespace dungeon {

			namespace stl {
				enum MazeDigType :std::size_t {
					maze_dig_type_wall,
					maze_dig_type_way,
				};

				template<typename Matrix_Int_>
				class MazeDig {
				public:
					//コンストラクタ
					constexpr MazeDig() noexcept = default;
					template<typename Matrix_>
					constexpr explicit MazeDig(Matrix_& data, const Matrix_Int_ v1_, const Matrix_Int_ v2_) noexcept {
						mazeDig_Create(data, v1_, v2_);
					}
					template<typename Matrix_>
					constexpr explicit MazeDig(Matrix_& data, const Matrix_Int_ v1_) noexcept {
						mazeDig_Create(data, v1_, static_cast<Matrix_Int_>(maze_dig_type_way));
					}
					template<typename Matrix_>
					constexpr explicit MazeDig(Matrix_& data) noexcept {
						mazeDig_Create(data, static_cast<Matrix_Int_>(maze_dig_type_wall), static_cast<Matrix_Int_>(maze_dig_type_way));
					}
				private:

					//生成チェック
					template<typename Matrix_>
					constexpr bool mazeDig_Check(const Matrix_& data) const noexcept {
						if (data.size() <= 2) return false;
						if (data[1].size() <= 2) return false;
						return true;
					}
					//穴掘り
					template<typename Matrix_>
					constexpr void mazeDig_Dig(Matrix_& data, std::size_t x_, std::size_t y_, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_) const noexcept {
						
						using dtl::random::mersenne_twister_32bit;
						
						if (!mazeDig_Check(data)) return;
						std::int_fast32_t dx{}, dy{};
						std::size_t random = std::size_t(mersenne_twister_32bit()), counter = 0;

						const std::size_t i_max{ ((data.size() % 2) == 0) ? data.size() - 2 : data.size() - 1 };
						const std::size_t j_max{ ((data[0].size() % 2) == 0) ? data[0].size() - 2 : data[0].size() - 1 };

						while (counter < 4) {
							switch ((random + counter) & 3)
							{
							case 0:dx = 0; dy = -2; break;
							case 1:dx = -2; dy = 0; break;
							case 2:dx = 0; dy = 2; break;
							case 3:dx = 2; dy = 0; break;
							default:dx = 0; dy = 0; break;
							}
							if (x_ + dx <= 0 || y_ + dy <= 0 || (x_ + dx) >= i_max || (y_ + dy) >= j_max || data[x_ + dx][y_ + dy] == id_empty_) {
								++counter;
							}
							else if (data[x_ + dx][y_ + dy] == id_wall_) {
								data[x_ + (dx / 2)][y_ + (dy / 2)] = id_empty_;
								data[x_ + dx][y_ + dy] = id_empty_;
								x_ += dx;
								y_ += dy;
								counter = 0;
								random = std::size_t(mersenne_twister_32bit());
							}
						}
						return;
					}
					//迷路生成
					template<typename Matrix_>
					constexpr std::size_t mazeDig_CreateLoop(const Matrix_& data, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_, std::unique_ptr<std::size_t[]>& select_x, std::unique_ptr<std::size_t[]>& select_y) const noexcept {
						std::size_t select_id{};
						const std::size_t i_max{ ((data.size() % 2) == 0) ? data.size() - 2 : data.size() - 1 };
						const std::size_t j_max{ ((data[0].size() % 2) == 0) ? data[0].size() - 2 : data[0].size() - 1 };

						for (std::size_t i{ 1 }; i < i_max; i += 2)
							for (std::size_t j{ 1 }; j < j_max; j += 2) {
								if (data[i][j] != id_empty_) continue;
								if ((i >= 2 && data[i - 2][j] == id_wall_) || (j >= 2 && data[i][j - 2] == id_wall_)) {
									select_x[select_id] = i;
									select_y[select_id] = j;
									++select_id;
								}
								else if ((j == j_max - 1) && (i == i_max - 1)) break;
								else if ((i + 2 < (i_max + 1) && data[i + 2][j] == id_wall_) || (j + 2 < (j_max + 1) && data[i][j + 2] == id_wall_)) {
									select_x[select_id] = i;
									select_y[select_id] = j;
									++select_id;
								}
							}
						return select_id;
					}
					//穴掘り法の迷路を生成する
					template<typename Matrix_>
					void mazeDig_Create(Matrix_& data, const Matrix_Int_ id_wall_, const Matrix_Int_ id_empty_) const {

						using dtl::random::mersenne_twister_32bit;

						if (!mazeDig_Check(data)) return;
						data[1][1] = id_empty_;

						std::size_t select_id{};

						std::unique_ptr<std::size_t[]> select_x;
						std::unique_ptr<std::size_t[]> select_y;
						try {
							select_x = std::make_unique<std::size_t[]>(data.size()*data[0].size());
							select_y = std::make_unique<std::size_t[]>(data.size()*data[0].size());
						}
						catch (const std::bad_alloc&) {
							//メモリ確保に失敗
							return;
						}



						//座標を選ぶ
						while (true) {
							select_id = mazeDig_CreateLoop(data, id_wall_, id_empty_, select_x, select_y);
							if (select_id == static_cast<std::size_t>(0)) break;

							select_id = static_cast<std::size_t>(mersenne_twister_32bit(static_cast<std::int_fast32_t>(select_id)));
							mazeDig_Dig(data, (std::size_t)select_x[select_id], (std::size_t)select_y[select_id], id_wall_, id_empty_);
						}
						return;
					}

				public:
					template<typename Matrix_>
					constexpr void operator()(Matrix_& data, const Matrix_Int_ v1_, const Matrix_Int_ v2_) const noexcept {
						mazeDig_Create(data, v1_, v2_);
					}
					template<typename Matrix_>
					constexpr void operator()(Matrix_& data, const Matrix_Int_ v1_) const noexcept {
						mazeDig_Create(data, v1_, static_cast<Matrix_Int_>(maze_dig_type_way));
					}
					template<typename Matrix_>
					constexpr void operator()(Matrix_& data) const noexcept {
						mazeDig_Create(data, static_cast<Matrix_Int_>(maze_dig_type_wall), static_cast<Matrix_Int_>(maze_dig_type_way));
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& data, const Matrix_Int_ v1_, const Matrix_Int_ v2_) const noexcept {
						mazeDig_Create(data, v1_, v2_);
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& data, const Matrix_Int_ v1_) const noexcept {
						mazeDig_Create(data, v1_, static_cast<Matrix_Int_>(maze_dig_type_way));
					}
					template<typename Matrix_>
					constexpr void create(Matrix_& data) const noexcept {
						mazeDig_Create(data, static_cast<Matrix_Int_>(maze_dig_type_wall), static_cast<Matrix_Int_>(maze_dig_type_way));
					}

				};



			} //namespace
		}
	}
}

#endif //Included Dungeon Template Library