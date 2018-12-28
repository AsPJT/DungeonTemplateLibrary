#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_SIMPLE_VORONOI_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_C99_SIMPLE_VORONOI_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <stdlib.h>
#include <limits.h>
#include "DungeonRandom.h"

struct PairSimpleVoronoiIsland {
	int first;
	int second;
};

int distanceSqrd_SimpleVoronoiIsland(const struct PairSimpleVoronoiIsland* point_, int x_, int y_) {
	x_ -= point_->first;
	y_ -= point_->second;
	return (x_ * x_) + (y_ * y_);
}

	int isMakeIsland_SimpleVoronoiIsland(const int x_, const int y_, const int numerator_, const int denominator_, const struct PairSimpleVoronoiIsland* point, const int point_count) {
		return (point[point_count].first > (x_ * numerator_ / denominator_) && point[point_count].first < (x_ * (denominator_ - numerator_) / denominator_)) && (point[point_count].second > (y_ * numerator_ / denominator_) && point[point_count].second < (y_ * (denominator_ - numerator_) / denominator_));
	}

	//コンストラクタ
	//void createSimpleVoronoiIslandAll(int** stl_, const int x_, const int y_, const int count_ = 100, const double rbool_ = 0.4, const int land_ = 1, const int sea_ = 0) {
	void createSimpleVoronoiIslandAll(int** stl_, const int x_, const int y_, const int count_, const double rbool_, const int land_, const int sea_) {
		struct PairSimpleVoronoiIsland* point = (struct PairSimpleVoronoiIsland*)malloc(sizeof(struct PairSimpleVoronoiIsland) * count_);
		int point_count = 0;
		int* color = (int*)malloc(sizeof(int) * count_);
		int color_count = 0;

		for (int i = 0; i < count_; ++i) {
			point[point_count].first = dungeonRand1(x_);
			point[point_count].second = dungeonRand1(y_);
			++point_count;
			if (isMakeIsland_SimpleVoronoiIsland(x_, y_, 2, 5, point, point_count-1) || (dungeonRandBool1(rbool_) && isMakeIsland_SimpleVoronoiIsland(x_, y_, 1, 5, point, point_count-1))) {
				color[color_count] = land_;
				++color_count;
			}
			else {
				color[color_count] = sea_;
				++color_count;
			}
		}
		int ds = 0, dist = 0, ind = 0;
		for (int hh = 0; hh < y_; ++hh)
			for (int ww = 0; ww < x_; ++ww) {
				ind = INT_MAX;
				dist = INT_MAX;
				for (int it = 0; it < point_count; ++it) {
					if ((ds = distanceSqrd_SimpleVoronoiIsland(&point[it], ww, hh)) >= dist) continue;
					dist = ds;
					ind = it;
				}
				if (ind != INT_MAX) stl_[hh][ww] = color[ind];
			}
		free(point);
		free(color);
	}
	void createSimpleVoronoiIsland(int** stl_, const int x_, const int y_) {
		createSimpleVoronoiIslandAll(stl_, x_, y_, 100, 0.4, 1, 0);
	}

#endif //Included Dungeon Template Library