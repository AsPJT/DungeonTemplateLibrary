/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <string>
#include <DTL/Base/Struct.hpp>
#include <DTL/Macros/nodiscard.hpp>
#include <DTL/Range/RectBase.hpp>
#include <DTL/Type/Forward.hpp>
#include <DTL/Type/SizeT.hpp>
#include <DTL/Utility/MatrixWrapper.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

		template<typename Derived, typename Matrix_Var_>
		class FileBase : public ::dtl::range::RectBase<Derived> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using ShapeBase_t = ::dtl::range::RectBase<Derived>;


			///// メンバ変数 (Member Variable) /////

			::std::string str{};


		public:


			///// メンバ変数の値を取得 (Get Value) /////

			DTL_VERSIONING_CPP17_NODISCARD
				::std::string getString() const {
				return this->str;
			}


			///// 生成呼び出しファンクタ (Drawing Functor) /////

			template<typename Matrix_, typename... Args_>
			bool operator()(const Matrix_& matrix, Args_&&... args) const {
				return static_cast<const Derived*>(this)->write(matrix, DTL_TYPE_FORWARD<Args_>(args)...);
			}


			///// ダンジョン行列生成 (Create Dungeon Matrix) /////

			template<typename Matrix_, typename...Args_>
			Matrix_&& create(Matrix_&& matrix, Args_&&... args) const {
				static_cast<const Derived*>(this)->write(matrix, DTL_TYPE_FORWARD<Args_>(args)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix);
			}
			template<typename Matrix_, typename... Args_>
			Matrix_&& createArray(Matrix_&& matrix, Args_&&... args) const {
				static_cast<const Derived*>(this)->writeArray(matrix, DTL_TYPE_FORWARD<Args_>(args)...);
				return DTL_TYPE_FORWARD<Matrix_>(matrix);
			}


			///// コンストラクタ (Constructor) /////

			using ShapeBase_t::ShapeBase_t;

			constexpr explicit FileBase(const ::std::string& write_value)
				:str(write_value) {}

			constexpr explicit FileBase(const ::dtl::base::MatrixRange& matrix_range, const ::std::string& write_value)
				:ShapeBase_t(matrix_range), str(write_value) {}

			constexpr explicit FileBase(const Index_Size start_x, const Index_Size start_y, const Index_Size width, const Index_Size height, const ::std::string& write_value)
				:ShapeBase_t(start_x, start_y, width, height), str(write_value) {}
		};
	}
}

#endif //Included Dungeon Template Library
