/*#######################################################################################
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
#include "Shape_PointGrid.hpp"
#include "Shape_BorderOdd.hpp"
#include "Shape_RandomRect.hpp"
#include "Base_Struct.hpp"

namespace dtl::shape {

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
		constexpr bool draw(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.draw(matrix_);
			pointGrid.draw(matrix_, args_...);
			borderOdd.draw(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.draw(matrix_);
			pointGrid.drawOperator(matrix_, args_...);
			borderOdd.drawOperator(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.draw(matrix_);
			pointGrid.drawArray(matrix_, args_...);
			borderOdd.drawArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			randomRect.draw(matrix_);
			pointGrid.drawOperatorArray(matrix_, args_...);
			borderOdd.drawOperatorArray(std::forward<Matrix_>(matrix_), std::forward<Args_>(args_)...);
			return true;
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return std::forward<Matrix_>(matrix_);
		}


		///// コンストラクタ /////

		constexpr PointGridAndSomeBlocksWithBorder() noexcept = default;
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_) noexcept
			:randomRect(draw_value_), borderOdd(draw_value_), pointGrid(draw_value_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairMatrixInt& pair_value_) noexcept
			:borderOdd(pair_value_.second), pointGrid(pair_value_.first) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& length_) noexcept
			:borderOdd(length_), pointGrid(length_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(length_, draw_value_), pointGrid(length_, draw_value_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(length_, pair_value_.second), pointGrid(length_, pair_value_.first) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& position_, const PairSize& length_) noexcept
			:borderOdd(position_, length_), pointGrid(position_, length_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(position_, length_, draw_value_), pointGrid(position_, length_, draw_value_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const PairSize& position_, const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(position_, length_, pair_value_.second), pointGrid(position_, length_, pair_value_.first) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
			:borderOdd(draw_value2_), pointGrid(draw_value_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_, const Matrix_Int_& draw_value3_) noexcept
			:randomRect(draw_value3_), borderOdd(draw_value2_), pointGrid(draw_value_) {}

		constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(width_, height_, pair_value_.second), pointGrid(width_, height_, pair_value_.first) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_), pointGrid(point_x_, point_y_, width_, height_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_, draw_value_), pointGrid(point_x_, point_y_, width_, height_, draw_value_) {}
		constexpr explicit PointGridAndSomeBlocksWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_, pair_value_.second), pointGrid(point_x_, point_y_, width_, height_, pair_value_.first) {}

		//template<typename ...Args_>
		//constexpr explicit PointGridAndSomeBlocksWithBorder(Args_&&... args_) noexcept
		//	:borderOdd(std::forward<Args_>(args_)...), pointGrid(std::forward<Args_>(args_)...) {}
	};
}

/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include "Shape_PointGrid.hpp"
#include "Shape_BorderOdd.hpp"
#include "Random_MersenneTwister32bit.hpp"

namespace dtl::generator::common::data {

	enum ePointGridFieldPutBlock {
		point_grid_field_put_block_empty_id,
		point_grid_field_put_block_wall_id,
		point_grid_field_put_block_block_id,
		point_grid_field_put_block_enum_num
	};
	constexpr bool point_grid_field_put_block_bool{ (point_grid_field_put_block_enum_num <= 2) ? true : false };

}

//STL版
namespace dtl::generator::common::stl {

	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_) noexcept {
		if (matrix_.size() < 3 || matrix_[1].size() < 3) return;
		const std::size_t y_end{ ((matrix_.size() % 2 == 0) ? (matrix_.size() - 2) : (matrix_.size() - 1)) };
		const std::size_t x_end{ ((matrix_[1].size() % 2 == 0) ? (matrix_[1].size() - 2) : (matrix_[1].size() - 1)) };

		matrix_[1][1] = 0;
		matrix_[1][2] = 0;
		matrix_[2][1] = 0;
		matrix_[y_end - 1][1] = 0;
		matrix_[y_end - 1][2] = 0;
		matrix_[y_end - 2][1] = 0;
		matrix_[1][x_end - 1] = 0;
		matrix_[1][x_end - 2] = 0;
		matrix_[2][x_end - 1] = 0;
		matrix_[y_end - 1][x_end - 1] = 0;
		matrix_[y_end - 1][x_end - 2] = 0;
		matrix_[y_end - 2][x_end - 1] = 0;
	}
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) const noexcept {

			using dtl::random::mersenne_twister_32bit;

			dtl::generator::common::stl::createPointGrid(matrix_, hard_value_);
			dtl::generator::common::stl::createBorderOdd(matrix_, hard_value_);
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					if (matrix_[row][col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = soft_value_;
			dtl::generator::common::stl::createPointGridFieldPlayerSpace(matrix_);
		}
	};

}
//Default版
namespace dtl::generator::common::normal {

	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 3 || x_ < 3) return;
		const std::size_t y_end{ ((y_ % 2 == 0) ? (y_ - 2) : (y_ - 1)) };
		const std::size_t x_end{ ((x_ % 2 == 0) ? (x_ - 2) : (x_ - 1)) };

		matrix_[1][1] = 0;
		matrix_[1][2] = 0;
		matrix_[2][1] = 0;
		matrix_[y_end - 1][1] = 0;
		matrix_[y_end - 1][2] = 0;
		matrix_[y_end - 2][1] = 0;
		matrix_[1][x_end - 1] = 0;
		matrix_[1][x_end - 2] = 0;
		matrix_[2][x_end - 1] = 0;
		matrix_[y_end - 1][x_end - 1] = 0;
		matrix_[y_end - 1][x_end - 2] = 0;
		matrix_[y_end - 2][x_end - 1] = 0;
	}
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) const noexcept {

			using dtl::random::mersenne_twister_32bit;

			dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, hard_value_);
			dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, hard_value_);
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					if (matrix_[row][col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col] = soft_value_;
			dtl::generator::common::normal::createPointGridFieldPlayerSpace(matrix_, x_, y_);
		}
	};

}

//Array版
namespace dtl::generator::common::array {

	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 3 || x_ < 3) return;
		const std::size_t y_end{ ((y_ % 2 == 0) ? (y_ - 2) : (y_ - 1)) };
		const std::size_t x_end{ ((x_ % 2 == 0) ? (x_ - 2) : (x_ - 1)) };

		matrix_[x_ + 1] = 0;
		matrix_[x_ + 2] = 0;
		matrix_[2 * x_ + 1] = 0;
		matrix_[(y_end - 1) * x_ + 1] = 0;
		matrix_[(y_end - 1) * x_ + 2] = 0;
		matrix_[(y_end - 2) * x_ + 1] = 0;
		matrix_[x_ + x_end - 1] = 0;
		matrix_[x_ + x_end - 2] = 0;
		matrix_[2 * x_ + x_end - 1] = 0;
		matrix_[(y_end - 1) * x_ + x_end - 1] = 0;
		matrix_[(y_end - 1) * x_ + x_end - 2] = 0;
		matrix_[(y_end - 2) * x_ + x_end - 1] = 0;
	}
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) const noexcept {

			using dtl::random::mersenne_twister_32bit;

			dtl::generator::common::array::createPointGrid(matrix_, x_, y_, hard_value_);
			dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, hard_value_);
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					if (matrix_[row * x_ + col] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row * x_ + col] = soft_value_;
			dtl::generator::common::array::createPointGridFieldPlayerSpace(matrix_, x_, y_);
		}
	};

}

//STL版
namespace dtl::generator::common::layer::stl {

	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() < 3 || matrix_[1].size() < 3) return;
		const std::size_t y_end{ ((matrix_.size() % 2 == 0) ? (matrix_.size() - 2) : (matrix_.size() - 1)) };
		const std::size_t x_end{ ((matrix_[1].size() % 2 == 0) ? (matrix_[1].size() - 2) : (matrix_[1].size() - 1)) };

		matrix_[1][1][layer_] = 0;
		matrix_[1][2][layer_] = 0;
		matrix_[2][1][layer_] = 0;
		matrix_[y_end - 1][1][layer_] = 0;
		matrix_[y_end - 1][2][layer_] = 0;
		matrix_[y_end - 2][1][layer_] = 0;
		matrix_[1][x_end - 1][layer_] = 0;
		matrix_[1][x_end - 2][layer_] = 0;
		matrix_[2][x_end - 1][layer_] = 0;
		matrix_[y_end - 1][x_end - 1][layer_] = 0;
		matrix_[y_end - 1][x_end - 2][layer_] = 0;
		matrix_[y_end - 2][x_end - 1][layer_] = 0;
	}
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t layer_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, layer_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) const noexcept {

			using dtl::random::mersenne_twister_32bit;

			dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, hard_value_);
			dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, hard_value_);
			for (std::size_t row{}; row < matrix_.size(); ++row)
				for (std::size_t col{}; col < matrix_[row].size(); ++col)
					if (matrix_[row][col][layer_] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col][layer_] = soft_value_;
			dtl::generator::common::layer::stl::createPointGridFieldPlayerSpace(matrix_, layer_);
		}
	};

}
//Default版
namespace dtl::generator::common::layer::normal {

	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 3 || x_ < 3) return;
		const std::size_t y_end{ ((y_ % 2 == 0) ? (y_ - 2) : (y_ - 1)) };
		const std::size_t x_end{ ((x_ % 2 == 0) ? (x_ - 2) : (x_ - 1)) };

		matrix_[1][1][layer_] = 0;
		matrix_[1][2][layer_] = 0;
		matrix_[2][1][layer_] = 0;
		matrix_[y_end - 1][1][layer_] = 0;
		matrix_[y_end - 1][2][layer_] = 0;
		matrix_[y_end - 2][1][layer_] = 0;
		matrix_[1][x_end - 1][layer_] = 0;
		matrix_[1][x_end - 2][layer_] = 0;
		matrix_[2][x_end - 1][layer_] = 0;
		matrix_[y_end - 1][x_end - 1][layer_] = 0;
		matrix_[y_end - 1][x_end - 2][layer_] = 0;
		matrix_[y_end - 2][x_end - 1][layer_] = 0;
	}
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, layer_, x_, y_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) const noexcept {

			using dtl::random::mersenne_twister_32bit;

			dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, hard_value_);
			dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, hard_value_);
			for (std::size_t row{}; row < y_; ++row)
				for (std::size_t col{}; col < x_; ++col)
					if (matrix_[row][col][layer_] == 0 && mersenne_twister_32bit.probability(probability_)) matrix_[row][col][layer_] = soft_value_;
			dtl::generator::common::layer::normal::createPointGridFieldPlayerSpace(matrix_, layer_, x_, y_);
		}
	};

}

#endif //Included Dungeon Template Library