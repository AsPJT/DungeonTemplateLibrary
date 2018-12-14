//ダンジョン生成チェック

#include <vector>
#include "DungeonOutput.hpp"
#include "DungeonNoise.hpp"

#include "RogueLike.hpp"
#include "SimpleVoronoiIsland.hpp"

template<typename STL_>
constexpr void dungeonInit_RangeBasedFor(STL_& stl_) {
	for (auto&& i : stl_)
		for (auto&& j : i)
			j = 0;
}

int main() {

	using int_map_t = int;
	std::vector<std::vector<int_map_t>> dungeon(96, std::vector<int_map_t>(96, 0));

	dtl::RogueLike<int_map_t> rogue_like(dungeon, 10);
	dtl::dungeonStringOutput(dungeon, " ", "#", "_", "*", "|");

	dungeonInit_RangeBasedFor(dungeon);

	dtl::SimpleVoronoiIsland<int_map_t> simple_voronoi_island(dungeon, 100, 0.5);
	dtl::noiseShoreBool(dungeon, 0.5);
	dtl::dungeonStringOutputBool(dungeon, "#", "_");

}