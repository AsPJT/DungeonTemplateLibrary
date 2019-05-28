#include <DTL.hpp>
#include <cstdint>
#include <array>

int main() {

	using shape_t = ::std::uint_fast8_t;
	::std::array< ::std::array<shape_t, 32>, 32> matrix{ {} };

	dtl::CellularAutomatonMixIsland<shape_t>(5, 0, 1, 2, 3, 4).draw(matrix);

	dtl::storage::FileMD<shape_t>("file_sample.md").write(matrix);

	return 0;
}