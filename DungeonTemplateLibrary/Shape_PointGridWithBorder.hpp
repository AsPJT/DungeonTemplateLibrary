/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_WITH_BORDER
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_POINT_GRID_WITH_BORDER

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include "Shape_PointGrid.hpp"
#include "Shape_BorderOdd.hpp"
#include "Base_Struct.hpp"

namespace dtl::shape {

	//マップの外枠を指定した数値で埋め、偶数マスを指定した数値で埋める
	template<typename Matrix_Int_>
	class PointGridWithBorder {
	private:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;
		using PairMatrixInt = std::pair<Matrix_Int_, Matrix_Int_>;


		///// メンバ変数 /////

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
			pointGrid.draw(matrix_, std::forward<Args_>(args_)...);
			borderOdd.draw(matrix_, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			pointGrid.drawOperator(matrix_, std::forward<Args_>(args_)...);
			borderOdd.drawOperator(matrix_, std::forward<Args_>(args_)...);
			return true;
		}

		//Array
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			pointGrid.drawArray(matrix_, std::forward<Args_>(args_)...);
			borderOdd.drawArray(matrix_, std::forward<Args_>(args_)...);
			return true;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr bool drawOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			pointGrid.drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			borderOdd.drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return true;
		}


		///// ダンジョン行列生成 /////

		template<typename Matrix_, typename ...Args_>
		constexpr auto create(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->draw(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperator(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperator(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}
		template<typename Matrix_, typename ...Args_>
		constexpr auto createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const noexcept {
			this->drawOperatorArray(matrix_, std::forward<Args_>(args_)...);
			return matrix_;
		}


		///// コンストラクタ /////

		constexpr PointGridWithBorder() noexcept = default;
		constexpr explicit PointGridWithBorder(const Matrix_Int_& draw_value_) noexcept
			:borderOdd(draw_value_), pointGrid(draw_value_) {}
		constexpr explicit PointGridWithBorder(const PairMatrixInt& pair_value_) noexcept
			:borderOdd(pair_value_.second), pointGrid(pair_value_.first) {}
		constexpr explicit PointGridWithBorder(const PairSize& length_) noexcept
			:borderOdd(length_), pointGrid(length_) {}
		constexpr explicit PointGridWithBorder(const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(length_, draw_value_), pointGrid(length_, draw_value_) {}
		constexpr explicit PointGridWithBorder(const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(length_, pair_value_.second), pointGrid(length_, pair_value_.first) {}
		constexpr explicit PointGridWithBorder(const PairSize& position_, const PairSize& length_) noexcept
			:borderOdd(position_, length_), pointGrid(position_, length_) {}
		constexpr explicit PointGridWithBorder(const PairSize& position_, const PairSize& length_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(position_, length_, draw_value_), pointGrid(position_, length_, draw_value_) {}
		constexpr explicit PointGridWithBorder(const PairSize& position_, const PairSize& length_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(position_, length_, pair_value_.second), pointGrid(position_, length_, pair_value_.first) {}
		constexpr explicit PointGridWithBorder(const Matrix_Int_& draw_value_, const Matrix_Int_& draw_value2_) noexcept
			:borderOdd(draw_value2_), pointGrid(draw_value_) {}
		constexpr explicit PointGridWithBorder(const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(width_, height_, draw_value_), pointGrid(width_, height_, draw_value_) {}
		constexpr explicit PointGridWithBorder(const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(width_, height_, pair_value_.second), pointGrid(width_, height_, pair_value_.first) {}
		constexpr explicit PointGridWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_), pointGrid(point_x_, point_y_, width_, height_) {}
		constexpr explicit PointGridWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_, draw_value_), pointGrid(point_x_, point_y_, width_, height_, draw_value_) {}
		constexpr explicit PointGridWithBorder(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const PairMatrixInt& pair_value_) noexcept
			:borderOdd(point_x_, point_y_, width_, height_, pair_value_.second), pointGrid(point_x_, point_y_, width_, height_, pair_value_.first) {}

		//template<typename ...Args_>
		//constexpr explicit PointGridWithBorder(Args_&&... args_) noexcept
		//	:borderOdd(std::forward<Args_>(args_)...), pointGrid(std::forward<Args_>(args_)...) {}
	};
}





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
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_) noexcept {
		dtl::generator::common::stl::createPointGrid(matrix_);
		dtl::generator::common::stl::createBorderOdd(matrix_);
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::stl::createPointGrid(matrix_, value_);
		dtl::generator::common::stl::createBorderOdd(matrix_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void create(Matrix_& matrix_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::stl::createPointGrid(matrix_, value_);
			dtl::generator::common::stl::createBorderOdd(matrix_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::normal {

	//Default版
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::normal::createPointGrid(matrix_, x_, y_);
		dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
		dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::normal::createPointGrid(matrix_, x_, y_, value_);
			dtl::generator::common::normal::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::array {

	//Array版
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::array::createPointGrid(matrix_, x_, y_);
		dtl::generator::common::array::createBorderOdd(matrix_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
		dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
	}
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void create(Matrix_& matrix_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::array::createPointGrid(matrix_, x_, y_, value_);
			dtl::generator::common::array::createBorderOdd(matrix_, x_, y_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::layer::stl {

	//STL版(1)
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_) noexcept {
		dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_);
		dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_);
	}
	//STL版(2)
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
		dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::stl::createPointGrid(matrix_, layer_, value_);
			dtl::generator::common::layer::stl::createBorderOdd(matrix_, layer_, value_);
		}
	};

} //namespace


namespace dtl::generator::common::layer::normal {

	//Default版
	template<typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_) noexcept {
		dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_);
		dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_);
	}
	template<typename Matrix_Int_, typename Matrix_>
	[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void createPointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_) noexcept {
		dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
		dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
	}
	//クラス版
	template<typename Matrix_Int_>
	class PointGridField {
	public:
		//コンストラクタ
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr PointGridField() noexcept = default;
		template<typename Matrix_>
		constexpr explicit PointGridField(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) noexcept {
			create(matrix_, layer_, x_, y_, value_);
		}
		template<typename Matrix_>
		[[deprecated("please use dtl::shape::PointGridWithBorder class")]] constexpr void create(Matrix_& matrix_, const std::size_t layer_, const std::size_t x_, const std::size_t y_, const Matrix_Int_ value_ = 1) const noexcept {
			dtl::generator::common::layer::normal::createPointGrid(matrix_, layer_, x_, y_, value_);
			dtl::generator::common::layer::normal::createBorderOdd(matrix_, layer_, x_, y_, value_);
		}
	};

} //namespace

#endif //Included Dungeon Template Library