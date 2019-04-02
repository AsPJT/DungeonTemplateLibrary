#include "DTL.hpp"
#include <array>
#include <chrono>

int main() {

	using std::array;
	using dtl::shape::Border;
	using dtl::console::OutputStringU8;

	constexpr std::size_t size_x{ 256 };
	constexpr std::size_t size_y{ 256 };

	array<array<std::uint_fast8_t, size_x>, size_y> matrix{ {} };
	std::chrono::system_clock::time_point  start, end;

	start = std::chrono::system_clock::now();
	//dtl::shape::CellularAutomatonIsland<std::uint_fast8_t>(1, 0, 20, 0.5).draw(matrix);
	//dtl::shape::MixRect<std::uint_fast8_t>(0, 1, 2, 3, 4).draw(matrix);
	dtl::shape::CellularAutomatonMixIsland<std::uint_fast8_t>(200, 0, 1, 2, 3, 4).draw(matrix);
	end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	//Border<std::uint_fast8_t>(0, 0, size_x / 2, size_y / 2, 1).draw(matrix);
	//Border<std::uint_fast8_t>(size_x / 2, 0, size_x / 2, size_y / 2, 2).draw(matrix);
	//Border<std::uint_fast8_t>(0, size_y / 2, size_x / 2, size_y / 2, 3).draw(matrix);
	//Border<std::uint_fast8_t>(size_x / 2, size_y / 2, size_x / 2, size_y / 2, 4).draw(matrix);
	
	dtl::retouch::RemovePoint<std::uint_fast8_t>().draw(matrix);
	OutputStringU8(" ","/","#","%","*").draw(matrix);

	//dtl::tile::stl::outputTileCUI(matrix);

}