#include "DTL.hpp"
#include <iostream>
#include <array>

int main() {
	//std::array<std::array<std::uint_fast8_t, 150>, 100> stl_{};

	//dtl::SimpleVoronoiIsland<std::uint_fast8_t> svi(stl_, 150, 0.5);
	//dtl::noiseShoreBothBool(stl_, 0.4);

	//dtl::dungeonStringOutputBool(stl_, "\x1b[42m　\x1b[49m", "\x1b[44m　\x1b[49m");

	//dtl::Bucket<std::uint_fast8_t>(stl_, 0, 0, 2);

	//dtl::Pen<std::uint_fast8_t>(stl_, 0, 0, 0);

	//dtl::dungeonStringOutput(stl_, "\x1b[46m　\x1b[49m", "\x1b[42m　\x1b[49m", "\x1b[44m　\x1b[49m");

	std::array<std::array<std::uint_fast8_t, 8>, 8> stl_{ {} };

	dtl::Reversi<std::uint_fast8_t> re(stl_);

	std::int_fast32_t turn{ 1 };
	for (std::size_t i{}; i < 15; ++i) {
		dtl::dungeonStringOutput(stl_, "\x1b[40m・", "\x1b[40m○", "\x1b[40m●", "\x1b[40m　");
		if (!dtl::isPassReversi(stl_, turn) && (dtl::reversiAI(stl_, turn, dtl::reversiAI_Priority, dtl::reversiAI_Greed, (turn == 1)))) {
			turn = 3 - turn;
		}
		else break;
	}

	//dtl::DungeonInit<std::uint_fast8_t> di(stl_);
	////dtl::DungeonBorder<std::uint_fast8_t> db(stl_);

	//dtl::RogueLike<std::uint_fast8_t> sr(stl_);
	//dtl::PointGrid<std::uint_fast8_t> pg(stl_, 3);

	//dtl::dungeonStringOutputBool(stl_, "■", "　");
	//dtl::dungeonStringOutputBool(stl_, "　", "■");

	

}