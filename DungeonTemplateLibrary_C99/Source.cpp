#include "DungeonRandom.h"
#include "DungeonOutput.h"
#include "FractalIsland.h"
#include "DungeonBinarization.h"
#include "DungeonNoise.h"
#include "DungeonStandard.h"
#include "SimpleRogueLike.h"
#include "SimpleVoronoiIsland.h"
#include <stdio.h>

int main(void) {

	int **dungeon, *dungeon_base_matrix;
	const int y = 128, x = 256;

	dungeon = (int **)malloc(y * sizeof(int *));
	dungeon_base_matrix = (int *)calloc(y * x, sizeof(int));
	for (int i = 0; i < y; ++i) {
		dungeon[i] = dungeon_base_matrix + i * x;
	}

	dungeonSeed0();

	//島(フラクタル)
	//createFractalIsland(dungeon, x, y);
	//dungeonBinarizationOver(dungeon, x, y, 150);
	//noiseShoreBool(dungeon, x, y, 0.5);
	//dungeonStringOutputBool(dungeon, x, y, "\x1b[42m　", "\x1b[44m　");

	//dungeonInit(dungeon, x, y);

	//ローグライク(区域分割法)
	//createSimpleRogueLike(dungeon, x, y);
	createSimpleVoronoiIsland(dungeon, x, y);
	noiseShoreBool(dungeon, x, y, 0.5);
	dungeonStringOutputBool(dungeon, x, y, "\x1b[42m　", "\x1b[44m　");

	dungeonInit(dungeon, x, y);

	free(dungeon_base_matrix);
	free(dungeon);

	return 0;
}