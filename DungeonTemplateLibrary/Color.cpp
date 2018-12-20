//ダンジョン生成チェック

#include <cstdint>
#include <array>
#include <bitset>

#include "DungeonOutput.hpp"
#include "DungeonNoise.hpp"
#include "DungeonBinarization.hpp"
#include "DungeonStandard.hpp"

#include "RogueLike.hpp"
#include "SimpleVoronoiIsland.hpp"
#include "FractalIsland.hpp"
#include "MazeDig.hpp"
#include "SimpleRogueLike.hpp"

int main() {

	using int_map_t = std::uint_fast8_t;
	constexpr std::size_t dungeon_size_x{ 128 };
	constexpr std::size_t dungeon_size_y{ 96 };
	
	std::array<std::array<int_map_t, dungeon_size_x>, dungeon_size_y> dungeon{ {} };
	std::array<std::bitset<dungeon_size_x>, dungeon_size_y> dungeon_bool{ {} };


	//std::vector<std::vector<int_map_t>> dungeon(dungeon_size_y, std::vector<int_map_t>(dungeon_size_x, 0));

	if(!dtl::dungeonArrayCheck(dungeon)) return 0;
	if (!dtl::dungeonArrayCheckBitset(dungeon_bool)) return 0;

	//ローグライク(穴掘り)
	dtl::RogueLike<int_map_t> rogue_like(dungeon, 50);
	dtl::dungeonStringOutput(dungeon, "\x1b[40m　", "\x1b[47m　", "\x1b[46m　", "\x1b[45m　", "\x1b[44m　");

	dtl::dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(ボロノイ)
	dtl::SimpleVoronoiIsland<int_map_t> simple_voronoi_island(dungeon, 100, 0.5);
	dtl::noiseShoreBool(dungeon, 0.5);
	dtl::dungeonStringOutputBool(dungeon, "\x1b[42m　", "\x1b[44m　");

	dtl::dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//島(フラクタル)
	dtl::FractalIsland<int_map_t> fractal_island(dungeon, 0, 255);
	dtl::dungeonBinarization(dungeon, 150);
	dtl::noiseShoreBool(dungeon, 0.5);
	dtl::dungeonStringOutputBool(dungeon, "\x1b[42m　", "\x1b[44m　");

	dtl::dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//迷路(穴掘り法)
	dtl::MazeDig<int_map_t> maze_dig(dungeon);
	dtl::dungeonStringOutputBool(dungeon, "\x1b[47m　", "\x1b[40m　");

	//dtl::dungeonStringOutputBool(dungeon, " ", " ");

	dtl::dungeonInit_RangeBasedFor(dungeon);
	std::cout << "\n";

	//ローグライク(区域分割法)
	dtl::SimpleRogueLike<int_map_t> simple_rogue_like(dungeon);
	dtl::dungeonStringOutputBool(dungeon, "\x1b[47m　", "\x1b[40m　");

	std::cout << std::endl;

}