#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_ROGUE_LIKE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SIMPLE_ROGUE_LIKE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <limits>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	template<typename Matrix_Int_>
	constexpr Matrix_Int_ absTemplate(const Matrix_Int_& value_) noexcept {
		return (value_ < 0) ? (-value_) : value_;
	}
	enum :std::int_fast32_t {
		RL_COUNT_X,
		RL_COUNT_Y
	};

	template<typename Matrix_Int_>
	class SimpleRogueLike {
	private:
		//生成される部屋の数 (正確に言うと生成される区域の数)---
		//マップの区分け最小数
		//マップの区分け数加算
		//生成される部屋のサイズ---
		//部屋のX座標の最小サイズ
		//部屋のX座標のサイズ加算
		//部屋のY座標の最小サイズ
		//部屋のY座標のサイズ加算

		//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
		std::vector<std::array<std::size_t, 4>> dungeon_division{};
		//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
		std::vector<std::array<std::size_t, 4>> dungeon_room{};
		//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
		std::vector<std::array<std::size_t, 4>> dungeon_road{};
	public:
		//コンストラクタ
		constexpr SimpleRogueLike() noexcept = default;
		template <typename Matrix_>
		constexpr explicit SimpleRogueLike(Matrix_& matrix_, const std::size_t division_min = 3, const std::size_t division_rand_max = 4, const std::size_t room_min_x = 5, const std::size_t room_rand_max_x = 2, const std::size_t room_min_y = 5, const std::size_t room_rand_max_y = 2) noexcept {
			create(matrix_, division_min, division_rand_max, room_min_x, room_rand_max_x, room_min_y, room_rand_max_y);
		}

		//ローグライク生成関数
		template <typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t division_min = 3, const std::size_t division_rand_max = 4, const std::size_t room_min_x = 5, const std::size_t room_rand_max_x = 2, const std::size_t room_min_y = 5, const std::size_t room_rand_max_y = 2) noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;
			//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
			const std::size_t mapDivCount{ division_min + (std::size_t)rnd(1,(std::int_fast32_t)division_rand_max) }; //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

			dungeon_division.resize(mapDivCount);
			dungeon_room.resize(mapDivCount);
			dungeon_road.resize(mapDivCount);
			for (std::size_t i{}; i < mapDivCount; ++i)
				for (std::size_t j{}; j < 4; ++j) {
					dungeon_division[i][j] = 0;
					dungeon_room[i][j] = 0;
					dungeon_road[i][j] = 0;
				}

			dungeon_division[0][0] = (matrix_.size() - 1); //マップの区分け初期サイズX終点 (マップの大きさX軸)
			dungeon_division[0][1] = (matrix_[0].size() - 1); //マップの区分け初期サイズY終点 (マップの大きさY軸)
			dungeon_division[0][2] = 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
			dungeon_division[0][3] = 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

			dungeon_road[0][0] = (std::numeric_limits<std::size_t>::max)();
			dungeon_road[0][1] = (std::numeric_limits<std::size_t>::max)();

			//マップを区分けしていく処理(区域を分割する処理)
			std::size_t division_After{};
			std::int_fast32_t count{}; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める

			for (std::size_t i{ 1 }; i < mapDivCount; ++i) {

				//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
				division_After = (std::size_t)rnd((std::int_fast32_t)i);

				//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
				if (dungeon_division[division_After][0] - dungeon_division[division_After][2] > dungeon_division[division_After][1] - dungeon_division[division_After][3]) count = RL_COUNT_X;
				else count = RL_COUNT_Y;

				if (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2] < division_rand_max * 2 + 8) {
					std::size_t k{};
					for (std::size_t j{ 1 }; j < mapDivCount; ++j) {
						if (dungeon_division[j][0] - dungeon_division[j][2] > k) {
							k = dungeon_division[j][0] - dungeon_division[j][2];
							division_After = j;
							count = RL_COUNT_X;
						}
						if (dungeon_division[j][1] - dungeon_division[j][3] > k) {
							k = dungeon_division[j][1] - dungeon_division[j][3];
							division_After = j;
							count = RL_COUNT_Y;
						}
					}
				}

				dungeon_road[i][0] = division_After;
				dungeon_road[i][1] = count;

				for (std::size_t j{ 1 }; j < i; ++j)
					if (dungeon_road[j][0] == division_After) dungeon_road[j][0] = i;

				//count軸の設定
				//0.軸の右端(iR)の座標(division_After*R/3~2division_After*R/3)
				dungeon_division[i][count] = dungeon_division[division_After][count + 2] + ((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3) + static_cast<std::size_t>(rnd(1,static_cast<std::int_fast32_t>((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3)));

				dungeon_division[i][count + 2] = dungeon_division[division_After][count + 2]; //0.軸の左端(iL)の座標(division_AfterL)
				dungeon_division[division_After][count + 2] = dungeon_division[i][count]; //division_After軸の左端(division_AfterL)の座標(iR)

				//countとは逆の軸の設定
				dungeon_division[i][absTemplate(count - 1)] = dungeon_division[division_After][absTemplate(count - 1)]; //軸の右端(iR)の座標(division_AfterR)
				dungeon_division[i][absTemplate(count - 1) + 2] = dungeon_division[division_After][absTemplate(count - 1) + 2]; //軸の左端(iL)の座標(division_AfterL)
			}

			//部屋を生成する処理
			for (std::size_t i{}; i < mapDivCount; ++i) {//区分け
				dungeon_room[i][2] = dungeon_division[i][2]; //区分けX始点をマップX始点へ代入
				dungeon_room[i][3] = dungeon_division[i][3]; //区分けY始点をマップY始点へ代入

				//X座標の部屋の長さを指定
				dungeon_room[i][0] = dungeon_division[i][2] + room_min_x + (std::size_t)rnd(1, (std::int_fast32_t)room_rand_max_x);
				if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
					dungeon_room[i][0] = dungeon_division[i][0] - 4;
					if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
						dungeon_room[i][0] = dungeon_division[i][2] + 1;
					}
				}

				dungeon_room[i][1] = dungeon_division[i][3] + room_min_y + (std::size_t)rnd(1, (std::int_fast32_t)room_rand_max_y);
				if (dungeon_division[i][1] - dungeon_division[i][3] < dungeon_room[i][1] - dungeon_room[i][3] + 5) {
					dungeon_room[i][1] = dungeon_division[i][1] - 4;
					if (dungeon_division[i][1] - dungeon_division[i][3] < dungeon_room[i][1] - dungeon_room[i][3] + 5) {
						dungeon_room[i][1] = dungeon_division[i][3] + 1;
					}
				}

				if (dungeon_room[i][0] - dungeon_division[i][2] <= 1 || dungeon_room[i][1] - dungeon_division[i][3] <= 1) {
					dungeon_room[i][0] = dungeon_division[i][2] + 1;
					dungeon_room[i][1] = dungeon_division[i][3] + 1;
				}
				const std::size_t l{ (std::size_t)rnd(1,(std::int_fast32_t)(dungeon_division[i][0] - dungeon_room[i][0] - 5)) + 2 };
				const std::size_t n{ (std::size_t)rnd(1,(std::int_fast32_t)(dungeon_division[i][1] - dungeon_room[i][1] - 5)) + 2 };
				dungeon_room[i][0] += l;
				dungeon_room[i][2] += l;
				dungeon_room[i][1] += n;
				dungeon_room[i][3] += n;

				for (std::size_t j{ dungeon_room[i][2] }; j < dungeon_room[i][0]; ++j)
					for (std::size_t k{ dungeon_room[i][3] }; k < dungeon_room[i][1]; ++k)
						matrix_[j][k] = static_cast<Matrix_Int_>(1);
			}


			//通路を生成する処理
			//通路は２部屋間の細い道のことを指す。
			//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
			//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
			//まず、前の通路を作り、次に後の通路を作る。
			//最後に前と後の通路を繋げる。
			std::size_t roomAfter{};
			for (std::size_t roomBefore{}; roomBefore < mapDivCount; ++roomBefore) {
				roomAfter = dungeon_road[roomBefore][0];
				//X座標の通路
				switch (dungeon_road[roomBefore][1]) {
				case RL_COUNT_X:
					dungeon_road[roomBefore][2] = (std::size_t)rnd((std::int_fast32_t)(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1)); //前側の通路の位置
					dungeon_road[roomBefore][3] = (std::size_t)rnd((std::int_fast32_t)(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1)); //後側の通路の位置
																																			 //前の通路
					for (std::size_t j{ dungeon_room[roomBefore][0] }; j < dungeon_division[roomBefore][0]; ++j)
						matrix_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画

					//後の通路
					for (std::size_t j{ dungeon_division[roomAfter][2] }; j < dungeon_room[roomAfter][2]; ++j)
						matrix_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画

					//通路をつなぐ
					for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
						matrix_[dungeon_division[roomBefore][0]][j] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画 2から5(上から下)
					for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
						matrix_[dungeon_division[roomBefore][0]][j] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画 5から2(下から上)
					break;

				case RL_COUNT_Y:
					dungeon_road[roomBefore][2] = (std::size_t)rnd((std::int_fast32_t)(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1)); //前側の通路の位置
					dungeon_road[roomBefore][3] = (std::size_t)rnd((std::int_fast32_t)(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1)); //後側の通路の位置
																																			 //前の通路
					for (std::size_t j{ dungeon_room[roomBefore][1] }; j < dungeon_division[roomBefore][1]; ++j)
						matrix_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画

					//後の通路
					for (std::size_t j{ dungeon_division[roomAfter][3] }; j < dungeon_room[roomAfter][3]; ++j)
						matrix_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画

					//通路をつなぐ
					for (std::size_t j{ dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2] }; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
						matrix_[j][dungeon_division[roomBefore][1]] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画
					for (std::size_t j{ dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2] }; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
						matrix_[j][dungeon_division[roomBefore][1]] = static_cast<Matrix_Int_>(1); //通路をマップチップに線画
					break;
				}
			}
			return;
		}

	};
}

#endif //Included Dungeon Template Library