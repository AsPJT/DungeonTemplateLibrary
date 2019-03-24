#include <cstdint>
#include <cstddef>
#include <array>
#include <bitset>
#include "DTL.hpp"

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t size_x{ 10 };
	constexpr std::size_t size_y{ 6 };
	constexpr std::size_t layer{ 2 };

	std::array<std::array<shape_t, size_x>, size_y> a{ {} };
	std::array<shape_t, size_x*size_y> b{ {} };
	std::array<std::array<std::array<shape_t, layer>, size_x>, size_y> c{ {} };

	//STL
	dtl::console::output::stl::number(dtl::shape::Border<shape_t>(1).create(a));
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//Normal
	dtl::console::output::normal::number(dtl::shape::Border<shape_t>(1).create(a, size_x, size_y), size_x, size_y);
	dtl::utility::array::init(b, size_x, size_y);
	std::cout << '\n';

	//Array
	dtl::console::output::array::number(dtl::shape::Border<shape_t>(1).createArray(b, size_x, size_y), size_x, size_y);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerSTL
	dtl::console::output::layer::stl::number(dtl::shape::Border<shape_t>(1).create(c, 0), 0);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerNormal
	dtl::console::output::layer::stl::number(dtl::shape::Border<shape_t>(1).create(c, 0, size_x, size_y), 0);
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//STL
	dtl::console::output::stl::number(dtl::shape::Border<shape_t>({ 6,3 }, { 5, 4 }, 1).create(a));
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//Normal
	dtl::console::output::normal::number(dtl::shape::Border<shape_t>({ 6,3 }, { 5, 4 }, 1).create(a, size_x, size_y), size_x, size_y);
	dtl::utility::array::init(b, size_x, size_y);
	std::cout << '\n';

	//Array
	dtl::console::output::array::number(dtl::shape::Border<shape_t>({ 6,3 }, { 5, 4 }, 1).createArray(b, size_x, size_y), size_x, size_y);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerSTL
	dtl::console::output::layer::stl::number(dtl::shape::Border<shape_t>({ 6,3 }, { 5, 4 }, 1).create(c, 0), 0);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerNormal
	dtl::console::output::layer::stl::number(dtl::shape::Border<shape_t>({ 6,3 }, { 5, 4 }, 1).create(c, 0, size_x, size_y), 0);
	dtl::utility::stl::init(a);
	std::cout << '\n';


	return 0;
}