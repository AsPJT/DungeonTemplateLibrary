#include <array>
#include <DTL.hpp>

int main() {

	using dungeon_t = bool;
	std::array<std::array<dungeon_t, 64>, 64> matrix{ {} };

	dtl::random::mersenne_twister_32bit.seed(1);

	//dtl::utility::stl::noiseBool(matrix, 0.6);
	dtl::generator::terrain::stl::SimpleVoronoiIsland<dungeon_t> a(matrix);
	dtl::utility::stl::rnoiseShoreBool(matrix,0.6);


	dtl::console::output::stl::stringBool(matrix, "##", "//");

	return 0;
}

//#include <array>
//#include <DTL.hpp>
//
//int main() {
//
//	using dungeon_t = bool;
//	std::array<std::array<dungeon_t, 10>, 8> matrix{ {} };
//
//	dtl::utility::stl::noiseBool<dungeon_t>(matrix, 0.5);
//
//	dtl::console::output::stl::stringBool(matrix, "##", "//");
//
//	return 0;
//}

//#include <array>
//#include <bitset>
//#include <chrono>
//#include "omp.h"
//#include "DTL.hpp"
//
//template<typename Generator_,typename Matrix_>
//void createDungeon(Matrix_& matrix_, Generator_& generator_) noexcept {
//	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };
//	generator_.create(matrix_, 10, 20);
//	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;
//	//dtl::console::output::stl::stringBool(matrix_, "##", "//");
//	dtl::console::output::stl::string(matrix_, "//", "##", "AA", "BB", "CC", "DD","EE","FF","GG","HH","II","JJ","KK","LL","MM","NN","OO","PP","QQ","RR");
//}
//
//int main() {
//	
//	//using dungeon_t = std::uint_fast8_t;
//	//std::array<std::array<dungeon_t, 64>, 64> matrix{ {} };
//	//dtl::generator::terrain::stl::SimpleBiomeIsland<dungeon_t> a;
//	
//	std::array<std::uint_fast64_t, 256> rn{ {} };
//	for (std::uint_fast32_t i{}; i < 0x2f; ++i)
//		rn[dtl::random::xor_8()]+=1;
//
//	for (std::size_t i{}; i < 256; ++i)
//		std::cout << rn[i] << std::endl;
//
//	//createDungeon(matrix, a);
//	//dtl::utility::stl::noiseShoreBool(matrix, 0.5);
//
//	//dtl::file::write::stl::objBoard<dungeon_t>(matrix, "write_board_test_2.obj", 5, 1);
//
//
//	return 0;
//}