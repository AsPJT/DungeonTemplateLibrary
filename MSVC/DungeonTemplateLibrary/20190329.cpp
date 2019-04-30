#include "DTL.hpp"
#include <cstddef>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 15 };
	constexpr std::size_t height{ 7 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };

	dtl::shape::Border<shape_t>(1).draw(matrix);

	dtl::storage::FileCSV<shape_t>("str.csv").write(matrix);
	dtl::file::write::stl::md(matrix, "str_md.txt");

	dtl::console::OutputNumber<shape_t>(",").draw(matrix);
	
}