//ダンジョン生成チェック

#include <cstdint>
#include <vector>

#include "DungeonOutput.hpp"
#include "DungeonNoise.hpp"
#include "DungeonBinarization.hpp"

#include "RogueLike.hpp"
#include "SimpleVoronoiIsland.hpp"
#include "FractalIsland.hpp"

template<typename STL_>
constexpr void dungeonInit_RangeBasedFor(STL_& stl_) {
	for (auto&& i : stl_)
		for (auto&& j : i)
			j = 0;
}

int main() {

	using int_map_t = std::uint_fast8_t;
	std::vector<std::vector<int_map_t>> dungeon(96, std::vector<int_map_t>(192, 0));

	//ローグライク
	dtl::RogueLike<int_map_t> rogue_like(dungeon, 50);
	dtl::dungeonStringOutput(dungeon, "_", "#", " ", "*", "-");

	dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(ボロノイ)
	dtl::SimpleVoronoiIsland<int_map_t> simple_voronoi_island(dungeon, 100, 0.5);
	dtl::noiseShoreBool(dungeon, 0.5);
	dtl::dungeonStringOutputBool(dungeon, "#", "_");

	dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(フラクタル)
	dtl::FractalIsland<int_map_t> fractal_island(dungeon, 0, 255);
	dtl::dungeonBinarization(dungeon, 150);
	dtl::noiseShoreBool(dungeon, 0.5);
	dtl::dungeonStringOutputBool(dungeon, "#", "_");


}