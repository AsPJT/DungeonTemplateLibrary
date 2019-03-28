#include <cstdint>
#include <cstddef>
#include <array>
#include <bitset>
#include "DTL.hpp"

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t size_x{ 18 };
	constexpr std::size_t size_y{ 12 };
	constexpr std::size_t layer{ 2 };

	std::array<std::array<shape_t, size_x>, size_y> a{ {} };
	std::array<shape_t, size_x*size_y> b{ {} };
	std::array<std::array<std::array<shape_t, layer>, size_x>, size_y> c{ {} };

	constexpr std::pair<std::size_t, std::size_t> point{ std::make_pair(2, 2) };
	constexpr std::pair<std::size_t, std::size_t> length{ std::make_pair(10,10) };

	//constexpr std::pair<shape_t, shape_t> id{ std::make_pair(1,2) };

	const std::string before_str{ "//" };
	const std::string after_str{ "##" };

	//STL
	dtl::utility::Init<shape_t>(0).draw(a);
	dtl::console::OutputString<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).createOperator(a, [](shape_t a_) {return a_ == 0; }));
	std::cout << '\n';

	//Normal
	dtl::utility::Init<shape_t>(0).draw(a);
	dtl::console::OutputString<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).createOperator(a, size_x, size_y, [](shape_t a_) {return a_ == 0; }));
	std::cout << '\n';

	//Array
	dtl::utility::Init<shape_t>(0).drawArray(b, size_x, size_y);
	dtl::console::OutputString<shape_t>(before_str, after_str).drawArray(dtl::shape::BorderOdd<shape_t>(1).createOperatorArray(b, size_x, size_y, [](shape_t a_) {return a_ == 0; }), size_x, size_y);
	std::cout << '\n';

	//LayerSTL
	dtl::utility::Init<shape_t>(0).draw(c, 0);
	dtl::console::OutputString<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).createOperator(c, 0, [](shape_t a_) {return a_ == 0; }), 0);
	std::cout << '\n';

	//LayerNormal
	dtl::utility::Init<shape_t>(0).draw(c, 0);
	dtl::console::OutputString<shape_t>(before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(1).createOperator(c, 0, size_x, size_y, [](shape_t a_) {return a_ == 0; }), 0);
	std::cout << '\n';

	//STL
	dtl::utility::Init<shape_t>(0).draw(a);
	dtl::console::OutputString<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).createOperator(a, [](shape_t a_) {return a_ == 0; }));
	std::cout << '\n';

	//Normal
	dtl::utility::Init<shape_t>(0).draw(a);
	dtl::console::OutputString<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).createOperator(a, size_x, size_y, [](shape_t a_) {return a_ == 0; }));
	std::cout << '\n';

	//Array
	dtl::utility::Init<shape_t>(0).drawArray(b, size_x, size_y);
	dtl::console::OutputString<shape_t>(point, length, before_str, after_str).drawArray(dtl::shape::BorderOdd<shape_t>(point, length, 1).createOperatorArray(b, size_x, size_y, [](shape_t a_) {return a_ == 0; }), size_x, size_y);
	std::cout << '\n';

	//LayerSTL
	dtl::utility::Init<shape_t>(0).draw(c, 0);
	dtl::console::OutputString<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).createOperator(c, 0, [](shape_t a_) {return a_ == 0; }), 0);
	std::cout << '\n';

	//LayerNormal
	dtl::utility::Init<shape_t>(0).draw(c, 0);
	dtl::console::OutputString<shape_t>(point, length, before_str, after_str).draw(dtl::shape::BorderOdd<shape_t>(point, length, 1).createOperator(c, 0, size_x, size_y, [](shape_t a_) {return a_ == 0; }), 0);
	std::cout << '\n';







	////STL
	//dtl::utility::Init<shape_t>(0).draw(a);
	//dtl::console::OutputString<shape_t>(before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(1, 2).create(a), [](shape_t a) {return a < 1; }));
	//std::cout << '\n';

	////Normal
	//dtl::utility::Init<shape_t>(0).draw(a);
	//dtl::console::OutputString<shape_t>(before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1,0).create(dtl::shape::PointGridWithBorder<shape_t>(id).create(a, size_x, size_y), [](shape_t a) {return a < 1; }));
	//std::cout << '\n';

	////Array
	//dtl::utility::Init<shape_t>(0).drawArray(b, size_x, size_y);
	//dtl::console::OutputString<shape_t>(before_str, after_str, "%%").drawArray(dtl::utility::Binarization<shape_t>(1, 0).createArray(dtl::shape::PointGridWithBorder<shape_t>(1,2).createArray(b, size_x, size_y), size_x, size_y, [](shape_t a) {return a < 1; }), size_x, size_y);
	//std::cout << '\n';

	////LayerSTL
	//dtl::utility::Init<shape_t>(0).draw(c, 0);
	//dtl::console::OutputString<shape_t>(before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(1, 2).create(c, 0), 0, [](shape_t a) {return a < 1; }), 0);
	//std::cout << '\n';

	////LayerNormal
	//dtl::utility::Init<shape_t>(0).draw(c, 0);
	//dtl::console::OutputString<shape_t>(before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(1, 2).create(c, 0, size_x, size_y), 0, [](shape_t a) {return a < 1; }), 0);
	//std::cout << '\n';

	////STL
	//dtl::utility::Init<shape_t>(0).draw(a);
	//dtl::console::OutputString<shape_t>(point, length, before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(point, length, id).create(a), [](shape_t a) {return a < 1; }));
	//std::cout << '\n';

	////Normal
	//dtl::utility::Init<shape_t>(0).draw(a);
	//dtl::console::OutputString<shape_t>(point, length, before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(point, length, id).create(a, size_x, size_y), size_x, size_y, [](shape_t a) {return a < 1; }));
	//std::cout << '\n';

	////Array
	//dtl::utility::Init<shape_t>(0).drawArray(b, size_x, size_y);
	//dtl::console::OutputString<shape_t>(point, length, before_str, after_str, "%%").drawArray(dtl::utility::Binarization<shape_t>(1, 0).createArray(dtl::shape::PointGridWithBorder<shape_t>(point, length, id).createArray(b, size_x, size_y), size_x, size_y, [](shape_t a) {return a < 1; }), size_x, size_y);
	//std::cout << '\n';

	////LayerSTL
	//dtl::utility::Init<shape_t>(0).draw(c, 0);
	//dtl::console::OutputString<shape_t>(point, length, before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(point, length, id).create(c, 0), 0, [](shape_t a) {return a < 1; }), 0);
	//std::cout << '\n';

	////LayerNormal
	//dtl::utility::Init<shape_t>(0).draw(c, 0);
	//dtl::console::OutputString<shape_t>(point, length, before_str, after_str, "%%").draw(dtl::utility::Binarization<shape_t>(1, 0).create(dtl::shape::PointGridWithBorder<shape_t>(point, length, id).create(c, 0, size_x, size_y), 0, [](shape_t a) {return a < 1; }), 0);
	//std::cout << '\n';


	//using rnd = std::size_t;
	//for (int i{}; i < 10; ++i) {
	//	std::cout << dtl::random::mt32bit.rand<rnd>(5, 10) << std::endl;
	//}
	//using std::array;
	//using dtl::shape::PointGridWithBorder;
	//using dtl::console::OutputStringBool;

	////2D平面を作成
	//array<array<shape_t, 32>, 16> matrix{ {} };
	////生成
	////PointGridWithBorder<shape_t>(1).draw(matrix);
	//dtl::utility::Init<shape_t>(1).draw(matrix);

	////出力
	//OutputStringBool<shape_t>("#", " ").draw(matrix);

	return 0;
}