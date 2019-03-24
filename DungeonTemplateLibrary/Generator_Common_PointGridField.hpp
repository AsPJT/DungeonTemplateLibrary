#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID_FIELD
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_GENERATOR_COMMON_POINT_GRID_FIELD
//:::::----------::::::::::----------::::://
//     Dungeon Template Library     //
//          Made by Gaccho.          //
// This code is licensed under CC0.  //
//       wanotaitei@gmail.com       //
//:::::----------::::::::::----------::::://

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include "Shape_PointGrid.hpp"
#include "Generator_Common_BorderOdd.hpp"

namespace dtl::generator::common::data {

	enum ePointGridField {
		point_grid_field_empty_id,
		point_grid_field_wall_id,
		point_grid_field_enum_num
	};
	constexpr bool point_grid_field_bool{ (point_grid_field_enum_num <= 2) ? true : false };

} //namespace


namespace dtl::generator::common::stl {

	//STL版(1)
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_) noexcept {
		dtl::generator::common::stl::createPointGrid(matrix_);
		dtl::generator::common::stl::createBorderOdd(matrix_);
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::stl::createPointGrid(matrix_, value_);
		dtl::generator::common::stl::createBorderOdd(matrix_, value_);
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
		constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::stl::createPointGrid(matrix_, value_);
			dtl::generator::common::stl::createBorderOdd(matrix_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::normal {

	//Default版
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::normal::createPointGrid(matrix_, x_, y_);
		dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
		dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
			dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::array {

	//Array版
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::array::createPointGrid(matrix_, x_, y_);
		dtl::generator::common::array::createBorderOdd(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
		dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
	}
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
			dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::layer::stl {

	//STL版(1)
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_) noexcept {
		dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_);
		dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_);
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
		dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
			dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::layer::normal {

	//Default版
	template<typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_);
		dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
		dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
			dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library