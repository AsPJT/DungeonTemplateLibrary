#include "DTL.hpp"
#include <array>
#include <bitset>

#include <vector>

int main() {

	std::array<std::bitset<128>, 64> matrix{ {} };

	//std::vector<std::vector<bool>> matrix;
	//dtl::matrix::resize(matrix, 128, 64);

	//dtl::SimpleVoronoiIsland<bool> generation(matrix);
	//dtl::noiseShoreBothBool(matrix, 0.3);

	dtl::createMountain<bool>(matrix);

	dtl::matrix::set(matrix, 0, 0, 1);

	dtl::dungeonStringOutputBool(matrix, "##", "  ");

	std::cout << std::endl;

	dtl::matrix::flip(matrix);
	dtl::matrix::mirror(matrix);
	dtl::dungeonStringOutputBool(matrix, "##", "  ");

	return 0;
}