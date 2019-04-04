/*#######################################################################################
	Made by Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/

#include <DTL.hpp>
#include <cstddef>
#include <cstdint>
#include <array>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 15 };
	constexpr std::size_t height{ 7 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };

	dtl::shape::PointGridWithBorder<shape_t>(1, 2).draw(matrix);

	dtl::console::OutputNumber<shape_t>().draw(matrix);

}