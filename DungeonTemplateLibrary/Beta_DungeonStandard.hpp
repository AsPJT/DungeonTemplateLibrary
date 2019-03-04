#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "Random_MersenneTwister32bit.hpp"
#include "Beta_DungeonMatrix.hpp"
#include "Generator_Common_PointGrid.hpp"
#include "Generator_Common_BorderOdd.hpp"

namespace dtl::generator::common {

	//----------   PointGridFieldPutBlock   ----------
	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める

	namespace data {

		enum ePointGridFieldPutBlock {
			point_grid_field_put_block_empty_id,
			point_grid_field_put_block_wall_id,
			point_grid_field_put_block_block_id,
			point_grid_field_put_block_enum_num
		};
		constexpr bool point_grid_field_put_block_bool{ (point_grid_field_put_block_enum_num <= 2) ? true : false };

	}

	//STL版
	namespace stl {
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
	namespace normal {
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
	namespace array {
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


	//----------   Line   ----------
	//beta

	namespace stl {

		//STL版(1)
		template<typename Matrix_>
		constexpr void createLineDown(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[0].size(); ++col)
				matrix_[0][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createLineUp(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createLineLeft(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][0] = 1;
			}
		}
		template<typename Matrix_>
		constexpr void createLineRight(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][matrix_[row].size() - 1] = 1;
			}
		}

		//----------   OneLine   ----------

		//STL版(1)
		template<typename Matrix_>
		constexpr void createOneLineDown(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[0].size(); ++col)
				matrix_[0][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineUp(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineLeft(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][0] = 1;
			}
		}
		template<typename Matrix_>
		constexpr void createOneLineRight(Matrix_& matrix_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][matrix_[row].size() - 1] = 1;
			}
		}
		//STL版(2)
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineDown(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[0].size(); ++col)
				matrix_[0][col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineUp(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][0] = value_;
			}
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineRight(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
			if (matrix_.size() == 0) return;
			for (std::size_t row{}; row < matrix_.size(); ++row) {
				if (matrix_[row].size() == 0) continue;
				matrix_[row][matrix_[row].size() - 1] = value_;
			}
		}
		//Default版
		template<typename Matrix_>
		constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[0][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row][0] = 1;
			}
		}
		template<typename Matrix_>
		constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row][x_ - 1] = 1;
			}
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[0][col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row][0] = value_;
			}
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row][x_ - 1] = value_;
			}
		}
		//Array版
		template<typename Matrix_>
		constexpr void createOneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[(y_ - 1)*x_ + col] = 1;
		}
		template<typename Matrix_>
		constexpr void createOneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row*x_] = 1;
			}
		}
		template<typename Matrix_>
		constexpr void createOneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row*x_ + x_ - 1] = 1;
			}
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (y_ == 0) return;
			for (std::size_t col{}; col < x_; ++col)
				matrix_[(y_ - 1)*x_ + col] = value_;
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row*x_] = value_;
			}
		}
		template<typename Matrix_Int_, typename Matrix_>
		constexpr void createOneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
			if (dtl::utility::isEmpty(x_, y_)) return;
			for (std::size_t row{}; row < y_; ++row) {
				matrix_[row*x_ + x_ - 1] = value_;
			}
		}
		//クラス版
		template<typename Matrix_Int_>
		class OneLineUp {
		public:
			//コンストラクタ
			constexpr OneLineUp() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineUp(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				createOneLineUp(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr explicit OneLineUp(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineUp(matrix_, x_, y_, value_);
			}
		};
		template<typename Matrix_Int_>
		class OneLineUp_Array {
		public:
			//コンストラクタ
			constexpr OneLineUp_Array() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineUp_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineUp_Array(matrix_, x_, y_, value_);
			}
		};
		//クラス版
		template<typename Matrix_Int_>
		class OneLineDown {
		public:
			//コンストラクタ
			constexpr OneLineDown() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineDown(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				createOneLineDown(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr explicit OneLineDown(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineDown(matrix_, x_, y_, value_);
			}
		};
		template<typename Matrix_Int_>
		class OneLineDown_Array {
		public:
			//コンストラクタ
			constexpr OneLineDown_Array() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineDown_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineDown_Array(matrix_, x_, y_, value_);
			}
		};
		//クラス版
		template<typename Matrix_Int_>
		class OneLineLeft {
		public:
			//コンストラクタ
			constexpr OneLineLeft() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineLeft(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				createOneLineLeft(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr explicit OneLineLeft(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineLeft(matrix_, x_, y_, value_);
			}
		};
		template<typename Matrix_Int_>
		class OneLineLeft_Array {
		public:
			//コンストラクタ
			constexpr OneLineLeft_Array() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineLeft_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineLeft_Array(matrix_, x_, y_, value_);
			}
		};
		//クラス版
		template<typename Matrix_Int_>
		class OneLineRight {
		public:
			//コンストラクタ
			constexpr OneLineRight() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineRight(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
				createOneLineRight(matrix_, value_);
			}
			template<typename Matrix_>
			constexpr explicit OneLineRight(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineRight(matrix_, x_, y_, value_);
			}
		};
		template<typename Matrix_Int_>
		class OneLineRight_Array {
		public:
			//コンストラクタ
			constexpr OneLineRight_Array() noexcept = default;
			template<typename Matrix_>
			constexpr explicit OneLineRight_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
				create(matrix_, x_, y_, value_);
			}
			template<typename Matrix_>
			constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
				createOneLineRight_Array(matrix_, x_, y_, value_);
			}
		};

	}

}

#endif //Included Dungeon Template Library