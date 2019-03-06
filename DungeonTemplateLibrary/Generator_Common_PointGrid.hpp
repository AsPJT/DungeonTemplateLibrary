#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : not checked */

#include <cstddef>

//総合データ
namespace dtl::generator::common::data {

	enum ePointGrid {
		point_grid_empty_id,
		point_grid_wall_id,
		point_grid_enum_num
	};
	constexpr bool point_grid_bool{ (point_grid_enum_num <= 2) ? true : false };

} //namespace

//STLデータ
namespace dtl::generator::common::stl {

	//偶数マスを1で埋める
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); row += 2)
			for (std::size_t col{}; col < matrix_[row].size(); col += 2)
				matrix_[row][col] = 1;
	}
	//偶数マスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); row += 2)
			for (std::size_t col{}; col < matrix_[row].size(); col += 2)
				matrix_[row][col] = value_;
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
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			createPointGrid(matrix_, value_);
		}
	};

} //namespace

//通常データ
namespace dtl::generator::common::normal {

	//偶数マスを1で埋める
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row][col] = 1;
	}
	//偶数マスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row][col] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createPointGrid(matrix_, x_, y_, value_);
		}
	};

} //namespace

//配列データ
namespace dtl::generator::common::array {

	//偶数マスを1で埋める
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row * x_ + col] = 1;
	}
	//偶数マスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row * x_ + col] = value_;
	}
	template<typename Matrix_Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			createPointGrid(matrix_, x_, y_, value_);
		}
	};

} //namespace

//レイヤーSTLデータ
namespace dtl::generator::common::layer::stl {

	//偶数マスを1で埋める
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); row += 2)
			for (std::size_t col{}; col < matrix_[row].size(); col += 2)
				matrix_[row][col][layer_] = 1;
	}
	//偶数マスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < matrix_.size(); row += 2)
			for (std::size_t col{}; col < matrix_[row].size(); col += 2)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			createPointGrid(matrix_, layer_, value_);
		}
	};

} //namespace

//レイヤー通常データ
namespace dtl::generator::common::layer::normal {

	//偶数マスを1で埋める
	template<typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row][col][layer_] = 1;
	}
	//偶数マスを指定した数値で埋める
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		for (std::size_t row{}; row < y_; row += 2)
			for (std::size_t col{}; col < x_; col += 2)
				matrix_[row][col][layer_] = value_;
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGrid {
	public:
		//コンストラクタ
		constexpr PointGrid() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGrid(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			createPointGrid(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library