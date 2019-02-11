#include "DTL.hpp"
#include <iostream>
#include <array>

int main() {
	std::array<std::array<std::uint_fast8_t, 150>, 100> stl_{};

	dtl::generator::terrain::stl::SimpleVoronoiIsland<std::uint_fast8_t> svi(stl_, 150, 0.5);
	dtl::utility::stl::noiseShoreBothBool(stl_, 0.4);
	dtl::artist::Bucket<std::uint_fast8_t>(stl_, 0, 0, 2);
	dtl::console::output::stl::string(stl_, "\x1b[46m \x1b[49m", "\x1b[42m \x1b[49m", "\x1b[44m \x1b[49m");

}