#include <DTL.hpp>
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

	constexpr std::size_t size_x{ 64 };
	constexpr std::size_t size_y{ 64 };
	constexpr std::size_t layer_num{ 2 };
	std::array<std::array<std::bitset<layer_num>, size_x>, size_y> dungeon_layer{ {} };
	dtl::generation::layer::stl::dungeonInit(dungeon_layer, 0);
	dtl::generation::layer::stl::createBorder(dungeon_layer, 0);
	dtl::generation::layer::stl::createBorderOdd(dungeon_layer, 0);
	dtl::generation::layer::stl::createPointGrid(dungeon_layer, 0);
	dtl::generation::layer::stl::createPointGridField(dungeon_layer, 0);
	dtl::generation::layer::stl::DungeonInit<bool>(dungeon_layer, 0);
	dtl::generation::layer::stl::Border<bool>(dungeon_layer, 0);
	dtl::generation::layer::stl::BorderOdd<bool>(dungeon_layer, 0);
	dtl::generation::layer::stl::PointGrid<bool>(dungeon_layer, 0);
	dtl::generation::layer::stl::PointGridField<bool>(dungeon_layer, 0);

	dtl::generation::layer::normal::dungeonInit(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::createBorder(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::createBorderOdd(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::createPointGrid(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::createPointGridField(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::DungeonInit<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::Border<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::BorderOdd<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::PointGrid<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generation::layer::normal::PointGridField<bool>(dungeon_layer, 0, size_x, size_y);

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
		dtl::noise::shoreBothBool(dungeon, 0.4);
	}

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

	dtl::console::output::stl::stringBool(dungeon, "#", ".");

	return 0;
}