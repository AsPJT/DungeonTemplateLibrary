﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_AND_SOME_BLOCKS_WITH_BORDER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_AND_SOME_BLOCKS_WITH_BORDER

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Shape/PointGrid.hpp>
#include <Shape/BorderOdd.hpp>
#include <Shape/RandomRect.hpp>
#include <Base/Struct.hpp>

namespace dtl {
	inline namespace shape {

		//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class PointGridAndSomeBlocksWithBorder {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;
			using PairSize = std::pair<Index_Size, Index_Size>;
			using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


			///// メンバ変数 /////

			dtl::shape::RandomRect<Matrix_Int_> randomRect{};
			dtl::shape::BorderOdd<Matrix_Int_> borderOdd{};
			dtl::shape::PointGrid<Matrix_Int_> pointGrid{};

		public:


			///// 情報取得 /////

			[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
				return this->borderOdd.getPointX();
			}
			[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
				return this->borderOdd.getPointY();
			}
			[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
				return this->borderOdd.getWidth();
			}
			[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
				return this->borderOdd.getHeight();
			}
			[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
				return this->borderOdd.getValue();
			}


			///// 生成呼び出し /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool draw(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				randomRect.draw(matrix_);
				pointGrid.draw(matrix_, args_...);
				borderOdd.draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				randomRect.draw(matrix_);
				pointGrid.drawOperator(matrix_, args_...);
				borderOdd.drawOperator(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				randomRect.drawArray(matrix_, args_...);
				pointGrid.drawArray(matrix_, args_...);
				borderOdd.drawArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}
			template<typename Matrix_, typename ...Args_>
			constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				randomRect.drawOperatorArray(matrix_, args_...);
				pointGrid.drawOperatorArray(matrix_, args_...);
				borderOdd.drawOperatorArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
				return true;
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto operator()(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			constexpr auto create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->draw(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperator(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// コンストラクタ /////

			constexpr PointGridAndSomeBlocksWithBorder() noexcept = default;
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_) noexcept
				:randomRect(draw_value_), borderOdd(draw_value_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const PairMatrixInt& pair_value_) noexcept
				:borderOdd(pair_value_.second), pointGrid(pair_value_.first) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
				:borderOdd(draw_value2_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_) noexcept
				:randomRect(draw_value3_), borderOdd(draw_value2_), pointGrid(draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
				:borderOdd(point_x_, point_y_, width_, height_), pointGrid(point_x_, point_y_, width_, height_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
				:borderOdd(point_x_, point_y_, width_, height_, draw_value_), pointGrid(point_x_, point_y_, width_, height_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
				:borderOdd(point_x_, point_y_, width_, height_, pair_value_.second), pointGrid(point_x_, point_y_, width_, height_, pair_value_.first) {}

			constexpr explicit PointGridAndSomeBlocksWithBorder(const dtl::base::MatrixRange& matrix_range_) noexcept
				:randomRect(matrix_range_), borderOdd(matrix_range_), pointGrid(matrix_range_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
				:randomRect(matrix_range_, draw_value_), borderOdd(matrix_range_, draw_value_), pointGrid(matrix_range_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const dtl::base::MatrixRange& matrix_range_, const PairMatrixInt& pair_value_) noexcept
				:borderOdd(matrix_range_, pair_value_.second), pointGrid(matrix_range_, pair_value_.first) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
				:borderOdd(matrix_range_, draw_value2_), pointGrid(matrix_range_, draw_value_) {}
			constexpr explicit PointGridAndSomeBlocksWithBorder(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_) noexcept
				:randomRect(matrix_range_, draw_value3_), borderOdd(matrix_range_, draw_value2_), pointGrid(matrix_range_, draw_value_) {}

		};
	}
}

#endif //Included Dungeon Template Library