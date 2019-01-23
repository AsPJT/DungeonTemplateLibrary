#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_NOISE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_DUNGEON_NOISE
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include "DungeonRandom.h"
	
void noiseBool3(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_, const int false_tile_) {
	for (int i = 0; i < y_; ++i)
		for (int j = 0; j < x_; ++j) {
			if (!dungeonRandBool1(rbool_)) continue;
			if (matrix_[i][j]) matrix_[i][j] = false_tile_;
			else matrix_[i][j] = true_tile_;
		}
}
void noiseBool2(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_) {
	noiseBool3(matrix_, x_, y_, rbool_, true_tile_, 0);
}
void noiseBool(int** matrix_, const int x_, const int y_, const double rbool_) {
	noiseBool3(matrix_, x_, y_, rbool_, 1, 0);
}

//ノイズを発生させる
void noiseShoreBool(int** matrix_, const int x_, const int y_, const double rbool_) {
	for (int i = 1; i < y_; ++i)
		for (int j = 1; j < x_; ++j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
			if (matrix_[i][j]) matrix_[i][j] = 0;
			else matrix_[i][j] = 1;
		}
}

void rnoiseShoreBool(int** matrix_, const int x_, const int y_, const double rbool_) {
	for (int i = y_ - 1; i >= 1; --i)
		for (int j = x_ - 1; j >= 1; --j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
			if (matrix_[i - 1][j - 1]) matrix_[i - 1][j - 1] = 0;
			else matrix_[i - 1][j - 1] = 1;
		}
}


void noiseShoreBothBool(int** matrix_, const int x_, const int y_, const double rbool_) {
	noiseShoreBool(matrix_, x_, y_, rbool_);
	rnoiseShoreBool(matrix_, x_, y_, rbool_);
}

void noiseShoreBothBool2(int** matrix_, const int x_, const int y_, const double rbool1_, const double rbool2_) {
	noiseShoreBool(matrix_, x_, y_, rbool1_);
	rnoiseShoreBool(matrix_, x_, y_, rbool2_);
}

void rnoiseShoreBothBool(int** matrix_, const int x_, const int y_, const double rbool_) {
	rnoiseShoreBool(matrix_, x_, y_, rbool_);
	noiseShoreBool(matrix_, x_, y_, rbool_);
}

void rnoiseShoreBothBool2(int** matrix_, const int x_, const int y_, const double rbool1_, const double rbool2_) {
	rnoiseShoreBool(matrix_, x_, y_, rbool1_);
	noiseShoreBool(matrix_, x_, y_, rbool2_);
}

void noiseShore3(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_, const int false_tile_) {
	for (int i = 1; i < y_; ++i)
		for (int j = 1; j < x_; ++j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
			if (matrix_[i][j]) matrix_[i][j] = false_tile_;
			else matrix_[i][j] = true_tile_;
		}
}
void noiseShore2(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_) {
	noiseShore3(matrix_, x_, y_, rbool_, true_tile_, 0);
}
void noiseShore(int** matrix_, const int x_, const int y_, const double rbool_) {
	noiseShore3(matrix_, x_, y_, rbool_, 1, 0);
}

void rnoiseShore3(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_, const int false_tile_) {
	for (int i = y_ - 1; i >= 1; --i)
		for (int j = x_ - 1; j >= 1; --j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
			if (matrix_[i - 1][j - 1]) matrix_[i - 1][j - 1] = false_tile_;
			else matrix_[i - 1][j - 1] = true_tile_;
		}
}
void rnoiseShore2(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_) {
	rnoiseShore3(matrix_, x_, y_, rbool_, true_tile_, 0);
}
void rnoiseShore(int** matrix_, const int x_, const int y_, const double rbool_) {
	rnoiseShore3(matrix_, x_, y_, rbool_, 1, 0);
}


void noiseShoreOver3(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_, const int false_tile_) {
	for (int i = 1; i < y_; ++i)
		for (int j = 1; j < x_; ++j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i][j] == matrix_[i][j - 1] && matrix_[i][j] == matrix_[i - 1][j])) continue;
			if (matrix_[i][j] >= true_tile_) matrix_[i][j] = false_tile_;
			else matrix_[i][j] = true_tile_;
		}
}
void noiseShoreOver2(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_) {
	noiseShoreOver3(matrix_, x_, y_, rbool_, true_tile_, 0);
}
void noiseShoreOver(int** matrix_, const int x_, const int y_, const double rbool_) {
	noiseShoreOver3(matrix_, x_, y_, rbool_, 1, 0);
}

void rnoiseShoreOver3(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_, const int false_tile_) {
	for (int i = y_ - 1; i >= 1; --i)
		for (int j = x_ - 1; j >= 1; --j) {
			if (!dungeonRandBool1(rbool_) || (matrix_[i - 1][j - 1] == matrix_[i][j - 1] && matrix_[i - 1][j - 1] == matrix_[i - 1][j])) continue;
			if (matrix_[i - 1][j - 1] >= true_tile_) matrix_[i - 1][j - 1] = false_tile_;
			else matrix_[i - 1][j - 1] = true_tile_;
		}
}
void rnoiseShoreOver2(int** matrix_, const int x_, const int y_, const double rbool_, const int true_tile_) {
	rnoiseShoreOver3(matrix_, x_, y_, rbool_, true_tile_, 0);
}
void rnoiseShoreOver(int** matrix_, const int x_, const int y_, const double rbool_) {
	rnoiseShoreOver3(matrix_, x_, y_, rbool_, 1, 0);
}

#endif //Included Dungeon Template Library