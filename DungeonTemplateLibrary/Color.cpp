//ダンジョン生成チェック

#include <cstdint>
#include <vector>

#include "DungeonOutput.hpp"
#include "DungeonNoise.hpp"
#include "DungeonBinarization.hpp"

#include "RogueLike.hpp"
#include "SimpleVoronoiIsland.hpp"
#include "FractalIsland.hpp"
#include "MazeDig.hpp"

template<typename STL_>
constexpr void dungeonInit_RangeBasedFor(STL_& stl_) noexcept {
	for (auto&& i : stl_)
		for (auto&& j : i)
			j = 0;
}

template<typename Int_, typename STL_>
constexpr void dungeonInit_RangeBasedFor(STL_& stl_, const Int_ value_) noexcept {
	for (auto&& i : stl_)
		for (auto&& j : i)
			j = value_;
}

int main() {

	using int_map_t = std::uint_fast8_t;
	std::vector<std::vector<int_map_t>> dungeon(96, std::vector<int_map_t>(128, 0));

	//ローグライク
	dtl::RogueLike<int_map_t> rogue_like(dungeon, 50);
	//dtl::dungeonStringOutput(dungeon, "\x1b[40m　", "\x1b[47m　", "\x1b[46m　", "\x1b[45m　", "\x1b[44m　");

	dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(ボロノイ)
	dtl::SimpleVoronoiIsland<int_map_t> simple_voronoi_island(dungeon, 100, 0.5);
	dtl::noiseShoreBool(dungeon, 0.5);
	//dtl::dungeonStringOutputBool(dungeon, "\x1b[42m　", "\x1b[44m　");

	dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(フラクタル)
	dtl::FractalIsland<int_map_t> fractal_island(dungeon, 0, 255);
	dtl::dungeonBinarization(dungeon, 150);
	dtl::noiseShoreBool(dungeon, 0.5);
	//dtl::dungeonStringOutputBool(dungeon, "\x1b[42m　", "\x1b[44m　");

	dungeonInit_RangeBasedFor<int_map_t>(dungeon, 1);
	std::cout << "\n";

	//迷路(穴掘り法)
	dtl::MazeDig<int_map_t> maze_dig(dungeon);
	//dtl::dungeonStringOutputBool(dungeon, "\x1b[40m　", "\x1b[47m　");

	dtl::dungeonStringOutputBool(dungeon, " ", " ");

	std::cout << std::endl;

}