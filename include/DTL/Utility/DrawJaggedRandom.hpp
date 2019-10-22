/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_DRAW_JAGGED_RANDOM_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_DRAW_JAGGED_RANDOM_HPP

///// DTL Only /////

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Random/RandomEngine.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/MatrixWrapper.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する

		template<typename Derived, typename Matrix_Var_, typename Random_Engine_, typename Return_Var_ = bool>
		class DrawJaggedRandom {
		private:

			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;


		public:

			///// 生成呼び出し (Drawing Function Call) /////

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename... Args>
			constexpr Return_Var_ redraw(const Matrix_Var_& init_value_, Matrix_& matrix_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->redrawNormal(init_value_, ::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename... Args>
			constexpr Return_Var_ draw(Matrix_& matrix_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()));
			}

			/*#######################################################################################
				[概要] Matrixに描画する。
				[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
				[Summary] Draw on Matrix.
				[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
			#######################################################################################*/
			template<typename Matrix_, typename... Args>
			constexpr Return_Var_ drawAdd(Matrix_& matrix_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), 0, 0, 0, 0);
			}

			/*#######################################################################################
							[概要] Matrixに描画する。
							[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
							[Summary] Draw on Matrix.
							[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
						#######################################################################################*/
			template<typename Matrix_, typename Matrix2_, typename... Args>
			constexpr Return_Var_ drawOther(Matrix_& matrix_, Matrix2_& matrix2_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), ::dtl::utility::makeWrapper<Matrix_Var_>(matrix2_, DTL_TYPE_FORWARD<Args>(args)...)
					, Matrix_Var_{}, 0, 0, 0, 0); //10*4 Copy
			}

			/*#######################################################################################
							[概要] Matrixに描画する。
							[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
							[Summary] Draw on Matrix.
							[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
						#######################################################################################*/
			template<typename Matrix_Var2_, typename Matrix_, typename Matrix2_, typename... Args>
			constexpr Return_Var_ drawOther(Matrix_& matrix_, Matrix2_& matrix2_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), ::dtl::utility::makeWrapper<Matrix_Var2_>(matrix2_, DTL_TYPE_FORWARD<Args>(args)...)
					, Matrix_Var2_{}, 0, 0, 0, 0); //10*4 Copy
			}

			/*#######################################################################################
				[概要] Matrixに描画する。
				[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
				[Summary] Draw on Matrix.
				[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
			#######################################################################################*/
			template<typename Matrix_, typename Function_, typename... Args>
			constexpr Return_Var_ drawOperator(Matrix_& matrix_, Function_&& function_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), function_);
			}

			/*#######################################################################################
							[概要] Matrixに描画する。
							[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
							[Summary] Draw on Matrix.
							[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
						#######################################################################################*/
			template<typename Matrix_, typename Function_, typename... Args>
			constexpr Return_Var_ drawFunction(Matrix_& matrix_, Function_&& function_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), function_, 0, 0, 0, 0);
			}

			/*#######################################################################################
							[概要] Matrixに描画する。
							[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
							[Summary] Draw on Matrix.
							[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
						#######################################################################################*/
			template<typename Matrix_, typename Function_, typename... Args>
			constexpr Return_Var_ drawAddOperator(Matrix_& matrix_, Function_&& function_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_RANDOM_ENGINE.get()), function_, 0, 0, 0);
			}

			/*#######################################################################################
				[概要] Matrixに描画する。
				[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
				[Summary] Draw on Matrix.
				[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
			#######################################################################################*/
			template<typename Matrix_>
			constexpr Return_Var_ drawArray(Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, max_x_, max_y_), Random_Engine_(DTL_RANDOM_ENGINE.get()));
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename SEED_, typename... Args>
			constexpr Return_Var_ drawSEED(Matrix_& matrix_, SEED_&& seed_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_TYPE_FORWARD<SEED_>(seed_)));
			}

			/*#######################################################################################
				[概要] Matrixに描画する。
				[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
				[Summary] Draw on Matrix.
				[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
			#######################################################################################*/
			template<typename Matrix_, typename SEED_, typename... Args>
			constexpr Return_Var_ drawAddSEED(Matrix_& matrix_, SEED_&& seed_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), Random_Engine_(DTL_TYPE_FORWARD<SEED_>(seed_)), 0, 0, 0, 0);
			}

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename... Args>
			constexpr Return_Var_ drawRandomEngine(Matrix_& matrix_, Random_Engine_&& seed_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), DTL_TYPE_FORWARD<Random_Engine_>(seed_));
			}

			/*#######################################################################################
				[概要] Matrixに描画する。
				[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
				[Summary] Draw on Matrix.
				[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
			#######################################################################################*/
			template<typename Matrix_, typename... Args>
			constexpr Return_Var_ drawAddRandomEngine(Matrix_& matrix_, Random_Engine_&& seed_, Args&& ... args) const noexcept {
				return static_cast<const Derived*>(this)->drawNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, DTL_TYPE_FORWARD<Args>(args)...), DTL_TYPE_FORWARD<Random_Engine_>(seed_), 0, 0, 0, 0);
			}

			///// 生成呼び出しファンクタ (Drawing Functor) /////

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は bool である。[ true : 描画に成功したことを示す / false : 描画に失敗したことを示す ]
	[Summary] Draw on Matrix.
	[Return value] The return type is bool. [ true: Drawing was successful. / false: Drawing failed. ]
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			constexpr Return_Var_ operator()(Matrix_& matrix_, Args_&& ... args_) const noexcept {
				return this->draw(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

/*#######################################################################################
	[概要] Matrixに描画する。
	[戻り値] 戻り値の型は 引数として渡されたMatrixの型(Matrix_型) である。
	[Summary] Draw on Matrix.
	[Return value] The return type is Matrix type of argument.
#######################################################################################*/
			template<typename Matrix_, typename ...Args_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
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
				Matrix_&& createArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
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
				Matrix_&& createOperator(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
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
				Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&& ... args_) const noexcept {
				this->drawOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
		};
	}
}

#endif //Included Dungeon Template Library
