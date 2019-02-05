#include "DTL.hpp"
#include <cstdint>
#include <array>
#include <memory>
#include <chrono>

int main() {

	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t size_x{ 64 };
	constexpr std::size_t size_y{ 32 };
	constexpr std::size_t layer_num{ 2 };

	std::array<std::array<dungeon_t, size_x>, size_y> stl_matrix;
	std::array<dungeon_t, size_x*size_y> array_matrix;
	std::array<std::array<std::array<dungeon_t, layer_num>, size_x>, size_y> layer_matrix;

	//STL - Class

	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::Border<dungeon_t> border_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::BorderOdd<dungeon_t> border_odd_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::Chess<dungeon_t> chess_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::ChunkIsland<dungeon_t> chunk_island_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::DungeonInit<dungeon_t> dungeon_init_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::FractalIsland<dungeon_t> fractal_island_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::MazeDig<dungeon_t> maze_dig_stl(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::Mountain<dungeon_t> mountain(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::PointGrid<dungeon_t> point_grid_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::PointGridField<dungeon_t> point_grid_field_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::Reversi<dungeon_t> reversi(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::RogueLike<dungeon_t> rogue_like_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::RogueLikeCave<dungeon_t> rogue_like_cave_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::SimpleRogueLike<dungeon_t> simple_rogue_like_stl(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_stl(stl_matrix);

	//STL - Function

	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::createBorder(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::createBorderOdd(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::createChess(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createChunkIsland(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::initDungeon(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createFractalIsland(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createMazeDig(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createMountain(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::createPointGrid(stl_matrix);
	dtl::matrix::stl::init(stl_matrix);
	dtl::generator::stl::createPointGridField(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createPointGridFieldPutBlock(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createRogueLike(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createRogueLikeCave(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createSimpleDiamondSquareAverageIsland(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createSimpleDiamondSquareAverageIslandCorner(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createSimpleRogueLike(stl_matrix);
	//dtl::matrix::stl::init(stl_matrix);
	//dtl::generator::stl::createSimpleVoronoiIsland(stl_matrix);

		//Normal - Class

	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::Border<dungeon_t> border_normal(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::BorderOdd<dungeon_t> border_odd_normal(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::Chess<dungeon_t> chess_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::ChunkIsland<dungeon_t> chunk_island_normal(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::DungeonInit<dungeon_t> dungeon_init_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::FractalIsland<dungeon_t> fractal_island_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::MazeDig<dungeon_t> maze_dig_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::Mountain<dungeon_t> mountain(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::PointGrid<dungeon_t> point_grid_normal(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::PointGridField<dungeon_t> point_grid_field_normal(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::Reversi<dungeon_t> reversi(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::RogueLike<dungeon_t> rogue_like_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::RogueLikeCave<dungeon_t> rogue_like_cave_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::SimpleRogueLike<dungeon_t> simple_rogue_like_normal(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_normal(stl_matrix,size_x,size_y);

	//Normal - Function

	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::createBorder(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::createBorderOdd(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::createChess(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createChunkIsland(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::initDungeon(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createFractalIsland(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createMazeDig(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createMountain(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::createPointGrid(stl_matrix,size_x,size_y);
	dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	dtl::generator::normal::createPointGridField(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createPointGridFieldPutBlock(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createRogueLike(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createRogueLikeCave(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createSimpleDiamondSquareAverageIsland(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createSimpleDiamondSquareAverageIslandCorner(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createSimpleRogueLike(stl_matrix,size_x,size_y);
	//dtl::matrix::normal::init(stl_matrix,size_x,size_y);
	//dtl::generator::normal::createSimpleVoronoiIsland(stl_matrix,size_x,size_y);

			//Array - Class

	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::Border<dungeon_t> border_array(array_matrix, size_x, size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::BorderOdd<dungeon_t> border_odd_array(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix, size_x, size_y);
	//dtl::generator::array::Chess<dungeon_t> chess_array(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::ChunkIsland<dungeon_t> chunk_island_array(array_matrix,size_x,size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::DungeonInit<dungeon_t> dungeon_init_array(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::FractalIsland<dungeon_t> fractal_island_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::MazeDig<dungeon_t> maze_dig_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::Mountain<dungeon_t> mountain(array_matrix,size_x,size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::PointGrid<dungeon_t> point_grid_array(array_matrix, size_x, size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::PointGridField<dungeon_t> point_grid_field_array(array_matrix, size_x, size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_array(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::Reversi<dungeon_t> reversi(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::RogueLike<dungeon_t> rogue_like_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::RogueLikeCave<dungeon_t> rogue_like_cave_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::SimpleRogueLike<dungeon_t> simple_rogue_like_array(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_array(array_matrix,size_x,size_y);

	//Array - Function

	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::createBorder(array_matrix, size_x, size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::createBorderOdd(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix, size_x, size_y);
	//dtl::generator::array::createChess(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createChunkIsland(array_matrix,size_x,size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::initDungeon(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createFractalIsland(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createMazeDig(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createMountain(array_matrix,size_x,size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::createPointGrid(array_matrix, size_x, size_y);
	dtl::matrix::array::init(array_matrix, size_x, size_y);
	dtl::generator::array::createPointGridField(array_matrix, size_x, size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createPointGridFieldPutBlock(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createRogueLike(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createRogueLikeCave(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createSimpleDiamondSquareAverageIsland(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createSimpleDiamondSquareAverageIslandCorner(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createSimpleRogueLike(array_matrix,size_x,size_y);
	//dtl::matrix::array::init(array_matrix,size_x,size_y);
	//dtl::generator::array::createSimpleVoronoiIsland(array_matrix,size_x,size_y);

		//Layer STL - Class

	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::Border<dungeon_t> border_layer_stl(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::BorderOdd<dungeon_t> border_odd_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::Chess<dungeon_t> chess_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::ChunkIsland<dungeon_t> chunk_island_layer_stl(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::DungeonInit<dungeon_t> dungeon_init_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::FractalIsland<dungeon_t> fractal_island_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::MazeDig<dungeon_t> maze_dig_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::Mountain<dungeon_t> mountain(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::PointGrid<dungeon_t> point_grid_layer_stl(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::PointGridField<dungeon_t> point_grid_field_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::Reversi<dungeon_t> reversi(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::RogueLike<dungeon_t> rogue_like_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::RogueLikeCave<dungeon_t> rogue_like_cave_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::SimpleRogueLike<dungeon_t> simple_rogue_like_layer_stl(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_layer_stl(stl_matrix);

	//Layer STL - Function

	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::createBorder(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::createBorderOdd(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createChess(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createChunkIsland(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::initDungeon(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createFractalIsland(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createMazeDig(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createMountain(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::createPointGrid(layer_matrix,layer_num);
	dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	dtl::generator::layer::stl::createPointGridField(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createPointGridFieldPutBlock(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createRogueLike(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createRogueLikeCave(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createSimpleDiamondSquareAverageIsland(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createSimpleDiamondSquareAverageIslandCorner(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createSimpleRogueLike(layer_matrix,layer_num);
	//dtl::matrix::layer::stl::init(layer_matrix,layer_num);
	//dtl::generator::layer::stl::createSimpleVoronoiIsland(layer_matrix,layer_num);

		//Layer Normal - Class

	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::Border<dungeon_t> border_layer_normal(layer_matrix,layer_num, size_x, size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::BorderOdd<dungeon_t> border_odd_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//dtl::generator::layer::normal::Chess<dungeon_t> chess_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::ChunkIsland<dungeon_t> chunk_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::DungeonInit<dungeon_t> dungeon_init_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::FractalIsland<dungeon_t> fractal_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::MazeDig<dungeon_t> maze_dig_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::Mountain<dungeon_t> mountain(layer_matrix,layer_num,size_x,size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::PointGrid<dungeon_t> point_grid_layer_normal(layer_matrix,layer_num, size_x, size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::PointGridField<dungeon_t> point_grid_field_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//dtl::generator::layer::normal::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::Reversi<dungeon_t> reversi(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::RogueLike<dungeon_t> rogue_like_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::RogueLikeCave<dungeon_t> rogue_like_cave_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::SimpleRogueLike<dungeon_t> simple_rogue_like_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_layer_normal(layer_matrix,layer_num,size_x,size_y);

	//Layer Normal - Function

	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::createBorder(layer_matrix,layer_num, size_x, size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::createBorderOdd(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//dtl::generator::layer::normal::createChess(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createChunkIsland(layer_matrix,layer_num,size_x,size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::initDungeon(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createFractalIsland(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createMazeDig(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createMountain(layer_matrix,layer_num,size_x,size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::createPointGrid(layer_matrix,layer_num, size_x, size_y);
	dtl::matrix::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	dtl::generator::layer::normal::createPointGridField(layer_matrix,layer_num, size_x, size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createPointGridFieldPutBlock(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createRogueLike(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createRogueLikeCave(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createSimpleDiamondSquareAverageIsland(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createSimpleDiamondSquareAverageIslandCorner(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createSimpleRogueLike(layer_matrix,layer_num,size_x,size_y);
	//dtl::matrix::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//dtl::generator::layer::normal::createSimpleVoronoiIsland(layer_matrix,layer_num,size_x,size_y);

	//File

	dtl::file::write::stl::all(stl_matrix, "Save\\Test\\All\\picture");
	dtl::file::write::stl::bmp(stl_matrix, "Save\\Test\\picture.bmp");
	dtl::file::write::stl::csv(stl_matrix, "Save\\Test\\picture.csv");
	dtl::file::write::stl::dtlm(stl_matrix, "Save\\Test\\picture.dtlm");
	dtl::file::write::stl::folderAll(stl_matrix, "Save\\Test\\", "picture");
	dtl::file::write::stl::md(stl_matrix, "Save\\Test\\picture.md");
	dtl::file::write::stl::objBoard<dungeon_t>(stl_matrix, "Save\\Test\\picture_b.obj");
	dtl::file::write::stl::objTerrain(stl_matrix, "Save\\Test\\picture_t.obj");
	dtl::file::write::stl::pbm(stl_matrix, "Save\\Test\\picture.pbm");
	dtl::file::write::stl::svg(stl_matrix, "Save\\Test\\picture.svg");
	dtl::file::write::stl::svgColor(stl_matrix, "Save\\Test\\picture_c.svg");
	dtl::file::write::stl::txt_0_9(stl_matrix, "Save\\Test\\picture.txt");

	//Binarization

	dtl::utility::stl::binarization(stl_matrix);
	dtl::utility::stl::binarizationBool(stl_matrix, stl_matrix);
	dtl::utility::stl::binarizationBool(stl_matrix, stl_matrix,1);
	dtl::utility::stl::binarizationOver(stl_matrix, 1);
	dtl::utility::rangeBasedFor::binarization(stl_matrix);
	dtl::utility::rangeBasedFor::binarization(stl_matrix, 1);

	//Output

	dtl::console::output::stl::number(stl_matrix);
	dtl::console::output::endl();
	dtl::console::output::stl::number(stl_matrix, ",");
	dtl::console::output::endl();
	dtl::console::output::stl::string(stl_matrix, ".", "#");
	dtl::console::output::endl();
	dtl::console::output::stl::stringBool(stl_matrix, "#", ".");
	dtl::console::output::endl();
	dtl::console::output::stl::stringMirrorBool(stl_matrix, "#", ".");
	dtl::console::output::puts("a");
	

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << std::endl;

	return 0;
}