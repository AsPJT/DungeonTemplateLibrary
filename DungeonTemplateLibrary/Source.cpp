#include <DTL.hpp>
#include <cstddef>
#include <cstdint>
#include <array>

namespace dtl::console {

	class SetColor {
	private:
		std::string str{};
	public:
		SetColor(const std::string& str_ = " ") noexcept :str(str_) {}
		std::string red() const noexcept {
			return "\x1b[41m" + str + "\x1b[49m";
		}
		std::string blue() const noexcept {
			return "\x1b[44m" + str + "\x1b[49m";
		}
		std::string green() const noexcept {
			return "\x1b[42m" + str + "\x1b[49m";
		}
		std::string gray() const noexcept {
			return "\x1b[47m" + str + "\x1b[49m";
		}
		std::string yellow() const noexcept {
			return "\x1b[43m" + str + "\x1b[49m";
		}
	};

}

int main() {

	//using shape_t = std::uint_fast8_t;
	using shape_t = float;
	//using shape_t = float;
	constexpr std::size_t width{ 257 };
	constexpr std::size_t height{ 257 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };

	//std::unique_ptr<shape_t[][width]> matrix(new(std::nothrow) shape_t[height][width]);
	dtl::utility::Init<shape_t>(0).draw(matrix, width, height);
	//std::unique_ptr<shape_t[][512]> matrix{ std::make_unique<shape_t[][512]>(512*512) };

	dtl::shape::SimpleDiamondSquareAverageIsland<shape_t>().draw(matrix, 64);
	//dtl::shape::CellularAutomatonIsland<shape_t>(1, 0, 50).draw(matrix, width, height);
	//dtl::generator::terrain::stl::SimpleVoronoiIsland<shape_t> sv(matrix);
	//dtl::generator::terrain::stl::SimpleDiamondSquareAverageIsland<shape_t> sv(matrix, 255);
	//dtl::generator::terrain::stl::FractalIsland<shape_t> sv(matrix, 0, 31);

	//for (std::size_t row{}; row < matrix.size(); ++row) {
	//	for (std::size_t col{}; col < matrix[row].size(); ++col) {
	//		std::cout << ((matrix[row][col] > 68) ? ((matrix[row][col] > 148) ? ((matrix[row][col] > 178) ? "■" : "▲") : "□") : "・");
	//	}
	//	std::cout << '\n';
	//}

	//const dtl::console::SetColor color("　");

	for (std::size_t row{ 1 }; row < matrix.size() - 1; ++row) {
		for (std::size_t col{ 1 }; col < matrix[row].size() - 1; ++col) {
			if (matrix[row][col] >= matrix[row][col - 1] && matrix[row][col] >= matrix[row][col + 1] && matrix[row][col] >= matrix[row - 1][col] && matrix[row][col] >= matrix[row + 1][col]) {
				auto max_value{ matrix[row][col - 1] };
				if (max_value < matrix[row][col + 1]) max_value = matrix[row][col + 1];
				if (max_value < matrix[row - 1][col]) max_value = matrix[row - 1][col];
				if (max_value < matrix[row + 1][col]) max_value = matrix[row + 1][col];
				matrix[row][col] = max_value;
			}
		}
	}

	dtl::storage::FileTerrainOBJ<shape_t>("cai6.obj").write(matrix, width, height);



	//dtl::console::OutputString<shape_t>(color.blue(), color.green(), color.gray(), color.yellow()).draw(matrix, width, height);//color.red(), 

}