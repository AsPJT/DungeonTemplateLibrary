/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_GET_LARGEST_SQUARE_AREA_SIZE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_FIND_GET_LARGEST_SQUARE_AREA_SIZE_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::find::GetLargestSquareAreaSize-(発見クラス)/
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

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace find { //"dtl::find"名前空間に属する

/*#######################################################################################
	[概要] GetLargestSquareAreaSizeとは "Matrixの描画範囲に描画値を設置する" 機能を持つクラスである。
	[Summary] GetLargestSquareAreaSize is a class that sets drawing values in the drawing range of Matrix.
#######################################################################################*/
		template<typename Matrix_Var_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<::dtl::type::size[]>>
		class GetLargestSquareAreaSize : public ::dtl::range::RectBaseWithValue<GetLargestSquareAreaSize<Matrix_Var_>, Matrix_Var_>,
			public ::dtl::utility::DrawJagged<GetLargestSquareAreaSize<Matrix_Var_>, Matrix_Var_, ::dtl::type::size> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBaseWithValue<GetLargestSquareAreaSize, Matrix_Var_>;
			using DrawBase_t = ::dtl::utility::DrawJagged<GetLargestSquareAreaSize, Matrix_Var_, ::dtl::type::size>;

			friend DrawBase_t;

			///// 基本処理 /////

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				::dtl::type::size drawNormal(Matrix_&& matrix_) const noexcept {
				const Index_Size end_x_{ this->calcEndX(matrix_.getX()) };
				const Index_Size end_y_{ this->calcEndY(matrix_.getY()) };

				const Index_Size width{ end_x_ - this->start_x };
				const Index_Size height{ end_y_ - this->start_y };

				UniquePtr_ dp(DTL_TYPE_NEW Index_Size[width * height]);
				if (!dp) return 0;

				for (Index_Size hi{}; hi < height; ++hi)
					dp[hi * width] = ((matrix_.get(this->start_x, this->start_y + hi) == this->draw_value) ? 1 : 0);
				for (Index_Size wi{}; wi < width; ++wi)
					dp[wi] = ((matrix_.get(this->start_x + wi, this->start_y) == this->draw_value) ? 1 : 0);

				Index_Size resArea{};
				for (Index_Size hi{ 1 }; hi < height; ++hi)
					for (Index_Size wi{ 1 }; wi < width; ++wi) {
						if (matrix_.get(this->start_x + wi, this->start_y + hi) != this->draw_value) {
							dp[hi * width + wi] = 0;
							continue;
						}
						dp[hi * width + wi] = DTL_TYPE_MIN(DTL_TYPE_MIN(dp[(hi - 1) * width + wi - 1], dp[hi * width + wi - 1]), dp[(hi - 1) * width + wi]) + 1;
						if (resArea >= dp[hi * width + wi]) continue;
						resArea = dp[hi * width + wi];
					}
				return resArea * resArea;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
