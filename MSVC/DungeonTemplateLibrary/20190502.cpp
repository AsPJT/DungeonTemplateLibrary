#include <DTL.hpp>
#include <Dungeon/ImageWrite.hpp>
#include <cstdint>
#include <array>

#include <list>
#include <vector>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 64>, 64> matrix{ {} };
	//std::vector<std::list<shape_t>> matrix(16, std::list<shape_t>(16, 0));

	dtl::MazeDig<shape_t>(1, 0).draw(matrix);
	dtl::OutputNumber<shape_t>(",").draw(matrix);

	//dtl::FileTerrainOBJ<shape_t>("Save/o.obj").write(matrix);

	//dtl::Rect<shape_t>(dtl::MatrixRange(5, 5, 5, 5), 1).drawList(matrix);

	//for (auto&& row : matrix) {
	//	for (auto&& col : row) {
	//		std::cout << (int)col << ',';
	//	}
	//	std::cout << '\n';
	//}

	//dtl::console::OutputStringBool<shape_t>(dtl::MatrixRange(5, 5, 5, 5), "#", "/").drawList(matrix);

	dtl::CellularAutomatonMixIsland<shape_t>(5, 0, 1, 2, 3, 4).draw(matrix);

	//dtl::storage::FileTXT_0_9<shape_t>("Save/file_sample_0_9.txt").write(matrix,32,32);

	//dtl::storage::FilePBM<shape_t>("Save/file_sample.pbm").setRange(2, 2, 25, 25).write(matrix, 32, 32);
	//dtl::storage::FilePBM<shape_t>(dtl::MatrixRange(2, 2, 25, 25), "Save/file_sample2.pbm").write(matrix);

	//dtl::storage::FilePNG<shape_t>("Save/file_samplen.png", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
	//	switch (value) {
	//	case 0:
	//		color[0] = 41;
	//		color[1] = 40;
	//		color[2] = 159;
	//		break;
	//	case 1:
	//		color[0] = 101;
	//		color[1] = 163;
	//		color[2] = 56;
	//		break;
	//	case 2:
	//		color[0] = 223;
	//		color[1] = 203;
	//		color[2] = 140;
	//		break;
	//	case 3:
	//		color[0] = 9;
	//		color[1] = 100;
	//		color[2] = 5;
	//		break;
	//	case 4:
	//		color[0] = 164;
	//		color[1] = 143;
	//		color[2] = 50;
	//		break;
	//	}
	//	});

	//dtl::storage::FileJPG<shape_t>("Save/file_samplen.jpg", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
	//	switch (value) {
	//	case 0:
	//		color[0] = 41;
	//		color[1] = 40;
	//		color[2] = 159;
	//		break;
	//	case 1:
	//		color[0] = 101;
	//		color[1] = 163;
	//		color[2] = 56;
	//		break;
	//	case 2:
	//		color[0] = 223;
	//		color[1] = 203;
	//		color[2] = 140;
	//		break;
	//	case 3:
	//		color[0] = 9;
	//		color[1] = 100;
	//		color[2] = 5;
	//		break;
	//	case 4:
	//		color[0] = 164;
	//		color[1] = 143;
	//		color[2] = 50;
	//		break;
	//	}
	//	});

	//dtl::storage::FileBMP<shape_t>("Save/file_samplen.bmp", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
	//	switch (value) {
	//	case 0:
	//		color[0] = 41;
	//		color[1] = 40;
	//		color[2] = 159;
	//		break;
	//	case 1:
	//		color[0] = 101;
	//		color[1] = 163;
	//		color[2] = 56;
	//		break;
	//	case 2:
	//		color[0] = 223;
	//		color[1] = 203;
	//		color[2] = 140;
	//		break;
	//	case 3:
	//		color[0] = 9;
	//		color[1] = 100;
	//		color[2] = 5;
	//		break;
	//	case 4:
	//		color[0] = 164;
	//		color[1] = 143;
	//		color[2] = 50;
	//		break;
	//	}
	//	});

	//dtl::storage::FileTGA<shape_t>("Save/file_samplen.tga", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
	//	switch (value) {
	//	case 0:
	//		color[0] = 41;
	//		color[1] = 40;
	//		color[2] = 159;
	//		break;
	//	case 1:
	//		color[0] = 101;
	//		color[1] = 163;
	//		color[2] = 56;
	//		break;
	//	case 2:
	//		color[0] = 223;
	//		color[1] = 203;
	//		color[2] = 140;
	//		break;
	//	case 3:
	//		color[0] = 9;
	//		color[1] = 100;
	//		color[2] = 5;
	//		break;
	//	case 4:
	//		color[0] = 164;
	//		color[1] = 143;
	//		color[2] = 50;
	//		break;
	//	}
	//	});

	//dtl::storage::FileHDR<shape_t>("Save/file_samplen.hdr", 3).write(matrix, [](const shape_t value, float* const color) {
	//	switch (value) {
	//	case 0:
	//		color[0] = 41.0f / 255.0f;
	//		color[1] = 40.0f / 255.0f;
	//		color[2] = 159.0f / 255.0f;
	//		break;
	//	case 1:
	//		color[0] = 101.0f / 255.0f;
	//		color[1] = 163.0f / 255.0f;
	//		color[2] = 56.0f / 255.0f;
	//		break;
	//	case 2:
	//		color[0] = 223.0f / 255.0f;
	//		color[1] = 203.0f / 255.0f;
	//		color[2] = 140.0f / 255.0f;
	//		break;
	//	case 3:
	//		color[0] = 9.0f / 255.0f;
	//		color[1] = 100.0f / 255.0f;
	//		color[2] = 5.0f / 255.0f;
	//		break;
	//	case 4:
	//		color[0] = 164.0f / 255.0f;
	//		color[1] = 143.0f / 255.0f;
	//		color[2] = 50.0f / 255.0f;
	//		break;
	//	}
	//	});

	return 0;
}