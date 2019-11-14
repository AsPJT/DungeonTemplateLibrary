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
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Range/RectBaseWithValue.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/IntX.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Utility/DrawJaggedRandom.hpp>

#include <array>
#include <vector>
#include <algorithm>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] ClusteringMazeとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] ClusteringMaze is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename Random_Engine_ = DTL_RANDOM_DEFAULT_RANDOM>
		class ClusteringMaze : public ::dtl::range::RectBaseWithValue<ClusteringMaze<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJaggedRandom<ClusteringMaze<Matrix_Var_>, Matrix_Var_, Random_Engine_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValue<ClusteringMaze, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJaggedRandom<ClusteringMaze, Matrix_Var_, Random_Engine_>;

			friend DrawBase_t;

			enum Direction : ::dtl::type::uint_fast8 {
				UP_DIR, RIGHT_DIR, DOWN_DIR, LEFT_DIR
			};

			::dtl::type::int_fast32 dirDx(Direction dir) const noexcept {
				switch (dir) {
				case UP_DIR:
				case DOWN_DIR:return 0;
				case RIGHT_DIR:return 1;
				case LEFT_DIR:return -1;
				}
				return 0;
			}
			::dtl::type::int_fast32 dirDy(Direction dir) const noexcept {
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
			::dtl::type::int_fast32 findDifNeighbor(Random_Engine_& random_engine_, std::vector<Index_Size>& data_, const Index_Size m_width, const Index_Size m_height, const Index_Size m_size, const Index_Size x, const Index_Size y, Index_Size& outX, Index_Size& outY, Direction& outDir) const {
				std::vector<Index_Size> sameTags{};
				const Index_Size cellind{ y * m_width + x };
				for (Index_Size i{}; i < m_size; ++i)
					if (this->same(data_, cellind, i)) sameTags.emplace_back(i);
				::std::shuffle(sameTags.begin(), sameTags.end(), random_engine_.getEngine());

				Index_Size cell1X{}, cell1Y{}, cell2X{}, cell2Y{}, cell2ind{};
				std::array<Direction, 4> dirs{ { UP_DIR, RIGHT_DIR, DOWN_DIR, LEFT_DIR } };
				for (auto cell1ind : sameTags) {
					cell1X = cell1ind % m_width;
					cell1Y = cell1ind / m_width;
					::std::shuffle(dirs.begin(), dirs.end(), random_engine_.getEngine());
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
			void uniteDifNeighbor(Random_Engine_& random_engine_, std::vector<Index_Size>& data_, std::vector<Index_Size>& rank_, const Index_Size m_width, const Index_Size m_height, const Index_Size m_size, const Index_Size x, const Index_Size y, Index_Size& outX, Index_Size& outY, Direction& outDir) const {
				Index_Size oX{}, oY{};
				Direction oDir{};
				if (this->findDifNeighbor(random_engine_, data_, m_width, m_height, m_size, x, y, oX, oY, oDir) != -1) this->unite(data_, rank_, y * m_width + x, oY * m_width + oX);
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
			//DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Random_Engine_&& random_engine_, Args_&& ... args_) const noexcept {
				const Index_Size width_size{ (this->calcEndX(matrix_.getX()) - this->start_x) };
				const Index_Size height_size{ (this->calcEndY(matrix_.getY()) - this->start_y) };

				const Index_Size width3{ (width_size % 2 == 0) ? width_size - 1 : width_size };
				const Index_Size height3{ (height_size % 2 == 0) ? height_size - 1 : height_size };

				for (Index_Size i{}; i < width3 / 2; ++i)
					for (Index_Size j{}; j < height3 / 2; ++j)
						matrix_.set(this->start_x + (2 * i + 1), this->start_y + (2 * j + 1), this->draw_value, args_...);

				const Index_Size m_width{ width3 / 2 }, m_height{ height3 / 2 }, m_size{ m_width * m_height };

				// for Union Find
				std::vector<Index_Size> data(m_size, 0);
				std::vector<Index_Size> rank(m_size, 0);
				for (Index_Size i{}; i < m_size; ++i) data[i] = i;

				Index_Size randCellX{}, randCellY{};
				Index_Size outX{}, outY{};
				Direction outDir{};
				while (!this->isAllSame(data, data.size())) {
					randCellX = static_cast<::dtl::type::uint_fast32>(random_engine_.get()) % (width3 / 2);
					randCellY = static_cast<::dtl::type::uint_fast32>(random_engine_.get()) % (height3 / 2);

					this->uniteDifNeighbor(random_engine_, data, rank, m_width, m_height, m_size, randCellX, randCellY, outX, outY, outDir);

					// break wall
					matrix_.set(this->start_x + (2 * outX + 1 - this->dirDx(outDir)), this->start_y + (2 * outY + 1 - this->dirDy(outDir)), this->draw_value, args_...);
				}

				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library