#include "DungeonRandom.h"
#include <stdio.h>

int main(void) {

	dungeonSeed0();

	for (int i = 0; i < 100; ++i) {
		//printf("%d\n", dungeonRand1(5));
		printf("%d\n", dungeonRandBool1(0.8));
	}


	return 0;
}