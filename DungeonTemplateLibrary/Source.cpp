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

	using shape_t = std::uint_fast8_t;
	constexpr std::size_t width{ 100 };
	constexpr std::size_t height{ 100 };

	std::array<std::array<shape_t, width>, height> matrix{ {} };
	//shape_t matrix[width * height]{};
	//
	////dtl::shape::MazeDig<shape_t>().draw(matrix);
	////dtl::shape::CellularAutomatonIsland<shape_t>().drawArray(matrix, width, height);

	////dtl::shape::Border<shape_t>(1).drawArray(matrix, width, height);

	//dtl::storage::TerrainOBJ<shape_t>("c.obj").drawArray(matrix, width, height);
	////dtl::console::OutputStringBool<shape_t>(" ","#").draw(matrix);
	//return 0;

	//dtl::shape::CellularAutomatonMixIsland<shape_t>(dtl::base::MatrixRange(10,10,80,80), 60, 1, 2, 3, 4).draw(matrix);
	//dtl::shape::Border<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1).draw(matrix);
	//dtl::shape::MixRect<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1, 2, 3, 4).draw(matrix);
	//dtl::shape::BorderOdd<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1).draw(matrix);
	//dtl::shape::HalfMixRect<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1, 2, 3, 4).draw(matrix);
	//dtl::shape::PointGrid<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1).draw(matrix);
	//dtl::shape::RandomRect<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1).draw(matrix);
	dtl::shape::Rect<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1).draw(matrix);
	
	//dtl::shape::PointGridWithBorder<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1, 2).draw(matrix);
	
	//dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1, 2, 3).draw(matrix);

	//dtl::shape::CellularAutomatonIsland<shape_t>(dtl::base::MatrixRange(10, 10, 80, 80), 1, 0, 50).draw(matrix);

	const dtl::console::SetColor color("　");

	dtl::console::OutputString<shape_t>(color.blue(), color.green(), color.gray(), color.yellow()).draw(matrix);//color.red(), 

}