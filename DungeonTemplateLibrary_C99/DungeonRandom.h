#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_RANDOM
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_RANDOM
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <stddef.h>
#include <stdlib.h>
#include <time.h>

		//初期値
void dungeonSeed0(void) {
	srand((unsigned int)time(NULL));
}
void dungeonSeed1(const unsigned int seed_) {
	srand((unsigned int)seed_);
}

//通常の乱数
int dungeonRand0(void) {
	return (int)rand();
}
//0～最大値-1 (余りの範囲の一様分布乱数)
int dungeonRand1(const int max_) {
	return (max_ > 1) ? ((int)(((double)rand() / ((double)RAND_MAX + 1)) * max_)) : 0;
}
//最小値～最大値
int dungeonRand2(const int min_, const int max_) {
	return (max_ > 1) ? ((int)(((double)rand() / ((double)RAND_MAX + 1)) * (max_ - min_ + 1)) + min_) : min_;
}
//確率
int dungeonRandBool1(const double probability_) {
	return (((double)rand() / ((double)RAND_MAX + 1)) < probability_) ? 1 : 0;
}
int dungeonRandBool0(void) {
	return ((dungeonRand1(2) == 1) ? 1 : 0);
}

#endif //Included Dungeon Template Library