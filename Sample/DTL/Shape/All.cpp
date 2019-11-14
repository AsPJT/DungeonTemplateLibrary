#include <DTL.hpp>

enum {
	class_name_CellularAutomatonMixIsland,
	class_name_CellularAutomatonIsland,
	class_name_FractalLoopIsland,
	class_name_FractalIsland,
	class_name_DiamondSquareAverageIsland,
	class_name_DiamondSquareAverageCornerIsland,
	class_name_SimpleVoronoiIsland,
	class_name_PerlinIsland,
	class_name_PerlinLoopIsland,
	class_name_PerlinSolitaryIsland,
	class_name_RogueLike,
	class_name_SimpleRogueLike,
	class_name_MazeDig,
	class_name_ClusteringMaze,
	class_name_Rect,
	class_name_Border,
	class_name_BorderOdd,
	class_name_PointGrid,
	class_name_PointGridWithBorder,
	class_name_PointGridAndSomeBlocksWithBorder,
	class_name_WhiteNoise,
	class_name_RandomRect,
	class_name_RandomVoronoi,
	class_name_AscendingOrder,
	class_name_AscendingOrder2,
	class_name_SimplePyramid,
	class_name_SimpleTruncatedSquarePyramid,
	class_name_Reversi,
	class_name_Shogi,
	class_name_DobutsuShogi,
	class_name_All,
	class_name_num
};

template<typename Matrix_>
void generate(const ::dtl::type::size type_id, Matrix_& matrix, const ::dtl::type::size size_x, const ::dtl::type::size size_y) noexcept {
	using shape_t = ::dtl::type::uint_fast32;
	switch (type_id) {
	case class_name_CellularAutomatonMixIsland: dtl::shape::CellularAutomatonMixIsland<shape_t>(5, 0, 1, 2, 3, 4, 5).drawArray(matrix, size_x, size_y); break;//
	case class_name_CellularAutomatonIsland: dtl::shape::CellularAutomatonIsland<shape_t>(1, 0, 5, 0.4).drawArray(matrix, size_x, size_y); break;//
	case class_name_FractalLoopIsland: dtl::shape::FractalLoopIsland<shape_t>(10, 150, 70).drawArray(matrix, size_x, size_y); break;//
	case class_name_FractalIsland: dtl::shape::FractalIsland<shape_t>(10, 150, 75).drawArray(matrix, size_x, size_y); break;//
	case class_name_DiamondSquareAverageIsland: dtl::shape::DiamondSquareAverageIsland<shape_t>(0, 80, 60).drawArray(matrix, size_x, size_y); break;//
	case class_name_DiamondSquareAverageCornerIsland: dtl::shape::DiamondSquareAverageCornerIsland<shape_t>(20, 80, 60).drawArray(matrix, size_x, size_y); break;//
	case class_name_SimpleVoronoiIsland: dtl::shape::SimpleVoronoiIsland<shape_t>(40, 0.5, 1, 0).drawArray(matrix, size_x, size_y); break;//
	case class_name_PerlinIsland: dtl::shape::PerlinIsland<shape_t>(6.0, 8, 63).draw(matrix, size_x, size_y); break;
	case class_name_PerlinLoopIsland: dtl::shape::PerlinLoopIsland<shape_t>(6.0, 8, 63).draw(matrix, size_x, size_y); break;
	case class_name_PerlinSolitaryIsland: dtl::shape::PerlinSolitaryIsland<shape_t>(0.8, 0.4, 6.0, 8, 60).draw(matrix, size_x, size_y); break;
	case class_name_RogueLike: dtl::shape::RogueLike<shape_t>(0, 1, 2, 3, 4, 20, dtl::base::MatrixRange(3, 3, 2, 2), dtl::base::MatrixRange(3, 3, 4, 4)).draw(matrix, size_x, size_y); break;
	case class_name_SimpleRogueLike: dtl::shape::SimpleRogueLike<shape_t>(1, 2, 3, 4, 5, 2, 5, 2).drawArray(matrix, size_x, size_y); break;//
	case class_name_MazeDig: dtl::shape::MazeDig<shape_t>(1, 0).draw(matrix, size_x, size_y); break;
	case class_name_ClusteringMaze: dtl::shape::ClusteringMaze<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_Rect: dtl::shape::Rect<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_Border: dtl::shape::Border<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_BorderOdd: dtl::shape::BorderOdd<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_PointGrid: dtl::shape::PointGrid<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_PointGridWithBorder: dtl::shape::PointGridWithBorder<shape_t>(1).drawArray(matrix, size_x, size_y); break;//
	case class_name_PointGridAndSomeBlocksWithBorder: dtl::shape::PointGridAndSomeBlocksWithBorder<shape_t>(1, 1, 2).drawArray(matrix, size_x, size_y); break;//
	case class_name_WhiteNoise: dtl::shape::WhiteNoise<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_RandomRect: dtl::shape::RandomRect<shape_t>(1, 0.8).drawArray(matrix, size_x, size_y); break;//
	case class_name_RandomVoronoi: dtl::shape::RandomVoronoi<shape_t>(20, 0.5, 1, 0).drawArray(matrix, size_x, size_y); break;//
	case class_name_AscendingOrder: dtl::shape::AscendingOrder<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_AscendingOrder2: dtl::shape::AscendingOrder2<shape_t>(1).draw(matrix, size_x, size_y); break;
	case class_name_SimplePyramid: dtl::shape::SimplePyramid<shape_t>(99, 10).draw(matrix, size_x, size_y); break;
	case class_name_SimpleTruncatedSquarePyramid: dtl::shape::SimpleTruncatedSquarePyramid<shape_t>(99, 150, 10).draw(matrix, size_x, size_y); break;
	case class_name_Reversi: dtl::shape::Reversi<shape_t>(1, 2).draw(matrix, size_x, size_y); break;
	case class_name_Shogi: dtl::shape::Shogi<shape_t>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28).draw(matrix, size_x, size_y); break;
	case class_name_DobutsuShogi: dtl::shape::DobutsuShogi<shape_t>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10).draw(matrix, size_x, size_y); break;
	case class_name_All: dtl::shape::Rect<shape_t>(1).drawArray(matrix, size_x, size_y); break;
	}
}

template<typename Matrix_>
void output(const ::dtl::type::size type_id, Matrix_& matrix, const ::dtl::type::size size_x, const ::dtl::type::size size_y) noexcept {
	using shape_t = ::dtl::type::uint_fast32;
	dtl::shape::Rect<shape_t>(0).drawArray(matrix, size_x, size_y);
	generate(type_id, matrix, size_x, size_y);
	dtl::console::OutputNumber<shape_t>(",").drawArray(matrix, size_x, size_y);
}

int main() {

	using shape_t = ::dtl::type::uint_fast32;
	::dtl::type::size size_x{ 32 }, size_y{ 16 };
	DTL_TYPE_UNIQUE_PTR<shape_t[]> matrix(DTL_TYPE_NEW shape_t[size_x * size_y]);
	if (!matrix) return -1;

	for (::dtl::type::size i{}; i < class_name_All; ++i)
		output(i, matrix, size_x, size_y);

	return 0;
}