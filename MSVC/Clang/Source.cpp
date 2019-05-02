#include <DTL.hpp>
#include <Dungeon/ImageWrite.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 64>, 48> matrix{ {} };

	dtl::shape::SimpleVoronoiIsland<shape_t>(40, 0.5, 1, 0).draw(matrix);

	dtl::storage::FileHDR<shape_t>("aa.hdr").write(matrix, [](const shape_t value, float* const color) {
		if (value) {
			color[0] = 1;
			color[1] = 1;
			color[2] = 1;
		}
		else {
			color[0] = 0;
			color[1] = 0;
			color[2] = 0;
		}
		});

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	dtl::console::OutputString<shape_t>("//", "##").draw(matrix);

	return 0;
}