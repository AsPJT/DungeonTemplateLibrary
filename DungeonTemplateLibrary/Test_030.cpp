#include <array>
#include "DTL.hpp"

int main() {

	using dungeon_t = std::uint_fast8_t;
	std::array<std::array<dungeon_t, 15>, 15> matrix{ {} };

	dtl::generator::common::stl::PointGridFieldPutBlock<dungeon_t>().create(matrix);

	dtl::console::output::stl::string(matrix, "　", "■", "□");
	//dtl::console::output::stl::number(matrix);

	

	return 0;
}