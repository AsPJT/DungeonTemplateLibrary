/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_CLUSTERING_MAZE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_CLUSTERING_MAZE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::ClusteringMaze-(形状クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Random/MersenneTwister32bit.hpp>
#include <DTL/Range/RectBaseWithValue.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>

#include <array>
#include <vector>
#include <random>
#include <algorithm>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

		struct ClusteringMazeCM {
			std::uint_fast32_t operator()() {
				return DTL_RANDOM_ENGINE.get();
			}
		};

/*#######################################################################################
	[概要] ClusteringMazeとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] ClusteringMaze is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = ::std::mt19937, typename Random_Seed_ = ClusteringMazeCM>
		class ClusteringMaze : public ::dtl::range::RectBaseWithValue<ClusteringMaze<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<ClusteringMaze<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValue<ClusteringMaze, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<ClusteringMaze, Matrix_Var_>;

			friend DrawBase_t;

			enum Direction : std::uint_fast8_t {
				UP_DIR, RIGHT_DIR, DOWN_DIR, LEFT_DIR
			};

			std::int_fast32_t dirDx(Direction dir) const noexcept {
				switch (dir) {
				case UP_DIR:
				case DOWN_DIR:return 0;
				case RIGHT_DIR:return 1;
				case LEFT_DIR:return -1;
				}
				return 0;
			}
			std::int_fast32_t dirDy(Direction dir) const noexcept {
				switch (dir) {
				case RIGHT_DIR:
				case LEFT_DIR:return 0;
				case UP_DIR:return -1;
				case DOWN_DIR:return 1;
				}
				return 0;
			}

			/*
			 * The class is Union Find set for creating maze.
			 */
			 // for Union Find
			Index_Size root(std::vector<Index_Size>& data_, const Index_Size x_) const {
				return (data_[x_] == x_) ? x_ : data_[x_] = this->root(data_, data_[x_]);
			}
			bool same(std::vector<Index_Size>& data_, const Index_Size x_, const Index_Size y_) const {
				return this->root(data_, x_) == this->root(data_, y_);
			}
			void unite(std::vector<Index_Size>& data_, std::vector<Index_Size>& rank_, Index_Size x, Index_Size y) const {
				x = this->root(data_, x);
				y = this->root(data_, y);
				if (x == y) return;

				if (rank_[x] < rank_[y]) data_[x] = y;
				else {
					data_[y] = x;
					if (rank_[x] == rank_[y]) ++rank_[x];
				}
			}

			// Find a different tag cell adjacent to a tag that contains a cell with coordinates (x, y).
			std::int_fast32_t findDifNeighbor(Random_Engine_& randomEngine, std::vector<Index_Size>& data_, const Index_Size m_width, const Index_Size m_height, const Index_Size m_size, const Index_Size x, const Index_Size y, Index_Size& outX, Index_Size& outY, Direction& outDir) const {
				std::vector<Index_Size> sameTags{};
				const Index_Size cellind{ y * m_width + x };
				for (Index_Size i{}; i < m_size; ++i)
					if (this->same(data_, cellind, i)) sameTags.emplace_back(i);
				::std::shuffle(sameTags.begin(), sameTags.end(), randomEngine);

				Index_Size cell1X{}, cell1Y{}, cell2X{}, cell2Y{}, cell2ind{};
				std::array<Direction, 4> dirs{ { UP_DIR, RIGHT_DIR, DOWN_DIR, LEFT_DIR } };
				for (auto cell1ind : sameTags) {
					cell1X = cell1ind % m_width;
					cell1Y = cell1ind / m_width;
					::std::shuffle(dirs.begin(), dirs.end(), randomEngine);
					for (auto dir : dirs) {
						if ((dirDx(dir) < 0 && cell1X == 0) || (dirDx(dir) > 0 && cell1X == m_width - 1)) continue;
						cell2X = cell1X + dirDx(dir);
						if ((dirDy(dir) < 0 && cell1Y == 0) || (dirDy(dir) > 0 && cell1Y == m_height - 1)) continue;
						cell2Y = cell1Y + dirDy(dir);
						cell2ind = cell2Y * m_width + cell2X;
						if (!this->same(data_, cell1ind, cell2ind)) {
							outX = cell2X;
							outY = cell2Y;
							outDir = dir;
							return 0;
						}
					}
				}
				return -1;
			}

			// findDifneighbor() and unite
			void uniteDifNeighbor(Random_Engine_& randomEngine, std::vector<Index_Size>& data_, std::vector<Index_Size>& rank_, const Index_Size m_width, const Index_Size m_height, const Index_Size m_size, const Index_Size x, const Index_Size y, Index_Size& outX, Index_Size& outY, Direction& outDir) const {
				Index_Size oX{}, oY{};
				Direction oDir{};
				if (this->findDifNeighbor(randomEngine, data_, m_width, m_height, m_size, x, y, oX, oY, oDir) != -1) this->unite(data_, rank_, y * m_width + x, oY * m_width + oX);
				outX = oX;
				outY = oY;
				outDir = oDir;
			}

			bool isAllSame(std::vector<Index_Size>& data_, const Index_Size d_size_) const {
				for (Index_Size i{ 1 }; i < d_size_; ++i) if (!this->same(data_, i, 0)) return false;
				return true;
			}

		public:

			///// 基本処理 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				const Index_Size width{ (this->calcEndX(matrix_.getX()) - this->start_x) };
				const Index_Size height{ (this->calcEndY(matrix_.getY()) - this->start_y) };

				const Index_Size width3{ (width % 2 == 0) ? width - 1 : width };
				const Index_Size height3{ (height % 2 == 0) ? height - 1 : height };

				for (Index_Size i{}; i < width3 / 2; ++i)
					for (Index_Size j{}; j < height3 / 2; ++j)
						matrix_.set(this->start_x + (2 * i + 1), this->start_y + (2 * j + 1), this->draw_value, args_...);


				Random_Engine_ randomEngine{ Random_Seed_()() };

				const Index_Size m_width{ width3 / 2 }, m_height{ height3 / 2 }, m_size{ m_width * m_height };

				// for Union Find
				std::vector<Index_Size> data(m_size, 0);
				std::vector<Index_Size> rank(m_size, 0);
				for (Index_Size i{}; i < m_size; ++i) data[i] = i;

				Index_Size randCellX{}, randCellY{};
				Index_Size outX{}, outY{};
				Direction outDir{};
				while (!this->isAllSame(data, data.size())) {
					randCellX = randomEngine() % (width3 / 2);
					randCellY = randomEngine() % (height3 / 2);

					this->uniteDifNeighbor(randomEngine, data, rank, m_width, m_height, m_size, randCellX, randCellY, outX, outY, outDir);

					// break wall
					matrix_.set(this->start_x + (2 * outX + 1 - this->dirDx(outDir)), this->start_y + (2 * outY + 1 - this->dirDy(outDir)), this->draw_value, args_...);
				}

				//UniquePtr_ select_x{ DTL_TYPE_NEW::dtl::type::size[(end_x_ - this->start_x) * (end_y_ - this->start_y)] };
				//if (!select_x) return false;
				//UniquePtr_ select_y{ DTL_TYPE_NEW::dtl::type::size[(end_x_ - this->start_x) * (end_y_ - this->start_y)] };
				//if (!select_y) return false;

				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library