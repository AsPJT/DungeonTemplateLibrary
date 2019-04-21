#include <DTL.hpp>
#include <iostream>
#include <cstddef>
#include <cstdint>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 16 };
	constexpr std::size_t height{ 8 };

	shape_t matrix[height * width]{};

	dtl::shape::Border<shape_t> border(1);

	border.setRange(2, 1, 8, 5).drawArray(matrix, width, height);

	std::cout << "PointX:" << border.getPointX() << '\n';
	std::cout << "PointY:" << border.getPointY() << '\n';
	std::cout << "Width:" << border.getWidth() << '\n';
	std::cout << "Height:" << border.getHeight() << '\n';

	dtl::console::OutputNumber<shape_t>(",").drawArray(matrix, width, height);
	dtl::console::OutputString<shape_t>("//", "##").drawArray(matrix, width, height);

	return 0;
}