/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_TXT_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_TXT_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <fstream>
#include <string>
#include <DTL/Base/Struct.hpp>
#include <DTL/Storage/FileBase.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/IsOutputCast.hpp>
#include <DTL/Utility/MatrixWrapper.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

		template<typename Derived, typename Matrix_Var_, typename Ofstream_>
		class FileBaseTxt : public ::dtl::storage::FileBase<Derived, Matrix_Var_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBase<Derived, Matrix_Var_>;

			friend FileBase_t;


			///// 基本処理 /////

			//STL
			template<typename Matrix_, typename... Args_>
			typename DTL_TYPE_ENABLE_IF<Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
			writeNormal(const Matrix_& matrix, Args_&&... args) const {
				const Index_Size end_y = this->calcEndY(matrix.getY());
				Ofstream_ ofs(this->getString());
				if (ofs.fail()) return false;
				return static_cast<const Derived*>(this)->writeFileJagged(ofs, end_y, matrix, DTL_TYPE_FORWARD<Args_>(args)...);
			}

			//Normal
			template<typename Matrix_, typename... Args_>
			typename DTL_TYPE_ENABLE_IF<!Matrix_::is_jagged::value, bool>::DTL_TYPE_EITYPE
			writeNormal(const Matrix_& matrix, Args_&&... args) const {
				const Index_Size end_x = this->calcEndX(matrix.getX());
				const Index_Size end_y = this->calcEndY(matrix.getY());
				Ofstream_ ofs(this->getString());
				if (ofs.fail()) return false;
				return static_cast<const Derived*>(this)->writeFile(ofs, end_x, end_y, matrix, DTL_TYPE_FORWARD<Args_>(args)...);
			}

		public:


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_>
			bool write(const Matrix_& matrix_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_));
			}
			template<typename Matrix_, typename Function_>
			bool writeOperator(const Matrix_& matrix_, Function_&& function_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_), function_);
			}

			//LayerSTL
			template<typename Matrix_>
			bool write(const Matrix_& matrix_, const Index_Size layer_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, layer_));
			}
			template<typename Matrix_, typename Function_>
			bool writeOperator(const Matrix_& matrix_, const Index_Size layer_, Function_&& function_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, layer_), function_);
			}

			//Normal
			template<typename Matrix_>
			bool write(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			bool writeOperator(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, max_x_, max_y_), function_);
			}

			//LayerNormal
			template<typename Matrix_>
			bool write(const Matrix_& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, layer_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			bool writeOperator(const Matrix_& matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, layer_, max_x_, max_y_), function_);
			}

			//Array
			template<typename Matrix_>
			bool writeArray(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, max_x_, max_y_));
			}
			template<typename Matrix_, typename Function_>
			bool writeOperatorArray(const Matrix_& matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_&& function_) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix_, max_x_, max_y_), function_);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename... Args_>
			Matrix_&& createOperator(Matrix_&& matrix_, Args_&&... args_) const {
				this->writeOperator(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename... Args_>
			Matrix_&& createOperatorArray(Matrix_&& matrix_, Args_&&... args_) const {
				this->writeOperatorArray(matrix_, DTL_TYPE_FORWARD<Args_>(args_)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix_);
			}


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
