/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CAMERA_MATRIX_VIEW_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_CAMERA_MATRIX_VIEW_HPP

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/IntX.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace camera { //"dtl::camera"名前空間に属する

		struct MatrixViewRect {
			MatrixViewRect() = default;
			::dtl::type::int_fast32 start_x{};
			::dtl::type::int_fast32 start_y{};
			::dtl::type::int_fast32 end_x{};
			::dtl::type::int_fast32 end_y{};
		};

		class SampleMatrixViewDraw {
		public:
			SampleMatrixViewDraw() = default;
			template<typename Matrix_> //maybe_unused
			DTL_VERSIONING_CPP14_CONSTEXPR
				void draw(const Matrix_&, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32, const ::dtl::type::int_fast32) const noexcept {}
		};

		class MatrixView {
		private:
			//画面の幅・高さ
			::dtl::type::int_fast32 window_width{};
			::dtl::type::int_fast32 window_height{};
			//画面の始点座標
			::dtl::type::int_fast32 window_start_x{};
			::dtl::type::int_fast32 window_start_y{};
			//画面の終点座標
			::dtl::type::int_fast32 window_end_x{};
			::dtl::type::int_fast32 window_end_y{};
			//画面の中心座標
			::dtl::type::int_fast32 window_center_x{};
			::dtl::type::int_fast32 window_center_y{};
			//1マスのピクセル数
			::dtl::type::int_fast32 pixel_width{};
			::dtl::type::int_fast32 pixel_height{};
			//画面内のマスの数
			double cell_width{};
			double cell_height{};
			//視点座標
			double target_x{};
			double target_y{};
		public:

			DTL_VERSIONING_CPP14_CONSTEXPR
				void setTarget(const double target_x_, const double target_y_) noexcept {
				this->target_x = target_x_;
				this->target_y = target_y_;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				void checkTarget(const double x_, const double y_) noexcept {
				while (this->target_x < 0) this->target_x += x_;
				while (this->target_y < 0) this->target_y += x_;
				while (this->target_x >= x_) this->target_x -= x_;
				while (this->target_y >= y_) this->target_y -= y_;
			}
			DTL_VERSIONING_CPP14_CONSTEXPR
				void checkTarget(double& target_x_, double& target_y_, const double x_, const double y_) const noexcept {
				while (target_x_ < 0) target_x_ += x_;
				while (target_y_ < 0) target_y_ += x_;
				while (target_x_ >= x_) target_x_ -= x_;
				while (target_y_ >= y_) target_y_ -= y_;
			}

			//コンストラクタ
			MatrixView() = default;
			constexpr MatrixView(const ::dtl::type::int_fast32 window_width_, const ::dtl::type::int_fast32 window_height_, const ::dtl::type::int_fast32 pixel_width_, const ::dtl::type::int_fast32 pixel_height_, const double target_x_, const double target_y_) noexcept
				:window_width(window_width_),
				window_height(window_height_),
				window_start_x(0),
				window_start_y(0),
				window_end_x(window_width_),
				window_end_y(window_height_),
				window_center_x(window_width_ / 2),
				window_center_y(window_height_ / 2),
				pixel_width(pixel_width_),
				pixel_height(pixel_height_),
				cell_width(window_width_ / static_cast<double>(pixel_width_)),
				cell_height(window_height_ / static_cast<double>(pixel_height_)),
				target_x(target_x_),
				target_y(target_y_) {}
			void setInit(const ::dtl::type::int_fast32 window_width_, const ::dtl::type::int_fast32 window_height_, const ::dtl::type::int_fast32 pixel_width_, const ::dtl::type::int_fast32 pixel_height_, const double target_x_, const double target_y_) noexcept {
				this->window_width = window_width_;
				this->window_height = window_height_;
				this->window_start_x = 0;
				this->window_start_y = 0;
				this->window_end_x = window_width_;
				this->window_end_y = window_height_;
				this->window_center_x = window_width_ / 2;
				this->window_center_y = window_height_ / 2;
				this->pixel_width = pixel_width_;
				this->pixel_height = pixel_height_;
				this->cell_width = window_width_ / static_cast<double>(pixel_width_);
				this->cell_height = window_height_ / static_cast<double>(pixel_height_);
				this->target_x = target_x_;
				this->target_y = target_y_;
			}


			template<typename Matrix_, typename View_Class_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				MatrixViewRect draw(Matrix_ && matrix_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_, View_Class_ && view_class_) const noexcept {
				if (x_ == 0 || y_ == 0) {
					return {};
				}
				const ::dtl::type::int_fast32 target_int_x{ static_cast< ::dtl::type::int_fast32>(this->target_x) };
				const ::dtl::type::int_fast32 target_int_y{ static_cast< ::dtl::type::int_fast32>(this->target_y) };
				const ::dtl::type::int_fast32 draw_position_x{ (this->target_x == static_cast<double>(target_int_x)) ? this->window_center_x : this->window_center_x - static_cast< ::dtl::type::int_fast32>((this->target_x - static_cast<double>(target_int_x)) * static_cast<double>(this->pixel_width)) };
				const ::dtl::type::int_fast32 draw_position_y{ (this->target_y == static_cast<double>(target_int_y)) ? this->window_center_y : this->window_center_y - static_cast< ::dtl::type::int_fast32>((this->target_y - static_cast<double>(target_int_y)) * static_cast<double>(this->pixel_height)) };

				MatrixViewRect rect{};

				for ( ::dtl::type::int_fast32 i{ draw_position_y }, draw_y{ target_int_y };; i -= this->pixel_height, --draw_y) {
					if (i <= (this->window_start_y - this->pixel_height)) {
						rect.start_y = draw_y;
						break;
					}
					while (draw_y < 0) draw_y += y_;
					if (draw_y >= y_) draw_y %= y_;
					//左上
					for ( ::dtl::type::int_fast32 j{ draw_position_x }, draw_x{ target_int_x };; j -= this->pixel_width, --draw_x) {
						if (j <= (this->window_start_x - this->pixel_width)) {
							rect.start_x = draw_x;
							break;
						}
						while (draw_x < 0) draw_x += x_;
						if (draw_x >= x_) draw_x %= x_;
						view_class_(matrix_, x_, y_, draw_x, draw_y, j, i, this->pixel_width, this->pixel_height);
					}
					//右上
					for ( ::dtl::type::int_fast32 j{ draw_position_x + this->pixel_width }, draw_x{ target_int_x + 1 }; j < this->window_end_x; j += this->pixel_width, ++draw_x) {
						if (draw_x >= x_) draw_x %= x_;
						while (draw_x < 0) draw_x += x_;
						view_class_(matrix_, x_, y_, draw_x, draw_y, j, i, this->pixel_width, this->pixel_height);
					}
				}
				for ( ::dtl::type::int_fast32 i{ draw_position_y + this->pixel_height }, draw_y{ target_int_y + 1 };; i += this->pixel_height, ++draw_y) {
					if (i >= this->window_end_y) {
						rect.end_y = draw_y;
						break;
					}
					if (draw_y >= y_) draw_y %= y_;
					while (draw_y < 0) draw_y += y_;
					//左下
					for ( ::dtl::type::int_fast32 j{ draw_position_x }, draw_x{ target_int_x }; j > (this->window_start_x - this->pixel_width); j -= this->pixel_width, --draw_x) {
						while (draw_x < 0) draw_x += x_;
						if (draw_x >= x_) draw_x %= x_;
						view_class_(matrix_, x_, y_, draw_x, draw_y, j, i, this->pixel_width, this->pixel_height);
					}
					//右下
					for ( ::dtl::type::int_fast32 j{ draw_position_x + this->pixel_width }, draw_x{ target_int_x + 1 };; j += this->pixel_width, ++draw_x) {
						if (j >= this->window_end_x) {
							rect.end_x = draw_x;
							break;
						}
						if (draw_x >= x_) draw_x %= x_;
						while (draw_x < 0) draw_x += x_;
						view_class_(matrix_, x_, y_, draw_x, draw_y, j, i, this->pixel_width, this->pixel_height);
					}
				}
				return rect;
			}
			template<typename Matrix_>
			constexpr inline MatrixViewRect draw(Matrix_ && matrix_, const ::dtl::type::int_fast32 x_, const ::dtl::type::int_fast32 y_) const noexcept {
				return this->draw(matrix_, x_, y_, SampleMatrixViewDraw());
			}

		};

	}
}

#endif //Included Dungeon Template Library