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

	//std::array<std::array<std::uint_fast16_t, 257>, 257> matrix{};
	//std::array<std::array<std::uint_fast8_t, 17>, 17> matrix{};

	std::array<std::array<std::uint_fast8_t, 512>, 512> matrix{};

	//dtl::SimpleVoronoiIsland<std::uint_fast8_t> svi(matrix);
	//dtl::noiseShoreBothBool(matrix, 0.4);
	//dtl::FractalIsland<std::uint_fast8_t> fi(matrix,0,60);
	//dtl::fileWriteTerrain_obj(matrix, "test.obj");

	//dtl::RogueLikeCave<std::uint_fast8_t> rc(matrix, 0x50);
	//dtl::createBorder(matrix);
	//dtl::MazeDig<std::uint_fast8_t> md(matrix);
	//dtl::SimpleRogueLike<std::uint_fast8_t> srl(matrix, 7, 0);
	dtl::FractalIsland<std::uint_fast8_t> fi(matrix, 0, 40);

	//dtl::createPointGridField(matrix);
	//dtl::fileWriteBoard_obj<std::uint_fast8_t>(matrix, "test_board.obj", 3, 0);
	dtl::fileWriteTerrain_obj(matrix, "test_fi.obj");

	//dtl::dungeonNumberOutput(matrix, ",");

	//dtl::dungeonBinarization(matrix, 40);
	//dtl::dungeonStringOutputBool(matrix, "##", "  ");

	return 0;
}