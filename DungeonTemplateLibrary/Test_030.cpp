#include <cstdint>
#include <cstddef>
#include <array>
#include <bitset>
#include "DTL.hpp"

int main() {

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t size_x{ 10 };
	constexpr std::size_t size_y{ 6 };
	constexpr std::size_t layer{ 2 };

	std::array<std::array<dungeon_t, size_x>, size_y> a{ {} };
	std::array<dungeon_t, size_x*size_y> b{ {} };
	std::array<std::array<std::array<dungeon_t, layer>, size_x>, size_y> c{ {} };

	dtl::console::output::stl::number(a);
	std::cout << '\n';
	dtl::console::output::normal::number(dtl::shape::Rect<dungeon_t>(2,1,5,4,1).create(a, size_x, size_y), size_x, size_y);
	dtl::utility::stl::init(a);
	std::cout << '\n';

	dtl::console::output::stl::number(a);
	std::cout << '\n';
	dtl::console::output::stl::number(dtl::shape::Rect<dungeon_t>(2,1,5,4,1).create(a));
	dtl::utility::stl::init(a);
	std::cout << '\n';

	dtl::console::output::array::number(b, size_x, size_y);
	std::cout << '\n';
	dtl::console::output::array::number(dtl::shape::Rect<dungeon_t>(2,1,5,4,1).createArray(b, size_x, size_y), size_x, size_y);
	dtl::utility::array::init(b, size_x, size_y);
	std::cout << '\n';

	dtl::console::output::stl::number(a);
	std::cout << '\n';
	dtl::console::output::layer::stl::number(dtl::shape::Rect<dungeon_t>(2,1,5,4,1).create(c, 0), 0);
	dtl::utility::stl::init(a);
	std::cout << '\n';

	dtl::console::output::stl::number(a);
	std::cout << '\n';
	dtl::console::output::layer::normal::number(dtl::shape::Rect<dungeon_t>(2,1,5,4,1).create(c, 0, size_x, size_y), 0, size_x, size_y);
	dtl::utility::stl::init(a);
	std::cout << '\n';


	return 0;
}