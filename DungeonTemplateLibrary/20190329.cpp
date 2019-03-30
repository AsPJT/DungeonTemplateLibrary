#include "DTL.hpp"
#include <array>

int main() {

	using std::array;
	using dtl::shape::Border;
	using dtl::console::OutputStringU8;

	constexpr std::size_t size_x{ 64 };
	constexpr std::size_t size_y{ 64 };

	array<array<std::uint_fast8_t, size_x>, size_y> matrix{ {} };

	dtl::shape::CellularAutomatonIsland<std::uint_fast8_t>(1, 0, 50, 0.5).draw(matrix);

	//Border<std::uint_fast8_t>(0, 0, size_x / 2, size_y / 2, 1).draw(matrix);
	//Border<std::uint_fast8_t>(size_x / 2, 0, size_x / 2, size_y / 2, 2).draw(matrix);
	//Border<std::uint_fast8_t>(0, size_y / 2, size_x / 2, size_y / 2, 3).draw(matrix);
	//Border<std::uint_fast8_t>(size_x / 2, size_y / 2, size_x / 2, size_y / 2, 4).draw(matrix);
	
	dtl::retouch::RemovePoint<std::uint_fast8_t>().draw(matrix);
	OutputStringU8("・","■","▲","　","▲").draw(matrix);

	//dtl::tile::stl::outputTileCUI(matrix);

}