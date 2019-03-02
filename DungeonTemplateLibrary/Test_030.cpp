#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = bool;
	std::array<std::array<dungeon_t, 11>, 9> matrix{ {} };

	dtl::generator::common::stl::createPointGridField(matrix);

	dtl::console::output::stl::number(matrix);

	return 0;
}