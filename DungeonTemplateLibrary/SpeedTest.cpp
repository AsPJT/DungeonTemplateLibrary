#include <DTL.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>
#include <new>
#include <chrono>

int main() {

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 256 };
	constexpr std::size_t height{ 256 };

	std::chrono::system_clock::time_point  start, end;
	std::unique_ptr<shape_t[][width]> matrix(new(std::nothrow) shape_t[height][width]);

	std::cout << "----------------------------------------------------------------------------------------------------\n";
	std::cout << "[[Speed Test]]\n";
	std::cout << "----------------------------------------------------------------------------------------------------\n";

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::Rect<shape_t>(1).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[Rect]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::DiamondSquareAverageCornerIsland<shape_t>(0, 165, 85).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[DiamondSquareAverageCornerIsland]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::Border<shape_t>(1).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[Border]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::CellularAutomatonMixIsland<shape_t>(0, 1, 2).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[CellularAutomatonMixIsland]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(1, 2, 3).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[PointGridAndSomeBlocksWithBorder]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	start = std::chrono::system_clock::now();
	dtl::shape::PointGridWithBorder<shape_t>(1, 2).draw(matrix, width, height);
	end = std::chrono::system_clock::now();

	std::cout << "[PointGridWithBorder]\n";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << '\n';

	return 0;
}