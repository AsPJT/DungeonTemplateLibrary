#include "DTL.hpp"
#include <array>
#include <bitset>

int main() {

	using matrix_t = std::uint_fast8_t;

	//constexpr std::size_t x{ 64 };

	std::array<std::array<matrix_t, 12>, 12> matrix{ {} };

	//dtl::fileRead_CSV<matrix_t>(matrix, "svi.csv");

	////dtl::SimpleVoronoiIsland<matrix_t> svi(matrix, 100, 0.5);
	//dtl::fileWrite<matrix_t>(matrix, "svi.txt");
	//dtl::fileWrite_CSV<matrix_t>(matrix, "svi.csv");
	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::createBorder(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::Border<matrix_t> bo(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::createBorderOdd(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::BorderOdd<matrix_t> boo(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::createPointGrid(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::PointGrid<matrix_t> pg(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::createPointGridField(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	std::cout << std::endl;
	dtl::dungeonInit(matrix);
	dtl::PointGridField<matrix_t> pgf(matrix);
	dtl::dungeonStringOutputBool(matrix, "■", "　");

	return 0;
}