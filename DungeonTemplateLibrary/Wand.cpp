#include "DTL.hpp"
#include <iostream>
#include <array>

int main() {
	std::array<std::array<std::uint_fast8_t, 150>, 100> stl_{};

	using dtl::generator::terrain::stl::SimpleVoronoiIsland;
	using dtl::utility::stl::noiseShoreBothBool;
	using dtl::artist::Bucket;
	using dtl::console::output::stl::string;

	SimpleVoronoiIsland<std::uint_fast8_t> svi(stl_, 150, 0.5);
	noiseShoreBothBool(stl_, 0.4);
	Bucket<std::uint_fast8_t>(stl_, 0, 0, 2);
	string(stl_, "\x1b[46m \x1b[49m", "\x1b[42m \x1b[49m", "\x1b[44m \x1b[49m");

}