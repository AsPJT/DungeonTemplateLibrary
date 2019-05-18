#include <DTL.hpp>
#include <DTL/ImageWrite.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 256>, 256> matrix{ {} };

	dtl::CellularAutomatonMixIsland<shape_t>(200, 0, 1, 2, 3, 4).draw(matrix);

	dtl::storage::FileHDR<shape_t>("file_sample.hdr", 3).write(matrix, [](const shape_t value, float* const color) {
		switch (value) {
		case 0:
			color[0] = 41.0f / 255.0f;
			color[1] = 40.0f / 255.0f;
			color[2] = 159.0f / 255.0f;
			break;
		case 1:
			color[0] = 101.0f / 255.0f;
			color[1] = 163.0f / 255.0f;
			color[2] = 56.0f / 255.0f;
			break;
		case 2:
			color[0] = 223.0f / 255.0f;
			color[1] = 203.0f / 255.0f;
			color[2] = 140.0f / 255.0f;
			break;
		case 3:
			color[0] = 9.0f / 255.0f;
			color[1] = 100.0f / 255.0f;
			color[2] = 5.0f / 255.0f;
			break;
		case 4:
			color[0] = 164.0f / 255.0f;
			color[1] = 143.0f / 255.0f;
			color[2] = 50.0f / 255.0f;
			break;
		}
		});

	return 0;
}