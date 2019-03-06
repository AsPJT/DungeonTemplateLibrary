#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID_FIELD_PUT_BLOCK
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID_FIELD_PUT_BLOCK
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */

#include <cstddef>
#include "Generator_Common_PointGrid.hpp"
#include "Generator_Common_BorderOdd.hpp"
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