//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://
#include "DTL.hpp"

#include <iostream>
#include <array>

int main() {

	using terrain_t = std::uint_fast8_t;

	std::array<std::array<terrain_t, 150>, 100> stl_{};

	dtl::SimpleVoronoiIsland<terrain_t> svi(stl_, 150, 0.5);
	dtl::noiseShoreBothBool(stl_, 0.4);
	dtl::Bucket<terrain_t>(stl_, 0, 0, 2);
	dtl::dungeonStringOutput(stl_, "\x1b[46m \x1b[49m", "\x1b[42m \x1b[49m", "\x1b[44m \x1b[49m");

}