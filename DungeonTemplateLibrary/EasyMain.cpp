#include "DTL.hpp"
#include <array>
#include <bitset>

#include <vector>

int main() {

	//std::array<std::bitset<128>, 64> matrix{ {} };

	//std::vector<std::vector<bool>> matrix;
	//dtl::matrix::resize(matrix, 128, 64);

	//dtl::SimpleVoronoiIsland<bool> generation(matrix);
	//dtl::noiseShoreBothBool(matrix, 0.3);

	//dtl::PaintTrajectory<bool> pt(10);

	//dtl::createMountain<bool>(matrix);

	//dtl::matrix::set(matrix, 0, 0, 1);

	//dtl::dungeonStringOutputBool(matrix, "##", "  ");

	//std::cout << std::endl;

	//dtl::matrix::flip(matrix);
	//dtl::matrix::mirror(matrix);
	//dtl::dungeonStringOutputBool(matrix, "##", "  ");

	std::array<std::array<std::uint_fast16_t, 257>, 257> matrix{};
	dtl::ChunkIsland<std::uint_fast8_t> fi(matrix, 0,60);
	dtl::fileWriteTerrain_obj(matrix, "test.obj");

	//dtl::dungeonNumberOutput(matrix, ",");

	//dtl::dungeonBinarization(matrix, 40);
	//dtl::dungeonStringOutputBool(matrix, "##", "  ");

	return 0;
}