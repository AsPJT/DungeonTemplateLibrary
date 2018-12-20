#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_BINARIZATION
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//:::::----------::::::::::----------::::://

//2値化処理
void dungeonBinarizationOver(int** stl_, const int x_, const int y_, const int value_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (stl_[i][j] >= value_) stl_[i][j] = 1;
			else stl_[i][j] = 0;
		}
}

void dungeonBinarization(int** stl_, const int x_, const int y_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (stl_[i][j]) stl_[i][j] = 1;
			else stl_[i][j] = 0;
		}
}

void dungeonBinarizationBool(int** stl_, int** stl2_, const int x_, const int y_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (stl_[i][j]) stl2_[i][j] = 1;
			else stl2_[i][j] = 0;
		}
}

void dungeonBinarizationBoolOver(int** stl_, int** stl2_, const int x_, const int y_, const int value_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (stl_[i][j] >= value_) stl2_[i][j] = 1;
			else stl2_[i][j] = 0;
		}
}

#endif //Included Dungeon Template Library