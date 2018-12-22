#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_SIMPLE_ROGUE_LIKE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_SIMPLE_ROGUE_LIKE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

#include <stdlib.h>
#include <limits.h>
#include "DungeonRandom.h"

int absTemplateSimpleRogueLike(const int value_) {
	return (value_ < 0) ? (value_ * -1) : value_;
}

//生成される部屋の数 (正確に言うと生成される区域の数)---
//マップの区分け最小数
//マップの区分け数加算
//生成される部屋のサイズ---
//部屋のX座標の最小サイズ
//部屋のX座標のサイズ加算
//部屋のY座標の最小サイズ
//部屋のY座標のサイズ加算
void createSimpleRogueLikeAll(int** stl_, const int x_, const int y_, const int division_min, const int division_rand_max, const int room_min_x, const int room_rand_max_x, const int room_min_y, const int room_rand_max_y) {
	//void createSimpleRogueLike2(int** stl_, const int x_, const int y_, const int division_min = 3, const int division_rand_max = 4, const int room_min_x = 5, const int room_rand_max_x = 2, const int room_min_y = 5, const int room_rand_max_y = 2) {
	if (y_ == 0 || x_ == 0) return;
	//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
	const int mapDivCount = division_min + (int)dungeonRand2(1, (int)division_rand_max); //マップの区分け数 (部屋の個数) 0~yまでの部屋ID

	int **dungeon_division, *dungeon_division_base_matrix;
	int **dungeon_room, *dungeon_room_base_matrix;
	int **dungeon_road, *dungeon_road_base_matrix;
	const int y = (int)mapDivCount, x = 4;

	//マップの区域 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
	dungeon_division = (int **)malloc(y * sizeof(int *));
	dungeon_division_base_matrix = (int *)calloc(y * x, sizeof(int));
	//マップの部屋 [部屋ID][X終点 , Y終点 , X始点 , Y始点]
	dungeon_room = (int **)malloc(y * sizeof(int *));
	dungeon_room_base_matrix = (int *)calloc(y * x, sizeof(int));
	//マップの道 [部屋ID(前)][繋がる先の部屋ID(後) , (0.X座標 , 1.Y座標) , (前)側の通路の位置 , (後)側の通路の位置]
	dungeon_road = (int **)malloc(y * sizeof(int *));
	dungeon_road_base_matrix = (int *)calloc(y * x, sizeof(int));
	for (int i = 0; i < y; ++i) {
		dungeon_division[i] = dungeon_division_base_matrix + i * x;
		dungeon_room[i] = dungeon_room_base_matrix + i * x;
		dungeon_road[i] = dungeon_road_base_matrix + i * x;
	}

	dungeon_division[0][0] = (y_ - 1); //マップの区分け初期サイズX終点 (マップの大きさX軸)
	dungeon_division[0][1] = (x_ - 1); //マップの区分け初期サイズY終点 (マップの大きさY軸)
	dungeon_division[0][2] = 1; //マップの区分け初期サイズX始点 (マップの大きさX軸)
	dungeon_division[0][3] = 1; //マップの区分け初期サイズY始点 (マップの大きさY軸)

	dungeon_road[0][0] = INT_MAX;
	dungeon_road[0][1] = INT_MAX;

	//マップを区分けしていく処理(区域を分割する処理)
	int division_After = 0;
	int count = 0; //(0:X, 1:Y) X軸で分けるかY軸で分けるか決める

	for (int i = 1; i < mapDivCount; ++i) {

		//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
		division_After = (int)dungeonRand1((int)i);

		//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
		if (dungeon_division[division_After][0] - dungeon_division[division_After][2] > dungeon_division[division_After][1] - dungeon_division[division_After][3]) count = 0;
		else count = 1;

		if (dungeon_division[division_After][count] - dungeon_division[division_After][count + 2] < division_rand_max * 2 + 8) {
			int k = 0;
			for (int j = 1; j < mapDivCount; ++j) {
				if (dungeon_division[j][0] - dungeon_division[j][2] > k) {
					k = dungeon_division[j][0] - dungeon_division[j][2];
					division_After = j;
					count = 0;
				}
				if (dungeon_division[j][1] - dungeon_division[j][3] > k) {
					k = dungeon_division[j][1] - dungeon_division[j][3];
					division_After = j;
					count = 1;
				}
			}
		}

		dungeon_road[i][0] = division_After;
		dungeon_road[i][1] = count;

		for (int j = 1; j < i; ++j)
			if (dungeon_road[j][0] == division_After) dungeon_road[j][0] = i;

		//count軸の設定
		//0.軸の右端(iR)の座標(division_After*R/3~2division_After*R/3)
		dungeon_division[i][count] = dungeon_division[division_After][count + 2] + ((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3) + (int)(dungeonRand2(1, (int)((dungeon_division[division_After][count] - dungeon_division[division_After][count + 2]) / 3)));

		dungeon_division[i][count + 2] = dungeon_division[division_After][count + 2]; //0.軸の左端(iL)の座標(division_AfterL)
		dungeon_division[division_After][count + 2] = dungeon_division[i][count]; //division_After軸の左端(division_AfterL)の座標(iR)

		//countとは逆の軸の設定
		dungeon_division[i][absTemplateSimpleRogueLike(count - 1)] = dungeon_division[division_After][absTemplateSimpleRogueLike(count - 1)]; //軸の右端(iR)の座標(division_AfterR)
		dungeon_division[i][absTemplateSimpleRogueLike(count - 1) + 2] = dungeon_division[division_After][absTemplateSimpleRogueLike(count - 1) + 2]; //軸の左端(iL)の座標(division_AfterL)
	}

	//部屋を生成する処理
	for (int i = 0; i < mapDivCount; ++i) {//区分け
		dungeon_room[i][2] = dungeon_division[i][2]; //区分けX始点をマップX始点へ代入
		dungeon_room[i][3] = dungeon_division[i][3]; //区分けY始点をマップY始点へ代入

		//X座標の部屋の長さを指定
		dungeon_room[i][0] = dungeon_division[i][2] + room_min_x + (int)dungeonRand2(1, (int)room_rand_max_x);
		if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
			dungeon_room[i][0] = dungeon_division[i][0] - 4;
			if (dungeon_division[i][0] - dungeon_division[i][2] < dungeon_room[i][0] - dungeon_room[i][2] + 5) {
				dungeon_room[i][0] = dungeon_division[i][2] + 1;
			}
		}

		dungeon_room[i][1] = dungeon_division[i][3] + room_min_y + (int)dungeonRand2(1, (int)room_rand_max_y);
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
		const int l = (int)dungeonRand2(1, (int)(dungeon_division[i][0] - dungeon_room[i][0] - 5)) + 2;
		const int n = (int)dungeonRand2(1, (int)(dungeon_division[i][1] - dungeon_room[i][1] - 5)) + 2;
		dungeon_room[i][0] += l;
		dungeon_room[i][2] += l;
		dungeon_room[i][1] += n;
		dungeon_room[i][3] += n;

		for (int j = dungeon_room[i][2]; j < dungeon_room[i][0]; ++j)
			for (int k = dungeon_room[i][3]; k < dungeon_room[i][1]; ++k)
				stl_[j][k] = 1;
	}
	//通路を生成する処理
	//通路は２部屋間の細い道のことを指す。
	//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
	//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
	//まず、前の通路を作り、次に後の通路を作る。
	//最後に前と後の通路を繋げる。
	int roomAfter = 0;
	for (int roomBefore = 0; roomBefore < mapDivCount; ++roomBefore) {
		roomAfter = dungeon_road[roomBefore][0];
		//X座標の通路
		switch (dungeon_road[roomBefore][1]) {
		case 0:
			dungeon_road[roomBefore][2] = (int)dungeonRand1((int)(dungeon_room[roomBefore][1] - dungeon_room[roomBefore][3] - 1)); //前側の通路の位置
			dungeon_road[roomBefore][3] = (int)dungeonRand1((int)(dungeon_room[roomAfter][1] - dungeon_room[roomAfter][3] - 1)); //後側の通路の位置
																																	 //前の通路
			for (int j = dungeon_room[roomBefore][0]; j < dungeon_division[roomBefore][0]; ++j)
				stl_[j][dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]] = 1; //通路をマップチップに線画

			//後の通路
			for (int j = dungeon_division[roomAfter][2]; j < dungeon_room[roomAfter][2]; ++j)
				stl_[j][dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]] = 1; //通路をマップチップに線画

			//通路をつなぐ
			for (int j = dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; ++j)
				stl_[dungeon_division[roomBefore][0]][j] = 1; //通路をマップチップに線画 2から5(上から下)
			for (int j = dungeon_road[roomBefore][3] + dungeon_room[roomAfter][3]; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][3]; ++j)
				stl_[dungeon_division[roomBefore][0]][j] = 1; //通路をマップチップに線画 5から2(下から上)
			break;

		case 1:
			dungeon_road[roomBefore][2] = (int)dungeonRand1((int)(dungeon_room[roomBefore][0] - dungeon_room[roomBefore][2] - 1)); //前側の通路の位置
			dungeon_road[roomBefore][3] = (int)dungeonRand1((int)(dungeon_room[roomAfter][0] - dungeon_room[roomAfter][2] - 1)); //後側の通路の位置
																																	 //前の通路
			for (int j = dungeon_room[roomBefore][1]; j < dungeon_division[roomBefore][1]; ++j)
				stl_[dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]][j] = 1; //通路をマップチップに線画

			//後の通路
			for (int j = dungeon_division[roomAfter][3]; j < dungeon_room[roomAfter][3]; ++j)
				stl_[dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]][j] = 1; //通路をマップチップに線画

			//通路をつなぐ
			for (int j = dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; j <= dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; ++j)
				stl_[j][dungeon_division[roomBefore][1]] = 1; //通路をマップチップに線画
			for (int j = dungeon_road[roomBefore][3] + dungeon_room[roomAfter][2]; j <= dungeon_road[roomBefore][2] + dungeon_room[roomBefore][2]; ++j)
				stl_[j][dungeon_division[roomBefore][1]] = 1; //通路をマップチップに線画
			break;
		}
	}
	free(dungeon_division_base_matrix);
	free(dungeon_division);
	free(dungeon_room_base_matrix);
	free(dungeon_room);
	free(dungeon_road_base_matrix);
	free(dungeon_road);
	return;
}
void createSimpleRogueLike(int** stl_, const int x_, const int y_) {
	createSimpleRogueLikeAll(stl_, x_, y_, 3, 4, 5, 2, 5, 2);
}

#endif //Included Dungeon Template Library