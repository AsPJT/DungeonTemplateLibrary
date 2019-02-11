#include <iostream>
#include <cstdint>
#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = bool;
	std::array<std::array<dungeon_t, 10>, 8> matrix{ {} };

	dtl::console::output::stl::number(matrix);

	return 0;
}