/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RETOUCH_BURY_POINT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_RETOUCH_BURY_POINT_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::retouch::BuryPoint-(修正クラス)/
#######################################################################################*/

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Range/RectBase.hpp>
#include <DTL/Utility/DrawJagged.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace retouch { //"dtl::retouch"名前空間に属する

		//マスを指定した数値で埋める
		template<typename Matrix_Var_>
		class BuryPoint : public ::dtl::range::RectBase<BuryPoint<Matrix_Var_>>,
		                  public ::dtl::utility::DrawJagged<BuryPoint<Matrix_Var_>, Matrix_Var_> {
		private:


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBase<BuryPoint>;
			using DrawBase_t = ::dtl::utility::DrawJagged<BuryPoint, Matrix_Var_>;

			friend DrawBase_t;


			///// 代入処理 /////

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				static void assign(Matrix_&& matrix_, const Index_Size col, const Index_Size row)
				noexcept(noexcept(matrix_(0, 0) != matrix_(0, 0)) && noexcept(matrix_(0, 0) = matrix_(0, 0))) {
				if (matrix_(col, row) != matrix_(col - 1, row) &&
					matrix_(col, row) != matrix_(col + 1, row) &&
					matrix_(col, row) != matrix_(col, row - 1) &&
					matrix_(col, row) != matrix_(col, row + 1))
					matrix_(col, row) = matrix_(col + 1, row);
			}

			template<typename Matrix_, typename Function_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				static void assign(Matrix_ && matrix_, const Index_Size col, const Index_Size row, Function_ && function_)
				noexcept(noexcept(function_(matrix_(0, 0))) && noexcept(assign(matrix_, 0, 0))) {
				if (function_(matrix_(col, row)))
					assign(matrix_, col, row);
			}


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_ && matrix_, Args_ && ... args_) const
				noexcept(noexcept(matrix_.getX()) && noexcept(matrix_.getY()) && noexcept(assign(matrix_, 0, 0, args_...))) {
				const Index_Size end_y_ = this->calcEndY(matrix_.getY()) - 1;
				for (Index_Size row{ this->start_y + 1 }; row < end_y_; ++row) {
					const Index_Size end_x_ = this->calcEndX(matrix_.getX(row)) - 1;
					for (Index_Size col{ this->start_x + 1 }; col < end_x_; ++col)
						assign(matrix_, col, row, args_...);
				}
				return true;
			}

			//Normal
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
				drawNormal(Matrix_ && matrix_, Args_ && ... args_) const
				noexcept(noexcept(matrix_.getX()) && noexcept(matrix_.getY()) && noexcept(assign(matrix_, 0, 0, args_...))) {
				const Index_Size end_x_ = this->calcEndX(matrix_.getX()) - 1;
				const Index_Size end_y_ = this->calcEndY(matrix_.getY()) - 1;
				for (Index_Size row{ this->start_y + 1 }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x + 1 }; col < end_x_; ++col)
						assign(matrix_, col, row, args_...);
				return true;
			}

		public:


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
