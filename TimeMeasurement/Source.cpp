#include "DTL.hpp"
#include <cstdint>
#include <iostream>
#include <chrono>
#include <array>
#include <bitset>

template<typename Matrix_,typename Dungeon_Generation_>
constexpr void loop(Matrix_& matrix_, Dungeon_Generation_& dungeon_generation_, const std::size_t n_) noexcept {



	for (std::size_t i{}; i < n_; ++i) {
		dtl::generation::stl::dungeonInit(matrix_);
		dungeon_generation_.create(matrix_);
		dtl::noiseShoreBothBool(matrix_, 0.4);
	}
}

int main() {

	std::array<std::array<std::bitset<2>, 64>, 64> dungeon_layer{ {} };
	dtl::generation::layer::stl::dungeonInit(dungeon_layer, 0);


	std::array<std::bitset<64>, 64> dungeon{ {} };
	//std::array<std::array<std::uint_fast8_t,256>, 256> dungeon{ {} };

	dtl::generation::stl::SimpleVoronoiIsland<bool> dungeon_generation;
	//dtl::generation::VoronoiData<bool> d;

	//dtl::Border<bool> dungeon_generation;
	//dtl::FractalIsland<std::uint_fast8_t> dungeon_generation;
	//dtl::SimpleRogueLike<bool> dungeon_generation;
	

	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };

	//loop(dungeon, dungeon_generation, 10);
	for (std::size_t i{}; i < 10; ++i) {
		dtl::generation::stl::dungeonInit(dungeon);
		dungeon_generation.create(dungeon);
		dtl::noiseShoreBothBool(dungeon, 0.4);
	}

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

	dtl::output::stl::stringBool(dungeon, "#", ".");

	return 0;
}