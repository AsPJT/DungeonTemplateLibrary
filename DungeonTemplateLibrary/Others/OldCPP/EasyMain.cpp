#include "DTL.hpp"
#include <cstdint>
#include <array>

int main() {

	using dungeon_t = std::uint_fast8_t;
	std::array<std::array<dungeon_t, 80>, 32> matrix{};
	//dtl::generation::stl::SimpleRogueLike<dungeon_t> generator(matrix);

	dtl::file::read::dtlm(matrix, "Save\\SimpleRogueLike\\picture.dtlm");
	dtl::file::write::all(matrix, "Save\\SimpleRogueLike\\picture");

	return 0;
}