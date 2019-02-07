#include <DTL.hpp>
#include <cstdint>
#include <iostream>
#include <chrono>
#include <array>
#include <bitset>

template<typename Matrix_,typename Dungeon_Generation_>
constexpr void loop(Matrix_& matrix_, Dungeon_Generation_& dungeon_generation_, const std::size_t n_) noexcept {



	for (std::size_t i{}; i < n_; ++i) {
		dtl::generator::common::stl::initDungeon(matrix_);
		dungeon_generation_.create(matrix_);
		dtl::noiseShoreBothBool(matrix_, 0.4);
	}
}

int main() {

	constexpr std::size_t size_x{ 64 };
	constexpr std::size_t size_y{ 64 };
	constexpr std::size_t layer_num{ 2 };
	std::array<std::array<std::bitset<layer_num>, size_x>, size_y> dungeon_layer{ {} };
	dtl::generator::common::layer::stl::initDungeon(dungeon_layer, 0);
	dtl::generator::common::layer::stl::createBorder(dungeon_layer, 0);
	dtl::generator::common::layer::stl::createBorderOdd(dungeon_layer, 0);
	dtl::generator::common::layer::stl::createPointGrid(dungeon_layer, 0);
	dtl::generator::common::layer::stl::createPointGridField(dungeon_layer, 0);
	dtl::generator::common::layer::stl::DungeonInit<bool>(dungeon_layer, 0);
	dtl::generator::common::layer::stl::Border<bool>(dungeon_layer, 0);
	dtl::generator::common::layer::stl::BorderOdd<bool>(dungeon_layer, 0);
	dtl::generator::common::layer::stl::PointGrid<bool>(dungeon_layer, 0);
	dtl::generator::common::layer::stl::PointGridField<bool>(dungeon_layer, 0);

	dtl::generator::common::layer::normal::initDungeon(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::createBorder(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::createBorderOdd(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::createPointGrid(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::createPointGridField(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::DungeonInit<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::Border<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::BorderOdd<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::PointGrid<bool>(dungeon_layer, 0, size_x, size_y);
	dtl::generator::common::layer::normal::PointGridField<bool>(dungeon_layer, 0, size_x, size_y);

	std::array<std::bitset<64>, 64> dungeon{ {} };
	//std::array<std::array<std::uint_fast8_t,256>, 256> dungeon{ {} };

	dtl::generator::terrain::stl::SimpleVoronoiIsland<bool> dungeon_generation;
	//dtl::generator::VoronoiData<bool> d;

	//dtl::Border<bool> dungeon_generation;
	//dtl::FractalIsland<std::uint_fast8_t> dungeon_generation;
	//dtl::SimpleRogueLike<bool> dungeon_generation;
	

	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };

	//loop(dungeon, dungeon_generation, 10);
	for (std::size_t i{}; i < 10; ++i) {
		dtl::generator::common::stl::initDungeon(dungeon);
		dungeon_generation.create(dungeon);
		dtl::utility::noiseShoreBothBool(dungeon, 0.4);
	}

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

	dtl::console::output::stl::stringBool(dungeon, "#", ".");

	return 0;
}