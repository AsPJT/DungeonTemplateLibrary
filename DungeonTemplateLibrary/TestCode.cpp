#include "DTL.hpp"
#include <cstdint>
#include <array>
#include <memory>
#include <chrono>

int main() {

	using dtl::utility::stl::init;
	using dtl::utility::normal::init;
	using namespace dtl::generator;

	const std::chrono::system_clock::time_point& start{ std::chrono::system_clock::now() };

	using dungeon_t = std::uint_fast8_t;
	constexpr std::size_t size_x{ 64 };
	constexpr std::size_t size_y{ 32 };
	constexpr std::size_t layer_num{ 2 };

	std::array<std::array<dungeon_t, size_x>, size_y> stl_matrix;
	std::array<dungeon_t, size_x*size_y> array_matrix;
	std::array<std::array<std::array<dungeon_t, layer_num>, size_x>, size_y> layer_matrix;

	//STL - Class

	init(stl_matrix);
	common::stl::Border<dungeon_t> border_stl(stl_matrix);
	init(stl_matrix);
	common::stl::BorderOdd<dungeon_t> border_odd_stl(stl_matrix);
	init(stl_matrix);
	boardGame::stl::Chess<dungeon_t> chess_stl(stl_matrix);
	init(stl_matrix);
	terrain::stl::ChunkIsland<dungeon_t> chunk_island_stl(stl_matrix);
	init(stl_matrix);
	common::stl::DungeonInit<dungeon_t> dungeon_init_stl(stl_matrix);
	init(stl_matrix);
	terrain::stl::FractalIsland<dungeon_t> fractal_island_stl(stl_matrix);
	init(stl_matrix);
	dungeon::stl::MazeDig<dungeon_t> maze_dig_stl(stl_matrix);
	//init(stl_matrix);
	//common::stl::Mountain<dungeon_t> mountain(stl_matrix);
	init(stl_matrix);
	common::stl::PointGrid<dungeon_t> point_grid_stl(stl_matrix);
	init(stl_matrix);
	common::stl::PointGridField<dungeon_t> point_grid_field_stl(stl_matrix);
	init(stl_matrix);
	common::stl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_stl(stl_matrix);
	init(stl_matrix);
	boardGame::stl::Reversi<dungeon_t> reversi(stl_matrix);
	init(stl_matrix);
	dungeon::stl::RogueLike<dungeon_t> rogue_like_stl(stl_matrix);
	init(stl_matrix);
	dungeon::stl::RogueLikeCave<dungeon_t> rogue_like_cave_stl(stl_matrix);
	init(stl_matrix);
	terrain::stl::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_stl(stl_matrix);
	init(stl_matrix);
	terrain::stl::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_stl(stl_matrix);
	init(stl_matrix);
	dungeon::stl::SimpleRogueLike<dungeon_t> simple_rogue_like_stl(stl_matrix);
	init(stl_matrix);
	terrain::stl::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_stl(stl_matrix);

	//STL - Function

	init(stl_matrix);
	common::stl::createBorder(stl_matrix);
	init(stl_matrix);
	common::stl::createBorderOdd(stl_matrix);
	init(stl_matrix);
	boardGame::stl::createChess(stl_matrix);
	//init(stl_matrix);
	//common::stl::createChunkIsland(stl_matrix);
	init(stl_matrix);
	common::stl::initDungeon(stl_matrix);
	//init(stl_matrix);
	//common::stl::createFractalIsland(stl_matrix);
	//init(stl_matrix);
	//common::stl::createMazeDig(stl_matrix);
	//init(stl_matrix);
	//common::stl::createMountain(stl_matrix);
	init(stl_matrix);
	common::stl::createPointGrid(stl_matrix);
	init(stl_matrix);
	common::stl::createPointGridField(stl_matrix);
	//init(stl_matrix);
	//common::stl::createPointGridFieldPutBlock(stl_matrix);
	//init(stl_matrix);
	//common::stl::createRogueLike(stl_matrix);
	//init(stl_matrix);
	//common::stl::createRogueLikeCave(stl_matrix);
	//init(stl_matrix);
	//common::stl::createSimpleDiamondSquareAverageIsland(stl_matrix);
	//init(stl_matrix);
	//common::stl::createSimpleDiamondSquareAverageIslandCorner(stl_matrix);
	//init(stl_matrix);
	//common::stl::createSimpleRogueLike(stl_matrix);
	//init(stl_matrix);
	//common::stl::createSimpleVoronoiIsland(stl_matrix);

		//Normal - Class

	init(stl_matrix,size_x,size_y);
	common::normal::Border<dungeon_t> border_normal(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::BorderOdd<dungeon_t> border_odd_normal(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	boardGame::normal::Chess<dungeon_t> chess_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::ChunkIsland<dungeon_t> chunk_island_normal(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::DungeonInit<dungeon_t> dungeon_init_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::FractalIsland<dungeon_t> fractal_island_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::MazeDig<dungeon_t> maze_dig_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::Mountain<dungeon_t> mountain(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::PointGrid<dungeon_t> point_grid_normal(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::PointGridField<dungeon_t> point_grid_field_normal(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::Reversi<dungeon_t> reversi(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::RogueLike<dungeon_t> rogue_like_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::RogueLikeCave<dungeon_t> rogue_like_cave_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::SimpleRogueLike<dungeon_t> simple_rogue_like_normal(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_normal(stl_matrix,size_x,size_y);

	//Normal - Function

	init(stl_matrix,size_x,size_y);
	common::normal::createBorder(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::createBorderOdd(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	boardGame::normal::createChess(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createChunkIsland(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::initDungeon(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createFractalIsland(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createMazeDig(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createMountain(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::createPointGrid(stl_matrix,size_x,size_y);
	init(stl_matrix,size_x,size_y);
	common::normal::createPointGridField(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createPointGridFieldPutBlock(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createRogueLike(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createRogueLikeCave(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createSimpleDiamondSquareAverageIsland(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createSimpleDiamondSquareAverageIslandCorner(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createSimpleRogueLike(stl_matrix,size_x,size_y);
	//init(stl_matrix,size_x,size_y);
	//common::normal::createSimpleVoronoiIsland(stl_matrix,size_x,size_y);

			//Array - Class

	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::Border<dungeon_t> border_array(array_matrix, size_x, size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::BorderOdd<dungeon_t> border_odd_array(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix, size_x, size_y);
	//common::array::Chess<dungeon_t> chess_array(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::ChunkIsland<dungeon_t> chunk_island_array(array_matrix,size_x,size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::DungeonInit<dungeon_t> dungeon_init_array(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::FractalIsland<dungeon_t> fractal_island_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::MazeDig<dungeon_t> maze_dig_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::Mountain<dungeon_t> mountain(array_matrix,size_x,size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::PointGrid<dungeon_t> point_grid_array(array_matrix, size_x, size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::PointGridField<dungeon_t> point_grid_field_array(array_matrix, size_x, size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_array(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::Reversi<dungeon_t> reversi(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::RogueLike<dungeon_t> rogue_like_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::RogueLikeCave<dungeon_t> rogue_like_cave_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::SimpleRogueLike<dungeon_t> simple_rogue_like_array(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_array(array_matrix,size_x,size_y);

	//Array - Function

	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::createBorder(array_matrix, size_x, size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::createBorderOdd(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix, size_x, size_y);
	//common::array::createChess(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createChunkIsland(array_matrix,size_x,size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::initDungeon(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createFractalIsland(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createMazeDig(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createMountain(array_matrix,size_x,size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::createPointGrid(array_matrix, size_x, size_y);
	dtl::utility::array::init(array_matrix, size_x, size_y);
	common::array::createPointGridField(array_matrix, size_x, size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createPointGridFieldPutBlock(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createRogueLike(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createRogueLikeCave(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createSimpleDiamondSquareAverageIsland(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createSimpleDiamondSquareAverageIslandCorner(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createSimpleRogueLike(array_matrix,size_x,size_y);
	//dtl::utility::array::init(array_matrix,size_x,size_y);
	//common::array::createSimpleVoronoiIsland(array_matrix,size_x,size_y);

		//Layer STL - Class

	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::Border<dungeon_t> border_layer_stl(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::BorderOdd<dungeon_t> border_odd_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::Chess<dungeon_t> chess_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::ChunkIsland<dungeon_t> chunk_island_layer_stl(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::DungeonInit<dungeon_t> dungeon_init_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::FractalIsland<dungeon_t> fractal_island_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::MazeDig<dungeon_t> maze_dig_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::Mountain<dungeon_t> mountain(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::PointGrid<dungeon_t> point_grid_layer_stl(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::PointGridField<dungeon_t> point_grid_field_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::Reversi<dungeon_t> reversi(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::RogueLike<dungeon_t> rogue_like_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::RogueLikeCave<dungeon_t> rogue_like_cave_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::SimpleRogueLike<dungeon_t> simple_rogue_like_layer_stl(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_layer_stl(stl_matrix);

	//Layer STL - Function

	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::createBorder(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::createBorderOdd(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createChess(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createChunkIsland(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::initDungeon(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createFractalIsland(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createMazeDig(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createMountain(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::createPointGrid(layer_matrix,layer_num);
	dtl::utility::layer::stl::init(layer_matrix,layer_num);
	common::layer::stl::createPointGridField(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createPointGridFieldPutBlock(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createRogueLike(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createRogueLikeCave(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createSimpleDiamondSquareAverageIsland(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createSimpleDiamondSquareAverageIslandCorner(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createSimpleRogueLike(layer_matrix,layer_num);
	//dtl::utility::layer::stl::init(layer_matrix,layer_num);
	//common::layer::stl::createSimpleVoronoiIsland(layer_matrix,layer_num);

		//Layer Normal - Class

	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::Border<dungeon_t> border_layer_normal(layer_matrix,layer_num, size_x, size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::BorderOdd<dungeon_t> border_odd_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//common::layer::normal::Chess<dungeon_t> chess_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::ChunkIsland<dungeon_t> chunk_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::DungeonInit<dungeon_t> dungeon_init_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::FractalIsland<dungeon_t> fractal_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::MazeDig<dungeon_t> maze_dig_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::Mountain<dungeon_t> mountain(layer_matrix,layer_num,size_x,size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::PointGrid<dungeon_t> point_grid_layer_normal(layer_matrix,layer_num, size_x, size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::PointGridField<dungeon_t> point_grid_field_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//common::layer::normal::PointGridFieldPutBlock<dungeon_t> point_grid_field_put_block_layer_normal(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::Reversi<dungeon_t> reversi(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::RogueLike<dungeon_t> rogue_like_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::RogueLikeCave<dungeon_t> rogue_like_cave_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::SimpleDiamondSquareAverageIsland<dungeon_t> simple_diamond_square_average_island_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::SimpleDiamondSquareAverageIslandCorner<dungeon_t> simple_diamond_square_average_island_corner_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::SimpleRogueLike<dungeon_t> simple_rogue_like_layer_normal(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::SimpleVoronoiIsland<dungeon_t> simple_voronoi_island_layer_normal(layer_matrix,layer_num,size_x,size_y);

	//Layer Normal - Function

	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::createBorder(layer_matrix,layer_num, size_x, size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::createBorderOdd(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	//common::layer::normal::createChess(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createChunkIsland(layer_matrix,layer_num,size_x,size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::initDungeon(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createFractalIsland(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createMazeDig(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createMountain(layer_matrix,layer_num,size_x,size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::createPointGrid(layer_matrix,layer_num, size_x, size_y);
	dtl::utility::layer::normal::init(layer_matrix,layer_num, size_x, size_y);
	common::layer::normal::createPointGridField(layer_matrix,layer_num, size_x, size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createPointGridFieldPutBlock(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createRogueLike(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createRogueLikeCave(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createSimpleDiamondSquareAverageIsland(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createSimpleDiamondSquareAverageIslandCorner(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createSimpleRogueLike(layer_matrix,layer_num,size_x,size_y);
	//dtl::utility::layer::normal::init(layer_matrix,layer_num,size_x,size_y);
	//common::layer::normal::createSimpleVoronoiIsland(layer_matrix,layer_num,size_x,size_y);

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

	//std::vector<std::vector<dungeon_t>> make_csv_matrix{ dtl::file::read::stl::make_csv<dungeon_t,std::vector<std::vector<dungeon_t>>>("Save\\Test\\picture.csv") };

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