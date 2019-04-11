#include <DTL.hpp>

int main() {

	using shape_t = std::uint_fast8_t;
	std::array<std::array<shape_t, 32>, 32> matrix{ {} };
	dtl::shape::Border<shape_t> generator(1);

	generator.setRange({ 0,0,0,0 }).draw(matrix);

	dtl::console::OutputStringBool<shape_t>("#", "/").draw(matrix);

	return 0;
}