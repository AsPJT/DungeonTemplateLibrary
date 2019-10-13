/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CUBOID_MAZE_DIG_3D_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CUBOID_MAZE_DIG_3D_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::cuboid::MazeDig3D-(立体クラス)/
#######################################################################################*/

#include <array>
#include <DTL/Base/Struct.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/Vector.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace cuboid { //"dtl::cuboid"名前空間に属する

		template<class Matrix_Var_>
		class MazeDig3D {
		private:

			Matrix_Var_ empty_value{};
			Matrix_Var_ wall_value{};

			using Index_Size = ::dtl::type::size;
			using Index_SSize = ::dtl::type::ssize;
			using stuple = ::dtl::base::MatrixVec3;
			using vectuple = DTL_TYPE_VECTOR<stuple>;
			using sstuple = ::dtl::Coordinate3Dimensional<Index_SSize>;

			template<typename Matrix_>
			constexpr bool isMinSize(const Matrix_& matrix_) const noexcept {
				return (matrix_.size() <= 2 || matrix_[0].size() <= 2 || matrix_[0][0].size() <= 2);
			}
			template<typename Matrix_>
			constexpr bool isInRange(const Matrix_ & matrix_, const Index_Size pos_x, const Index_Size pos_y, const Index_Size pos_z) const noexcept {
				return (pos_z >= 0 && pos_y >= 0 && pos_x >= 0 &&
					pos_z < matrix_.size() && pos_y < matrix_[pos_z].size() && pos_x < matrix_[pos_z][pos_y].size());
			}
			template<typename Matrix_>
			vectuple getCanDiggingDirs(const Matrix_ & matrix_, const Index_Size pos_x, const Index_Size pos_y, const Index_Size pos_z) const {
				vectuple result{};
				constexpr ::std::array<sstuple, 6> dirs{ { sstuple(-1,0,0),sstuple(1,0,0), sstuple(0,-1,0), sstuple(0,1,0), sstuple(0,0,-1), sstuple(0,0,1) } };
				for (const auto& dir : dirs) {
					const Index_Size check_x{ static_cast<Index_Size>(static_cast<Index_SSize>(pos_x) + dir.x * 2) };
					const Index_Size check_y{ static_cast<Index_Size>(static_cast<Index_SSize>(pos_y) + dir.y * 2) };
					const Index_Size check_z{ static_cast<Index_Size>(static_cast<Index_SSize>(pos_z) + dir.z * 2) };
					if (!this->isInRange(matrix_, check_x, check_y, check_z) || !(static_cast<Matrix_Var_>(matrix_[check_z][check_y][check_x]) == this->wall_value)) continue;
					result.DTL_TYPE_VEMPLACE(static_cast<Index_Size>(dir.x), static_cast<Index_Size>(dir.y), static_cast<Index_Size>(dir.z));
				}
				return result;
			}

			template<typename Matrix_>
			vectuple getCanRespawnSeedPositions(const Matrix_ & matrix_) const {
				vectuple result{};
				for (Index_Size z{}; z < matrix_.size() / 2; ++z)
					for (Index_Size y{}; y < matrix_[z * 2].size() / 2; ++y)
						for (Index_Size x{}; x < matrix_[z * 2][y * 2].size() / 2; ++x) {
							const Index_Size check_x{ x * 2 + 1 };
							const Index_Size check_y{ y * 2 + 1 };
							const Index_Size check_z{ z * 2 + 1 };
							if (this->isInRange(matrix_, check_x, check_y, check_z) &&
								(static_cast<Matrix_Var_>(matrix_[check_z][check_y][check_x]) == this->empty_value) &&
								this->getCanDiggingDirs(matrix_, check_x, check_y, check_z).DTL_TYPE_VSIZE()) {
								result.DTL_TYPE_VEMPLACE(check_x, check_y, check_z);
							}
						}
				return result;
			}

			template<typename Matrix_>
			void setMazeChip(Matrix_ & matrix_, const Index_Size pos_x, const Index_Size pos_y, const Index_Size pos_z, const Matrix_Var_ new_state) const {
				if (this->isInRange(matrix_, pos_x, pos_y, pos_z)) matrix_[pos_z][pos_y][pos_x] = new_state;
			}

		public:


			//3D迷路を生成
			template<typename Matrix_>
			void draw(Matrix_ & matrix_) const {
				if (this->isMinSize(matrix_)) return;

				Index_Size seed_x{ 1 };
				Index_Size seed_y{ 1 };
				Index_Size seed_z{ 1 };
				this->setMazeChip(matrix_, seed_x, seed_y, seed_z, this->empty_value);

				bool finish_flag{ false };
				while (!finish_flag) {
					const vectuple can_digging_dirs{ this->getCanDiggingDirs(matrix_, seed_x, seed_y, seed_z) };
					if (can_digging_dirs.DTL_TYPE_VSIZE()) {
						const stuple digging_dir{ can_digging_dirs[DTL_RANDOM_ENGINE.get<Index_Size>(can_digging_dirs.DTL_TYPE_VSIZE())] };
						const Index_Size dir_x{ digging_dir.x };
						const Index_Size dir_y{ digging_dir.y };
						const Index_Size dir_z{ digging_dir.z };
						this->setMazeChip(matrix_, seed_x + dir_x, seed_y + dir_y, seed_z + dir_z, this->empty_value);
						this->setMazeChip(matrix_, seed_x + dir_x * 2, seed_y + dir_y * 2, seed_z + dir_z * 2, this->empty_value);
						seed_x += dir_x * 2;
						seed_y += dir_y * 2;
						seed_z += dir_z * 2;
					}
					else {
						const vectuple can_respawn_seed_positions{ this->getCanRespawnSeedPositions(matrix_) };
						if (can_respawn_seed_positions.DTL_TYPE_VSIZE()) {
							const stuple respawn_pos{ can_respawn_seed_positions[DTL_RANDOM_ENGINE.get<Index_Size>(can_respawn_seed_positions.DTL_TYPE_VSIZE())] };
							seed_x = respawn_pos.x;
							seed_y = respawn_pos.y;
							seed_z = respawn_pos.z;
							this->setMazeChip(matrix_, seed_x, seed_y, seed_z, this->empty_value);
						}
						else finish_flag = true;
					}
				}
			}

			//コンストラクタ
			MazeDig3D() = default;
			constexpr MazeDig3D(const Matrix_Var_ & empty_value_)
				:empty_value(empty_value_) {}
			constexpr MazeDig3D(const Matrix_Var_ & empty_value_, const Matrix_Var_ & wall_value_)
				: empty_value(empty_value_), wall_value(wall_value_) {}

		};
	}
}

#endif //Included Dungeon Template Library