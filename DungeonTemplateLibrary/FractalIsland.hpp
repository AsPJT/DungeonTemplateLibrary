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

	template<typename Matrix_Int_>
	class FractalIsland {
	public:
		//コンストラクタ
		constexpr FractalIsland() noexcept = default;
		template<typename Matrix_>
		constexpr explicit FractalIsland(Matrix_& world_map, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) noexcept {
			create(world_map, seed_, max_value_);
		}
		//ワールドマップ生成
		template<typename Matrix_>
		constexpr void create(Matrix_& world_map, std::size_t seed_ = 0, const std::int_fast32_t max_value_ = 255) const noexcept {
			if (seed_ == 0) seed_ = static_cast<std::size_t>(rnd(0xffff));
			std::array<std::array<Matrix_Int_, 17>, 17> map_{ {} };

			//横画面サイズ
			const std::size_t map_x{ world_map.size() };
			//縦画面サイズ
			const std::size_t map_y{ ((world_map.empty()) ? 0 : world_map[0].size()) };

			const std::size_t chunk_x{ (map_x / 16) };
			const std::size_t chunk_y{ (map_y / 16) };

			constexpr std::size_t aslib_world_make_seed1{ 0x3220 };
			constexpr std::size_t aslib_world_make_seed2{ 0x292 };

			for (std::size_t i{}; i < chunk_x; ++i)
				for (std::size_t j{}; j < chunk_y; ++j) {
					//四角形の4点の高さを決定
					rnd.seed(static_cast<std::uint_fast32_t>(seed_ + i + (j * aslib_world_make_seed1) + ((i^j) * aslib_world_make_seed2)));
					map_[0][0] = static_cast<Matrix_Int_>(rnd(max_value_));
					rnd.seed(static_cast<std::uint_fast32_t>(seed_ + ((i + 1) % chunk_x) + (j * aslib_world_make_seed1) + ((((i + 1) % chunk_x) ^ j) * aslib_world_make_seed2)));
					map_[16][0] = static_cast<Matrix_Int_>(rnd(max_value_));
					rnd.seed(static_cast<std::uint_fast32_t>(seed_ + i + (((j + 1) % chunk_y) * aslib_world_make_seed1) + ((i ^ ((j + 1) % chunk_y)) * aslib_world_make_seed2)));
					map_[0][16] = static_cast<Matrix_Int_>(rnd(max_value_));
					rnd.seed(static_cast<std::uint_fast32_t>(seed_ + ((i + 1) % chunk_x) + (((j + 1) % chunk_y) * aslib_world_make_seed1) + ((((i + 1) % chunk_x) ^ ((j + 1) % chunk_y)) * aslib_world_make_seed2)));
					map_[16][16] = static_cast<Matrix_Int_>(rnd(max_value_));

					//チャンク生成
					worldMapSimple(map_, max_value_);
					//生成したチャンクをワールドマップにコピペ
					for (std::size_t i2{}; i2 < 16; ++i2)
						for (std::size_t j2{}; j2 < 16; ++j2)
							world_map[i * 16 + i2][j * 16 + j2] = map_[i2][j2];
				}
		}
	private:
		//チャンク生成
		constexpr void worldMapMake(const std::size_t x_, const std::size_t y_, const std::size_t size_, const std::size_t t1_, const std::size_t t2_, const std::size_t t3_, const std::size_t t4_, std::array<std::array<Matrix_Int_, 17>, 17>& map_, const std::size_t max_value_) const noexcept {
			//再起の終了処理
			if (size_ == 0) return;
			//頂点の高さを決める
			const std::size_t vertex_height{ ((t1_ + t2_ + t3_ + t4_) / 4) + static_cast<std::size_t>(rnd(static_cast<std::int_fast32_t>(size_))) };
			map_[x_][y_] = ((vertex_height >= max_value_) ? static_cast<Matrix_Int_>(max_value_) : static_cast<Matrix_Int_>(vertex_height));
			//四角形の2点同士の中点の高さを決定
			const std::size_t s1{ ((t1_ + t2_) / 2) };
			const std::size_t s2{ ((t1_ + t3_) / 2) };
			const std::size_t s3{ ((t2_ + t4_) / 2) };
			const std::size_t s4{ ((t3_ + t4_) / 2) };
			//4つの地点の座標を決める
			map_[x_ + size_][y_] = static_cast<Matrix_Int_>(s3);
			map_[x_ - size_][y_] = static_cast<Matrix_Int_>(s2);
			map_[x_][y_ + size_] = static_cast<Matrix_Int_>(s4);
			map_[x_][y_ - size_] = static_cast<Matrix_Int_>(s1);

			//分割サイズを半分にする
			const std::size_t& size{ size_ / static_cast<std::size_t>(2) };
			//4つに分割
			worldMapMake(x_ - size, y_ - size, size, t1_, s1, s2, map_[x_][y_], map_, max_value_);
			worldMapMake(x_ + size, y_ - size, size, s1, t2_, map_[x_][y_], s3, map_, max_value_);
			worldMapMake(x_ - size, y_ + size, size, s2, map_[x_][y_], t3_, s4, map_, max_value_);
			worldMapMake(x_ + size, y_ + size, size, map_[x_][y_], s3, s4, t4_, map_, max_value_);
		}
		//チャンク生成の呼び出し・実行
		constexpr void worldMapSimple(std::array<std::array<Matrix_Int_, 17>, 17>& map_, const std::size_t max_value_) const noexcept {
			worldMapMake(8, 8, 8, map_[0][0], map_[16][0], map_[0][16], map_[16][16], map_, max_value_);
		}
	};
}

#endif //Included Dungeon Template Library