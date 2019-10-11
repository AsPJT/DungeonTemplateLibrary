/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_GET_LARGEST_RECT_AREA_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_GET_LARGEST_RECT_AREA_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::find::GetLargestRectArea-(発見クラス)/
#######################################################################################*/

#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/constexpr.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/Min.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Type/UniquePtr.hpp>
#include <DTL/Range/RectBaseWithValue.hpp>
#include <DTL/Utility/DrawJagged.hpp>

#include <stack>
#include <utility>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace find { //"dtl::find"名前空間に属する

/*#######################################################################################
	[概要] GetLargestRectAreaとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] GetLargestRectArea is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<::dtl::type::size[]>>
		class GetLargestRectArea : public ::dtl::range::RectBaseWithValue<GetLargestRectArea<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<GetLargestRectArea<Matrix_Var_>, Matrix_Var_, ::dtl::base::MatrixRange> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValue<GetLargestRectArea, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<GetLargestRectArea, Matrix_Var_, ::dtl::base::MatrixRange>;

			friend DrawBase_t;

			///// 基本処理 /////

			template<typename Matrix_>
			//DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::base::MatrixRange drawNormal(Matrix_&& matrix_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const Index_Size width{ end_x_ - this->start_x };
				const Index_Size height{ end_y_ - this->start_y };

				::dtl::base::MatrixRange range{};
				UniquePtr_ heightCnt(DTL_TYPE_NEW Index_Size[(width + 1) * height]);
				if (!heightCnt) return range;

				for (Index_Size hi{}; hi < height; ++hi)
					for (Index_Size wi{}; wi <= width; ++wi)
						heightCnt[hi * (width + 1) + wi] = 1;

				for (Index_Size hi{}; hi < height; ++hi)
					for (Index_Size wi{}; wi < width; ++wi) {
						if (matrix_.get(wi, hi) != this->draw_value) {
							heightCnt[hi * (width + 1) + wi] = 0;
							continue;
						}
						if (hi < 1) continue;
						heightCnt[hi * (width + 1) + wi] = ((matrix_.get(wi, hi) == matrix_.get(wi, hi - 1)) ? (heightCnt[(hi - 1) * (width + 1) + wi] + 1) : 1);
					}

				Index_Size resArea{};
				for (Index_Size hi{}; hi < height; ++hi) {
					heightCnt[hi * (width + 1) + width] = 0;
					::std::stack< ::std::pair<Index_Size, Index_Size> > st{};
					Index_Size rect{};
					Index_Size wii{};
					Index_Size ww{};
					Index_Size hh{};
					for (Index_Size wi{}; wi <= width; ++wi) {
						::std::pair< Index_Size, Index_Size > currentRect{ ::std::make_pair(heightCnt[hi * (width + 1) + wi], wi) };
						if (st.empty()) st.push(currentRect);
						else if (st.top().first < currentRect.first) st.push(currentRect);
						else if (st.top().first > currentRect.first) {
							Index_Size target{ wi };
							while (!st.empty() && st.top().first >= currentRect.first) {
								::std::pair< Index_Size, Index_Size > stackTop{ st.top() };
								st.pop();
								const Index_Size rect2{ (stackTop.first) * (wi - stackTop.second) };
								if (rect < rect2) {
									rect = rect2;
									wii = wi;
									hh = stackTop.first;
									ww = (wi - stackTop.second);
								}
								target = stackTop.second;
							}
							currentRect.second = target;
							st.push(currentRect);
						}
					}
					if (resArea < rect) {
						resArea = rect;
						range.x = this->start_x + wii - ww;
						range.y = this->start_y + hi + 1 - hh;
						range.w = ww;
						range.h = hh;
					}
				}
				return range;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
