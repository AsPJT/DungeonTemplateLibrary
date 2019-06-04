/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_DRAW_JAGGED_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_DRAW_JAGGED_HPP

///// DTL Only /////

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/MatrixWrapper.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		//マップの外枠を指定した数値で埋める
		template<typename Derived, typename Matrix_Int_>
		class DrawJagged {
		private:

			///// エイリアス /////

			using Index_Size = ::dtl::type::size;


		public:


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_), function_);
			}

			//LayerSTL
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, layer_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, layer_), function_);
			}

			//Normal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, max_x_, max_y_), function_);
			}

			//LayerNormal
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, layer_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, layer_, max_x_, max_y_), function_);
			}

			//Array
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(makeWrapper(matrix_, max_x_, max_y_), function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperatorArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
		};
	}
}

#endif //Included Dungeon Template Library
