#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DUNGEON_STANDARD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>
#include "DungeonRandom.hpp"

//Dungeon Template Library Namespace
namespace dtl {

	//----------   DungeonInit   ----------
	//1.全てのマスを0で埋める
	//2.全てのマスを指定した数値で埋める

	//STL版(1)
	template<typename Matrix_>
	constexpr void dungeonInit(Matrix_& matrix_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				matrix_[i][j] = 0;
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonInit(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				matrix_[i][j] = value_;
	}
	//Default版
	template<typename Matrix_>
	constexpr void dungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				matrix_[i][j] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				matrix_[i][j] = value_;
	}
	//Array版
	template<typename Matrix_>
	constexpr void dungeonInit_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				matrix_[i * x_ + j] = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonInit_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; ++i)
			for (std::size_t j{}; j < x_; ++j)
				matrix_[i * x_ + j] = value_;
	}
	//RangeBasedFor版
	template<typename Matrix_>
	constexpr void dungeonInit_RangeBasedFor(Matrix_& matrix_) noexcept {
		for (auto&& i : matrix_)
			for (auto&& j : i)
				j = 0;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void dungeonInit_RangeBasedFor(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (auto&& i : matrix_)
			for (auto&& j : i)
				j = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class DungeonInit {
	public:
		//コンストラクタ
		constexpr DungeonInit() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 0) noexcept {
			dungeonInit(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr explicit DungeonInit(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			dungeonInit(matrix_, x_, y_, value_);
		}
	};
	template<typename Matrix_Int_>
	class DungeonInit_Array {
	public:
		//コンストラクタ
		constexpr DungeonInit_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit DungeonInit_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 0) noexcept {
			dungeonInit_Array(matrix_, x_, y_, value_);
		}
	};



	//----------   PointGrid   ----------
	//1.偶数マスを1で埋める
	//2.偶数マスを指定した数値で埋める

	//Array版
	template<typename Matrix_>
	constexpr void createPointGrid_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				matrix_[i * x_ + j] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				matrix_[i * x_ + j] = value_;
	}

	//Default版
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				matrix_[i][j] = 1;
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < y_; i += 2)
			for (std::size_t j{}; j < x_; j += 2)
				matrix_[i][j] = value_;
	}

	//STL版(1)
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); i += 2)
			for (std::size_t j{}; j < matrix_[i].size(); j += 2)
				matrix_[i][j] = 1;
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t i{}; i < matrix_.size(); i += 2)
			for (std::size_t j{}; j < matrix_[i].size(); j += 2)
				matrix_[i][j] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid(matrix_, x_, y_, value_);
		}
	};
	template<typename Matrix_Int_>
	class PointGrid_Array {
	public:
		//コンストラクタ
		constexpr PointGrid_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid_Array(matrix_, x_, y_, value_);
		}
	};
	


	//----------   BorderOdd   ----------
	//1.マップの外枠を1で埋める(枠の内部を奇数マスにする)
	//2.マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)

	//Array版
	template<typename Matrix_>
	constexpr void createBorderOdd_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[i] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				matrix_[(y_ - 1) * x_ + i] = 1;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			matrix_[(y_ - 2) * x_ + i] = 1;
			matrix_[(y_ - 1) * x_ + i] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i*x_] = 1;
			if (x_ % 2 == 0) matrix_[i*x_ + x_ - 2] = 1;
			matrix_[i*x_ + x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[i] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				matrix_[(y_ - 1) * x_ + i] = value_;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			matrix_[(y_ - 2) * x_ + i] = value_;
			matrix_[(y_ - 1) * x_ + i] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i*x_] = value_;
			if (x_ % 2 == 0) matrix_[i*x_ + x_ - 2] = value_;
			matrix_[i*x_ + x_ - 1] = value_;
		}
	}

	//Default版
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[0][i] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				matrix_[y_ - 1][i] = 1;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			matrix_[y_ - 2][i] = 1;
			matrix_[y_ - 1][i] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i][0] = 1;
			if (x_ % 2 == 0) matrix_[i][x_ - 2] = 1;
			matrix_[i][x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[0][i] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t i{}; i < x_; ++i)
				matrix_[y_ - 1][i] = value_;
		}
		else for (std::size_t i{}; i < x_; ++i) {
			matrix_[y_ - 2][i] = value_;
			matrix_[y_ - 1][i] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i][0] = value_;
			if (x_ % 2 == 0) matrix_[i][x_ - 2] = value_;
			matrix_[i][x_ - 1] = value_;
		}
	}

	//STL版(1)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t i{}; i < matrix_[0].size(); ++i)
			matrix_[0][i] = 1;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i)
				matrix_[matrix_.size() - 1][i] = 1;
		}
		else for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i) {
			matrix_[matrix_.size() - 2][i] = 1;
			matrix_[matrix_.size() - 1][i] = 1;
		}
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			if (matrix_[i].size() < 2) continue;
			matrix_[i][0] = 1;
			if (matrix_[i].size() % 2 == 0) matrix_[i][matrix_[i].size() - 2] = 1;
			matrix_[i][matrix_[i].size() - 1] = 1;
		}
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t i{}; i < matrix_[0].size(); ++i)
			matrix_[0][i] = value_;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i)
				matrix_[matrix_.size() - 1][i] = value_;
		}
		else for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i) {
			matrix_[matrix_.size() - 2][i] = value_;
			matrix_[matrix_.size() - 1][i] = value_;
		}
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			if (matrix_[i].size() < 2) continue;
			matrix_[i][0] = value_;
			if (matrix_[i].size() % 2 == 0) matrix_[i][matrix_[i].size() - 2] = value_;
			matrix_[i][matrix_[i].size() - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createBorderOdd(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createBorderOdd(matrix_, x_, y_, value_);
		}
	};
	template<typename Matrix_Int_>
	class BorderOdd_Array {
	public:
		//コンストラクタ
		constexpr BorderOdd_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createBorderOdd_Array(matrix_, x_, y_, value_);
		}
	};



	//----------   PointGridField   ----------
	//PointGrid + BorderOdd

	//Array版
	template<typename Matrix_>
	constexpr void createPointGridField_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		createPointGrid_Array(matrix_, x_, y_);
		createBorderOdd_Array(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		createPointGrid_Array(matrix_, x_, y_, value_);
		createBorderOdd_Array(matrix_, x_, y_, value_);
	}

	//Default版
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		createPointGrid(matrix_, x_, y_);
		createBorderOdd(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		createPointGrid(matrix_, x_, y_, value_);
		createBorderOdd(matrix_, x_, y_, value_);
	}

	//STL版(1)
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_) noexcept {
		createPointGrid(matrix_);
		createBorderOdd(matrix_);
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		createPointGrid(matrix_, value_);
		createBorderOdd(matrix_, value_);
	}

	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid(matrix_, value_);
			createBorderOdd(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid(matrix_, x_, y_, value_);
			createBorderOdd(matrix_, x_, y_, value_);
		}
	};
	template<typename Matrix_Int_>
	class PointGridField_Array {
	public:
		//コンストラクタ
		constexpr PointGridField_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid_Array(matrix_, x_, y_, value_);
			createBorderOdd_Array(matrix_, x_, y_, value_);
		}
	};



	//----------   PointGridFieldPutBlock   ----------
	//PointGrid + BorderOdd + 枠の内部の空マスを指定した確率で埋める

	//STL版
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

	//Default版
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

	//Array版
	template<typename Matrix_>
	constexpr void createPointGridFieldPlayerSpace_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
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
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			createPointGrid(matrix_, hard_value_);
			createBorderOdd(matrix_, hard_value_);
			for (std::size_t i{}; i < matrix_.size(); ++i)
				for (std::size_t j{}; j < matrix_[i].size(); ++j)
					if (matrix_[i][j] == 0 && rnd.randBool(probability_)) matrix_[i][j] = soft_value_;
			createPointGridFieldPlayerSpace(matrix_);
		}

		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			createPointGrid(matrix_, x_, y_, hard_value_);
			createBorderOdd(matrix_, x_, y_, hard_value_);
			for (std::size_t i{}; i < y_; ++i)
				for (std::size_t j{}; j < x_; ++j)
					if (matrix_[i][j] == 0 && rnd.randBool(probability_)) matrix_[i][j] = soft_value_;
			createPointGridFieldPlayerSpace(matrix_, x_, y_);
		}
	};
	template<typename Matrix_Int_>
	class PointGridFieldPutBlock_Array {
	public:
		//コンストラクタ
		constexpr PointGridFieldPutBlock_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridFieldPutBlock_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			create(matrix_, x_, y_, probability_, hard_value_, soft_value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const double probability_ = 0.8, const Matrix_Int_ hard_value_ = 1, const Matrix_Int_ soft_value_ = 2) noexcept {
			createPointGrid_Array(matrix_, x_, y_, hard_value_);
			createBorderOdd_Array(matrix_, x_, y_, hard_value_);
			for (std::size_t i{}; i < y_; ++i)
				for (std::size_t j{}; j < x_; ++j)
					if (matrix_[i * x_ + j] == 0 && rnd.randBool(probability_)) matrix_[i * x_ + j] = soft_value_;
			createPointGridFieldPlayerSpace_Array(matrix_, x_, y_);
		}
	};



	//----------   Border   ----------
	//1.マップの外枠を1で埋める
	//2.マップの外枠を指定した数値で埋める

	//STL版(1)
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t i{}; i < matrix_[0].size(); ++i)
			matrix_[0][i] = 1;
		for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i)
			matrix_[matrix_.size() - 1][i] = 1;
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			if (matrix_[i].size() == 0) continue;
			matrix_[i][0] = 1;
			matrix_[i][matrix_[i].size() - 1] = 1;
		}
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t i{}; i < matrix_[0].size(); ++i)
			matrix_[0][i] = value_;
		for (std::size_t i{}; i < matrix_[matrix_.size() - 1].size(); ++i)
			matrix_[matrix_.size() - 1][i] = value_;
		for (std::size_t i{}; i < matrix_.size(); ++i) {
			if (matrix_[i].size() == 0) continue;
			matrix_[i][0] = value_;
			matrix_[i][matrix_[i].size() - 1] = value_;
		}
	}
	//Default版
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[0][i] = 1;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[y_ - 1][i] = 1;
		if (x_ == 0) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i][0] = 1;
			matrix_[i][x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[0][i] = value_;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[y_ - 1][i] = value_;
		if (x_ == 0) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i][0] = value_;
			matrix_[i][x_ - 1] = value_;
		}
	}
	//Array版
	template<typename Matrix_>
	constexpr void createBorder_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[i] = 1;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[(y_ - 1) * x_ + i] = 1;
		if (x_ == 0) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i * x_] = 1;
			matrix_[i * x_ + x_ - 1] = 1;
		}
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[i] = value_;
		for (std::size_t i{}; i < x_; ++i)
			matrix_[(y_ - 1) * x_ + i] = value_;
		if (x_ == 0) return;
		for (std::size_t i{}; i < y_; ++i) {
			matrix_[i * x_] = value_;
			matrix_[i * x_ + x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			createBorder(matrix_, value_);
		}
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createBorder(matrix_, x_, y_, value_);
		}
	};
	template<typename Matrix_Int_>
	class Border_Array {
	public:
		//コンストラクタ
		constexpr Border_Array() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border_Array(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createBorder_Array(matrix_, x_, y_, value_);
		}
	};



	//----------*----------*----------*----------*----------*
	//初期化系
	//----------*----------*----------*----------*----------*

	template<typename Matrix_>
	constexpr bool dungeonArrayCheckBitset(const Matrix_& matrix_) noexcept {
		if (matrix_.size() < 1 || matrix_[0].size() < 1) return false;
		const auto& stl_value{ matrix_[0][0] };
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				if (stl_value != matrix_[i][j]) return false;
		return true;
	}

	//値が全て一致しているか確認する
	template<typename Matrix_>
	constexpr bool dungeonArrayCheck(const Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0 || matrix_.front().size() == 0) return false;
		const auto& stl_value{ matrix_.front().front() };
		for (std::size_t i{}; i < matrix_.size(); ++i)
			for (std::size_t j{}; j < matrix_[i].size(); ++j)
				if (stl_value != matrix_[i][j]) return false;
		return true;
	}

	template<typename Matrix_>
	constexpr bool dungeonArrayCheck_RangeBasedFor(const Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0 || matrix_.front().size() == 0) return false;
		const auto& stl_value{ matrix_.front().front() };
		for (const auto& i : matrix_)
			for (const auto& j : i)
				if (stl_value != j) return false;
		return true;
	}

}

#endif //Included Dungeon Template Library