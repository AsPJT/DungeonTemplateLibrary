/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_BIN_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BASE_BIN_HPP

#include <DTL/Workaround/cstdioGets.hpp> //Support Clang 3.4.2

#include <string>
#include <type_traits>
#include <utility>
#include <DTL/Base/Struct.hpp>
#include <DTL/Storage/FileBase.hpp>
#include <DTL/Type/New.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

		template<typename Derived, typename Matrix_Var_, typename UniquePtr_>
		class FileBaseBin : public ::dtl::storage::FileBase<Derived, Matrix_Var_> {


			///// エイリアス (Alias) /////

			using Index_Size = ::dtl::type::size;
			using FileBase_t = ::dtl::storage::FileBase<Derived, Matrix_Var_>;

			friend FileBase_t;


			///// メンバ変数 (Member Variable) /////

			::dtl::type::size color_num{ 3 };


			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename Function_>
			bool writeNormal(const Matrix_& matrix, Function_&& function) const {
				const Index_Size end_x = this->calcEndX(matrix.getX());
				const Index_Size end_y = this->calcEndY(matrix.getY());
				const Index_Size width = end_x - this->start_x;
				const Index_Size height = end_y - this->start_y;
				UniquePtr_ data(DTL_TYPE_NEW typename ::std::remove_reference<decltype(::std::declval<UniquePtr_>()[0])>::type[width * height * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y; ++row)
					for (Index_Size col{ this->start_x }; col < end_x; ++col)
						function(
							matrix(col, row),
							&data[((row - this->start_y) * width + (col - this->start_x)) * this->color_num]
						);
				static_cast<const Derived*>(this)->writeFile(this->getString().c_str(), static_cast<int>(width), static_cast<int>(height), static_cast<int>(this->color_num), data.get());
				return true;
			}

		public:


			///// 生成呼び出し (Drawing Function Call) /////

			//STL
			template<typename Matrix_, typename Function_>
			bool write(const Matrix_& matrix, Function_&& function) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix), function);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			bool write(const Matrix_& matrix, const Index_Size layer, Function_&& function) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix, layer), function);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			bool write(const Matrix_& matrix, const Index_Size max_x, const Index_Size max_y, Function_&& function) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix, max_x, max_y), function);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			bool write(const Matrix_& matrix, const Index_Size layer, const Index_Size max_x, const Index_Size max_y, Function_&& function) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix, layer, max_x, max_y), function);
			}

			//Array
			template<typename Matrix_, typename Function_>
			bool writeArray(const Matrix_& matrix, const Index_Size max_x, const Index_Size max_y, Function_&& function) const {
				return this->writeNormal(::dtl::utility::makeWrapper<Matrix_Var_>(matrix, max_x, max_y), function);
			}


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;

			constexpr explicit FileBaseBin(const ::std::string& write_value, const ::dtl::type::size color_num_)
				:FileBase_t(write_value), color_num(color_num_) {}

			constexpr explicit FileBaseBin(const ::dtl::base::MatrixRange& matrix_range, const ::std::string& write_value, const ::dtl::type::size color_num_)
				:FileBase_t(matrix_range, write_value), color_num(color_num_) {}

			constexpr explicit FileBaseBin(const Index_Size end_x, const Index_Size end_y, const Index_Size width, const Index_Size height, const ::std::string& write_value, const ::dtl::type::size color_num_)
				:FileBase_t(end_x, end_y, width, height, write_value), color_num(color_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library
