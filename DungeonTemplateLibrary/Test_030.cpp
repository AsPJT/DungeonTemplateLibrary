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

	constexpr std::pair<std::size_t, std::size_t> point{ std::make_pair(2, 2) };
	constexpr std::pair<std::size_t, std::size_t> length{ std::make_pair(10,10) };

	const std::string before_str{ "##" };
	const std::string after_str{ "//" };

	//STL
	dtl::console::OutputStringBool<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).create(a));
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//Normal
	dtl::console::OutputStringBool<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).create(a, size_x, size_y), size_x, size_y);
	dtl::utility::array::init(b, size_x, size_y);
	std::cout << '\n';

	//Array
	dtl::console::OutputStringBool<shape_t>(before_str, after_str).drawArray(dtl::shape::BorderOdd<shape_t>(1).createArray(b, size_x, size_y), size_x, size_y);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerSTL
	dtl::console::OutputStringBool<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).create(c, 0), 0);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerNormal
	dtl::console::OutputStringBool<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).create(c, 0, size_x, size_y), 0);
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//STL
	dtl::console::OutputStringBool<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).create(a));
	dtl::utility::stl::init(a);
	std::cout << '\n';

	//Normal
	dtl::console::OutputStringBool<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).create(a, size_x, size_y), size_x, size_y);
	dtl::utility::array::init(b, size_x, size_y);
	std::cout << '\n';

	//Array
	dtl::console::OutputStringBool<shape_t>(point, length, before_str, after_str).drawArray(dtl::shape::BorderOdd<shape_t>(point, length, 1).createArray(b, size_x, size_y), size_x, size_y);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerSTL
	dtl::console::OutputStringBool<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).create(c, 0), 0);
	dtl::utility::layer::stl::init(c, 0);
	std::cout << '\n';

	//LayerNormal
	dtl::console::OutputStringBool<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).create(c, 0, size_x, size_y), 0);
	dtl::utility::stl::init(a);
	std::cout << '\n';


	//using std::array;
	//using dtl::shape::Border;
	//using dtl::console::OutputNumber;

	////2D平面を作成
	//array<array<shape_t, 32>, 32> matrix{ {} };
	////生成
	//Border<shape_t>(1).draw(matrix);
	////出力
	//OutputNumber<shape_t>(",").draw(matrix);

	return 0;
}