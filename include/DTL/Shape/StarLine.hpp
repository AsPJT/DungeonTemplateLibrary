/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_STAR_LINE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_SHAPE_STAR_LINE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::shape::StarLine-(形状クラス)/
#######################################################################################*/

#include <cmath>
#include <array>
#include <utility>

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/Max.hpp>
#include <DTL/Type/Min.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/SSizeT.hpp>
#include <DTL/Range/RectBaseWithValueXYRA.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace shape { //"dtl::shape"名前空間に属する

/*#######################################################################################
	[概要] StarLineとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] StarLine is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_>
		class StarLine : public ::dtl::range::RectBaseWithValueXYRA<StarLine<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<StarLine<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValueXYRA<StarLine, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<StarLine, Matrix_Var_>;

			friend DrawBase_t;


			///// 基本処理 /////

			constexpr double toRadian(const double angle_) const noexcept {
				return (angle_ * 3.141592 / 180.0);
			}
			struct StarLineLine {
				double x0{}, x1{}, y0{}, y1{};
				double inclination{};
				double section{};
			};
			void make_line(::std::array<StarLineLine, 5> & lines_, const ::std::array<::std::pair<double, double>, 5> & vertex_, const ::dtl::type::size fir_, const ::dtl::type::size sec_, ::dtl::type::size& index_) const {
				if (lines_.size() <= index_) return;
				if (vertex_.size() <= fir_) return;
				if (vertex_.size() <= sec_) return;
				StarLineLine& line{ lines_[index_] };
				line.x0 = vertex_[fir_].first;
				line.y0 = vertex_[fir_].second;
				line.x1 = vertex_[sec_].first;
				line.y1 = vertex_[sec_].second;
				line.inclination = (line.y1 - line.y0) / (line.x1 - line.x0);
				line.section = line.y0 - line.inclination * line.x0;
				++index_;
			};

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				bool drawNormal(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				::std::array<StarLineLine, 5> lines{ {} };
				::std::array<::std::pair<double, double>, 5> vertex{ {} };
				for (::dtl::type::size vertex_index{}; vertex_index < 5; ++vertex_index) {
					const double rad{ this->angle + this->toRadian(vertex_index * (360.0 / 5.0) + 270.0) };
					const double tmp_x{ ::std::round(this->position_r * ::std::cos(rad) + this->position_x) }, tmp_y{ ::std::round(this->position_r * ::std::sin(rad) + this->position_y) };
					vertex[vertex_index] = ::std::pair<double, double>(tmp_x, tmp_y);
				} //Calculate the positions of every vertexes.

				//Set each line.
				::dtl::type::size index{};
				for (::dtl::type::size i{}; i < 3; ++i) {
					if (i < 2) {
						this->make_line(lines, vertex, i, i + 2, index);
						this->make_line(lines, vertex, i, i + 3, index);
					}
					else this->make_line(lines, vertex, i, i + 2, index);
				}
				const ::dtl::type::ssize end_x_s{ static_cast<::dtl::type::ssize>(this->calcEndX(matrix_.getX()) - this->start_x) };
				const ::dtl::type::ssize end_y_s{ static_cast<::dtl::type::ssize>(this->calcEndY(matrix_.getY()) - this->start_y) };
				for (::dtl::type::size vertex_index{}; vertex_index < 5; ++vertex_index) {
					const StarLineLine& line{ lines[vertex_index] };
					for (::dtl::type::ssize x{ static_cast<::dtl::type::ssize>(::std::round(DTL_TYPE_MIN(line.x0, line.x1))) }, prev{ static_cast<::dtl::type::ssize>(-1) }; x <= static_cast<::dtl::type::ssize>(::std::round(DTL_TYPE_MAX(line.x0, line.x1))); ++x) {
						::dtl::type::ssize y = static_cast<::dtl::type::ssize>(::std::round(line.inclination * x + line.section));
						if (y >= end_y_s || x >= end_x_s || x < 0 || y < 0) continue;
						matrix_.set(this->start_x + x, this->start_y + y, this->draw_value, args_...);
						if (prev != -1 && (y < prev - 1 || prev + 1 < y)) {
							const bool flag{ (prev < y) };
							for (::dtl::type::ssize i{ (flag ? DTL_TYPE_MIN(prev + 1, y - 1) : DTL_TYPE_MIN(prev - 1, y + 1)) }; i <= (flag ? DTL_TYPE_MAX(prev + 1, y - 1) : DTL_TYPE_MAX(prev - 1, y + 1)); ++i) {
								if (i >= end_y_s || x >= end_x_s || x < 0 || i < 0) continue;
								matrix_.set(this->start_x + x, this->start_y + i, this->draw_value, args_...);
							}
						}
						prev = y;
					}
				}
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
