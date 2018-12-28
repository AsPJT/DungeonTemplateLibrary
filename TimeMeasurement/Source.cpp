#include "DungeonOutput.hpp"
#include "DungeonNoise.hpp"
#include "DungeonBinarization.hpp"
#include "DungeonStandard.hpp"

#include "RogueLike.hpp"
#include "SimpleVoronoiIsland.hpp"
#include "FractalIsland.hpp"
#include "MazeDig.hpp"
#include "SimpleRogueLike.hpp"
#include "SimpleTerrain1.hpp"

#include <cstdint>
#include <iostream>
#include <chrono>
#include <array>
#include <bitset>

int main() {

	std::array<std::bitset<256>, 256> dungeon{ {} };
	dtl::SimpleVoronoiIsland<bool> simple_voronoi_island;

	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };

	dtl::dungeonInit(dungeon);
	simple_voronoi_island.create(dungeon, 3000, 0.5);
	dtl::noiseShoreBothBool(dungeon, 0.4);

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

	dtl::dungeonStringOutputBool(dungeon, "\x1b[42m@", "\x1b[44m@");

	return 0;
}