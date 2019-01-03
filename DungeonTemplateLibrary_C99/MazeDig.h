#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_MAZE_DIG
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_MAZE_DIG
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <stdlib.h>
#include "DungeonRandom.h"

enum MazeDigType {
	maze_dig_type_wall,
	maze_dig_type_way,
};

//生成チェック
int mazeDig_Check_MazeDig(const int x_, const int y_) {
	if (y_ <= 2) return 0;
	if (x_ <= 2) return 0;
	return 1;
}
//穴掘り
void mazeDig_Dig_MazeDig(int** data, const int x_, const int y_, int w_, int h_, const int id_wall_, const int id_empty_) {
	if (!mazeDig_Check_MazeDig(x_, y_)) return;
	int dx = 0, dy = 0;
	int random = dungeonRand0(), counter = 0;

	const int i_max = ((y_ % 2) == 0) ? y_ - 2 : y_ - 1;
	const int j_max = ((x_ % 2) == 0) ? x_ - 2 : x_ - 1;

	while (counter < 4) {
		switch ((random + counter) & 3)
		{
		case 0:dx = 0; dy = -2; break;
		case 1:dx = -2; dy = 0; break;
		case 2:dx = 0; dy = 2; break;
		case 3:dx = 2; dy = 0; break;
		default:dx = 0; dy = 0; break;
		}
		if (w_ + dx <= 0 || h_ + dy <= 0 || (w_ + dx) >= i_max || (h_ + dy) >= j_max || data[w_ + dx][h_ + dy] == id_empty_) {
			++counter;
		}
		else if (data[w_ + dx][h_ + dy] == id_wall_) {
			data[w_ + (dx / 2)][h_ + (dy / 2)] = id_empty_;
			data[w_ + dx][h_ + dy] = id_empty_;
			w_ += dx;
			h_ += dy;
			counter = 0;
			random = dungeonRand0();
		}
	}
	return;
}
//迷路生成
int mazeDig_CreateLoop_MazeDig(int** data, const int x_, const int y_, const int id_wall_, const int id_empty_, int* select_x, int* select_y) {
	int select_id = 0;
	const int i_max = ((y_ % 2) == 0) ? y_ - 2 : y_ - 1;
	const int j_max = ((x_ % 2) == 0) ? x_ - 2 : x_ - 1;

	for (int i = 1; i < i_max; i += 2)
		for (int j = 1; j < j_max; j += 2) {
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
void mazeDig_Create_MazeDig(int** data, const int x_, const int y_, const int id_wall_, const int id_empty_) {
	if (!mazeDig_Check_MazeDig(x_, y_)) return;
	data[1][1] = id_empty_;

	int select_id = 0;
	int* select_x = (int*)malloc(sizeof(int) * y_*x_);
	if (select_x == NULL) return;
	int* select_y = (int*)malloc(sizeof(int) * y_*x_);
	if (select_y == NULL) return;

	//座標を選ぶ
	while (1) {
		select_id = mazeDig_CreateLoop_MazeDig(data, x_, y_, id_wall_, id_empty_, select_x, select_y);
		if (select_id == 0) break;

		select_id = dungeonRand1(select_id);
		mazeDig_Dig_MazeDig(data, x_, y_, select_x[select_id], select_y[select_id], id_wall_, id_empty_);
	}
	free(select_x);
	free(select_y);
	return;
}

void createMazeDigAll(int** data, const int x_, const int y_, const int v1_, const int v2_) {
	mazeDig_Create_MazeDig(data, x_, y_, v1_, v2_);
}
void createMazeDig2(int** data, const int x_, const int y_, const int v1_) {
	mazeDig_Create_MazeDig(data, x_, y_, v1_, maze_dig_type_way);
}
void createMazeDig(int** data, const int x_, const int y_) {
	mazeDig_Create_MazeDig(data, x_, y_, maze_dig_type_wall, maze_dig_type_way);
}

#endif //Included Dungeon Template Library