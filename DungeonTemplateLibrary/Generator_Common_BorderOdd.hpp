#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_BORDER_ODD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_BORDER_ODD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */

#include <cstddef>

//総合データ
namespace dtl::generator::common::data {

	enum eBorderOdd {
		border_odd_empty_id,
		border_odd_wall_id,
		border_odd_enum_num
	};
	constexpr bool border_odd_bool{ (border_odd_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = 1;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = 1;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col] = 1;
			matrix_[matrix_.size() - 1][col] = 1;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0] = 1;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = 1;
			matrix_[row][matrix_[row].size() - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = value_;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col] = value_;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col] = value_;
			matrix_[matrix_.size() - 1][col] = value_;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0] = value_;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2] = value_;
			matrix_[row][matrix_[row].size() - 1] = value_;
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
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::stl::createBorderOdd(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = 1;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col] = 1;
			matrix_[y_ - 1][col] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = 1;
			if (x_ % 2 == 0) matrix_[row][x_ - 2] = 1;
			matrix_[row][x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col] = value_;
			matrix_[y_ - 1][col] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = value_;
			if (x_ % 2 == 0) matrix_[row][x_ - 2] = value_;
			matrix_[row][x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t row{}; row < x_; ++row)
			matrix_[row] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t row{}; row < x_; ++row)
				matrix_[(y_ - 1) * x_ + row] = 1;
		}
		else for (std::size_t row{}; row < x_; ++row) {
			matrix_[(y_ - 2) * x_ + row] = 1;
			matrix_[(y_ - 1) * x_ + row] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = 1;
			if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = 1;
			matrix_[row*x_ + x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[(y_ - 1) * x_ + col] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[(y_ - 2) * x_ + col] = value_;
			matrix_[(y_ - 1) * x_ + col] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row*x_] = value_;
			if (x_ % 2 == 0) matrix_[row*x_ + x_ - 2] = value_;
			matrix_[row*x_ + x_ - 1] = value_;
		}
	}
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = 1;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col][layer_] = 1;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col][layer_] = 1;
			matrix_[matrix_.size() - 1][col][layer_] = 1;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0][layer_] = 1;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = 1;
			matrix_[row][matrix_[row].size() - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() < 2) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = value_;
		if (matrix_.size() % 2 == 1) {
			for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
				matrix_[matrix_.size() - 1][col][layer_] = value_;
		}
		else for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col) {
			matrix_[matrix_.size() - 2][col][layer_] = value_;
			matrix_[matrix_.size() - 1][col][layer_] = value_;
		}
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() < 2) continue;
			matrix_[row][0][layer_] = value_;
			if (matrix_[row].size() % 2 == 0) matrix_[row][matrix_[row].size() - 2][layer_] = value_;
			matrix_[row][matrix_[row].size() - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {

	//マップの外枠を1で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = 1;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col][layer_] = 1;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col][layer_] = 1;
			matrix_[y_ - 1][col][layer_] = 1;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = 1;
			if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = 1;
			matrix_[row][x_ - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める(枠の内部を奇数マスにする)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ < 2) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = value_;
		if (y_ % 2 == 1) {
			for (std::size_t col{}; col < x_; ++col)
				matrix_[y_ - 1][col][layer_] = value_;
		}
		else for (std::size_t col{}; col < x_; ++col) {
			matrix_[y_ - 2][col][layer_] = value_;
			matrix_[y_ - 1][col][layer_] = value_;
		}
		if (x_ < 2) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = value_;
			if (x_ % 2 == 0) matrix_[row][x_ - 2][layer_] = value_;
			matrix_[row][x_ - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class BorderOdd {
	public:
		//コンストラクタ
		constexpr BorderOdd() noexcept = default;
		template<typename Matrix_>
		constexpr explicit BorderOdd(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library