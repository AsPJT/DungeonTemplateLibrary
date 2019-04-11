/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BASE_SHAPE
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_SHAPE_BASE_SHAPE

/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <Base/Struct.hpp>

namespace dtl::shape {

	//マップの外枠を指定した数値で埋める
	template<typename Matrix_Int_>
	class BaseShape {
//	protected:
	public:


		///// エイリアス /////

		using Index_Size = std::size_t;
		using PairSize = std::pair<Index_Size, Index_Size>;


		///// メンバ変数 /////

		Index_Size point_x{};
		Index_Size point_y{};
		Index_Size width{};
		Index_Size height{};
		Matrix_Int_ draw_value{};

	public:


		///// 情報取得 /////

		[[nodiscard]] constexpr Index_Size getPointX() const noexcept {
			return this->point_x;
		}
		[[nodiscard]] constexpr Index_Size getPointY() const noexcept {
			return this->point_y;
		}
		[[nodiscard]] constexpr Index_Size getWidth() const noexcept {
			return this->width;
		}
		[[nodiscard]] constexpr Index_Size getHeight() const noexcept {
			return this->height;
		}
		[[nodiscard]] constexpr Matrix_Int_ getValue() const noexcept {
			return this->draw_value;
		}


		///// セット /////

		constexpr auto setPointX(const Index_Size& point_x_) noexcept {
			point_x = point_x_;
			return *this;
		}
		constexpr auto setPointY() noexcept {
			return this->point_y;
			return *this;
		}
		constexpr auto setWidth() noexcept {
			return this->width;
			return *this;
		}
		constexpr auto setHeight() noexcept {
			return this->height;
			return *this;
		}
		constexpr auto setValue() noexcept {
			return this->draw_value;
			return *this;
		}
		constexpr auto setRange(const dtl::base::MatrixRange& matrix_range_) noexcept {
			this->point_x = matrix_range_.x;
			this->point_y = matrix_range_.y;
			this->width = matrix_range_.w;
			this->height = matrix_range_.h;
			return *this;
		}


		///// コンストラクタ /////

		constexpr BaseShape() noexcept = default;
		constexpr explicit BaseShape(const Matrix_Int_& draw_value_) noexcept
			:draw_value(draw_value_) {}
		constexpr explicit BaseShape(const dtl::base::MatrixRange& matrix_range_) noexcept
			:point_x(matrix_range_.x), point_y(matrix_range_.y),
			width(matrix_range_.w), height(matrix_range_.h) {}
		constexpr explicit BaseShape(const dtl::base::MatrixRange& matrix_range_, const Matrix_Int_& draw_value_) noexcept
			:point_x(matrix_range_.x), point_y(matrix_range_.y),
			width(matrix_range_.w), height(matrix_range_.h),
			draw_value(draw_value_) {}
		constexpr explicit BaseShape(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_) {}
		constexpr explicit BaseShape(const Index_Size point_x_, const Index_Size point_y_, const Index_Size width_, const Index_Size height_, const Matrix_Int_& draw_value_) noexcept
			:point_x(point_x_), point_y(point_y_),
			width(width_), height(height_),
			draw_value(draw_value_) {}
	};

} //namespace

#endif //Included Dungeon Template Library