#include "DTL.hpp"
#include <array>
#include <bitset>

int main() {

	using matrix_t = std::uint_fast8_t;

	//constexpr std::size_t x{ 64 };

	std::array<std::array<matrix_t, 64>, 64> matrix{ {} };

	//dtl::fileRead_CSV<matrix_t>(matrix, "svi.csv");

	////dtl::SimpleVoronoiIsland<matrix_t> svi(matrix, 100, 0.5);
	//dtl::fileWrite<matrix_t>(matrix, "svi.txt");
	//dtl::fileWrite_CSV<matrix_t>(matrix, "svi.csv");

	dtl::createBorder(matrix);

	dtl::dungeonStringOutputBool(matrix, "Å°", "Å@");

	return 0;
}