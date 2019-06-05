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

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_), function_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size layer_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, layer_));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, layer_), function_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, max_x_, max_y_));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, max_x_, max_y_), function_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_>
			constexpr bool draw(Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, layer_, max_x_, max_y_));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperator(Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, layer_, max_x_, max_y_), function_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_>
			constexpr bool drawArray(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, max_x_, max_y_));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename Function_>
			constexpr bool drawOperatorArray(Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Int_>(matrix_, max_x_, max_y_), function_);
			}


			///// 生成呼び出しファンクタ /////

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は 引数として渡されたMatrixの型(Matrix_型) である。
	[Summary] Draw on Matrix.
	[Return value] The return type is Matrix type of argument.
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は 引数として渡されたMatrixの型(Matrix_型) である。
	[Summary] Draw on Matrix.
	[Return value] The return type is Matrix type of argument.
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は 引数として渡されたMatrixの型(Matrix_型) である。
	[Summary] Draw on Matrix.
	[Return value] The return type is Matrix type of argument.
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& createOperator(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->drawOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は 引数として渡されたMatrixの型(Matrix_型) である。
	[Summary] Draw on Matrix.
	[Return value] The return type is Matrix type of argument.
#######################################################################################*/
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
