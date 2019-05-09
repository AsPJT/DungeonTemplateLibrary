#include <DTL.hpp>
#include <Dungeon/ImageWrite.hpp>
#include <cstdint>
#include <array>

#include <list>
#include <vector>

int main() {

	using shape_t = std::uint_fast8_t;
	//std::array<std::array<shape_t, 32>, 32> matrix{ {} };

	std::vector<std::list<shape_t>> matrix(16, std::list<shape_t>(16, 0));

	dtl::Rect<shape_t>(dtl::MatrixRange(5, 5, 5, 5), 1).drawList(matrix);

	//for (auto&& row : matrix) {
	//	for (auto&& col : row) {
	//		std::cout << (int)col << ',';
	//	}
	//	std::cout << '\n';
	//}

	dtl::console::OutputStringBool<shape_t>(dtl::MatrixRange(5, 5, 5, 5), "#", "/").drawList(matrix);

	//dtl::CellularAutomatonMixIsland<shape_t>(5, 0, 1, 2, 3, 4).draw(matrix);

	//dtl::storage::FileTXT_0_9<shape_t>("Save/file_sample_0_9.txt").write(matrix,32,32);

	//dtl::storage::FilePBM<shape_t>("Save/file_sample.pbm").setRange(2, 2, 25, 25).write(matrix, 32, 32);
	//dtl::storage::FilePBM<shape_t>(dtl::MatrixRange(2, 2, 25, 25), "Save/file_sample2.pbm").write(matrix);

	//dtl::storage::FilePNG<shape_t>("Save/file_sample2.png", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
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

	return 0;
}