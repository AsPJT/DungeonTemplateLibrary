#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_FRACTAL_ISLAND
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_FRACTAL_ISLAND
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include <cstdint>
#include <array>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	//Diamond Square (Average)
	//ダイヤモンド・スクエア法(平均値)
	template<typename Matrix_Int_,typename Matrix_>
	constexpr void createDiamondSquareAverage_Map(const std::size_t x_, const std::size_t y_, std::size_t size_, const Matrix_Int_ t1_, const Matrix_Int_ t2_, const Matrix_Int_ t3_, const Matrix_Int_ t4_, Matrix_& matrix_, const Matrix_Int_ max_value_) noexcept {
		//再起の終了処理
		if (size_ == static_cast<std::size_t>(0)) return;

		const Matrix_Int_ vertex_rand{ static_cast<Matrix_Int_>(rnd(static_cast<std::int_fast32_t>(size_))) };
		//頂点の高さを決める
		const Matrix_Int_ vertex_height{ static_cast<Matrix_Int_>((t1_ / 4 + t2_ / 4 + t3_ / 4 + t4_ / 4)) };
		matrix_[y_][x_] = ((vertex_height > max_value_ - vertex_rand) ? max_value_ : (vertex_height + vertex_rand));
		//四角形の2点同士の中点の高さを決定
		const Matrix_Int_ s1{ static_cast<Matrix_Int_>((t1_ / 2 + t2_ / 2)) };
		const Matrix_Int_ s2{ static_cast<Matrix_Int_>((t1_ / 2 + t3_ / 2)) };
		const Matrix_Int_ s3{ static_cast<Matrix_Int_>((t2_ / 2 + t4_ / 2)) };
		const Matrix_Int_ s4{ static_cast<Matrix_Int_>((t3_ / 2 + t4_ / 2)) };
		//4つの地点の座標を決める
		matrix_[y_ + size_][x_] = s3;
		matrix_[y_ - size_][x_] = s2;
		matrix_[y_][x_ + size_] = s4;
		matrix_[y_][x_ - size_] = s1;

		//分割サイズを半分にする
		size_ /= static_cast<std::size_t>(2);
		//4つに分割
		createDiamondSquareAverage_Map(x_ - size_, y_ - size_, size_, t1_, s1, s2, matrix_[y_][x_], matrix_, max_value_);
		createDiamondSquareAverage_Map(x_ - size_, y_ + size_, size_, s1, t2_, matrix_[y_][x_], s3, matrix_, max_value_);
		createDiamondSquareAverage_Map(x_ + size_, y_ - size_, size_, s2, matrix_[y_][x_], t3_, s4, matrix_, max_value_);
		createDiamondSquareAverage_Map(x_ + size_, y_ + size_, size_, matrix_[y_][x_], s3, s4, t4_, matrix_, max_value_);
	}

	constexpr std::size_t getDiamondSquareMatrixSize(const std::size_t matrix_size) noexcept {
		std::size_t map_size{ 2 };
		while (true) {
			if ((map_size + 1) > matrix_size) return (map_size >>= 1);
			map_size <<= 1;
		}
		return 0;
	}

	//ダイヤモンド・スクエア法(平均値)
	template<typename Matrix_Int_>
	class SimpleDiamondSquareAverageIsland {
	public:
		//コンストラクタ
		constexpr SimpleDiamondSquareAverageIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit SimpleDiamondSquareAverageIsland(Matrix_& matrix_, const Matrix_Int_ max_value_ = 255) noexcept {
			create(matrix_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ max_value_ = 255) const noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;

			const std::size_t map_size{ getDiamondSquareMatrixSize((matrix_.size() > matrix_[0].size()) ? matrix_[0].size() : matrix_.size()) };

			matrix_[0][0] = static_cast<Matrix_Int_>(max_value_);
			matrix_[0][map_size] = static_cast<Matrix_Int_>(rnd(max_value_));
			matrix_[map_size][0] = static_cast<Matrix_Int_>(rnd(max_value_));
			matrix_[map_size][map_size] = static_cast<Matrix_Int_>(rnd(max_value_));
			createDiamondSquareAverage_Map<Matrix_Int_>(map_size / 2, map_size / 2, map_size / 2, matrix_[0][0], matrix_[map_size][0], matrix_[0][map_size], matrix_[map_size][map_size], matrix_, max_value_);
		}
	};

	constexpr std::size_t chunk_size{ 17 };
	constexpr std::size_t chunk_array_max{ 16 };
	constexpr std::size_t chunk_array_max_half{ 8 };

	template<typename Matrix_Int_>
	class FractalIsland {
	public:
		//コンストラクタ
		constexpr FractalIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit FractalIsland(Matrix_& matrix_, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) noexcept {
			create(matrix_, seed_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		void create(Matrix_& matrix_, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) const noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;

			if (seed_ == 0) seed_ = static_cast<std::size_t>(rnd(1, 0x7fffffff));
			std::array<std::array<Matrix_Int_, chunk_size>, chunk_size> chunk_matrix{ {} };
			const std::size_t chunk_x{ (matrix_[0].size() / chunk_array_max) };
			const std::size_t chunk_y{ (matrix_.size() / chunk_array_max) };

			std::unique_ptr<std::int_fast32_t[]> rand_up(new std::int_fast32_t[chunk_x + 1]);
			std::unique_ptr<std::int_fast32_t[]> rand_down(new std::int_fast32_t[chunk_x + 1]);
			std::unique_ptr<std::int_fast32_t[]> rand_first_row(new std::int_fast32_t[chunk_x + 1]);

			for (std::size_t col{}; col < chunk_x; ++col) {
				rand_up[col] = rnd(max_value_);
				rand_first_row[col] = rand_up[col];
			}
			rand_first_row[chunk_x] = rand_up[chunk_x] = rand_up[0];

			for (std::size_t row{}; row < chunk_y; ++row) {

				if ((row + 1) == chunk_y) rand_down = std::move(rand_first_row);
				else {
					for (std::size_t col{}; col < chunk_x; ++col)
						rand_down[col] = rnd(max_value_);
					rand_down[chunk_x] = rand_down[0];
				}
				for (std::size_t col{}; col < chunk_x; ++col) {
					//四角形の4点の高さを決定
					chunk_matrix[0][0] = static_cast<Matrix_Int_>(rand_up[col]);
					chunk_matrix[chunk_array_max][0] = static_cast<Matrix_Int_>(rand_down[col]);
					chunk_matrix[0][chunk_array_max] = static_cast<Matrix_Int_>(rand_up[col+1]);
					chunk_matrix[chunk_array_max][chunk_array_max] = static_cast<Matrix_Int_>(rand_down[col+1]);
					//チャンク生成
					createWorldMapSimple(chunk_matrix, static_cast<Matrix_Int_>(max_value_));
					//生成したチャンクをワールドマップにコピペ
					for (std::size_t row2{}; row2 < chunk_array_max; ++row2)
						for (std::size_t col2{}; col2 < chunk_array_max; ++col2)
							matrix_[row * chunk_array_max + row2][col * chunk_array_max + col2] = chunk_matrix[row2][col2];
				}
				for (std::size_t col{}; col <= chunk_x; ++col)
					rand_up[col] = rand_down[col];
			}
		}
	private:
		//チャンク生成の呼び出し・実行
		constexpr void createWorldMapSimple(std::array<std::array<Matrix_Int_, chunk_size>, chunk_size>& matrix_, const Matrix_Int_ max_value_) const noexcept {
			createDiamondSquareAverage_Map<Matrix_Int_>(chunk_array_max_half, chunk_array_max_half, chunk_array_max_half, matrix_[0][0], matrix_[chunk_array_max][0], matrix_[0][chunk_array_max], matrix_[chunk_array_max][chunk_array_max], matrix_, max_value_);
		}
	};

	template<typename Matrix_Int_>
	class ChunkIsland {
	public:
		//コンストラクタ
		constexpr ChunkIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit ChunkIsland(Matrix_& matrix_, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) noexcept {
			create(matrix_, seed_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		void create(Matrix_& matrix_, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) const noexcept {
			if (matrix_.size() == 0 || matrix_[0].size() == 0) return;

			if (seed_ == 0) seed_ = static_cast<std::size_t>(rnd(1, 0x7fffffff));
			std::array<std::array<Matrix_Int_, chunk_size>, chunk_size> chunk_matrix{ {} };
			const std::size_t chunk_x{ (matrix_[0].size() / chunk_array_max) };
			const std::size_t chunk_y{ (matrix_.size() / chunk_array_max) };

			std::unique_ptr<std::int_fast32_t[]> rand_up(new std::int_fast32_t[chunk_x + 1]);
			std::unique_ptr<std::int_fast32_t[]> rand_down(new std::int_fast32_t[chunk_x + 1]);

			for (std::size_t col{}; col <= chunk_x; ++col)
				rand_up[col] = 0;

			for (std::size_t row{}; row < chunk_y; ++row) {

				if ((row + 1) == chunk_y)
					for (std::size_t col{}; col <= chunk_x; ++col)
						rand_down[col] = 0;
				else {
					for (std::size_t col{1}; col < chunk_x; ++col)
						rand_down[col] = rnd(max_value_);
					rand_down[0] = 0;
					rand_down[chunk_x] = 0;
				}
				for (std::size_t col{}; col < chunk_x; ++col) {
					//四角形の4点の高さを決定
					chunk_matrix[0][0] = static_cast<Matrix_Int_>(rand_up[col]);
					chunk_matrix[chunk_array_max][0] = static_cast<Matrix_Int_>(rand_down[col]);
					chunk_matrix[0][chunk_array_max] = static_cast<Matrix_Int_>(rand_up[col + 1]);
					chunk_matrix[chunk_array_max][chunk_array_max] = static_cast<Matrix_Int_>(rand_down[col + 1]);
					//チャンク生成
					createWorldMapSimple(chunk_matrix, static_cast<Matrix_Int_>(max_value_));
					//生成したチャンクをワールドマップにコピペ
					for (std::size_t row2{}; row2 < chunk_array_max; ++row2)
						for (std::size_t col2{}; col2 < chunk_array_max; ++col2)
							matrix_[row * chunk_array_max + row2][col * chunk_array_max + col2] = chunk_matrix[row2][col2];
				}
				for (std::size_t col{}; col <= chunk_x; ++col)
					rand_up[col] = rand_down[col];
			}
		}
	private:
		//チャンク生成の呼び出し・実行
		constexpr void createWorldMapSimple(std::array<std::array<Matrix_Int_, chunk_size>, chunk_size>& matrix_, const Matrix_Int_ max_value_) const noexcept {
			createDiamondSquareAverage_Map<Matrix_Int_>(chunk_array_max_half, chunk_array_max_half, chunk_array_max_half, matrix_[0][0], matrix_[chunk_array_max][0], matrix_[0][chunk_array_max], matrix_[chunk_array_max][chunk_array_max], matrix_, max_value_);
		}
	};

}

#endif //Included Dungeon Template Library