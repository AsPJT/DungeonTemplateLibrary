#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

//2値化処理
void dungeonBinarizationOver(int** matrix_, const int x_, const int y_, const int value_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (matrix_[i][j] >= value_) matrix_[i][j] = 1;
			else matrix_[i][j] = 0;
		}
}

void dungeonBinarization(int** matrix_, const int x_, const int y_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (matrix_[i][j]) matrix_[i][j] = 1;
			else matrix_[i][j] = 0;
		}
}

void dungeonBinarizationBool(int** matrix_, int** stl2_, const int x_, const int y_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (matrix_[i][j]) stl2_[i][j] = 1;
			else stl2_[i][j] = 0;
		}
}

void dungeonBinarizationBoolOver(int** matrix_, int** stl2_, const int x_, const int y_, const int value_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (matrix_[i][j] >= value_) stl2_[i][j] = 1;
			else stl2_[i][j] = 0;
		}
}

#endif //Included Dungeon Template Library