#include "DTL.hpp"
#include <array>
#include <bitset>

int main() {

	using matrix_t = bool;

	std::array<std::bitset<64>, 64> matrix{ {} };

	dtl::fileRead_CSV<matrix_t>(matrix, "svi.csv");

	//dtl::SimpleVoronoiIsland<matrix_t> svi(matrix, 100, 0.5);
	dtl::fileWrite<matrix_t>(matrix, "svi.txt");
	dtl::fileWrite_CSV<matrix_t>(matrix, "svi.csv");

	return 0;
}