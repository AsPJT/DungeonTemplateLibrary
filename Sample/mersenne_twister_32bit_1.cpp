#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = bool;
	std::array<std::array<dungeon_t, 10>, 8> matrix{ {} };
	dtl::generator::common::stl::createBorder(matrix);

	dtl::file::write::stl::objBoard<dungeon_t>(matrix, "write_board_test_2.obj", 5, 1);

	dtl::console::output::stl::stringBool(matrix, "##", "  ");

	return 0;
}