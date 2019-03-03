#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_BORDER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_BORDER
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

#include <cstddef>

//総合データ
namespace dtl::generator::common::data {

	enum eBorder {
		border_empty_id,
		border_wall_id,
		border_enum_num
	};
	constexpr bool border_bool{ (border_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//マップの外枠を1で埋める
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = 1;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col] = 1;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0] = 1;
			matrix_[row][matrix_[row].size() - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col] = value_;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col] = value_;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0] = value_;
			matrix_[row][matrix_[row].size() - 1] = value_;
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
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::stl::createBorder(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//マップの外枠を1で埋める
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = 1;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col] = 1;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = 1;
			matrix_[row][x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col] = value_;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col] = value_;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0] = value_;
			matrix_[row][x_ - 1] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::normal::createBorder(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {
	//マップの外枠を1で埋める
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = 1;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[(y_ - 1) * x_ + col] = 1;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row * x_] = 1;
			matrix_[row * x_ + x_ - 1] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[col] = value_;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[(y_ - 1) * x_ + col] = value_;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row * x_] = value_;
			matrix_[row * x_ + x_ - 1] = value_;
		}
	}
	template<typename Matrix_Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::array::createBorder(matrix_, x_, y_, value_);
		}
	};

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//マップの外枠を1で埋める
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, std::size_t layer_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = 1;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col][layer_] = 1;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0][layer_] = 1;
			matrix_[row][matrix_[row].size() - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
		if (matrix_.size() == 0) return;
		for (std::size_t col{}; col < matrix_[0].size(); ++col)
			matrix_[0][col][layer_] = value_;
		for (std::size_t col{}; col < matrix_[matrix_.size() - 1].size(); ++col)
			matrix_[matrix_.size() - 1][col][layer_] = value_;
		for (std::size_t row{}; row < matrix_.size(); ++row) {
			if (matrix_[row].size() == 0) continue;
			matrix_[row][0][layer_] = value_;
			matrix_[row][matrix_[row].size() - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::stl::createBorder(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {
	//マップの外枠を1で埋める
	template<typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = 1;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col][layer_] = 1;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = 1;
			matrix_[row][x_ - 1][layer_] = 1;
		}
	}
	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createBorder(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		if (y_ == 0) return;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[0][col][layer_] = value_;
		for (std::size_t col{}; col < x_; ++col)
			matrix_[y_ - 1][col][layer_] = value_;
		if (x_ == 0) return;
		for (std::size_t row{}; row < y_; ++row) {
			matrix_[row][0][layer_] = value_;
			matrix_[row][x_ - 1][layer_] = value_;
		}
	}
	//クラス版
	template<typename Matrix_Int_>
	class Border {
	public:
		//コンストラクタ
		constexpr Border() noexcept = default;
		template<typename Matrix_>
		constexpr explicit Border(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::normal::createBorder(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library