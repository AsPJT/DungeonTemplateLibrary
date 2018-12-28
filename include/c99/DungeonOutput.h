#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_OUTPUT
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_OUTPUT
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <stddef.h>
#include <stdio.h>

//数値出力
void dungeonNumberOutput(int** stl_, const int x_, const int y_) {
	for (int i = 0; i < y_; ++i) {
		for (int j = 0; j < x_; ++j)
			printf("%d", stl_[i][j]);
		printf("\n");
	}
}
void dungeonNumberStringOutput(int** stl_, const int x_, const int y_, const char* string_) {
	if (string_ == NULL) return;
	for (int i = 0; i < y_; ++i) {
		for (int j = 0; j < x_; ++j)
			printf("%d%s", stl_[i][j], string_);
		printf("\n");
	}
}
//文字出力
void dungeonStringOutputBool(int** stl_, const int x_, const int y_, const char* true_, const char* false_) {
	if (true_ == NULL || false_ == NULL) return;
	for (int i = 0; i < y_; ++i) {
		for (int j = 0; j < x_; ++j) {
			if (stl_[i][j]) printf("%s", true_);
			else printf("%s", false_);
		}
		printf("\n");
	}
}

#endif //Included Dungeon Template Library