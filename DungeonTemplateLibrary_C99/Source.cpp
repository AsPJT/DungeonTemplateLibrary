#include "DungeonRandom.h"
#include "DungeonOutput.h"
#include "FractalIsland.h"
#include "DungeonBinarization.h"
#include "DungeonNoise.h"
#include <stdio.h>

int main(void) {

	int **matrix, *base_matrix;
	int y = 128, x = 128;

	matrix = (int **)malloc(y * sizeof(int *));
	base_matrix = (int *)calloc(y * x, sizeof(int));
	for (int i = 0; i < y; ++i) {
		matrix[i] = base_matrix + i * x;
	}

	dungeonSeed0();
	createFractalIsland(matrix, x, y);
	dungeonBinarizationOver(matrix, x, y, 150);
	noiseShoreBool(matrix, x, y, 0.5);
	dungeonStringOutputBool(matrix, x, y, "■", "ー");

	free(base_matrix);
	free(matrix);

	return 0;
}