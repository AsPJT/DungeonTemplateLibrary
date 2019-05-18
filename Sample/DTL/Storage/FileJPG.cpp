#include <DTL.hpp>
#include <DTL/ImageWrite.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 256>, 256> matrix{ {} };

	dtl::CellularAutomatonMixIsland<shape_t>(200, 0, 1, 2, 3, 4).draw(matrix);

	dtl::storage::FileJPG<shape_t>("file_sample.jpg", 3).write(matrix, [](const shape_t value, unsigned char* const color) {
		switch (value) {
		case 0:
			color[0] = 41;
			color[1] = 40;
			color[2] = 159;
			break;
		case 1:
			color[0] = 101;
			color[1] = 163;
			color[2] = 56;
			break;
		case 2:
			color[0] = 223;
			color[1] = 203;
			color[2] = 140;
			break;
		case 3:
			color[0] = 9;
			color[1] = 100;
			color[2] = 5;
			break;
		case 4:
			color[0] = 164;
			color[1] = 143;
			color[2] = 50;
			break;
		}
		});

	return 0;
}